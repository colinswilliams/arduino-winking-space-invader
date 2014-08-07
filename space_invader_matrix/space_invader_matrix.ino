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
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

int buttonPin = 2;
int buttonStatus = 0;

void setup() {  
  matrix.begin(0x70);  // pass in the address
  pinMode(buttonPin, INPUT);
}

static const uint8_t PROGMEM
  invader_bmp[] = 
  { B00011000,
    B00111100,
    B01111110,
    B11011011,
    B11111111,
    B01100110,
    B10111101,
    B01100110 };

void loop() {
    checkButton();
    matrix.drawBitmap(0, 0, invader_bmp, 8, 8, LED_ON);
    matrix.drawPixel(0, 7, LED_OFF);
    matrix.drawPixel(1, 6, LED_OFF);
    matrix.drawPixel(7, 7, LED_OFF);
    matrix.drawPixel(6, 6, LED_OFF);
    matrix.writeDisplay();
    delay(300);
    
    checkButton();
    matrix.drawPixel(0, 6, LED_OFF);
    matrix.drawPixel(1, 7, LED_OFF);
    matrix.drawPixel(7, 6, LED_OFF);
    matrix.drawPixel(6, 7, LED_OFF);
    matrix.drawPixel(0, 7, LED_ON);
    matrix.drawPixel(1, 6, LED_ON);
    matrix.drawPixel(7, 7, LED_ON);
    matrix.drawPixel(6, 6, LED_ON);
    matrix.writeDisplay();
    delay(300);
}

int checkButton() {
    buttonStatus = digitalRead(buttonPin);
  
  if(buttonStatus == 1) {  
    matrix.drawPixel(5, 3, LED_ON);
    matrix.writeDisplay();
  } else {
    matrix.drawPixel(5, 3, LED_OFF); 
  }
}
