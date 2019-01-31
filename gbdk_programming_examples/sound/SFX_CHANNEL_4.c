
#include <gb/gb.h>

#define SND_LENGTH(N)				(N % 64)
#define ENVELOPE_LENGTH(N)			(N % 8)
#define ENVELOPE_UP_OR_DOWN(N)		(N % 2) << 3
#define DEFAULT_ENVELOPE_VALUE(N)   (N % 16) << 4
#define FREQ_DIV(N)					(N % 8)
#define POLYCNT_STEPS(N)			(N % 2) << 3
#define SHFT_CLCK_FRQ_OF_POLY(N)	(N % 4) << 4
#define SND_INIT(N)					(N % 2) << 7

void main() {
  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels

  while (1) {
  	if (joypad() & J_A) {
  		NR44_REG = SND_INIT(0);
  		NR41_REG = SND_LENGTH(12);
  		NR42_REG = DEFAULT_ENVELOPE_VALUE(2) | ENVELOPE_UP_OR_DOWN(0) | ENVELOPE_LENGTH(4);
  		NR43_REG = SHFT_CLCK_FRQ_OF_POLY(3) | POLYCNT_STEPS(0) | FREQ_DIV(2);
  		NR44_REG = SND_INIT(1);
  	}
	wait_vbl_done();  
  }
}