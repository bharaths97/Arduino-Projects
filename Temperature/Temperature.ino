#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); 
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius 
float vout;  //temporary variable to hold sensor reading
float tempf;//variable to store temperature in Fahreinheit 
void setup()
{
  pinMode(sensor,INPUT); // Configuring pin A1 as input
  Serial.begin(9600);
  lcd.begin(16,2);  
  delay(500);
}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
lcd.setCursor(0,0);
lcd.print("Room Temperature");
lcd.setCursor(0,1);
lcd.print(tempc);
lcd.print(" C");
delay(5000);
lcd.setCursor(0,1);
lcd.print(tempf);
lcd.print(" F");
delay(5000); //Delay of 5 second for ease of viewing in serial monitor
}

