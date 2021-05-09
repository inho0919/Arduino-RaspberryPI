import serial
import time

#LED 
ser = serial.Serial(port="/dev/ttyS0", baudrate=115200, timeout=3)

num_red = 2
num_green = 8
ser.write(num_red)
ser.write(num_green)
