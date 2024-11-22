/*
PRIMEIRO SCRIPT (BUTTON CLICKED X TIMES)
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
*/


/*
LIGAR E DESLIGAR LED 1.3 em 1.3 segundos
#include <Arduino.h>

#define LED 2

hw_timer_t *My_timer = NULL;

void IRAM_ATTR onTimer() {
  digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  pinMode(LED, OUTPUT);
  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  timerAlarmWrite(My_timer, 1300000, true);
  timerAlarmEnable(My_timer);
}

void loop() {

}
*/

#include <Arduino.h>

const int ledPin = 2; 

const int pwmChannel = 0; // Selects channel 0
const int frequency = 1000; // PWM frequency of 1 kHz
const int resolution = 8; // 8-bit resolution, 256 possible values
const int pwmPin = ledPin;

void setup() {
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, frequency, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // changing the LED brightness with PWM
    ledcWrite(pwmChannel, dutyCycle);
    delay(15);
  }
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    // changing the LED brightness with PWM
    ledcWrite(pwmChannel, dutyCycle);
    delay(15);
  }
}