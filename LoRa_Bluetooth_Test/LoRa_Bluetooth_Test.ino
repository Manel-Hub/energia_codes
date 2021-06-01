//TIVA1294 + LoRa E32TTL100 433 MHz + Bluetooth HC05

#define PL0 34 //M0
#define PL1 33 //M1

char msg = ' ';
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PL0, OUTPUT);
  pinMode(PL1, OUTPUT);
  digitalWrite(PL0, LOW);
  digitalWrite(PL1, LOW);
  Serial7.begin(9600);
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  /*if(Serial7.available()){
    msg = Serial7.read();
    //Serial.print(msg);
    Serial2.print(msg);
  }*/
  Serial7.println(i);
  Serial2.println(i);
  delay(5000);
  i++; 
}
