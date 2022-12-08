#include <LiquidCrystal_I2C.h>
#define sda 4
#define scl 5
#define ledg 1
#define ledr 2
String codigo;
// set the LCD number of columns and rows
int ColunaLCD = 16;
int LinhaLCD = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, ColunaLCD, LinhaLCD);
// Function to scroll text
// The function acepts the following arguments:
// row: row number where the text will be displayed
// message: message to scroll
// delayTime: delay between each character shifting
// lcdColumns: number of columns of your LCD
void setup(){
  // initialize LCD
  Serial.begin(115200);
  Wire.begin(sda, scl);
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  pinMode(1,OUTPUT);
  pinMode(2, OUTPUT);

  Serial.println("Digite a senha que você quer de salvar: ");
  while (Serial.available() == 0) {}
  codigo = Serial.readString();
  Serial.print("O codigo é: " + codigo);
  //lcd.print(codigo);
}
void loop(){

  Serial.println("Digite a senha:");
  while (Serial.available() == 0) {}
  String codigo_correto = Serial.readString();  //read until timeout
  // senha_correta.trim();                        // remove any \r \n whitespace at the end of the String
  Serial.println("A senha digitada foi: " + codigo_correto);
  if (codigo_correto == codigo) {
    Serial.println("Senha correta");
    lcd.setCursor(0, 0);
    lcd.print("Senha Correta!!!");

    delay(3000);
    digitalWrite(1, HIGH);
    delay(1000);
    digitalWrite(1, LOW);
    delay(3000);
    lcd.clear();
  }
  else {
    Serial.println("Senha incorreta");
    lcd.setCursor(0, 0);
    lcd.print("Incorreta :( ");
   
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(3000);
    delay(3000);
    lcd.clear();
  }
}