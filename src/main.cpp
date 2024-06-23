#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES 2

#define RED_LED 11
#define ORANGE_LED 10
#define YELLOW_LED 9
#define GREEN_LED 6
#define BLUE_LED 5

// LED CODE
#define RED_CODE 4
#define ORANGE_CODE 3
#define YELLOW_CODE 2
#define GREEN_CODE 1

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

  for (int i = 0; i < ORANGE_CODE; i++)
  {
    blinkLed(ORANGE_LED);
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

  analogWrite(BLUE_LED, HIGH);
  delay(2000);
  analogWrite(BLUE_LED, LOW);
  delay(2000);
}

void setup()
{

  lcd.init();
  lcd.backlight();

  lcd.setCursor(3, 0);
  lcd.print("LOESUNG HIER");

  playLedCode();
}

void loop()
{
}
