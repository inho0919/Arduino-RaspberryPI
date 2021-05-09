import RPi.GPIO as GPIO
import time

rot = 12
blau = 7

GPIO.setmode(GPIO.BOARD)
GPIO.setup(rot, GPIO.OUT)
GPIO.setup(blau, GPIO.OUT)

plus = 0.0099
minus = -0.0099

GPIO.output(rot,1)
GPIO.output(blau,1)

while True:
# ----- Fade out -----
    if (plus > minus):
        plus = plus - 0.0001
        minus = minus + 0.0001
        GPIO.output(rot,0)
        GPIO.output(blau,0)
        time.sleep(plus + 0.0001 )
        GPIO.output(rot,1)
        GPIO.output(blau,1)
        time.sleep(0.01-plus)
# ----- Zero -----
    elif (plus == minus):
        plus = plus - 0.0001
        minus = minus + 0.0001
# ----- Fade in (Worked) -----
    elif (plus < minus and minus < 0.0099):
        plus = plus - 0.0001
        minus = minus + 0.0001
        GPIO.output(rot,0)
        GPIO.output(blau,0)
        time.sleep(minus)
        GPIO.output(rot,1)
        GPIO.output(blau,1)
        time.sleep(0.01 - minus)

    else:
        plus = 0.0099
        minus = -0.0099


