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
    String value = Serial.readString();
    
    if (value == "OFF" || value == "Off" || value == "off")
    {
      for (int i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, i);
        analogWrite(10, i);
        delay(10);
      }
    }
    else if ( value == "ON" || value == "On" || value == "on" )
    {
      for (int i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, 255-i);
        analogWrite(10, 255-i);
        delay(10);
      }
    }
    else if (value == "Sputnik")
    {
      for (int i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, i);
        analogWrite(10, i);
        delay(10);
      }
      for (int i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, 255-i);
        analogWrite(10, 255-i);
        delay(10);
      }
    }
    else 
    {
      // None
    }


  }
}
