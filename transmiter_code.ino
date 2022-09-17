#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


int potpin1 = A1;
int potpin2 = A2;

int buttonState1 = 0;
int buttonState2 = 0;
RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}
void loop() 
{
   int a = analogRead(potpin1);
  int b = analogRead(potpin2);

   int anglea = map(a,0,1023,0,180);
   int angleb = map(b,0,1023,0,180);
 
 
    radio.write(&anglea,sizeof(anglea));
    radio.write(&angleb,sizeof(angleb));
  
}
