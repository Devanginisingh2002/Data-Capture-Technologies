#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(13, OUTPUT);
   pinMode(10, OUTPUT);
  Serial.begin(9600); 
  lcd.begin(16,2); 
  lcd.setCursor(0, 0);
  lcd.print(" Wear Masks");
delay(5000);
}

void loop() {
    //
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    
    distance= duration*0.034/2;
   
    Serial.print("Distance: ");
    Serial.println(distance);
    
    if(distance<20){  
   
    digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
       lcd.begin(16,2);
       lcd.setCursor(0, 0);
  lcd.print("      MAINTAIN");
   lcd.setCursor(0, 1);
  lcd.print("SOCIAL DISTANCE");

     delay(1000);}
    else
   {

  digitalWrite(13, LOW);
   digitalWrite(10, LOW);
   lcd.begin(16,2);
   lcd.setCursor(0, 1);
  lcd.print("SAFE  DISTANCE");
  
    }                 
}
