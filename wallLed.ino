#include <FastLED.h>

#define DATA_PIN 3
#define COLOR_ORDER GRB
#define NUM_LEDS 130
#define BRIGHTNESS 125        // Max brightness
#define FADE_DELAY 20         // Delay for smooth fading

CRGB leds[NUM_LEDS];

// Array of colors for cycling: Red, Blue, Green
CRGB colors[] = {CRGB::Red, CRGB::Blue, CRGB::Green};
int colorIndex1 = 0;  // Index for the first color
int colorIndex2 = 1;  // Index for the second color

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(0);   // Start with LEDs off
}

void loop() {
  // Fill gradient with current color pair
  fill_gradient_RGB(leds, NUM_LEDS, colors[colorIndex1], colors[colorIndex2]);

  // Pulse effect: Increase brightness
  for (int brightness = 0; brightness <= BRIGHTNESS; brightness += 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(FADE_DELAY);
  }
  delay(5000);
  // Pulse effect: Decrease brightness
  for (int brightness = BRIGHTNESS; brightness >= 0; brightness -= 5) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(FADE_DELAY);
  }

  // Move to the next color combination
  colorIndex1 = (colorIndex1 + 1) % 3;  // Cycle through 0, 1, 2
  colorIndex2 = (colorIndex2 + 1) % 3;
}
