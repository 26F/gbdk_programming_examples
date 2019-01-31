
#include <gb/gb.h>
#include <gb/drawing.h.>

// sound channel 2
#define SND_LENGTH(N)             (N % 64)
#define WAV_DUTY(N)               (N % 4) << 6
#define ENVELOPE_STEPS(N)         (N % 8)
#define ENVELOPE_UP_OR_DOWN(N)    (N % 2) << 3
#define DEFAULT_ENVELOPE_VALUE(N) (N % 16) << 4
#define HOFD(N)                   (N % 8) // high order freq data
#define INIT_SND(N)               (N % 2) << 7

void main() {
  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels

  while (1) {   
    if (joypad() & J_A) {
        NR14_REG = INIT_SND(0);
        NR21_REG = WAV_DUTY(6) | SND_LENGTH(4);
        NR22_REG = DEFAULT_ENVELOPE_VALUE(3) | ENVELOPE_UP_OR_DOWN(0) | ENVELOPE_STEPS(3);
        NR23_REG = 0xFA; // low order freq data
        NR24_REG = INIT_SND(1);
    }
    wait_vbl_done();
  }   
}