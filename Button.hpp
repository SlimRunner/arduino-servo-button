#pragma once

enum class PressedWhen { low, high };

class Button {
private:
  const int m_pin;
  const PressedWhen m_pressvoltage;

  void begin();
  bool getState();

public:
  Button() = delete;
  Button(int pin);
  Button(int pin, PressedWhen volt);

  // default destructor

  bool isPressed();
};

void Button::begin() { pinMode(m_pin, INPUT_PULLUP); }

bool Button::getState() {
  switch (m_pressvoltage) {
  case PressedWhen::high:
    return HIGH;

  case PressedWhen::low:
    return LOW;

  default:
    // this should never happen
    return false;
  }
}

Button::Button(int pin) : m_pin(pin), m_pressvoltage(PressedWhen::low) {
  begin();
}

Button::Button(int pin, PressedWhen volt) : m_pin(pin), m_pressvoltage(volt) {
  begin();
}

bool Button::isPressed() {
  return digitalRead(m_pin) == getState();
}
