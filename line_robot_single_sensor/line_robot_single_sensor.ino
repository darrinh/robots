//Define ON and OFF
#define ON HIGH
#define OFF LOW

//Variable to hold returned sensor value
int sensorValue = 0; 
const int mid_sensor = 4;

//Mapping motor functions to Arduio pins
const int LMR = 3; //IB1
const int LMF = 5;  //IA1
const int RMR = 7; //IA2
const int RMF = 9; //IB2
const int HS = 255;
const int LS = 120;

//Setup function
void setup() {
    //Set motor control pins as output
    pinMode(LMR,OUTPUT);
    pinMode(RMR,OUTPUT);
    pinMode(LMF,OUTPUT);
    pinMode(RMF,OUTPUT);
    pinMode(mid_sensor,INPUT);
    //Ensure motor reverse is turned off.
    analogWrite(LMR,OFF);
    analogWrite(RMR,OFF);

}
//Main program loop
void loop() {
    //Read sensor value
    sensorValue = digitalRead(mid_sensor);
    if(sensorValue) {
        digitalWrite(LMF,OFF);
        analogWrite(RMF,LS);
    
       
    } else {
      analogWrite(LMF,LS);
      digitalWrite(RMF,OFF);

    }


}

