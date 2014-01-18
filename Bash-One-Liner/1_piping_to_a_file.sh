#!/bin/bash

cat /dev/cu.usbmodem1421 | awk '{ for (i=0; i<NF; i++) printf $i + system("date +,%s")}' >> sensor_readings.dat
