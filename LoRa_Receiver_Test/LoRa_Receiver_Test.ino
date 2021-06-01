//TIVA123 + LoRa E32TTL100 433 MHz

#define PB7 15 //M0
#define PB6 14 //M1

char msg = ' ';

void setup() {
  // put your setup code here, to run once:
  pinMode(PB7, OUTPUT);
  pinMode(PB6, OUTPUT);
  digitalWrite(PB7, LOW);
  digitalWrite(PB6, LOW);
  Serial.begin(9600);
  Serial7.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Serial7.available()){
    msg = Serial7.read();
    Serial.print(msg);
  }
}
