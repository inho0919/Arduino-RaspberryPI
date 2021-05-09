int speakerpin = 12; //스피커가 연결된 디지털핀 설정
int note[] = {262,294,330,349,392,440,494,523}; //도레미파솔라시도
 
void setup() {
  int elementCount = sizeof(note) / sizeof(int);
  for (int i=0; i < elementCount; i++)    //note를 play
  {
    tone(speakerpin,note[i],500);
    delay(100);
  }
}
 
void loop() {
}
