#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    36
#define BRIGHTNESS  510



CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
  }

  for (int i = 31; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
  }

  leds[32] = CRGB::White;


  
    
}

void loop() {
FastLED.show();  

  
}
