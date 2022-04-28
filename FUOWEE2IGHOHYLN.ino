#include <RFID.h>



/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/

#include <SPI.h>
#include <RFID.h>

#define SS1_PIN 10
#define RST1_PIN 9
#define RST_PIN 6
#define SS_PIN 3

RFID rfid1(SS1_PIN,RST1_PIN);
RFID rfid(SS_PIN,RST_PIN);


// LED pin numbers
int yellow = 7;
int blue = 8;
int red = 5;
int green = 4;

int power = 8; 
int serNum[5];
int cards[][5] = {
  {5,117,21,219,190}
  
};

bool access = false;

int id;
int id1;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    rfid1.init();

    pinMode(yellow, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(red, OUTPUT);


    digitalWrite(yellow, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
   
}

void loop(){
    
    if(rfid.isCard() or rfid1.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");

            // the ID number is the first part of the serial number
            id = rfid.serNum[0];
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
           
        }

        if(rfid1.readCardSerial()){
            Serial.print(rfid1.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid1.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid1.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid1.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid1.serNum[4]);
            Serial.println("");

            // the ID number is the first part of the serial number
            id1 = rfid1.serNum[0];
        }

         if (id == 19) {
           Serial.println("Not allowed!"); 
           digitalWrite(yellow, HIGH);
           delay(500);
           digitalWrite(yellow, LOW); 
           delay(500);      
       } else if (id == 131) {
           Serial.println("Not allowed!"); 
           digitalWrite(blue, HIGH);
           delay(500);
           digitalWrite(blue, LOW); 
           delay(500);      
       } else if (id == 243) {
           Serial.println("Not allowed!"); 
           digitalWrite(red, HIGH);
           delay(500);
           digitalWrite(red, LOW); 
           delay(500);      
       } else if (id == 3) {
           Serial.println("Not allowed!"); 
           digitalWrite(green, HIGH);
           delay(500);
           digitalWrite(green, LOW); 
           delay(500);      
       } else {
           Serial.println("Not allowed!"); 
           digitalWrite(green, HIGH);
           delay(500);
           digitalWrite(green, LOW); 
           delay(500);   
       }
        
       if (id1 == 19) {
           Serial.println("Not allowed!"); 
           digitalWrite(yellow, HIGH);
           delay(500);
           digitalWrite(yellow, LOW); 
           delay(500);      
       } else if (id1 == 131) {
           Serial.println("Not allowed!"); 
           digitalWrite(blue, HIGH);
           delay(500);
           digitalWrite(blue, LOW); 
           delay(500);      
       } else if (id1 == 243) {
           Serial.println("Not allowed!"); 
           digitalWrite(red, HIGH);
           delay(500);
           digitalWrite(red, LOW); 
           delay(500);      
       } else if (id1 == 3) {
           Serial.println("Not allowed!"); 
           digitalWrite(green, HIGH);
           delay(500);
           digitalWrite(green, LOW); 
           delay(500);      
       } else {
           Serial.println("Not allowed!"); 
           digitalWrite(green, HIGH);
           delay(500);
           digitalWrite(green, LOW); 
           delay(500);   
       }
    }
    
    
    rfid.halt();

}
