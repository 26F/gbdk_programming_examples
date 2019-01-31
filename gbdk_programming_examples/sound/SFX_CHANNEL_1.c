
#include <gb/gb.h>

// sound channel 1
#define SWEEP_SHIFT(N)            (N % 8)
#define SWEEP_INC_OR_DEC(N)       (N % 2) << 3
#define SND_LENGTH(N)             (N % 64)
#define SWEEP_TIME(N)             (N % 8) << 4
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
  
  // SND 1 rectangle waveform with sweep envelope
  while (1) {
    if (joypad() & J_A) {
        NR14_REG = INIT_SND(0) | HOFD(1); // init sound off
        NR10_REG = SWEEP_TIME(1) | SWEEP_INC_OR_DEC(0) | SWEEP_SHIFT(4);
        NR11_REG = WAV_DUTY(2) | SND_LENGTH(1);
        NR12_REG = DEFAULT_ENVELOPE_VALUE(5) | ENVELOPE_UP_OR_DOWN(1) | ENVELOPE_STEPS(5);
        NR13_REG = 0xF0; // waveform data one byte
        NR14_REG = INIT_SND(1) | HOFD(1); // init sound on
    }
    wait_vbl_done();
  }
  
}