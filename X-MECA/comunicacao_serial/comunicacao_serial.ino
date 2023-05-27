void setup() {
  Serial.begin(9600);
}

void loop() {
  int altura = 70;
  int luz = 60;
  int umidade = 50;
  int nivel = 40;

  while(nivel--){
    Serial.write(altura);
    Serial.write(luz);
    Serial.write(umidade);
    Serial.write(nivel);
    altura--;
    luz--;
    umidade--;
    delay(1000);
  }
  
}
