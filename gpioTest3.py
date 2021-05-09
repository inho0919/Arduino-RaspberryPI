import RPi.GPIO as GPIO
import time

led = 7

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led, GPIO.OUT)

while True:
    print("1~100 Light")
    level = int(input())

    if (level <= 100 or level >0):
        for i in range(1, 100, 1):
            gauge = float(level*0.0001)

            if (i == level):
                while True:
                    GPIO.output(led, 0)
                    time.sleep(gauge)
                    GPIO.output(led, 1)
                    time.sleep(0.01-gauge)
                    #여기서 새로 입력받고 조정
                    #print("Back?")
                    #choose = input()
                    #if (choose == 'y' or choose == 'yes'):
                    #    break
    else:
        print("Again")
