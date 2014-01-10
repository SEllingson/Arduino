#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 7 
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  lcd.begin(16, 2);
  dht.begin();
}

void loop() 
{ 
  int h = dht.readHumidity();
  int t = (1.80 * dht.readTemperature() + 32.00);

  if (isnan(t) || isnan(h)) 
    {
      lcd.print("Failed to read from DHT");
    } 
  else 
    {
      lcd.setCursor(0, 0);
      lcd.print("Temp:"); 
      lcd.print(t);
      lcd.print((char)223);
      lcd.print((char)70);
      lcd.print(" RH:"); 
      lcd.print(h);
      lcd.print("%");
    }
}
