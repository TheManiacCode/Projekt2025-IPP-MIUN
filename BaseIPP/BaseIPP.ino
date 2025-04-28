#include <Arduino.h>
#include <Olimex16x2.h>

Olimex16x2 lcd;

void setup() {
    lcd.begin();
    lcd.setBacklight(255);
    lcd.clear();
    lcd.drawLine(0, "Tryck Start");
}

void loop() {
    if (lcd.readButton(0)) 
    {
        startTimer();
    }
}

void startTimer() {
    int i;
    for (i = 30; i >= 0; i--) {
        lcd.clear();
        lcd.drawLine(0, " Timer: " + String(i)); 
    int tmp = i/4;
        String progressBar = " ";
        for (int j = 0; j < tmp; j++) 
        {
            progressBar += "#";
        }
        lcd.drawLine(1, progressBar);

        delay(800);
        lcd.clearLine(0);
        lcd.clearLine(1);
        delay(200);
    }
}