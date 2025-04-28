#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define BUTTON_PIN A0 // Knapparna är anslutna till analog pin A0

void setup() {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tryck Start");
}

void loop() {
    int buttonValue = analogRead(BUTTON_PIN);

    if (buttonValue < 100) { // Justering beroende på vilken knapp som används
        startTimer();
    }
}

void startTimer() {
    for (int i = 30; i >= 0; i--) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Timer: ");
        lcd.print(i);

        lcd.setCursor(0, 1);
        int progress = map(i, 0, 30, 0, 16);
        for (int j = 0; j < progress; j++) {
            lcd.print("#");
        }

        delay(1000);
    }
}