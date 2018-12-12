/*
 *  Sobre este c�digo:
 *  O arquivo main.c configura os registradores e bits de configura��o do pic 16f18875 e aqui encontra-se a rotina 
 *  principal da aplica��o. O MCU fica a espera de um comando enviado pela porta serial, e executa o algorito de
 *  Roberts Cross para detec��o de bordas na imagem armazenada no arquivo image.h. Os valores dos novos pixels s�o
 *  enviados para a interface serial onde podem ser lidos por um pc atrav�s de um adaptador usb/serial(ttl).

 *  Autores : Tiago Dionizio e Lucas Magalh�es

 *  Copyright (C) 2018 Tiago Siqueira Dionizio  <tiagosdionizio@gmail.com>

 *  Copyright (C) 2018 Lucas Magalh�es de Sousa <lucasmag97@gmail.com> 

 *  Data de Atualiza��o : 20 de Novembro de 2018

 *  Modo de uso:
 *  A aplica��o � controlada por comandos enviados para a entrada serial EUSART (RX - RC7, TX - RC6) do MCU, essas 
 *  entradas podem ser enviadas por um script em python usando o m�dulo pySerial, por meio desse script � poss�vel
 *  ordenar a execu��o do algoritmo de Roberts e gerar a imagem resultante com os pixels calculados e enviados pelo
 *  MCU. 

 *  Restri��o de uso:
 *  Necessita-se de um interpretador python ( >= 2.7) instalado na m�quina que se comunicar� com a aplica��o,
 *  bem como o m�dulo pySerial. Al�m disso, � necess�rio um adaptador usb/serial(ttl), como o pl2303, de modo que 
 *  que possa haver um canal de comunica��o entre o computador e a aplica��o embarcada. A imagem gerada � em formato
 *  .pgm bin�rio (P5).

 *  Refer�ncia para o algoritmo: 
 *  MARQUES FILHO, Og�; VIEIRA NETO, Hugo. Processamento Digital de Imagens, Rio de Janeiro: Brasport, 1999, pg: 97.
*/


// Production -> Set Configuration Bits;
// PIC16F18875 Configuration Bit Settings
// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC  = OFF       // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC   = HFINT32   // Power-up default value for COSC bits (HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF       // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN    = ON        // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN    = ON        // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE    = ON        // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE    = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN  = OFF       // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN    = ON        // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV     = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD      = OFF       // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY  = ON        // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN   = ON        // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS   = WDTCPS_31 // WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE     = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS   = WDTCWS_7  // WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS   = SC        // WDT input clock selector (Software Control)

// CONFIG4
#pragma config WRT      = OFF       // UserNVM self-write protection bits (Write protection off)
#pragma config SCANE    = available // Scanner Enable bit (Scanner module is available for use)
#pragma config LVP      = ON        // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP       = OFF       // UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD      = OFF       // DataNVM code protection bit (Data EEPROM code protection disabled)

#include <xc.h>
#include <string.h>
#include "image.h"
#include "uart.h"

/*
 * LEDs para indicar,respectivamente, que est� havendo comunica��o de dados entre o MCU e o computador e
 * que o filtro de Roberts est� sendo processado pelo MCU.
 */
#define comunicacaoLED  LATAbits.LATA7
#define robertsLED      LATAbits.LATA6

char entrada[10];

/*
 *  Esta fun��o configura alguns registradores do MCU pic16f18875, os pinos dos bloco A e B configurados como sa�da,
 *  enquanto o bloco C tem o pino RC7 como entrada e os demais como sa�da.
 */
void ConfigurarPIC(void){
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x80;
}

/*
 * Esta fun��o � chamada quando o comando ROB � recebido na interface serial EUSART e serve para aplicar o 
 * algoritmo de Roberts Cross para todos os pixels da imagem. Foi necess�rio adaptar o algoritmo, pois a imagem
 * foi armazenada como const, pois, ao contr�rio, n�o seria poss�vel armazenar os 3010 pixels referentes a esta.
 * Assim sendo, para cada novo pixel calculado, este valor � imediatamente enviado para a interface serial, para que
 * o computador, rodando o script em python possa receber esses valores e gerar a imagem resultante(bordas). 
 * O la�o que percorre a imagem inicia da primeira linha e primeira coluna e vai at� a pen�ltima linha e pen�ltima 
 * coluna, pois a imagem armazenada no arquivo image.h � o resultado da imagem original adicionada de um padding, uma
 * borda feita apenas de pixels com intensidade 0 (preto) colocados ao redor de toda a imagem, 
 * adicionando, assim, duas linhas e duas colunas a mais, que devem ser ignoradas do conjunto de pixels a se aplicar
 * o filtro de Roberts.
 */
void RobertsCrossSerial(void){
    short i,j,k,l;
    unsigned char p;
    unsigned char novo_pixel;
    robertsLED = 1;
    for(i = 1; i < imgAltura; i++){
        for(j = 1; j < imgLargura; j++){
            if (j == 1) {
                for (l = 0; l < 2; l++) {
                    UART_Ler_Pixel(&p);
                    regiaoAtual[0][0] = p;
                    UART_Ler_Pixel(&p);
                    regiaoAtual[1][0] = p;
                }
            } 
            else {
                for (k = 0; k < 2; k++) {
                    UART_Ler_Pixel(&p);
                    regiaoAtual[k][1] = p;
                }
            }
            novo_pixel = RobertsCross();
            comunicacaoLED = 1;
            UART_Escrever_Pixel(novo_pixel);
            comunicacaoLED = 0;
            
            for(k = 0; k < 2; k++){
                regiaoAtual[k][0] = regiaoAtual[k][1];
            }
        }
    }
    robertsLED = 0;
}

void obterDimensoes(){
    short i = 0;
    short j;
    imgLargura = 0;
    imgAltura = 0;
    while(entrada[i] != 'x'){
        imgLargura = 10 * imgLargura + (entrada[i] - '0');
        i++;
    }
    i++;
    while(entrada[i] != '\0'){
        imgAltura = 10 * imgAltura + (entrada[i] - '0'); 
        i++;
    }
}

void iniciarConexao(){
    UART_Escrever_Texto("ACK");//confirmou conex�o com o PC
    UART_Ler_Texto(entrada);//espera as dimens�es da imagem a ser processada
    obterDimensoes();//parseia a mensagem recebida e converte para valores inteiros
    UART_Escrever_Texto("ACK");//confirma o recebimento e convers�o da resolu��o da imagem
    RobertsCrossSerial();//inicia o filtro de Roberts
}

/*
 * A rotina principal configura os pinos de I/O e os registradores EUSART do MCU, acende o LED conectado ao pino
 * RA7 para indicar funcionamento da rotina e, em seguida, coloca o MCU em modo de espera de um comando na interface
 * serial EUSART. Caso o comando recebido seja GET, os pixels da imagem no arquivo image.h s�o enviados serialmente
 * para o computador. Caso o comando o seja ROB, o MCU executa o filtro de Roberts Cross.
 */
int main(void) {
    ConfigurarPIC();
    UART_iniciar();  
    LATA = 0x10;
    
    while (1) {
        UART_Ler_Texto(entrada);
        if(strcmp(entrada,"SYN") == 0){ 
            iniciarConexao();
        }
    }
    
    return EXIT_SUCCESS;
}