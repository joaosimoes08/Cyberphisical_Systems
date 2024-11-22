#include <Arduino.h>

struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button1 = {0, 0, false};

unsigned long button_time = 0;
unsigned long last_button_time = 0;

void IRAM_ATTR isr_button() {
  button_time = millis();
  if (button_time - last_button_time > 250) {
    button1.numberKeyPresses++;
    button1.pressed = true;
    last_button_time = button_time;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button1.PIN, INPUT_PULLUP);
  attachInterrupt(button1.PIN, isr_button, FALLING);
}

void loop() {
  if (button1.pressed) {
    Serial.printf("Button has been pressed %u times\n", button1.numberKeyPresses);
    button1.pressed = false;
  }
}