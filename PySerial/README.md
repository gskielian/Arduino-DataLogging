PySerial
========

Pyserial is an excellent way to grab data from your Arduino, and it is both robust and easy to implement.




The following examples shows a really simple approach for doing this, which will get you started.

**HOWEVER, be careful that the arduino is not constantly sending data to your program -- you will likely encounter errors from the buffer overfilling.**


### Naive Pyserial and Sketch


```python 

import serial

ser = serial.Serial('/dev/ttyACM0',115200)

f = open('dataFile.txt','a')

while 1 :
    f.write(ser.readline())
    f.close()
    f = open('dataFile.txt','a')
```

```arduino

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(1000);
}
```


### Robust Pyserial and Sketch


