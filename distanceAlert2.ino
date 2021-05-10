#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
/*
 * <Alert Machine>
 * 제작 - 
 * 상황용 - Serial Monitor
 * 현장용 - LCD Monitor
 * 
 */

int echo = 12;
int trig = 13;
int red = 5;
int yellow = 4;
int green = 3;
int blue = 2;

int arr[6] = {5,4,3,2,12,13};


String title = "Enemy Alert ";
char buf[12] = {0};

void setup()
{
  Serial.begin(115200);
  lcd.begin(16, 2);
  title.toCharArray(buf, 12);

  for (int i = 0; i < title.length(); i++)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(title);

    String temp;
    temp = title.substring(0, 1);
    title = title.substring(1, title.length());
    title = title + temp;

    if (i % 2 != 0)
    {
      lcd.setCursor(2, 1);
      lcd.print("*1778 TECH*");
    }
    delay(300);
    lcd.clear();
  }

  for(int i = 0; i<6; i++)
  {
    pinMode(arr[i], OUTPUT);  
  }
}

void loop()
{
  lcd.clear();
  unsigned long times = millis();
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((float)(340 * duration) / 10000) / 2;

  if (distance < 20)
  {
    if (distance >= 15)
    {
      lcd.setCursor(3, 0);
      lcd.print("DEFCON : 4");
      lcd.setCursor(0, 1);
      lcd.print("Enemy - ");
      lcd.print(distance);
      lcd.print("cm");

      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println("cm");
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    }
    else if (distance < 15 && distance >= 10)
    {
      lcd.setCursor(3, 0);
      lcd.print("DEFCON : 3");
      lcd.setCursor(0, 1);
      lcd.print("Enemy - ");
      lcd.print(distance);
      lcd.print("cm");

      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println("cm");
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);
    }
    else if (distance < 10 && distance >= 5)
    {
      lcd.setCursor(3, 0);
      lcd.print("DEFCON : 2");
      lcd.setCursor(0, 1);
      lcd.print("Enemy - ");
      lcd.print(distance);
      lcd.print("cm");

      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println("cm");
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }
    else if (distance < 5 && distance >= 0)
    {
      lcd.setCursor(3, 0);
      lcd.print("DEFCON : 1");
      lcd.setCursor(0, 1);
      lcd.print("Enemy - ");
      lcd.print(distance);
      lcd.print("cm");

      Serial.print("Distance : ");
      Serial.print(distance);
      Serial.println("cm");
      Serial.println("Alert! Alert! Emergency!!");
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }
    delay(3000);
  }
}
