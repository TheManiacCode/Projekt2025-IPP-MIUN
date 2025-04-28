#include <Arduino.h>
#include <Olimex16x2.h>

Olimex16x2 lcd;
bool finishTimer = false;
void setup() {
    lcd.begin();
    lcd.setBacklight(255);
    lcd.clear();
    lcd.drawLine(0, "tryck vanstra");
    lcd.drawLine(1, "for att starta");
    }

void loop() {
    if (lcd.readButton(0)) 
    {
        startTimer();
    }
    if (finishTimer)
    {
        lcd.clear();
        lcd.drawLine(0, "Bra skrubbat");
        delay(500);
        finishTimer = false;
        lcd.clearLine(0);
        lcd.clearLine(1);
        lcd.drawLine(0, "tryck vanstra");
        lcd.drawLine(1, "for att starta");
    }
}

void startTimer() {
    short i;
    for (i = 30; i >= 0; i--) {
        lcd.clear();
        lcd.drawLine(0, " Timer: " + String(i)); 
    short tmp = i/3;
        String progressBar = " ";
        for (short j = 0; j < tmp; j++) 
        {
            progressBar += "#";
        }
        if (i > 0 && tmp <= 0)
        {
            progressBar = "#";
        }
        lcd.drawLine(1, progressBar);
        delay(800);
        lcd.clearLine(0);
        lcd.clearLine(1);
        delay(200);
    }
    finishTimer = true;
}