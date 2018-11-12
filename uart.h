/* 
 * File:   uart.h
 * Author: Tiago Dionizio
 *
 * Created on 11 de Novembro de 2018, 14:22
 */

#ifndef UART_H
#define	UART_H

void UART_iniciar(){
    ANSELCbits.ANSC7 = 0;
    ANSELCbits.ANSC6 = 0;   // Disable Analog function of pin RC6/AN8
    RC6PPS = 0x10; // MAKE PIN RC6 AS TX PIN -> see PIC16F18875 datasheet
    RXPPSbits.RXPPS = 0x17; // MAKE PIN RC7 AS RX PIN -> see PIC16F18875 datasheet 
    SPBRG = 51; //baud rate 9600
    TX1STAbits.BRGH = 0;// Initialising BRGH and BRG16 register pair (BAUD RATE)
    BAUDCON1bits.BRG16 = 0;// Initialising BRGH and BRG16 register pair (BAUD RATE)             
    TX1STAbits.TXEN = 1;               // Enables Transmitter circuitry
    TX1STAbits.SYNC = 0;// Clearing SYNC bit (TXxSTA reg)|Configures EUSART for asynchronous operation
    RC1STAbits.SPEN = 1;               // Enables EUSART and configures TX/CK I/O pin as output
    RC1STAbits.CREN = 1;    //habilita EUSART Rx
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

