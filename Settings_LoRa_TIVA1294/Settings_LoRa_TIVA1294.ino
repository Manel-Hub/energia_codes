#define PE0 23 //M0
#define PE1 24 //M1

#define lora_reset 1
#define lora_read_par 2
#define lora_set_par 3

//AQUI SE ESCOLHE O TIPO DE INSTRUCAO
int opt = lora_read_par;
char parametros;

//--Parameters settings--
#define HEAD_SAVE 0xC0
#define HEAD_NOT_SAVE 0xC2
#define ADDH 0x00 // Por default e 00H
#define ADDL 0x00 // Por default e 00H
#define SPED 0x1A // Aqui se determina a paridade, taxa da uart e taxa de transmissao no ar - Sem paridade, 9600 e 0,3kbps
#define CHAN 0x17 // Frequencia do Canal
#define OPTION 0x44 // Configura alguns detalhes - ver manual

void setup() {

  pinMode(PE0, OUTPUT);
  pinMode(PE1, OUTPUT);
  digitalWrite(PE0, HIGH);
  digitalWrite(PE1, HIGH);
  Serial.begin(9600);
  Serial7.begin(9600);
}

void loop() {

  switch (opt) {
    case lora_reset:
      parameters_reset();
      break;
    case lora_read_par:
      parameters_read_config();
      break;
    case lora_set_par:
      parameters_settings_save();
      break;
  }
  delay(1000);
  // put your main code here, to run repeatedly:
}

void parameters_reset() {
  uint8_t CMD[3] = {0xC4, 0xC4, 0xC4};
  Serial7.write(CMD, 3);
  delay(5000);
}

void parameters_read_config() {
  uint8_t CMD[3] = {0xC1, 0xC1, 0xC1};
  Serial7.write(CMD, 3);
  delay(50);
  while (Serial7.available()) {
    parametros = Serial7.read();
    Serial.print(parametros, HEX);
  }
  delay(5000);
  Serial.println();
}

void parameters_settings_save() {
  uint8_t COM[6] = {HEAD_SAVE, ADDH, ADDL, SPED, CHAN, OPTION};
  Serial7.write(COM, 6);
  delay(50);
  for (int i = 0; i < 6; i++) {
    Serial.print(COM[i], HEX);
  }
  delay(1000);
  Serial.println();
}
