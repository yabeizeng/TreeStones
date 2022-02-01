/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

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
  bound_one[] =
  { B11111111,
  B11000011,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11000011,
  B11111111},
  inside_one[] =
  { B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000 },
   inside_two[] =
  { B00000000,
  B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00000000,
  B00000000 },
   inside_three[] =
  { B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000 },
   inside_four[] =
  { B00000000,
  B00111100,
  B01111110,
  B01100110,
  B01100110,
  B01111110,
  B00111100,
  B00000000 },
  inside_five[] =
  {  B00000000,
  B00111100,
  B01100110,
  B01000010,
  B01000010,
  B01100110,
  B00111100,
  B00000000 },
  inside_six[] =
  {  B01111110,
  B11111111,
  B11100111,
  B11000011,
  B11000011,
  B11100111,
  B11111111,
  B01111110 },
  inside_seven[] =
  { B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000 },
  bound_seven[] =
  { B11111111,
  B11000011,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11000011,
  B11111111},
  inside_eight[] =
  { B00000000,
  B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00000000,
  B00000000},
  bound_eight[] =
  { B10000001,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000001},
  inside_nine[] =
  { B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000},
  inside_ten[] =
  { B00000000,
  B00111100,
  B01111110,
  B01100110,
  B01100110,
  B01111110,
  B00111100,
  B00000000},
  inside_xi[] =
  {   B00000000,
  B00111100,
  B01100110,
  B01000010,
  B01000010,
  B01100110,
  B00111100,
  B00000000},
  inside_xii[] =
  { B01111110,
  B11111111,
  B11100111,
  B11000011,
  B11000011,
  B11100111,
  B11111111,
  B01111110},
  inside_xiii[] =
  { B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000},
  bound_xiii[] =
  { B11111111,
  B11000011,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11000011,
  B11111111},
  inside_xiv[] =
  { B00000000,
  B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00000000,
  B00000000},
  bound_xiv[] =
  { B10000001,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000001},
  inside_xv[] =
  { B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011000,
  B00000000,
  B00000000},
  inside_xvi[] =
  { B00000000,
  B00111100,
  B01111110,
  B01100110,
  B01100110,
  B01111110,
  B00111100,
  B00000000},
  inside_xvii[] =
  {  B00000000,
  B00111100,
  B01100110,
  B01000010,
  B01000010,
  B01100110,
  B00111100,
  B00000000},
  inside_xviii[] =
  { B01111110,
  B11111111,
  B11100111,
  B11000011,
  B11000011,
  B11100111,
  B11111111,
  B01111110};

void loop() {

  matrix.clear();
  matrix.drawBitmap(0, 0, bound_one, 8, 8, LED_YELLOW);
  matrix.drawBitmap(0, 0, inside_one, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_two, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_three, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_four, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_five, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_six, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_seven, 8, 8, LED_YELLOW);
  matrix.drawBitmap(0, 0, bound_seven, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, inside_eight, 8, 8, LED_YELLOW);
  matrix.drawBitmap(0, 0, bound_eight, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_nine, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_ten, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xi, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xii, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xiii, 8, 8, LED_GREEN);
  matrix.drawBitmap(0, 0, bound_xiii, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xiv, 8, 8, LED_GREEN);
  matrix.drawBitmap(0, 0, bound_xiv, 8, 8, LED_YELLOW);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xv, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xvi, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xvii, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(100);

  matrix.clear();
  matrix.drawBitmap(0, 0, inside_xviii, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(100);

  

  
  matrix.setRotation(0);
}
