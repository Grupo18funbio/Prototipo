//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
int lectura0;
int lectura1;
int lectura2;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(8,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear(); 
  lcd.setCursor (0,1);
  lcd.print("Iniciando");
}
void loop() {
  lectura0=analogRead(A0);
  lectura1=analogRead(A1);
  lectura2=analogRead(A2);
  
  if(lectura0 >= 1000){
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(lectura0);
    
  }
  if(lectura1 >= 1000){
    digitalWrite(8,HIGH);
   // lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Llenando aire");
  }
  if(lectura2 >=1000){
  lcd.setCursor(0,0);
  lcd.print("Elija una opcion");
  }
}
