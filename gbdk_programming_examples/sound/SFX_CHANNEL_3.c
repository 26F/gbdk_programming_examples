
#include <gb/gb.h>

#define TOGGLE_SOUND(N)		(N % 2) << 7
#define SND_LENGTH(N)		(N % 256)
#define VOLUME(N)			(N % 4) << 5
#define HOFD(N)				(N % 8)
#define SND_INIT(N)			(N % 2) << 7

void main() {
  UBYTE freqdata = 0;
  UBYTE increment = 1;
  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels

  while (1) {
  	if (joypad() & J_A) {
  		NR34_REG = SND_INIT(0);
  		NR30_REG = TOGGLE_SOUND(1);
  		NR31_REG = SND_LENGTH(13);
  		NR32_REG = VOLUME(3);
  		NR33_REG = freqdata;
  		NR34_REG = SND_INIT(1) | HOFD(increment); // increment here is a silly value because it is mod 8
  	}
  	freqdata += increment;
  	wait_vbl_done();
  	
  	if (joypad() & J_B) {
  		increment++;
  	}

  }
}