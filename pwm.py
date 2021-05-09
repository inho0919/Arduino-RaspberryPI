import RPi.GPIO as GPIO
import time

# 밝기 제어
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(7, GPIO.OUT)
GPIO.setup(12, GPIO.OUT)

p = GPIO.PWM(7, 50)
q = GPIO.PWM(12, 0)

p.start(0)
q.start(0)

try:
	while 1:
		for dc in range(0, 101, 5):
			p.ChangeDutyCycle(dc)
			q.ChangeDutyCycle(dc)
			time.sleep(0.05)
		for dc in range(100, -1, 5):
			p.ChangeDutyCycle(dc)
			q.ChangeDutyCycle(dc)
			time.sleep(0.05)
except KeyBoardInterrupt:
	print("End")
	pass
p.stop()
q.stop()

GPIO.cleanup()


# 나노파이 - 아두이노간 시리얼 통신 UART통신  / 시리얼통신 할수있는 포트가 있는데 활성화시켜야됨
