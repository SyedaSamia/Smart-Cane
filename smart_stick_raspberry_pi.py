import serial
import RPi.GPIO as GPIO
import time
import subprocess


ser=serial.Serial("/dev/ttyACM0",9600)  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=9600

while True:
    read_ser = ser.readline()
    print(read_ser)
    if(read_ser == b'1\r\n'):
        text1 = '"Sir, There is a, larger, obstacle"'
        subprocess.call('echo '+text1+'|festival --tts', shell=True)

    if(read_ser == b'2\r\n'):
        text2 = '"Sir, careful! There is an upstair"'
        subprocess.call('echo '+text2+'|festival --tts', shell=True)

    if(read_ser == b'3\r\n'):
        text3 = '"Sir, Careful! There is a, smaller, obstacle"'
        subprocess.call('echo '+text3+'|festival --tts', shell=True)

    if(read_ser == b'4\r\n'):
        text3 = '"Sir, stick is out of line!"'
        subprocess.call('echo '+text3+'|festival --tts', shell=True)
