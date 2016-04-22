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

static const int sparkles = 17;
static uint8_t nums[sparkles];
static uint8_t hues[sparkles];
static uint8_t values[sparkles];

void _H(){
  nums[0] = 8;
  nums[1] = 16;
  nums[2] = 24;
  nums[3] = 32;
  nums[4] = 40;
  nums[5] = 25;
  nums[6] = 26;
  nums[7] = 11;
  nums[8] = 19;
  nums[9] = 27;
  nums[10] = 35;
  nums[11] = 43;
}
void _I(){
  nums[12] = 13;
  nums[13] = 21;
  nums[14] = 29;
  nums[15] = 37;
  nums[16] = 45;
}

void setup() {
  //Serial.begin(9600);
  FastLED.addLeds<CHIPSET, DATA_PIN>(leds, NUM_LEDS);
  _H();
  _I();
  for(int i = 0; i < sparkles; i++) {
    hues[i] = random8();
    values[i] = random8();
  }
}

void loop() {
  for(int i = 0; i < sparkles; i++) {
    leds[nums[i]] = CHSV(hues[i], 255, values[i]);

    if(values[i] == 0) {
      nums[i] = random8() % NUM_LEDS;
      hues[i] = random8();
      values[i] = 255;
    }

    if(values[i] >= 16) {
      values[i] -= 16;
    } else {
      values[i] = 0;
    }

    FastLED.show();
    delay(30);
  }
}
