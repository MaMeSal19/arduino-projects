/*

For 14core starter kit

*/

int ledPin1 = 9; //Define Pin 9 LED1
int ledPin2 = 10; //Define Pin 10 LED2
int ledPin3 = 11; //Define Pin 11 LED3

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}

void loop(){
analogWrite(ledPin1, random(300)+500); //Random 
analogWrite(ledPin2, random(200)+500);
analogWrite(ledPin3, random(250)+500);
delay(random(100)); //Delay for 10 seconds 
}

