int trigPin = 12;
int echoPin = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin,HIGH);
  delay(100);
  digitalWrite(trigPin,LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = ((float)(340*duration)/ 10000) / 2;

  Serial.print("Duration : ");
  Serial.print(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println("cm\n");
  delay(500);
}
