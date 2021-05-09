String readString;

void setup()
{
  Serial.begin(115200); // initialization
}

void loop()
{
  char incomingByte;
  while (Serial.available() > 0)
  {
    incomingByte = Serial.read(); // read byte
    readString += incomingByte;
  }

  int first = readString.indexOf("\n");

  String arr[2];

  arr[0] = readString.substring(0, first);
  arr[1] = readString.substring(first + 1, readString.length());

  if (arr[1] != "")
  {
    arr[0] = arr[1];
    readString = arr[0];
  }
  else
  {
    if (readString != "")
    {
      Serial.print("arduino recived this : ");
      Serial.println(arr[0]);
    }
  }
}
