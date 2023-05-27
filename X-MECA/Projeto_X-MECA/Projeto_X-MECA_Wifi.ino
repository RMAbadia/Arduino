#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
WiFiClient espClient;
PubSubClient client(espClient);

//declara função
void setupWifi();
void reconnect();
void callback(char* topic, byte* payload, unsigned int length);

//Conexão ao Wifi
const char* ssid = ""; //nome da rede wifi
const char* pass = ""; //senha da rede wifi

//Conectando ao Server Broker
const char* server = "MQTT"; //endereço do servidor
const int port = 1883; //porta do mqtt

//portas esp32
int botao_emergencia = 4;
int transistor_emergencia = 2;

//variaveis wifi
unsigned long lastMsg = 0;
char messages[50];
int value = 0;

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
  //serial
  Serial.begin(9600);

  //lcd
  lcd.init();

  //pinagem
  pinMode(botao_emergencia, INPUT_PULLUP);
  pinMode(transistor_emergencia, OUTPUT);

  //wifi
  setupWifi();
  client.setServer(server,port); //nome do server e porta
  client.setCallback(callback);
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

  //wifi
  if (!client.connected()){
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now-lastMsg>5000){
    lastMsg = now;

    char tempString[8];
    dtostrf(altura, 1, 2, tempString);
    Serial.print("Altura: ");
    Serial.println(tempString);
    client.publish("Altura", tempString);

    //Recebimento da Umidade

    //Envio da umidade
   
    char umiString[8];
    dtostrf(umidade, 1, 2, umiString);
    Serial.print("Umidade: ");
    Serial.println(umiString);
    client.publish("Umidade", umiString);

    //Recebimento de Luz

    //Envio de Luz
    char luzString[8];
    dtostrf(luz, 1, 2, luzString);
    Serial.print("Luz: ");
    Serial.println(luzString);
    client.publish("Luz", luzString);

    ////Recebimento de Água

    //Envio de Água
    char aguaString[8];
    dtostrf(volume, 1, 2, aguaString);
    Serial.print("Nível de Água: ");
    Serial.println(aguaString);
    client.publish("Nível de Água", aguaString);

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

void setupWifi(){
  delay(10);
  Serial.println("\nConnecting to");
  Serial.println(ssid);
  
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
  Serial.print("\nWiFi conectado em");
  Serial.println(ssid);
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect(){
  while(!client.connected()){
    Serial.print("\nConectando em");
    Serial.println(server);
    if(client.connect("ESP32-CLIENT")){
      Serial.print("\nConectado em");
      Serial.println(server);
      client.subscribe("engeasier/publisher"); //pode mudar dependendo do server
      }
    else{
      Serial.println("\nFalha ao se conectar!");
      Serial.print(client.state());
      Serial.println("Tente novamente em 5 segundos");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Recebendo mensagens: ");
  Serial.println(topic);
  Serial.print(". Mensagem: ");
  String messageTemp;
  for(int i=0; i<length; i++){
    Serial.print((char) payload[i]);
    messageTemp += (char)payload[i];
  }
  Serial.println();
}