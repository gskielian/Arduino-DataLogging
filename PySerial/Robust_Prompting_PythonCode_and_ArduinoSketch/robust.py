#!/usr/bin/python
import serial
import time
import datetime

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
  time_stamp =time.time()
  arduino_sensor = send_and_receive('1')
  date_stamp = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
  f.write(time_stamp + arduino_sensor + date_stamp)
  f.closed
  f = open('dataFile.txt','a')
