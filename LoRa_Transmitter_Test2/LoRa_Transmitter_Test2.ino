//TIVA123 + LoRa E32TTL100 433 MHz

#define PB7 15 //M0
#define PB6 14 //M1
int i = 0;
void setup() {

  pinMode(PB7, OUTPUT);
  pinMode(PB6, OUTPUT);
  digitalWrite(PB7, LOW);
  digitalWrite(PB6, LOW);
  Serial.begin(9600);
  Serial7.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  Serial7.println(i);
  i++;
  delay(1000);
}
