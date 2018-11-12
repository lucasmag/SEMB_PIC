import serial
from serial import Serial

ser = serial.Serial(port = "/dev/ttyUSB0", baudrate = 9600, timeout = 2)

#essa linha inicia o envio de pixels do pic para o pc
#ser.write(b'GET$')
#le o pixels aqui
while True:
    bytesToRead = ser.inWaiting()
    c = ser.read(1)
    if(c != b''):
        print(ord(c))
        
#depois de ler os pixels cria um arquivo .pgm(P5) em disco



