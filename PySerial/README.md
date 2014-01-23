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

```ino

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(1000);
}
```


### Robust Pyserial and Sketch
```python 
#!/usr/bin/python
import serial, time
ser = serial.Serial('/dev/ttyACM0',  115200, timeout = 0.1)

#if you only want to send data to arduino (i.e. a signal to move a servo)
def send( theinput ):
  ser.write( theinput )
  while True:
    try:
      time.sleep(0.01)
      break
    except:
      pass
  time.sleep(0.1)

#if you would like to tell the arduino that you would like to receive data from the arduino
def send_and_receive( theinput ):
  ser.write( theinput )
  while True:
    try:
      time.sleep(0.01)
      state = ser.readline()
      print state
      return state
    except:
      pass
  time.sleep(0.1)

f = open('dataFile.txt','a')

while 1 :
    arduino_sensor = send_and_receive('1')
    f.write(arduino_sensor)
    f.close()
    f = open('dataFile.txt','a')

```

```arduino
void setup () {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
} 
 
 
void loop() {

  if (Serial.available()) 
  {
  
     ch = Serial.read();
      
     if ( ch == '1' ) { 
       Serial.println(analogRead(A0)); // if '1' is received, then send back analog read A0
     } 
     else if (ch == '2') {    
       digitalWrite(13,HIGH); // if '2' is received, turn on the led attached to 13
     } 
     else if (ch == '3') {
       digitalWrite(13,LOW); // if '3' is received then turn off the led attached 13
     } else {
       delay(10);
     }
     
  }
  
}
```
