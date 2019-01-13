#include <FastLED.h>

//Constants
#define LED_PIN     15
#define NUM_LEDS    120
#define CHIPSET     WS2812B
#define COLOR_ORDER RGB
#define BRIGHTNESS  128
#define BUTTON_PIN  A1

CRGB leds[NUM_LEDS];

int buttonState = 0;
int counter = 0;
int maxc = 4;

void setup() {
  delay( 3000 );
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0, 0, 0);
    FastLED.show(); 
  }
  
}//SETUP

void loop() {
  static uint8_t starthue = 0;
  buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == HIGH) {
    counter++;
    if (counter == maxc){counter==1;}
  }
  
  if (counter == 1) {
    for(int i = 0; i < NUM_LEDS; i++) {
     fill_rainbow( leds, NUM_LEDS, --starthue, 20);
     FastLED.show(); 
  }//for
  }

  if (counter == 2) {
   for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0, 0, 0);
    FastLED.show(); 
  }
 }//if
 
 if (counter == 3) {
   for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(255, 41, 87);
    FastLED.show(); 
  }
 }//if
 
}//LOOP
