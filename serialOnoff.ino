void setup() 
{
  Serial.begin(115200);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

int i = 1;

void loop() 
{
  while (Serial.available() > 0)
  {
    String value = Serial.readString();
    
    if (value == "OFF" || value == "Off" || value == "off")
    {
      for (i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, i);
        analogWrite(10, i);
        delay(10);
      }
    }
    else if ( value == "ON" || value == "On" || value == "on" )
    {
      for (i = 255; i > 0; i = i - 1)
      {
        analogWrite(9, i);
        analogWrite(10, i);
        delay(10);
      }
    }
    else if (value == "Sputnik")
    {
      for (i = 1; i <= 255; i = i + 1)
      {
        analogWrite(9, i);
        analogWrite(10, i);
        delay(10);
      }
      for (i = 1; i <= 255; i = i + 1)
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
