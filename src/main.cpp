#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES 2

#define RED_LED 11
#define YELLOW_LED 10
#define GREEN_LED 9
#define BLUE_LED 6

// LED CODE
#define RED_CODE 2
#define YELLOW_CODE 3
#define GREEN_CODE 1
#define BLUE_CODE 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void blinkLed(int pin)
{
  analogWrite(pin, HIGH);
  delay(600);
  analogWrite(pin, LOW);
  delay(600);
}

void playLedCode()
{
  for (int i = 0; i < RED_CODE; i++)
  {
    blinkLed(RED_LED);
  }

  delay(400);

  for (int i = 0; i < YELLOW_CODE; i++)
  {
    blinkLed(YELLOW_LED);
  }

  delay(400);

  for (int i = 0; i < GREEN_CODE; i++)
  {
    blinkLed(GREEN_LED);
  }

  delay(400);

  for (int i = 0; i < BLUE_CODE; i++)
  {
    blinkLed(BLUE_LED);
  }
  
  delay(2000);
}

void setup()
{

  lcd.init();
  lcd.backlight();

  lcd.setCursor(1, 0);
  lcd.print("Hacker Attack");

  playLedCode();
}

void loop()
{
}
