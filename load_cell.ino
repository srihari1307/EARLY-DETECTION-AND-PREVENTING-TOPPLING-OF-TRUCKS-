#include "HX711.h"  //You must have this library in your arduino library folder
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#define DOUT  4
#define CLK  5
HX711 scale(DOUT, CLK);
float calibration_factor = 2230; // this calibration factor is adjusted according to my load cell
float units;
void setup() {
 lcd.begin(16,2);
 Serial.begin(9600);  
 Serial.println("Press T to tare");
scale.set_scale(calibration_factor); //Adjust to this calibration factor
 scale.tare(); 
}
void loop() {
units = scale.get_units(), 5;
 if (units < 0)
 {
   units = 0.00;
 }
 lcd.setCursor(0,0);
 lcd.print("Weight: ");
 lcd.setCursor(8,0);
 lcd.print(units,5); //displays the weight in 4 decimal places only for calibration
 lcd.setCursor(14,0);
 lcd.print("grams");
 if(Serial.available())
 {
   char temp = Serial.read();
   if(temp == 't' || temp == 'T')
     scale.tare();  //Reset the scale to zero      
 }
} 
