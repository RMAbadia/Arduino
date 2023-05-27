int portaumidade = A0;
int rele = 7;
int time = 0;

void setup() {
  pinMode(portaumidade, INPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int umidade = analogRead(portaumidade);
  if(millis() - time > 1000){ 
    Serial.print("Umidade: ");
    Serial.println(umidade);

    if(umidade < 800){
      digitalWrite(rele, LOW);
    }
    else{
      digitalWrite(rele, HIGH);
    }

    time = millis();
  }
  
  
}
