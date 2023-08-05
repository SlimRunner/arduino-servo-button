#include <Servo.h>
#include "Button.hpp"

constexpr int clockRotPin = 8;
constexpr int anticRotPin = 7;
constexpr int servoPin = 10;

Servo myservo;

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
}

void loop() {
  constexpr int MAX_VALUE = 6000;
  constexpr int MAX_DEG = 180;
  constexpr float V2D = static_cast<float>(MAX_DEG) / MAX_VALUE;
  constexpr float D2V = static_cast<float>(MAX_VALUE) / MAX_DEG;
  static Button clockPush(clockRotPin);
  static Button anticPush(anticRotPin);
  static int angle = myservo.read() * D2V;

  if (clockPush.isPressed()) {
    angle = min(angle + 1, MAX_VALUE);
  } else if (anticPush.isPressed()) {
    angle = max(angle - 1, 0);
  }

  myservo.write(angle * V2D);
  // Serial.println(static_cast<int>(angle * V2D));
}
