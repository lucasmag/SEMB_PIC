import serial
from serial import Serial
import array

def recebe_pixels():
    nPixels = 0
    pixel = ser.read(1)
    pixels = []
    totalPixelsEsperado = 3010
    print("Recebendo pixels")
    
    while nPixels < totalPixelsEsperado:
        pixel = ser.read(1)
        if(pixel != b''):
            nPixels += 1
            pixels.append(ord(pixel))
    print("Transferência concluída!")
    return pixels

def cria_p5(pixels):
    print("Gerando imagem RobertPIC.PGM")
    img = array.array('B')
    for i in range(70):
        for j in range(43):
            if(j != 43):
                img.append(pixels[i* 43 + j])
            else:
                img.append(pixels[i* 43 + j])
    return img

if __name__ == "__main__":
    ser = serial.Serial(port = "/dev/ttyUSB0", baudrate = 9600, timeout = 0)
    ser.write(b'ROB$')
    #ser.write(b'GET$')
    pixels = recebe_pixels()
    img = cria_p5(pixels)
    imageFile = open("RobertPIC.PGM","w")
    imageFile.write("P5\n70 43\n255\n")
    
    imageFile = open("RobertPIC.PGM","ab")
    img.tofile(imageFile)
    print("Imagem .pgm P5 gerada com sucesso!")
    imageFile.close()
