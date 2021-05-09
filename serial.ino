void setup() 
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  
}

void loop() 
{
  Serial.println("Yes");

  digitalWrite(2, HIGH);
 
}
