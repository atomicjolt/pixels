// Free RTOS
// #include <Arduino_FreeRTOS.h>
// #include <croutine.h>
// #include <event_groups.h>
// #include <FreeRTOSConfig.h>
// #include <FreeRTOSVariant.h>
// #include <list.h>
// #include <mpu_wrappers.h>
// #include <portable.h>
// #include <portmacro.h>
// #include <projdefs.h>
// #include <queue.h>
// #include <semphr.h>
// #include <StackMacros.h>
// #include <task.h>
// #include <timers.h>

// FastLED
#include <FastLED.h>


#define NUM_LEDS 64
#define DATA_PIN 7
#define CHIPSET     NEOPIXEL

CRGB leds[NUM_LEDS];
static uint8_t hue = 0;

void setup() {
  //Serial.begin(9600);
  FastLED.addLeds<CHIPSET, DATA_PIN>(leds, NUM_LEDS);
}

void stars(){
  for(int i = 0; i < 100; i++) {
    uint8_t light = random8(0, NUM_LEDS);
    uint8_t dark = random8(0, NUM_LEDS);
    leds[light] = CHSV(hue++, 255, 255);
    FastLED.show();
    leds[dark] = CRGB::Black;
    delay(5);
  }
}

void ran(){
  B();
  // for(int i = 0; i < 100; i++) {
  //   uint8_t light = random8(0, NUM_LEDS);
  //   uint8_t dark = random8(0, NUM_LEDS);
  //   leds[light] = CHSV(hue++, 255, 255);
  //   FastLED.show();
  //   leds[dark] = CRGB::Black;
  //   delay(5);
  // }
}

void B(){
  for(int i = 41; i < 47; i++){
    // uint8_t = Unsigned int 8 bit
    leds[i] = CHSV(hue++, 255, 255);
  }
  leds[33] = CHSV(hue++, 255, 255);
  leds[25] = CHSV(hue++, 255, 255);
  leds[18] = CHSV(hue++, 255, 255);
  leds[27] = CHSV(hue++, 255, 255);
  leds[20] = CHSV(hue++, 255, 255);
  leds[21] = CHSV(hue++, 255, 255);
  leds[30] = CHSV(hue++, 255, 255);
  leds[38] = CHSV(hue++, 255, 255);
  FastLED.show();
  delay(30);
}

// One dot moving along the screen
void dot(){
  for(int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CHSV(hue++, 255, 255);
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(30);
  }
}

// Fade color in and out
void fade(){
  for(int dot = 0; dot < 100; dot++) {
    FastLED.showColor(CHSV(hue++, 255, 255));
    delay(10);
  }
}

// Fill entire screen one dot at a time and then clear it one dot at a time
void dotFill(){

  for(int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CHSV(hue++, 255, 255);
    FastLED.show();
    // clear this led for the next time around the loop
    delay(30);
  }

  for(int dot = 0; dot < NUM_LEDS; dot++) {
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    FastLED.show();
    delay(30);
 }
}

void chase(int block){
  for(int dot = 0; dot < NUM_LEDS+block; dot++) {

    leds[dot] = CHSV(hue++, 255, 255);
    if(dot-5 >=0){
      leds[dot-5] = CRGB::Black;
    }

    FastLED.show();
    // clear this led for the next time around the loop
    delay(10);
  }
}

void loop() {
   B();
  //ran();
//  dot();
//  fade();
//  dotFill();
//  for(int i=3; i<10; i++){
//    chase(i);
//  }
}
