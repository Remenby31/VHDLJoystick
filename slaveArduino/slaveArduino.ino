#include<SPI.h>
#define LEDpin 7
#define buttonpin 2

volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;

void setup() {
  // put your setup code here, to run once:
  pinMode(MISO,OUTPUT); // set MISO as output
  digitalWrite(MISO,LOW); // set MISO low
  SPCR |= _BV(SPE);  
  Serial.begin(9600); // set baud rate
  SPI.begin();
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}

void loop() {
  if(received) {                           //Logic to SET LED ON OR OFF depending upon the value recerived from master
        Serial.println(Slavereceived);       //Prints the value received from master
  } 

  Slavesend=0;                              //Sets the value to be sent to master as 0
  
  SPDR = Slavesend;                           //Sends the x value to master via SPDR 
  delay(1000);


}
