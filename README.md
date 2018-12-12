## Descrição
O presente projeto tem como objetivo a implementação de um filtro de detecção de bordas em imagens na plataforma embarcada PIC18F4520. O filtro implementado foi o operador Roberts Cross.

O projeto se consiste em duas partes, uma feita no computador usando python e outra na plataforma embarcada PIC18F4520 em C.

- __Computador/Python:__ O script em Python envia um comando, serialmente, através da porta USB, para o PIC, iniciando aplicação do filtro na imagem. Os pixels da imagem, logo após a aplicação do filtro, são automaticamente enviados ao computador e armazenados em um array. Quando toda a imagem é recebida o script retorna um arquivo de imagem no formato .pgm P5.

- __PIC/C:__ A imagem é previamente armazenada na memória interna do microcontrolador. Quando o PIC recebe o comando, ele pega um pixel da imagem, aplica o filtro de Roberts Cross e envia ao computador. Esse processo é feito com cada pixel da imagem, até que todos tenham sido enviados.

## Resultado
A imagem de teste armazenada no microcontrolador é uma imagem em escala de cinza de 8 bits de profundidade de cor com resolução de 70 x 43(3010 pixels). 

<p align="center">
  <img src="https://i.imgur.com/NmNl9Si.jpg"> <img src="https://i.imgur.com/XWNHeOc.jpg">
</p>

<p align="center">
 <em>Foto original(à esquerda) e Foto com filtro Roberts Cross aplicado(à direita)</em>
</p>

>O tamanho reduzido das imagens se deve a limitação de memória do microcontrolador utilizado neste projeto.

## Desenvolvido com

* [MPLAB® X Integrated Development Environment (IDE)](https://www.microchip.com/mplab/mplab-x-ide) 
* [Python 3 IDLE](https://www.python.org/downloads/)

## Autores

* **Lucas Magalhães** - [LucasMag](https://github.com/lucasmag)
* **Tiago Siqueira** - [TiagoSD22](https://github.com/TiagoSD22)

