#include <Arduino.h>
#include <Olimex16x2.h>
//#include <NewPing.h>

Olimex16x2 lcd;
bool finishTimer = false;
/*const unsigned int TRIG_PIN = 13;
const unsigned int ECHO_PIN = 12;
const unsigned int BAUD_RATE=9600;
NewPing sonar(3,2,200);
int distance;
*/
void setup() 
{
    lcd.begin();
    lcd.setBacklight(255);
    lcd.clear();
    lcd.drawLine(0, "ta fram handerna");
    lcd.drawLine(1, "for att starta");
    //Serial.begin(BAUD_RATE);

}

void loop() 
{
    /*
    while (distance > 0)
    {
        getDistance();
        delay(5000);
    }
    if (distance > 0 && distance <= 8) 
    {
        distance = -1;
        startTimer();
    }
    */
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
        delay(800);
        lcd.clearLine(0);
        lcd.clearLine(1);
        delay(200);
    }
    finishTimer = true;
    //getDistance();
}
/*void getDistance() 
{
    distance = sonar.ping_cm();
    if(distance == 0)
    {
        Serial.println("Warning: no pulse from sensor");
    }  
    else
    {
        Serial.print("distance to nearest object:");
        Serial.println(distance);
        Serial.println(" cm");
    }
    delay(500);
}
*/
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
