/*
 * created by Rui Santos, http://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin 9
        Echo: Echo (OUTPUT) - Pin 10
        GND: GND
 */
 int ledPin1 = 9; //Define Pin 9 LED1
int ledPin2 = 10; //Define Pin 10 LED2
int ledPin3 = 11; //Define Pin 11 LED3

int trigPin = 7;    //Trig - green Jumper
int echoPin = 8;    //Echo - yellow Jumper
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}
 
void loop()
{
 
 
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm > 5 && cm <10)fire();
  if (cm > 0 && cm <5)fireoff();
  delay(250);
}



void fire(){
analogWrite(ledPin1, random(300)+500); //Random 
analogWrite(ledPin2, random(200)+500);
analogWrite(ledPin3, random(250)+500);
delay(random(100)); //Delay for 10 seconds 
}

void fireoff(){
analogWrite(ledPin1, LOW);
analogWrite(ledPin2, LOW);
analogWrite(ledPin3, LOW);
  
}

