
#include<Arduino.h>
#include<UTFT.h>
#include "UTFTRus.h"
/**
	таблица перекодировки. часть русских букв переиспользует английские,
	за сим линейного преобразования нет, нужна таблица соответствий.
*/
uint8_t const utf8_rus_charmap[] PROGMEM = {
'A', 	//A		0
128,	//Б		1
'B',	//В		2
129,	//Г		3
130,	//Д		4
'E',	//Е		5
131,	//Ё		6
132,	//Ж		7
133,	//З
134,	//И
135,	//Й		10
'K',	//К
136,	//Л
'M',	//М
'H',	//Н
'O',	//		15
137,	//П
'P',	//
'C',	//
'T',	//
138,	//У		20
139,	//Ф
'X',	//
140,	//Ц
141,	//Ч
142,	//Ш		25
143,	//Щ
144,	//Ъ
145,	//Ы
146,	//Ь
147,	//Э		30
148,	//Ю
149,	//Я		32
//small letters
'a',	//		33
150,	//б
151,	//в		35
152,	//г
153,	//д
'e',
154,	//ё
155,	//ж		40
156,	//з
157,	//и
158,	//й
159,	//к
160,	//л		45
161,	//м
162,	//н
'o',	//
163,	//п
'p',	//р		50
'c',	//c		51
164,	//т
'y',
165,	//ф
'x',	//		55
166,	//ц
167,	//ч
168,	//ш
169,	//щ
170,	//ъ		60
171,	//ы
172,	//ь
173,	//э
174,	//ю
175		//я		65
};

UTFTRus::UTFTRus(byte model, int RS, int WR, int CS, int RST, int SER):UTFT(model, RS, WR, CS, RST, SER)
{

}


void	UTFTRus::print(char *st, int x, int y, int deg)
{
	int stl, i;

	stl = strlen(st);

	if (orient==PORTRAIT)
	{
	if (x==RIGHT)
		x=(disp_x_size+1)-(stl*cfont.x_size);
	if (x==CENTER)
		x=((disp_x_size+1)-(stl*cfont.x_size))/2;
	}
	else
	{
	if (x==RIGHT)
		x=(disp_y_size+1)-(stl*cfont.x_size);
	if (x==CENTER)
		x=((disp_y_size+1)-(stl*cfont.x_size))/2;
	}

	uint8_t utf_high_byte = 0;
	uint8_t ch, ch_pos = 0;

	for (i = 0; i < stl; i++) {
		ch = st[i];
		if ( ch >= 128) {
			if ( utf_high_byte == 0 && (ch ==0xD0 || ch == 0xD1)) {
				utf_high_byte = ch;
				continue;
			} else {
				if ( utf_high_byte == 0xD0) {
					if (ch == 0x81) { //Ё
						ch = 6;
					} else {
						if(ch <= 0x95) {
							ch -= 0x90;
						} else if( ch < 0xB6){
							ch -= (0x90 - 1);
						} else {
							ch -= (0x90 - 2);
						}
					}
					ch = pgm_read_byte(utf8_rus_charmap + ch);
				} else if (utf_high_byte == 0xD1) {
					if (ch == 0x91) {//ё
						ch = 39;
					} else {
						ch -= 0x80;
						ch += 50;
					}
					ch = pgm_read_byte(utf8_rus_charmap + ch);
				}
				utf_high_byte = 0;
			}
		} else {
			utf_high_byte = 0;
		}
		if (deg==0) {
			printChar(ch, x + (ch_pos * (cfont.x_size)), y);
		} else {
			rotateChar(ch, x, y, ch_pos, deg);
		}
		++ch_pos;
	}
}
