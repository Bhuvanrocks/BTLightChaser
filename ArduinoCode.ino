/*
Author - Bhuvan Kumar
Description- Starts initially with multicolored lighting that can be controlled using a Mobile app 
App link: https://gallery.appinventor.mit.edu/?galleryid=dbf235ed-54b5-4455-8362-a9e9c3ffc891
This code is the intellectual property of Bhuvan Kumar.
It is shared under the GPL-3.0 license.
*/

#include <FastLED.h>

#define DATA_PIN    6   // Pin to which the data input of the LED strip is connected
#define NUM_LEDS    60  // Number of pixels in your LED strip
#define BRIGHTNESS  100  // Set the brightness of the LEDs (0-255)

#define TEMPERATURE_1 Tungsten100W
#define TEMPERATURE_2 OvercastSky
#define DISPLAYTIME 20
#define BLACKTIME   3

CRGB leds[NUM_LEDS];

unsigned long previousMillis = 0;
const long interval = 50;  
char prevData;

void handleBluetoothData(char receivedChar);

void CT() {
  static uint8_t starthue = 0;
  fill_rainbow(leds + 5, NUM_LEDS - 5, --starthue, 20);

  uint8_t secs = (millis() / 1000) % (DISPLAYTIME * 2);
  if (secs < DISPLAYTIME) {
    FastLED.setTemperature(TEMPERATURE_1);
    leds[0] = TEMPERATURE_1; 
  } else {
    FastLED.setTemperature(TEMPERATURE_2); 
    leds[0] = TEMPERATURE_2; 
  }

  FastLED.show();
}

void colorChase(CRGB color) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color;
      FastLED.show();
      unsigned long startMillis = millis();
      while (millis() - startMillis < 10) {}
    }
  }

void CC() {
  colorChase(CRGB::Red);    
  colorChase(CRGB::Green);  
  colorChase(CRGB::Blue);   
}

void randomCol() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 75) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(random8(), 255, random8());
    }
    FastLED.show();
    previousMillis = currentMillis;
  }
}

void twinkle(int numTwinkles, int count, int speed) {
  static CRGB twinkleColor;
  static unsigned long previousMillisTwinkle = 0;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisTwinkle >= speed) {
    previousMillisTwinkle = currentMillis;

    fill_solid(leds, NUM_LEDS, CRGB::Black);

    twinkleColor = CHSV(random8(), 255, 255);

    for (int j = 0; j < count; j++) {
      int pixel = random(NUM_LEDS);
      leds[pixel] = twinkleColor;
    }

    FastLED.show();
  }
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  CT();
  if(Serial.available()) {
    char data = Serial.read();
    Serial.print("Data");
    Serial.println(data);
    if(data >= '0' && data <= '9') {
      handleBluetoothData(data);
      while(!Serial.available()){ handleBluetoothData(prevData);}
    } else {
      prevData = data;
      while(!Serial.available()){ handleBluetoothData(data);}
    }
  }
}

void handleBluetoothData(char receivedChar) {
  switch (receivedChar) {
    case '0': FastLED.setBrightness(0); break;
    case '1': FastLED.setBrightness(25); break;
    case '2': FastLED.setBrightness(50); break;
    case '3': FastLED.setBrightness(75); break;
    case '4': FastLED.setBrightness(100); break;
    case '5': FastLED.setBrightness(125); break;
    case '6': FastLED.setBrightness(150); break;
    case '7': FastLED.setBrightness(175); break;
    case '8': FastLED.setBrightness(200); break;
    case '9': FastLED.setBrightness(255); break;
    case 'A': CT(); break;
    case 'B': CC(); break;
    case 'C': randomCol(); break;
    case 'D': twinkle(5, 10, 100); break;
  }
}
