/* 
 * File:   uart.h
 * Author: Tiago Dionizio
 *
 * Created on 11 de Novembro de 2018, 14:22
 */

#ifndef UART_H
#define	UART_H

void UART_iniciar(){
    ANSELCbits.ANSC7 = 0;   //Desativa função analógica no pino RC7
    ANSELCbits.ANSC6 = 0;   //Desativa função analógica no pino RC6
    RC6PPS = 0x10;          //Configura pino RC6 como TX
    RXPPSbits.RXPPS = 0x17; //Configura pino RC7 como RX
    TX1STAbits.BRGH = 0;    //Necessário para configurar o baud rate da EUSART
    BAUDCON1bits.BRG16 = 0; //Configura registrado BAUDCON1 como 8 bits
    SPBRG = 51;             //Configura baud rate para 9600bps
    RC1STAbits.SPEN = 1;    //Habilita EUSART
    RC1STAbits.CREN = 1;    //Habilita recebimento EUSART (RX)
    TX1STAbits.TXEN = 1;    //Habilita transmissão EUSART (TX)
    TX1STAbits.SYNC = 0;    //Configura EUSART para modo assíncrono
}

char UART_Ler(){
    while(!RCIF);
    return RCREG;
}

void UART_Ler_Texto(char* saida){
    short index = 0;
    char c;
    while(c != '$'){
       c = UART_Ler(); 
       saida[index] = c;
       index++;
    }
    saida[index - 1] = '\0';
}

void UART_Escrever(char c){
    while(!TX1STAbits.TRMT);
    TXREG = c;
}

void UART_Escrever_Pixel(unsigned char p){
    while(!TX1STAbits.TRMT);
    TXREG = p;
}

void UART_Escrever_Texto(char* texto){
    int index;
    for(index=0; texto[index]!='\0'; index++)
        UART_Escrever(texto[index]);
}

#endif	/* UART_H */

