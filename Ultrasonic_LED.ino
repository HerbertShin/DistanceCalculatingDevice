/* 
Hardware Setup 
Ultrasonic sensor echo pin is connected to pin 9 (TRIG) and 10 (ECHO)
Button is connected to pin 2
LCD RS(pin 12), E(pin 8), D4(pin 6), D5(pin 3), D6(pin 5), D7(pin 4)
Red LED (pin 7)
White LED (pin 11)
Button (pin 2)
*/

#include <LiquidCrystal.h>

int led1 = 7;
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
lcd.begin(16,2); //Sets columns and rows 
lcd.print("Device Ready"); //Prints this message on startup 
pinMode(button,INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
}
 
void loop(){
lcd.display();
UltraSonic_Sensor();
buttonState = digitalRead(button); 
if (buttonState== HIGH){ //When button is pushed, the device will operate 
if (distance < 1000){ //If the sensor detects an object within those units of bytes calculated the following code will run 
  digitalWrite(led1, HIGH); //Appropriate distance needed for measurements can be changed in the if (conditions) loop
  lcd.println(distance); //Prints the distance on the LCD screen 
}
else{
  digitalWrite(led1,LOW);
  Avoid(); //When an object is not detected it runs the Avoid() method 
}
}
else{ //Shuts off components when not in use 
 OFF();
}
} //End of nested loop 

//Blinks the white LED when an object is not detected 
int Avoid(){
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led2, LOW);
  delay(200);
}

//Method for all ultrasonic code
void UltraSonic_Sensor(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2; //Calculates the distance one way 
}

//Method to shutoff led and sensor when the button is not pushed 
void OFF(){
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
}
