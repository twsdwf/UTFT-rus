// UTFT_ViewFont (C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This program is a demo of the included fonts.
//
// This demo was made for modules with a screen resolution 
// of 320x240 pixels.
//
// This program requires the UTFT library.
//
// This programm modified by Alexey Stepanov (C) 2013
// Added cyrillic characters and other symbols in SmallSystemFont

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t SmallSymbolFont[];

// Uncomment the next line for Arduino 2009/Uno
//UTFT myGLCD(ITDB32S,19,18,17,16);   // Remember to change the model parameter to suit your display module!

// Uncomment the next line for Arduino Mega
//UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!
UTFT myGLCD(ITDB50,38,39,40,41);

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setBackColor(0, 0, 0);

  // маленький шрифт
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("SmallFont (c \xA3""o""\x99\x99""ep""\x9b\x9f""o""\x9e"" pycc""\x9f""o""\x98""o):", 15, 15);
  
  int j=0;
  int cnt = 32; // "смещение" 
  
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 255, 0);
  while (j<7){
    for (int i=0; i<26; i++){
      if (cnt<176) {
        myGLCD.print(String(char(cnt)), i*10+30, j*20+40);
        cnt++;
      }
    }
    j++;
  }
  
  // маленькие символы
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("SmallSymbolFont (""\x99""o""\xa3"".c""\x9d\xa1\x97""o""\xa0\xab""):", 15, 170);
  
  j=0;
  cnt = 32; // "смещение" 
  
  myGLCD.setFont(SmallSymbolFont);
  myGLCD.setColor(0, 0, 255);
  while (j<2){
    for (int i=0; i<26; i++){
      if (cnt<55) {
        myGLCD.print(String(char(cnt)), i*10+30, j*20+200);
        cnt++;
      }
    }
    j++;
  }
  
  // большой шрифт
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("BigFont (c \xA3""o""\x99\x99""ep""\x9b\x9f""o""\x9e"" pycc""\x9f""o""\x98""o):", 15, 240);
  
  j=0;
  cnt = 32; // "смещение" 
  
  myGLCD.setFont(BigFont);
  myGLCD.setColor(0, 255, 0);
  while (j<7){
    for (int i=0; i<26; i++){
      if (cnt<176) {
        myGLCD.print(String(char(cnt)), i*20+30, j*25+270);
        cnt++;
      }
    }
    j++;
  }

}

void loop()
{

}


