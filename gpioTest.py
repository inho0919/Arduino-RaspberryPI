import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led, GPIO.OUT)


while 1:
    level = int(input())

    if(level == 1):
        GPIO.output(led, 0)
        time.sleep(0.1)
        GPIO.output(led, 1)
        time.sleep(0.03)

        GPIO.output(led, 0)
        time.sleep(0.01)
        GPIO.output(led, 1)
        time.sleep(0.06)

        GPIO.output(led, 0)
        time.sleep(0.01)

        GPIO.output(led, 1)
        time.sleep(0.08)

        while 1:
            GPIO.output(led, 0)
            time.sleep(0.001)
            GPIO.output(led, 1)
            time.sleep(0.01)

#    elif(level == 2):
#        while 1:
#            GPIO.output(led, 0)
#            time.sleep(1)
#            GPIO.output(led, 1)
#            time.sleep(1)

# 7번 - 청빛
# 12번 - 적빛

# -------주석-------
# 청빛,  적빛 둘중 하나만
# 빛 입력값은 2개 ( 입력1 : 청빛, 적빛 선택(아무것도 선택 x, 청만 선택, 적만 선택, 둘다선택) / 입력2 : 광도조정)
# 1. 광도는 5단계 (매우낮음, 낮음, 보통, 밝음, 매우밝음)
# 2. 청 적 둘다선택시 각각 광도 물어봄
# 3. 모드 제작 (Kreuzung, Glatt Kreuzung, Glatt Welle, Alles Immer)
# 4. 최종항목 1) 청빛 2) 적빛 3) 둘다 4) 모드
#   -1,2,3) 청빛 광도 input
#   -4) 모드 : 4개중 선택 다시
# 5. 회귀 <= 중요
# 
# 연구노트
#--------------------
