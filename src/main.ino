int BTN1 = D4;
int BTN2 = D5;
int BTN3 = D6;
int BTN4 = D7;

int BTNs[] = {D4, D5, D6, D7};
int LEDs[] = {D0, D1, D2, D3};
int currentLed = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(BTNs[i], INPUT_PULLUP);
  }
}

void loop() {
  int BtnsPressed[4];
  int pressedCount = 0;

  // turn off leds
  for (int i = 0; i < 4; i++) {
    digitalWrite(LEDs[i], LOW);
  }

  // get pressed buttons
  for (int i = 0; i < 4; i++) {
    if (digitalRead(BTNs[i]) == LOW) {
      BtnsPressed[pressedCount] = i;
      pressedCount++;
    }
  }

  // if pressed buttons, light up only those leds, otherwise loop leds.
  if (pressedCount > 0) {
    for (int i = 0; i < pressedCount; i++) {
      digitalWrite(LEDs[BtnsPressed[i]], HIGH);
    }
  } else {
    digitalWrite(LEDs[currentLed], HIGH);
    delay(250);
    digitalWrite(LEDs[currentLed], LOW);
    delay(250);
    currentLed = (currentLed + 1) % 4;
  }
}
