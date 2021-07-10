// Include NewPing Library
// Hooking  up  4 HC-SR04 with Rduino in Three wire Mood
// Maximum Distance is 400 cm
//IR sensor black surface 1, white 0

#include "NewPing.h"
#define MAX_DISTANCE1 400
#define MAX_DISTANCE2 400
#define MAX_DISTANCE3 400
int nd= 30; //notification distance
int us3d = 37;
int us4d = 40;
int data=0;
int trigPin2 = 2;    // Trigger
int echoPin2 = 3;    // Echo
int trigPin3 = 4;    // Trigger
int echoPin3 = 5;    // Echo
int trigPin4 = 6;    // Trigger
int echoPin4 = 7;    // Echo
int ir = 9; // data of ir sensor
int ldr = A0; //day night sensor pin
int ldrv = 0; // value of ldr 
int teta = 0; //teta for ir
int irp = 12; //arduino reads 1 if switch is on
int usp =13;
NewPing sonar2(trigPin2 ,echoPin2, MAX_DISTANCE1);
NewPing sonar3(trigPin3 ,echoPin3, MAX_DISTANCE2);
NewPing sonar4(trigPin4 ,echoPin4, MAX_DISTANCE3);

float distance2; // Stores calculated distance in cm for Second Sensor
float distance3; // Stores calculated distance in cm for Third Sensor
float distance4; // Stores calculated distance in cm for Third Sensor

void setup() {
  Serial.begin (9600);
  pinMode(ir, INPUT);
  pinMode(irp, INPUT);
  pinMode(usp, INPUT);
  //No need to define  inputs and outputs as we are using ping library
}

void loop() 
{
  data =0;
  distance2 = sonar2.ping_cm();
  distance3 = sonar3.ping_cm();
  distance4 = sonar4.ping_cm();
  delay(1000);
  if(digitalRead(irp)==1) //switch is on
  {
    if(digitalRead(ir)==0) //white surface
    {
      data = 4;
      Serial.println(data);
      delay(1000); 
    }
    else 
    {
      data = 0;     //black surface
      delay(1000);
    }
  }
  
     // Serial.println(distance2);
      //Serial.println(distance3);
      //Serial.println(distance4);
      
  if(digitalRead(usp)==1) //us switch is on
  {
    if(distance2>nd || distance2 ==0) 
    {
      //Serial.println("No obstacles");
      data = 0; //no obstacle
      Serial.println(data);
      delay(1000);
    }
    else     // distance2<=nd
    { 
      if(distance3 <= us3d)
      {
      
        if(distance4 <= us4d)
        {
           data = 1; //larger
           //Serial.println("larger");
           Serial.println(data);
           delay(1000);
        }
        else    //distance4 > us4d
        {
          // Serial.println("Smaller");
           data = 3; //smaller
           Serial.println(data);
           delay(1000);
        }        
      }

      else if(distance3>=us3d)
      {
        //Serial.println("Stair"); // stair
        data=2;
        Serial.println(data);
        delay(1000);
      }
      else
      {
        delay(1000);
      }
    }
  delay(1000); 
}
data = 0;
}
