#include<OneWire.h>
#include<DallasTemperature.h>
#include<LiquidCrystal_I2C.h>

OneWire oneWire(8);
DallasTemperature sensor(&oneWire);
LiquidCrystal_I2C lcd(0x27,16,2);

int RED = 3;
int GREEN = 4;
int BUZZER = 5;
int FAN = 6;
int BUTTON = 7;
bool isAlarm = 0;
bool isRed = 0;
unsigned long lastFlashTime = 0;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(FAN,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(BUTTON,INPUT);

  Serial.begin(9600);
  sensor.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("The init is OK!");
  delay(1000);
  lcd.clear();

  
}

void loop(){
  sensor.requestTemperatures();
  float temp = sensor.getTempCByIndex(0);
  Serial.print("temp:");
  Serial.print(temp);
  Serial.print("C\n");
  lcd.setCursor(0,0);
  lcd.print("temp:");
  lcd.print(temp);
  lcd.print("C\n");

  if(digitalRead(BUTTON) == LOW){
    isAlarm = 0;
    delay(200);
  }

  if(temp > 30){
    isAlarm = 1;
  }

  if(isAlarm == 1){
    lcd.setCursor(0,1);
    lcd.print("Alarm!");
    digitalWrite(GREEN,LOW);
    digitalWrite(BUZZER,HIGH);
    digitalWrite(FAN,HIGH);
    if(millis() - lastFlashTime >= 500){
      lastFlashTime = millis();
      isRed =! isRed;
      digitalWrite(RED,isRed);
    }
  }
  else{
    lcd.setCursor(0,1);
    lcd.print("Normal~");
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BUZZER,LOW);
    digitalWrite(FAN,LOW);
  }
  delay(50);  
}


