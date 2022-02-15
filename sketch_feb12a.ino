
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("16x8 LED Mini Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
image[][8]={
{
  B11111111,
  B10011001,
  B10011001,
  B11100111,
  B11000011,
  B11000011,
  B11011011,
  B11111111
},{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
},{
  B01111110,
  B01000010,
  B11000011,
  B10100101,
  B01100110,
  B00111100,
  B00011000,
  B00111100
},{
  B00011000,
  B01111110,
  B01111110,
  B11111111,
  B10001001,
  B00001000,
  B00101000,
  B00111000
},{
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
},{
  B00000000,
  B00111110,
  B01000001,
  B01010101,
  B01000001,
  B01010101,
  B01001001,
  B00111110
},{
  B00000000,
  B00111110,
  B01111111,
  B01101011,
  B01111111,
  B01101011,
  B01110111,
  B00111110
},{
  B11111111,
  B11111111,
  B11100011,
  B11011101,
  B11011101,
  B11011101,
  B11100011,
  B11111111
},{
  B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00011000,
  B00000000,
  B00011000
},{
  B00000000,
  B00001000,
  B00011100,
  B00101010,
  B01111111,
  B00101010,
  B00001000,
  B00011100
}};
static const uint8_t PROGMEM
blank[]={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

void imagedisplay(int i,int j, int x){
  if(x==0){
    if(j<5){
      matrix.clear();
      matrix.drawBitmap(0,0,image[i],8,8,LED_ON);
      matrix.writeDisplay();
      
    }
    else{
      matrix.clear();
      matrix.drawBitmap(0,8,image[i],8, 8, LED_ON);
      matrix.writeDisplay();
      
    }
  }

else{
  matrix.clear();
  matrix.drawBitmap(0,0,image[i],8,8,LED_ON);
  matrix.drawBitmap(0,8,image[j],8,8, LED_ON);
  matrix.writeDisplay();
}
}

char *myStrs[] = {"Hello","World",
"Tree" "Stone","Atrium","Display",
"string", "land","water",
"Earth","Ocean"};

void wordDisplay(int i, int j){
  if(j == 1){
    matrix.setTextSize(1);
    matrix.setTextWrap(false);
    matrix.setTextColor(LED_ON);
    matrix.setRotation(1);
    for(int8_t x =7; x >= -36; x--){
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print(myStrs[i]);
      matrix.writeDisplay();
      delay(100);
    }
  }
  else{
     matrix.setTextSize(2);
     matrix.setTextWrap(false); 
     matrix.setTextColor(LED_ON);
     for (int8_t x=0; x>=-64; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print(myStrs[i]);
      matrix.writeDisplay();
      delay(100);
     }
    
  }
}
void loop(){
  uint8_t x = random(0,10);
  uint8_t y = random(0,10);
  imagedisplay(x,y,0);
  delay(500);

  
  matrix.clear();
  matrix.drawBitmap(0,8,image[1],8,8, LED_ON);
  
  matrix.writeDisplay();
  delay(500);

  uint8_t a = random(0,11);
  wordDisplay(a,2);
  delay(500);
  
  matrix.setRotation(0);
}
 
