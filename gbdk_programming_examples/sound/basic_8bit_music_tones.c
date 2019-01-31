
#include <gb/gb.h>
#include <gb/drawing.h>

void cls();

void main() {
	unsigned char freqs[] = {13, 40, 68, 91, 114, 137, 157, 177, 195, 214, 231, 247};
	UINT8 freq = 1;
	UINT8 loc = 0;
	UINT16 timer = 0;
	NR52_REG = 0x80; // turn on sound
	NR50_REG = 0x7F; // master volume
	NR51_REG = 0xFF;
	// NR51 channels (0x11) 2 (0x22) 3 (0x44) 4 (0x88)
	
	//NR51_REG = 0x11;

	// SND 1 rectangle waveform with sweep envelope
	//NR10_REG = 0x86; // BITS: 7 not used. 6-5-4 sweep time (0-7). 3 sweep inc or dec. 2-1-0: sweep shift (0 through 7)
	NR11_REG = 0x86; // BITS: 7-6 waveform duty cycle (R/W). 5-4-3-2-1-0 sound length (0 through 63)
	NR12_REG = 0xc0; // BITS: 7-6-5-4 Default envelope value. 3 envelope up/down. 2-1-0 envelope steps (0 through 7)
	//NR13_REG //  BITS: 7-6-5-4-3-2-1-0 for freq data.
	NR14_REG = 0x86; //  BITS: 7 init. 6 counter/continuous selection. 2-1-0 high order freq data

	while (1) {
    if (timer > 2000) { 
    	timer = 0;
    	loc++;
    	if (loc == 12) loc = 0;
    	
    }
    NR13_REG = freqs[loc];
    timer++;
	// wait_vbl_done();
	}	


	// SND 2 rectangle waveform with envelope functions
	//NR21_REG; // BITS: 7-6 waveform duty. 5-4-3-2-1-0 Sound length.
	//NR22_REG; // BITS: 7-6-5-4 Default envelope. 3 envelope up/down. 2-1-0 length of envelope steps (0-7)
	//NR23_REG; // BITS: 7-6-5-4-3-2-1-0 low order freq data
	//NR24_REG; // BITS: 7 init. 6 counter/continuous selection (R/W). 2-1-0 high order freq data.

	// SND 3 waveform from waveform RAM
	//NR30_REG; // BIT 7 toggle sound output.
	//NR31_REG; // BITS: 7-6-5-4-3-2-1-0 sound length.
	//NR32_REG; // BITS: 6-5 output level.
	//NR33_REG; // BITS: 7-6-5-4-3-2-1-0 low order freq data 
	//NR34_REG; // BITS: 7 init. 6 counter/continuous selection (R/W). 2-1-0 high order freq data

	// SND 4 white noise with envelope
	//NR41_REG; // BITS: 5-4-3-2-1-0 sound length
	//NR42_REG; // BITS: 7-6-5-4 default envelope value. 3 envelope up/down. 2-1-0 length of envelope. (0 - 7) (ALL R/W)
	//NR43_REG; // BITS: 7-6-5-4 shift freq of polynomial counter. 3 polynomial counter steps. 2-1-0 division of freq.
	//NR44_REG; // BITS: 7 init. 6 counter/continuous selection

}