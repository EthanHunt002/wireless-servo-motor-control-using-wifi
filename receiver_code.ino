#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo servo1;
Servo servo2;


int buttonState = 0;

int anglea=0,angleb=0;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00002";

void setup() {
  servo1.attach(5);
  servo2.attach(6);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  servo1.write(92);
  servo2.write(92);
}
void loop() {
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  radio.read(&anglea, sizeof(anglea));
  radio.read(&angleb, sizeof(angleb));
  Serial.println(buttonState);
  Serial.println(anglea);
  Serial.println(angleb);
 
 if(anglea==89&&angleb==86)
   {servo1.write(92);
    servo2.write(92);
     
   }
   else if(anglea==89)
    servo1.write(90);
   else if(angleb==86)
     servo2.write(90);
   else
  //joystick
  {
    servo1.write(anglea);
    servo2.write(angleb);
  }
}
