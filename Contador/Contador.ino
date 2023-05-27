int A = 9, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, P = 8, botao = 13;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(P, OUTPUT);
  pinMode(botao, INPUT);
  
  Serial.begin(9600);
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

int contador() {

  int valor1, valor2, numero = 0, x;
  
  for (x = 0; numero <= 9 ; x++){
    
    int valorbotao = digitalRead(botao);
    
    valor2 = valor1;
    valor1 = valorbotao;

    if (valor1 != 1 && valor1 != valor2){
      numero += 1;
    }
  
    switch(numero){
      case(0): 
        zero();
        break;
      case(1):
        um();
        break;
      case(2):
        dois();
        break;
      case(3):
        tres();
        break;
      case(4):
        quatro();
        break;
      case(5):
        cinco();
        break;
      case(6):
        seis();
        break;
      case(7):
        sete();
        break;
      case(8):
        oito();
        break;
      case(9):
        nove();
        break;
    }
  }
  
}

void loop(){

  contador();
  
}
