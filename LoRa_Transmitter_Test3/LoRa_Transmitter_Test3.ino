//TIVA1294 (Placa TCC) + LoRa E32TTL100 433 MHz

#define PE3 26 //M0
#define PD7 27 //M1
int i = 0;
void setup() {

  pinMode(PE3, OUTPUT);
  pinMode(PD7, OUTPUT);
  digitalWrite(PE3, LOW);
  digitalWrite(PD7, LOW);
  Serial.begin(9600);
  Serial7.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  Serial7.println(i);
  i++;
  delay(5000);
}
