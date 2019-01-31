#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <stdlib.h>

UWORD sndval = 0;
UWORD regval = 0;
UWORD delval = 1;
UWORD shift = 0;

void clrscr() {
	UINT8 x;
	UINT8 y;
	gotogxy(0,0);
	for (x=0; x < 20; x++) {
		for (y=0; y < 18; y++) {
			gprintf(" ");
		}
	}
	gotogxy(0,0);
}

void main() {
	UINT8 cset = 0;
	UINT8 whichc = 10;
	UWORD repstage = 0;
	// init sound
	NR52_REG = 0x80;
	
	gprintf("UP    channel 1      ");
	gprintf("RIGHT channel 2      ");
	gprintf("DOWN  channel 3      ");
	gprintf("LEFT  channel 4      ");
	
	while (1) {
	if (joypad() & J_UP) {
		NR51_REG = 0x11;
		gprintf("CHN 1 selected   ");	
		cset = 1;
		whichc = 1;
		}
	if (joypad() & J_RIGHT) {
		NR51_REG = 0x22;
		gprintf("CHN 2 selected   ");
		cset = 1;
		whichc = 2;
		}
	if (joypad() & J_DOWN) {
		NR51_REG = 0x44;
		gprintf("CHN 3 selected   ");
		cset = 1;
		whichc = 3;
		}
	if (joypad() & J_LEFT) {
		NR51_REG = 0x88;
		gprintf("CHN 4 selected   ");
		cset = 1;
		whichc = 4;
		}
		if (cset == 1) {
			break;
		}
	}
	NR50_REG = 0xFF;
	clrscr();

	gprintf("LEFT/RIGHT -+ sound ");
	gprintf("DOWN/UP -+ delay    ");
	gprintf("SELECT (RESET)      ");
	gprintf("PRESS START...");
	waitpad(J_START);
	// loop
	clrscr();
	while (1) {
		if (joypad() & J_LEFT) {
			sndval--;
		}
		if (joypad() & J_RIGHT) {
			sndval++;
		}
		if (joypad() & J_UP) {
			delval++;
		}
		if (joypad() & J_DOWN) {
			delval--;
			
		}
		if (joypad() & J_B) {
			shift--;
		}
		if (joypad() & J_A) {
			shift++;
		}
		delval %= 200;
		if (delval == 0) {
			delval = 1;
		}
		if (joypad() & J_SELECT) {
			reset();
		}
		gotogxy(0,0);
		gprintf("value: %u",sndval);
		gotogxy(0,1);
		gprintf("delay: %u",delval);
		gotogxy(0,2);
		gprintf("shift: %u",shift);

		if (whichc == 1) {
			repstage = repstage % 5;
			switch(repstage) {
				case 0: {
					NR10_REG = sndval; 
					delay(delval);
					break;
				}
				case 1: {
					NR11_REG = sndval; delay(delval);
					break; 
				}
				case 2: { 
					NR12_REG = sndval + (shift * repstage); delay(delval);
					break; 
				}
				case 3: { 
					NR13_REG = sndval + (shift * repstage); delay(delval);
					break; 
				}
				case 4: { 
					NR14_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				default: break;
			}
			repstage++;
		}
		if (whichc == 2) {
			repstage = repstage % 4;
			switch(repstage) {
				case 0: { 
					NR21_REG = sndval; delay(delval);
					break; 
				}
				case 1: { 
					NR22_REG = sndval + (shift * repstage); delay(delval);
					break; 
				}
				case 2: { 
					NR23_REG = sndval + (shift * repstage); delay(delval);
					break; 
				}
				case 3: { 
					NR24_REG = sndval + (shift * repstage); delay(delval);
					break; 
				}
				default: break;
			}
			repstage++;
		}
		if (whichc == 3) {
			repstage = repstage % 5;
			switch(repstage) {
				case 0: { 
					NR30_REG = sndval; delay(delval);
					break; 
				}
				case 1: {
					NR31_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				case 2: {
					NR32_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				case 3: {
					NR33_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				case 4: {
					NR34_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				default: break;
			}
			repstage++;
		}
		if (whichc == 4) {
			repstage = repstage % 4;
			switch(repstage) {
				case 0: {
					NR41_REG = sndval; delay(delval);
					break;
				}
				case 1: {
					NR42_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				case 2: {
					NR43_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				case 3: {
					NR44_REG = sndval + (shift * repstage); delay(delval);
					break;
				}
				default: break;
			}
			repstage++;
		}
		wait_vbl_done();
	}
}