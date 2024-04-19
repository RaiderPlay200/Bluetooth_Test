#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial hc06(1,0);
String message="";

void setup(){
Serial.begin(9600);
lcd.init();
lcd.backlight();
//Initialize Serial Monitor
//Initialize Bluetooth Serial Port
hc06.begin(9600);
}

void loop(){
lcd.setCursor(0, 0);
//Write data from HC06 to Serial Monitor
if (hc06.available()){
message+=char(hc06.read());
Serial.print(message);
lcd.clear();
lcd.print(message); //Display the message in the LCD display}
}
else message="";
}