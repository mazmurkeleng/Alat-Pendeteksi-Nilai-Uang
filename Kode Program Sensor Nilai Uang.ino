#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

 
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  

  lcd.init();
  lcd.backlight();
  lcd.print(" Selamat Datang ");
  lcd.setCursor(0, 1);
  lcd.print(" Di Sensor Uang  ");
  delay(5000);
  lcd.clear();
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
    
void loop() 
{  
   lcd.setCursor(0, 0);
  lcd.print("   Nilai Uang   ");//printing name 

  color(); 
  
 
  if (red < blue && red < green && red < 12)
  {  
   Serial.println(" - (Red Color)");
    lcd.setCursor(0, 1);  
   lcd.print("  Rp. 100.000   ");
   delay(1000);
   
  }  
 
  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)"); 
   lcd.setCursor(0, 1);
   lcd.print("   Rp. 50.000    ") ;
   delay(500);
   
  }  
 

  else{
  
  lcd.setCursor(0, 1); 
  lcd.print("Tidak Terdeteksi"); 
  delay (1000); 
  }   
 
    
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
