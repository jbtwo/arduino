#include <Servo.h> 

Servo myservo;

int pos = 136;
const int EchoPin = 4;
const int TriggerPin = 6;
void setup(){
Serial.begin(9600);
myservo.attach(9);
pinMode(TriggerPin,OUTPUT);
pinMode(EchoPin, INPUT);
}
void loop() {
int cm = ping(TriggerPin, EchoPin);
Serial.print("Distance: ");
Serial.println(cm);
delay(1000);
}

int ping(int TriggerPin, int EchoPin) {
long duration, distanceCm;
digitalWrite(TriggerPin, LOW);
delayMicroseconds(4);
digitalWrite(TriggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(TriggerPin, LOW);
duration = pulseIn(EchoPin, HIGH);
distanceCm = duration * 10 / 292/ 2;
if (distanceCm <= 90 && distanceCm >= 30) {
for (pos = 136; pos >= 27; pos -= 1) {

myservo.write(pos);             
delay(1);                      
}
delay(2000);
for (pos = 27; pos <= 136; pos += 1) {
myservo.write(pos);
delay(1);
} }
return distanceCm;
}
