
void setup()
{
  Serial.begin(115200);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  while (Serial.available() > 0)
  {
    long value1 = Serial.parseInt();
    long value2 = Serial.parseInt();
    if ( value1 >= 100)
    {
      Serial.println("Kreuzung Lichtmodus");
      Serial.println(value1);
      Serial.println(value2);
      Serial.println("Ende");
      while(1)
      {
        for (int i = 1; i <= 255; i = i + 1)
        {
          analogWrite(9, i);
          analogWrite(10, 255 - i);
          delay(10);
        }
        for (int i = 1; i <= 255; i = i + 1)
        {
          analogWrite(9, 255 - i);
          analogWrite(10, i);
          delay(10);
        }
      }
      
    }
    else
    {
      Serial.println("Alles Lichtmodus");
      Serial.println(value1);
      Serial.println(value2);
      Serial.println("Ende");
      while(1)
      {
        for (int i = 1; i <= 255; i = i + 1)
        {
          analogWrite(9, i);
          analogWrite(10, i);
          delay(10);
        }
        for (int i = 1; i <= 255; i = i + 1)
        {
          analogWrite(9, 255 - i);
          analogWrite(10, 255 - i);
          delay(10);
        }
      }
    }
  }
}
