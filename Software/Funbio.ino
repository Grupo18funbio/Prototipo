#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
int bot1;
int bot2;
int bot3;
int modo=0;
int val=0;
void setup() {
  Serial.begin(9600);
  pinMode(A3,INPUT);
  //pinMode(A0,INPUT);
  //pinMode(A1,INPUT);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear(); 
  lcd.setCursor (0,1);
  lcd.print("Iniciando");
}
void loop() {
  val=map(analogRead(A3),0,1023,0,255);
  delay(10);
  bot1=digitalRead(7);
  bot2=digitalRead(8);
  bot3=digitalRead(4);
  if (digitalRead(bot1)==0 && modo!=1){
    modo=1;
    delay(500);
  }
  if (digitalRead(bot2)==0 && modo!=2){
    modo=2;
    delay(500);
  }
  if(modo == 2){
    //lcd.clear();
    digitalWrite(3,LOW);
    analogWrite(5,val);
    analogWrite(6,val);
    analogWrite(9,val);
    analogWrite(10,val);
    analogWrite(11,val);
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Generando         ");
    lcd.setCursor(0,1);
    lcd.print("vibracion         ");
  }
  if(modo==1){
    analogWrite(3,val);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Llenando aire    ");
    lcd.setCursor(0,1);
    lcd.print("                              ");
  }
  if(modo==0){
  //lcd.clear()
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  lcd.setCursor(0,0);
  lcd.print("Elija un modo y    ");
  lcd.setCursor(0,1);
  lcd.print("una intensidad    ");
  }
}
