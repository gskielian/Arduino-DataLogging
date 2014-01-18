#!/bin/bash

cat /dev/cu.usbmodem1421 | awk '{ for (i=0; i<NF; i++) if($i == 9001) {system("say ITS OVER 9000\!")} printf $i + system("date +,%s")}' >> sensor_readings.dat
