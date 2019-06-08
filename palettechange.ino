#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    10
#define BRIGHTNESS  96
#define LED_TYPE    WS2812
#define COLOR_ORDER BRG
CRGB leds[NUM_LEDS];

DEFINE_GRADIENT_PALETTE( greentopink_gp ) {
/*   0,  225,0,50,
  50,  225,0,40,
  55,  0,200,30,
  135, 0,220,30,
  145, 0,235,40,
  165, 0,215,30,
  175, 50,200,10,
  215, 200,0,50,
  255, 255,0,20  };*/

    0, 252, 13,63,
   44, 0, 50, 40,
   64,   0,116,86,
   128,  0,180,62,
   192,135, 25, 99,
   255,236,  0,140 };

DEFINE_GRADIENT_PALETTE( pinktoblue_gp ) {
    0, 50,0,245,
   65, 255,0,30,
  150, 255,0,50,
  255, 150,0,245  };

DEFINE_GRADIENT_PALETTE( bluetogreen_gp ) {
    0, 0,255,10,
   100, 0,200,80,
   140, 0,150,40,
   150, 50,200,80,
   255, 150,255,0  };

DEFINE_GRADIENT_PALETTE( bg_gp ) {
   0,   0,126,53,
   150,  0,195,51,
   200, 158,203,0,
   255, 76,230,0  };

DEFINE_GRADIENT_PALETTE( sunset_gp ) {
  0,   255,  84,  0,
  50,  144,  0,  146,
  100,0 ,93,  232,
  150,248,245,0,
  151, 0,0,0,
  255,0,0,0};

DEFINE_GRADIENT_PALETTE( bhw1_28_gp ) {
    0,  1,221, 53,
  150, 30, 80, 60,
  255, 73,  3,178};

DEFINE_GRADIENT_PALETTE (mustakeski_gp) {
0, 231,0,126,
75, 0,0,0,
150, 0,0,0,
255,0,210,20};

DEFINE_GRADIENT_PALETTE (redgreen_gp) {

0, 0, 255,0,
30, 180,200,0,
45, 0,0,0,
180, 0,0,0,
190, 255, 0, 174,
255, 255, 0,0 };

CRGBPalette16 greentopink =  greentopink_gp;
CRGBPalette16 pinktoblue = pinktoblue_gp;
CRGBPalette16 bluetogreen = bluetogreen_gp;
CRGBPalette16 bgradient = bg_gp;
CRGBPalette16 currentPalette = greentopink_gp;
CRGBPalette16 targetPalette = pinktoblue_gp;
CRGBPalette16 sunset = sunset_gp;
CRGBPalette16 bhw1_28 = bhw1_28_gp;
CRGBPalette16 mustakeski = mustakeski_gp;
CRGBPalette16 redgreen = redgreen_gp;

boolean jokatoinen = false;
int nextcolor = 255/NUM_LEDS;

void setup() {
    
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( Typical8mmPixel );
    LEDS.setBrightness(BRIGHTNESS);
    delay( 1000 ); // power-up safety delay
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0)); 
    FastLED.show();
    delay(1000);
    randomit();
    startLeds();
      
}

void randomit() {

      for(int i = 0; i < 20; i++) {
              fill_gradient(leds,0,CHSV(random8(),255,255),random8(NUM_LEDS),CHSV(random8(),255,255),SHORTEST_HUES);
              if(jokatoinen) { setJokatoinen(); }
              FastLED.show();
              delay(500);
            }
              
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0)); 
    FastLED.show();
    delay(500);
          
}


void setJokatoinen() {

  for(int i = 0; i<NUM_LEDS; i++) {
        if(i % 2 == 0) { leds[i] = CHSV(0,0,0); }
      }
}

void startLeds() {
    uint8_t colorIndex = 0;
    uint8_t changeamount = 255/NUM_LEDS;
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
          for(int x = 0; x < 255; x += 4) {
              leds[i] = ColorFromPalette( currentPalette, colorIndex, x, LINEARBLEND);
              if(jokatoinen) { setJokatoinen(); }
              if(colorIndex > 255) {colorIndex = 255;}
              if(x > 255) {x = 255;}
              if(i > 8 && i < 23) { leds[i].fadeLightBy( 192 );}
              FastLED.show();
              }
        colorIndex = colorIndex+changeamount;
       }
}

void fillLeds( uint8_t colorIndex, uint8_t changeamount) {
    
    uint8_t brightness = 255;

    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, LINEARBLEND);
        if(i > 8 && i < 23) { leds[i].fadeLightBy( 192 );}
        colorIndex = colorIndex+changeamount;
        if(colorIndex > 255) {colorIndex = 255;}
        }
    if(jokatoinen) { setJokatoinen();}

    // 9-20 monitori

}

void ChangePalette() {

  if(currentPalette == greentopink)     { targetPalette = pinktoblue; }
  if(currentPalette == pinktoblue)      { targetPalette = bluetogreen; }
  if(currentPalette == bluetogreen)     { targetPalette = mustakeski; }
  if(currentPalette == mustakeski)      { targetPalette = bgradient; }
  if(currentPalette == bgradient)       { targetPalette = sunset; }
  if(currentPalette == sunset)          { targetPalette = bhw1_28; }  
  if(currentPalette == bhw1_28)         { targetPalette = redgreen; }
  if(currentPalette == redgreen)        { targetPalette = greentopink; }

}
 


void loop() {
  
  int palettedelay = 60; 
  static uint8_t index = 0;
  uint8_t changeamount = 255/NUM_LEDS;
  uint8_t maxChanges = 48;
  
  EVERY_N_SECONDS(palettedelay) { ChangePalette();  }

  fillLeds(index, changeamount);
  nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges); 
  FastLED.show();
  FastLED.delay(35);
  //delay(200); toimi ok
  


  
}

