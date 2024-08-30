#include<Servo.h>
#define sensorPin 10
#define RELAY_PIN 9

Servo myservo,myservo1,myservo2;
int pos = 0;
int pos1 = 0;
int pos2 = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(7);
  myservo1.attach(6);
  myservo2.attach(11);
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}


void loop() {
   // Read the Analog Input
   // 625 IS AIR = 0%
   // 280-290 = WATER = 100%
  
   
    int value = analogRead(sensorPin);
  
  // Print the value to the serial monitor
  Serial.println("Analog output: ");
  Serial.println(value);
  
  // Wait for 1 second before the next reading
  delay(3000);
for(pos1 = 45; pos1 >= 0; pos1 -= 1)
   {
     myservo1.write(pos1);
     delay(500);
   }
  if(value > 650){
   for(pos = 0; pos <= 45; pos += 1)
   {
      myservo.write(pos);
      delay(90);
   }
   for(pos = 45; pos >= 0; pos -= 1)
   {
      myservo.write(pos);
      delay(45);
   }


    Serial.println("The soil moisture is DRY => activate pump");
    digitalWrite(RELAY_PIN, HIGH);
    //delay(2000);
  }else{
    Serial.println("The soil moisture is WET => deactivate the pump");
    digitalWrite(RELAY_PIN, LOW);
    delay(2000);
  }
    for(pos2 = 0; pos2 <= 90; pos2 += 1)
   {
     myservo2.write(pos2);
     delay(1000);
   }
   for(pos2 = 90; pos2 >= 0; pos2 -= 1)
   {
     myservo2.write(pos2);
     delay(1000);
   }

  delay(1000);
}