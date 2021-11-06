#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
int lectura0;
int lectura1;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear(); 
  lcd.setCursor (0,1);
  lcd.print("Iniciando");
}
void loop() {
  lectura0=digitalRead(A0);
  lectura1=digitalRead(A1);
  if(lectura0 == 1 and lectura1 == 0){
    //lcd.clear();
    digitalWrite(2,LOW);
    digitalWrite(8,HIGH);
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Generando vibración");
  }
  if(lectura1 == 1 and lectura0 == 0){
    digitalWrite(8,LOW);
    digitalWrite(2,HIGH);
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Llenando aire");
  }
  if(lectura1 == 0 and lectura0 == 0){
  //lcd.clear()
  digitalWrite(2,LOW);
  digitalWrite(8,LOW);
  lcd.setCursor(0,0);
  lcd.print("Elija un modo y");
  lcd.setCursor(0,1);
  lcd.print("una intensidad");
  }
}
