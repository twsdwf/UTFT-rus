#include <UTFT.h>
#include <memorysaver.h>
#include <UTFTRus.h>

UTFTRus tft(SSD1289, 52, 51, 45, 46);
extern uint8_t SmallRusFont[];
extern uint8_t BigRusFont[];

void setup()
{
  tft.InitLCD(PORTRAIT);
  tft.clrScr();
  tft.setColor(VGA_BLACK);
  tft.fillRect(0,0, tft.getDisplayXSize()-1, tft.getDisplayYSize()-1);
  tft.setFont(BigRusFont);
  tft.setColor(VGA_WHITE);
  tft.setBackColor(VGA_TRANSPARENT);
  tft.print("АБВГДЕЁЖЗИЙКЛМН", 0, 0);

  tft.print("ОПРСТУФХШЩЬЫЪЭ", 0, 20); 
  tft.print("ЮЯабвгдеёжзийкл", 0, 40);
  tft.print("мнопрстуфхцчшщь", 0, 60);
  tft.print("ыъэюя", 0, 80);
  tft.setFont(SmallRusFont);
  tft.print("АБВГДЕЁЖЗИЙКЛМН", 0, 100);

  tft.print("ОПРСТУФХШЩЬЫЪЭ", 0, 120); 
  tft.print("ЮЯабвгдеёжзийкл", 0, 140);
  tft.print("мнопрстуфхцчшщь", 0, 160);
  tft.print("ыъэюя", 0, 180);
}

void loop()
{
}




