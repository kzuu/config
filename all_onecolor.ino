/* black
 *
 * By: Andrew Tuline
 * 
 * Date: July, 2015
 * 
 * Please, just turn off the damn colours while I do some more programming.
 *
 */


#include "FastLED.h"                                          // FastLED library. Please use the latest development version.

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif
 
// Fixed definitions cannot change on the fly.
#define LED_DT 3                                             // Data pin to connect to the strip.
#define LED_CK 11                                             // Clock pin for WS2801 or APA102.
#define COLOR_ORDER BRG                                       // It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE WS2812                                      // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 40                                           // Number of LED's.

// Global variables can be changed on the fly.
uint8_t max_bright = 128;                                      // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                   // Initialize our LED array.



void setup() {

  Serial.begin(57600);                                        // Initialize serial port for debugging.
  delay(1000);                                                // Soft startup to ease the flow of electrons.
  
//  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2801 or APA102
LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2812
  
  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, 500);               // FastLED Power management set at 5V, 500mA.

} // setup()

void setColor(int l, int r, int g, int b) {

  leds[l].red   = r;
  leds[l].green = g;
  leds[l].blue  = b;
}

/* GOOD COLOURS FOR PALETTE:
 * PINKISH RED : 225,0,20
 * MORE PINKISH RED: 225,0,80
 * HUE GREEN: 0,225,15
 * YELLOWISH GREEN: 170,245,0
 */


void loop() {     

  //fill_solid(leds, NUM_LEDS, CRGB::Black);                    // Just to be sure, let's really make it BLACK.
 for(int i = 0; i<NUM_LEDS; i++) {
  setColor(i, 170,245,0);
 }
  FastLED.show();                         // Power managed display
  
} // loop()


