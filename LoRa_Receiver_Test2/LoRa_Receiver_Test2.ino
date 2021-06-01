//TIVA1294 (Placa Mestrado) + LoRa E32TTL100 433 MHz

#define PL0 34 //M0
#define PL1 33 //M1

char msg = ' ';

void setup() {
  // put your setup code here, to run once:
  pinMode(PL0, OUTPUT);
  pinMode(PL1, OUTPUT);
  digitalWrite(PL0, LOW);
  digitalWrite(PL1, LOW);
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
