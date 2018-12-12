/*
 *  Esta biblioteca serve para armazenar os pixels da imagem de teste e define o algoritmo de Roberts Cross.

 *  Autores : Tiago Dionizio e Lucas Magalh�es

 *  Copyright (C) 2018 Tiago Siqueira Dionizio  <tiagosdionizio@gmail.com>

 *  Copyright (C) 2018 Lucas Magalh�es de Sousa <lucasmag97@gmail.com> 

 *  Data de Atualiza��o : 20 de Novembro de 2018
*/

#ifndef IMAGE_H
#define	IMAGE_H

#include <math.h>

int imgLargura;
int imgAltura;

/*
 * Esses valores s�o referentes aos pixels da imagem de teste, imagem com 43 linhas e 70 colunas.
 * Entretanto, a imagem armazenada � composta tamb�m da t�cnica de padding, logo, a estrutura de dados para comportar
 * a imagem deve ter duas linhas e duas colunas adicionais, referentes �s bordas do padding. Por isso os valors 0x0 
 * nas primeiras e �ltimas linhas e colunas.
 */
unsigned char regiaoAtual[2][2];

unsigned int isqrt(int Value) {
    unsigned Root = 0;
    unsigned Bit;
    for (Bit = 0x4000; Bit > 0; Bit >>= 2) {
        unsigned Trial = Root + Bit;
        Root >>= 1;
        if (Trial <= Value) {
            Root += Bit;
            Value -= Trial;
        }
    }
    return Root;
}

/*
 * Pela defini��o do algoritmo de Roberts, para um pixel em x,y dado por P(x,y) = p, 
 * seu novo valor, p' dado por P'(x,y) ser�:
    Gx = (P(x,y) - P(x + 1, y + 1))  (Convolu��o por robertX, define a varia��o horizontal)
    Gy = (P(x, y + 1) - P(x + 1, y)) (Convolu��o por robertY, define a varia��o vertical)
    P'(x,y) = sqrt(Gx^2 + Gy^2)
 * essa convolu��o � realizada pelos la�os for(x de 0 a 2) e for(y de 0 a 2).
 * Observe que o pixel � um dado do tipo unsigned char, por a imagem manipulada est� em formato .pgm bin�rio(P5),
 * em que os pixels podem assumir intensidades de 0 a 255, logo, s�o necess�rios 8 bits (1 byte) para armazenar 
 * cada pixel, aliado ao fato de que esses valores n�o podem ser negativos, 
 * o tipo unsigned char � o mais apropriado.
 */
unsigned char RobertsCross(){
    int Gx = 0;
    int Gy = 0;
    unsigned char novo_pixel;
    Gx = regiaoAtual[0][0] - regiaoAtual[1][1];
    Gy = regiaoAtual[0][1] - regiaoAtual[1][0];
    //novo_pixel = abs(Gx) + abs(Gy);
    novo_pixel = isqrt((Gx*Gx + Gy*Gy));
    return novo_pixel;
}

#endif	/* IMAGE_H */
