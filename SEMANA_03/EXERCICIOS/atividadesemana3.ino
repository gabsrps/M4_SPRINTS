#define LED0 18
#define LED1 8
#define LED2 3
#define LED3 46
#define LDR 4
#define BUZZER 17
#define ESCOLHER 1
#define TOCAR 2
int anterior = 0;
int notaAtual = 0;
double notas[15] = {132, 148.1, 166.32, 176.22,
                    197.74, 222.02, 249.22, 264,
                    296.2, 332.6, 352.4, 395.5,
                    444, 498.4, 528};
int escolhidas[50] = {};
int ultima = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ESCOLHER, INPUT_PULLUP);
  pinMode(TOCAR, INPUT_PULLUP);
}
void sequencia(int numero) {// codifica acendimento dos leds e faz o buzzer tocar nas mudanças de luminosidade.
  digitalWrite(LED0, numero & 0b0001);
  digitalWrite(LED1, numero & 0b0010);
  digitalWrite(LED2, numero & 0b0100);
  digitalWrite(LED3, numero & 0b1000);
  tone(BUZZER, notas[numero], 500);
  notaAtual = notas[numero];
   Serial.println("Nota Atual: ");
   Serial.println(notaAtual);
  delay(500);
}
void loop() {
  int leitura = analogRead(LDR);
  int escala = map(leitura, 32, 4063, 0, 15);
  Serial.println(escala);
  if (anterior != escala){ //aterior é variável.
    // Serial.println(escala);
    sequencia(escala);
    anterior = escala;
  }
  if (digitalRead(ESCOLHER) == LOW) {//salva algumas notas.
    escolhidas[ultima] = notaAtual;
    ultima++;
    Serial.println("escolhida: ");
    Serial.println(escolhidas[ultima]);
  }
  if (digitalRead(TOCAR) == LOW) {//toca as notas anteriormente salvas. cada nota toca por 1 décimo de segundo.
    for (int i =0; i <= ultima; i++){
      tone(BUZZER, escolhidas[i], 100);
      Serial.println("tocar :");
      Serial.println(escolhidas[i]);
    }
  }
  delay(100);
}