#ifndef _UTFT_RUS_INCLUDED_
#define _UTFT_RUS_INCLUDED_

#include<Arduino.h>
#include<UTFT.h>

class UTFTRus: public UTFT {
public:
// 	UTFTRus();
	UTFTRus(byte model, int RS, int WR, int CS, int RST, int SER=0);
	void print(char *st, int x, int y, int deg=0);
};

#endif
