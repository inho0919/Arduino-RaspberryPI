void setup() 
{
  Serial.begin(115200);
}
char stx = char(0x02); //STX -> 0x02
char etx = char(0x03); //ETX -> 0x03
char parse1 = '#';

void loop() 
{
  String text = Serial.readStringUntil(etx); //ETX까지 문자 읽어들임

  String arr[5];

  int first = text.indexOf(parse1);
  int second = text.indexOf(parse1, first + 1);
  int third = text.indexOf(parse1, second + 1);
  int fourth = text.indexOf(parse1, third + 1);

  int len = text.length();

  int arr_int[4];

  arr_int[0] = first;
  arr_int[1] = second;
  arr_int[2] = third;
  arr_int[3] = fourth;

  arr[0] = text.substring(0, first);
  arr[1] = text.substring(first+1, second);
  arr[2] = text.substring(second+1, third);
  arr[3] = text.substring(third+1, fourth);
  arr[4] = text.substring(fourth+1, len);

  int count = 0;
  for(int i = 1; i<5; i++)
  {
    if(arr[i] == "0000000000")
    {
      count = i;
      break;
    }
    count++;
  }

  for (int i = 1; i<5; i++)
  {
    if(count < i)
    {
      arr[i]= "";
    }
  }
  
  Serial.println("---------------------");
  Serial.println(arr[0]);
  Serial.println(arr[1]);
  Serial.println(arr[2]);
  Serial.println(arr[3]);
  Serial.println(arr[4]);
  Serial.println("---------------------");

  
/*
  for (int i = 0; i < 5; i++)
  {
    arr[i + 1] = text.substring(arr_int[i] + 1, arr_int[i + 1]);
  }

  arr[4] = text.substring(arr_int[3] + 1, len);
  */
}
