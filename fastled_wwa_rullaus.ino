#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    30
#define BRIGHTNESS  255
#define LED_TYPE    WS2812
#define COLOR_ORDER BRG
CRGB leds[NUM_LEDS];


const int colourInPin = A2; 
void setup() {
    //Serial.begin(9600);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( Typical8mmPixel );
    LEDS.setBrightness(BRIGHTNESS);
    delay( 1000 ); // power-up safety delay
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0)); 
    int colorstep = 0;
    int coloradd = 170/NUM_LEDS;
    FastLED.show();
      for(int x = 0; x<NUM_LEDS; x++) {
       leds[x] = CHSV(colorstep,255,255); 
       FastLED.show();
       colorstep = colorstep+coloradd;
       delay(200);
      }
   
    delay(1000);

}

void loop() {

// 166 = COLD WHITE
int mappedHue = map(analogRead(colourInPin), 0, 1023, 0, 255);
fill_solid(leds, NUM_LEDS, CHSV(mappedHue,255,255));

FastLED.show();
delay(5);


}
