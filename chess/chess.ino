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

static const int boardsquares = 64;
static uint8_t nums[boardsquares];
static uint8_t hues[boardsquares];
static uint8_t sats[boardsquares];
static uint8_t values[boardsquares];

void setup() {
  //Serial.begin(9600);
  FastLED.addLeds<CHIPSET, DATA_PIN>(leds, NUM_LEDS);
  for(int i = 0; i < boardsquares; i = i + 2) {
    nums[i] = i;
    hues[i] = random8();
    sats[i] = random8();
    values[i] = random8();
  }
}

void loop() {
  for(int i = 0; i < boardsquares; i = i + 2) {
    leds[nums[i]] = CHSV(hues[i], sats[i], values[i]);

    if(values[i] == 0) {
      nums[i] = i;
      hues[i] = random8();
      sats[i] = random8();
      values[i] = 255;
    }

    if(values[i] >= 16) {
      values[i] -= 16;
    } else {
      values[i] = 0;
    }

    FastLED.show();
    delay(5);
  }
}
