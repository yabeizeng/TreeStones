#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
H[] =
{B01001000,
  B01001000,
  B01001000,
  B01111000,
  B01001000,
  B01001000,
  B01001000,
  B00000000},
H_shadow[]=
{B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00110000,
  B00000000,
  B00000000,
  B01001000
},
E[]=
{B01111000,
  B01000000,
  B01000000,
  B01111000,
  B01000000,
  B01000000,
  B01111000,
  B00000000},
E_shadow[]={
  B00000000,
  B00111000,
  B00000000,
  B00000000,
  B00111000,
  B00000000,
  B00000000,
  B01111000};

void loop() {
  int8_t j;

  for(int8_t i = 0,j =5; i >-6; i--, j--){
     matrix.clear();
     matrix.drawBitmap(i, 0, H, 8, 8, LED_YELLOW);
     matrix.drawBitmap(i, 0, H_shadow, 8, 8, LED_GREEN);
     matrix.drawBitmap(j, 0, E, 8, 8, LED_YELLOW);
     matrix.drawBitmap(j, 0, E_shadow, 8, 8, LED_GREEN);
     matrix.writeDisplay();
     delay(500);
  }


 
 
  matrix.setRotation(0);
}
