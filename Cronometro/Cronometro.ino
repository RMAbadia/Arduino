int A = 9, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, P = 8;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(P, OUTPUT);
  
}

int apaga(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(P, LOW);
}

int zero(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
}

int um(){
  apaga();
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);  
}

int dois(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
}

int tres(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

int quatro(){
  apaga();
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
}

int cinco(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

int seis(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
}

int sete(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

int oito(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

int nove(){
  apaga();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

int contagem(){
  zero();
  delay(1000);
  apaga();

  um();
  delay(1000);
  apaga();

  dois();
  delay(1000);
  apaga();

  tres();
  delay(1000);
  apaga();

  quatro();
  delay(1000);
  apaga();

  cinco();
  delay(1000);
  apaga();

  seis();
  delay(1000);
  apaga();

  sete();
  delay(1000);
  apaga();

  oito();
  delay(1000);
  apaga();

  nove();
  delay(1000);
  apaga();

}

void loop(){

  contagem();
  
}
