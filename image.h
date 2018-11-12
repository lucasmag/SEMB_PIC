/* 
 * File:   image.h
 * Author: tiagosd
 *
 * Created on 7 de Novembro de 2018, 22:31
 */

#ifndef IMAGE_H
#define	IMAGE_H

#define imgALTURA 70
#define imgLARGURA 43

//unsigned char  pixels[35][43];

void ZerarPixels(void){
    int i,j;
    for(i = 0; i< imgALTURA; i++){
        for(j = 0; j < imgLARGURA; j++){
//            pixels[i][j] = (unsigned char) 0;
        }
    }
}

#endif	/* IMAGE_H */

