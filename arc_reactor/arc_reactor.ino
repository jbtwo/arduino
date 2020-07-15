#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    36
#define MAX_BRIGHTNESS 255     
#define MIN_BRIGHTNESS 32       
#define potPin A0
#define buttonPin D6

int resistance = 0;
int state = HIGH;
int buttonState= HIGH;
int reading;           // the current reading from the input pin
int previous = LOW;

long ms = 0;         // the last time the output pin was toggled
long debounce = 200;

CRGB leds[NUM_LEDS];
void setup() {

   Serial.begin(115200);
  
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
  }

for (int i = 31; i < NUM_LEDS; i++) {
    leds[i] = 0x5757ff;
  }
  leds[32] = CRGB::White;
  leds[36] = CRGB::Blue;

     FastLED.setBrightness(MAX_BRIGHTNESS);

     pinMode(buttonPin, INPUT);
}



void loop() {
 
resistance = map(analogRead(potPin), 0, 1023, 0, 255);
reading = digitalRead(buttonPin);

 // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
 if (reading == HIGH && previous == LOW && millis() - ms > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    ms = millis();    
  }
  

  
if (state == HIGH) {
  FastLED.setBrightness(constrain(resistance, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
} else {
  FastLED.setBrightness(0);
}

   FastLED.show();

   previous = reading;
   
 delay(100);
 
}
