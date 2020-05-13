#include <LiquidCrystal.h>
int led = 7;
int led2 = 11;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
const int button = 2;
int buttonState = 0;
const int rs = 12, en = 8, d4 = 6, d5 = 3, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6,d7);

void setup(){
Serial.begin(9600);
lcd.begin(16,2);
lcd.print("STANDBY...");
pinMode(button,INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
}
 
void loop(){
lcd.display();
UltraSonic_Sensor();
buttonState = digitalRead(button);
if (buttonState== HIGH){
if (distance < 1000){
  digitalWrite(led, HIGH);
  lcd.println(distance);
}
else{
  digitalWrite(led,LOW);
  Avoid();
}
}
else{
 OFF();
}
}// end loop() 

int Avoid(){
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led2, LOW);
}

void UltraSonic_Sensor(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;
}

void OFF(){
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
}
