void loop() {
  String data = Serial.readStringUntil("\n");
  Serial.println(data);
  delay(1000);
}

int red = Serial.readInt();
int green = Serial.readInt();

void setup() {
  // put your setup code here, to run once:
  Serial.berin(115200);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(red, HIGH);
	digitalWrite(green, LOW);
	delay(2000);
	digitalWrite(red, LOW);
	digitalWrite(green, HIGH);
	delay(2000);
}
