import serial
from serial import Serial

ser = serial.Serial(port = "/dev/ttyUSB0", baudrate = 9600, timeout = 0)

nPixels = 0
pixel = ser.read(1)
pixels = []
ser.write(b'ROB$')
#ser.write(b'GET$')

totalPixelsEsperado = 3010
print("Recebendo pixels")
while nPixels < totalPixelsEsperado:
    pixel = ser.read(1)
    if(pixel != b''):
        nPixels += 1
        pixels.append(ord(pixel))

print("Transferência concluída!")
print("Gerando imagem RobertPIC.PGM")
imagemFile = open("RobertPIC.PGM","w")
imagemFile.write("P2\n70 43\n255\n")

#pixelsBytes = bytearray(pixels)
#imagemFile = open("RobertPIC.PGM","wb+")
for i in range(70):
    for j in range(43):
        if(j != 43):
            imagemFile.write("%d " % pixels[i* 43 + j])
        else:
            imagemFile.write("%d" % pixels[i* 43 + j])
    imagemFile.write("\n")
imagemFile.write("\r")
imagemFile.close()
'''
imagemFile = open("RobertPIC.PGM","ab+")
imagemFile.write(pixelsBytes)
imagemFile = open("RobertPIC.PGM","a+")
imagemFile.write("\r")
'''
print("Imagem gerada com sucesso!")
imagemFile.close()







