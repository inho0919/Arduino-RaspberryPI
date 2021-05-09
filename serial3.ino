void setup()
{
  Serial.begin(115200);
}
 
void loop()
{   
  String input;
  input = Serial.readString();
  
  if(input != "close" )
  {
    Serial.println(input);    
  }
}
