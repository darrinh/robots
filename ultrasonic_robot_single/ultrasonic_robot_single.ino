#include <NewPing.h>

//Define ON and OFF
#define ON HIGH
#define OFF LOW

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



//Variable to hold returned sensor value
int sensorValue = 0; 


//Mapping motor functions to Arduio pins
const int LMR = 3; //IB1
const int LMF = 5;  //IA1
const int RMR = 7; //IA2
const int RMF = 9; //IB2
const int HS = 255;
const int LS = 120;
const int DIS = 10;


//Setup function
void setup() {
    //Set motor control pins as output
    pinMode(LMR,OUTPUT);
    pinMode(RMR,OUTPUT);
    pinMode(LMF,OUTPUT);
    pinMode(RMF,OUTPUT);
  
    //Ensure motor reverse is turned off.
    digitalWrite(LMR,OFF);
    digitalWrite(RMR,OFF);
    digitalWrite(LMF,OFF);
    digitalWrite(RMF,OFF);
    Serial.begin(9600);

}
//Main program loop
void loop() {
    //Read sensor value
    sensorValue = sonar.ping_cm();
   
   analogWrite(LMF,HS);
   analogWrite(RMF,HS);

   if(sensorValue <= DIS && sensorValue > 0) {
      
      
  
     digitalWrite(LMF,OFF);
     digitalWrite(RMF,OFF);
      
     delay(400);
     
     analogWrite(LMR,HS);
     analogWrite(RMR,HS);
     
     delay(400);
   
     analogWrite(LMR,OFF);
     analogWrite(RMR,OFF);
       
     
    
     do {
      
       analogWrite(LMF,HS);
       analogWrite(RMR,HS);
      delay(300);
        sensorValue = sonar.ping_cm();  
      
     } while(sensorValue <= DIS && sensorValue > 0);
  
    
    
     digitalWrite(LMF,OFF);
     digitalWrite(RMR,OFF);
      }

}

