#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27  //0x3F vid fel adress
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() 
{
    lcd.init();
    lcd.backlight();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    lcd.setCursor(0, 0);
    lcd.print("Tryck Start");
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) 
    { 
        startTimer();
    }
}

void startTimer() {
    for (int i = 30; i >= 0; i--) 
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Timer: ");
        lcd.print(i);

        lcd.setCursor(0, 1);
        int progress = map(i, 0, 30, 0, 16);
        for (int j = 0; j < progress; j++) 
        {
            lcd.print("#");
        }

        delay(1000);
    }
}