#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    12
#define BRIGHTNESS  96
#define LED_TYPE    WS2812
#define COLOR_ORDER BRG
CRGB leds[NUM_LEDS];

void setup() {

    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( Typical8mmPixel );
    LEDS.setBrightness(BRIGHTNESS);
    delay( 1000 ); // power-up safety delay
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0)); 
    FastLED.show();
    delay(1000);

}

void loop() {

for(int i = 0; i<170; i++) {
fill_solid(leds, NUM_LEDS, CHSV(i,255,255));
FastLED.show();
delay(25);
}

}
