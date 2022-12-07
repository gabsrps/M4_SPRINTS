#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32s3gabs";      // Enter SSID here
const char* password = "senha1dois3";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(177, 32, 196, 34);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

int led1 = 1;
bool LED1status = LOW;

int led2 = 2;
bool LED2status = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", gameInit);
  server.on("/player1", player1Win);
  server.on("/player2", player2Win);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if (LED1status) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  if (LED2status) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}


void player1Win() {
  LED1status = HIGH;
  Serial.println("O JOGADOR 'X' GANHOU!");
  server.send(200, "text/html");
}

void player2Win() {
  LED2status = HIGH;
  Serial.println("O JOGADOR 'O' GANHOU!");
  server.send(200, "text/html");
}