#include <Servo.h>
#include "Button.hpp"
#include "utilities.hpp"

constexpr int clockRotPin = 7;
constexpr int anticRotPin = 8;
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
    angle = max(angle - 1, 0);
  } else if (anticPush.isPressed()) {
    angle = min(angle + 1, MAX_VALUE);
  }

  myservo.write(angle * V2D);
  // Serial.println(static_cast<int>(angle * V2D));
}
