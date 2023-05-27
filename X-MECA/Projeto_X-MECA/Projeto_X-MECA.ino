#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//portas esp32
int botao_emergencia = 4;
int transistor_emergencia = 2;

//variaveis utilizadas
bool variavel_emergencia = 0;
bool mostrador = 0;
unsigned long time_lcd = 0;
float altura = 0;
float luz = 0;
float umidade = 0;
float volume = 0;
int estado_botao1;
int estado_botao2;

void setup() {
  lcd.init();
  Serial.begin(9600);

  pinMode(botao_emergencia, INPUT_PULLUP);
  pinMode(transistor_emergencia, OUTPUT);

}

void loop() {
  //avalia botao de destruicao

  estado_botao2 = estado_botao1;
  estado_botao1 = digitalRead(botao_emergencia);

  if(estado_botao1 != 1 && estado_botao1 != estado_botao2){
    variavel_emergencia = !variavel_emergencia;
  }

  //avalia caso de detruicao
  if(variavel_emergencia == 1){
    for(int i = 0; i < 50; i++){
      detonar();
    }
    variavel_emergencia = 0;
  }
  
  //avalia comunicacao serial
  if(Serial.available() > 0){
    altura = Serial.read();
    luz = Serial.read();
    umidade = Serial.read();
    volume = Serial.read();
  }

  //muda as informacoes do lcd
  if(millis() - time_lcd >= 10000){
    time_lcd = millis();
    mostrador = !mostrador;
  }
  else{
    mostrador == 0 ? tela1(altura, luz) : tela2(umidade, volume);
  }

}

void tela1(float altura, float luz){
  lcd.print("                 ");
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ALTURA: ");
  lcd.setCursor(8, 0);
  lcd.print(altura);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("LUZ: ");
  lcd.setCursor(5, 1);
  lcd.print(luz);
}

void tela2(float umidade, float volume){
  lcd.print("                 ");
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("UMIDADE: ");
  lcd.setCursor(9, 0);
  lcd.print(umidade);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("VOLUME: ");
  lcd.setCursor(8, 1);
  lcd.print(volume);
}

void detonar(){
  digitalWrite(transistor_emergencia, HIGH);
  delay(200);
  digitalWrite(transistor_emergencia, LOW);
  delay(200);
}
