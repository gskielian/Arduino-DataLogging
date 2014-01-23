import serial

ser = serial.Serial('/dev/ttyACM0',115200)

f = open('dataFile.txt','a')

while 1 :
    f.write(ser.readline())
    f.close()
    f = open('dataFile.txt','a')
    
    
