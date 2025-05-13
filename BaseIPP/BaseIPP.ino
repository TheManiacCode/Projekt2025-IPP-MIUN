#include <Arduino.h>
#include <Olimex16x2.h>
#include <NewPing.h>

Olimex16x2 lcd;
bool finishTimer = false;
#define TRIGGER_PIN 3 
#define ECHO_PIN 2     
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() 
{
    lcd.begin();
    lcd.setBacklight(255);
    lcd.clear();
    lcd.drawLine(0, "ta fram handerna");
    lcd.drawLine(1, "for att starta");
    Serial.begin(9600);
}

void loop() 
{
    int distance = sonar.ping_cm();
    delay(200);
    if (distance > 0 && distance <= 10) 
    {
        startTimer();
    }
    if (lcd.readButton(0))
    {
        startTimer();
    }
    if (finishTimer)
    {
        cleanDone();
    }
}
void startTimer() 
{
    short i;
    for (i = 30; i >= 0; i--) 
    {
        lcd.clear();
        lcd.drawLine(0, " Timer: " + String(i)); 
    short prgrsCnt = i/3;
        String progressBar = " ";
        for (short j = 0; j < prgrsCnt; j++) 
        {
            progressBar += "#";
        }
        if (i > 0 && prgrsCnt <= 0)
        {
            progressBar = "#";
        }
        lcd.drawLine(1, progressBar);
        delay(350);
        lcd.clearLine(0);
        lcd.clearLine(1);
        delay(150);
    }
    finishTimer = true;
}
void cleanDone()
{
    lcd.clear();
    lcd.drawLine(0, "Bra skrubbat");
    delay(500);
    finishTimer = false;
    lcd.clearLine(0);
    lcd.clearLine(1);
    lcd.drawLine(0, "ta fram handerna");
    lcd.drawLine(1, "for att starta");
}
