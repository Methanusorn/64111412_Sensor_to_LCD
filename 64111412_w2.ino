#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp;
float humid;
DHT dht14(D4, DHT11);

void setup() {
  lcd.begin();
  lcd.setCursor(0,0);
  temp = 0;
  humid = 0;
  Serial.begin(9600);
  dht14.begin();
}

void loop() {
  lcd.clear();
  humid = dht14.readHumidity();
  temp = dht14.readTemperature();
  lcd.print("Humi: ");
  lcd.print(humid);
  lcd.print(" %");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  delay(1000);
}



