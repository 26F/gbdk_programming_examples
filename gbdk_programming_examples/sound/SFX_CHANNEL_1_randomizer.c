

#include <gb/gb.h>
#include <gb/drawing.h>
#include <rand.h>
#include <stdio.h>

// sound channel 1
#define SWEEP_SHIFT(N)            (N % 8)
#define SWEEP_INC_OR_DEC(N)       (N % 2) << 3
#define SND_LENGTH(N)             (N % 64)
#define SWEEP_TIME(N)             (N % 8) << 4
#define WAV_DUTY(N)               (N % 4) << 6
#define ENVELOPE_STEPS(N)         (N % 8)
#define ENVELOPE_UP_OR_DOWN(N)    (N % 2) << 3
#define DEFAULT_ENVELOPE_VALUE(N) (N % 16) << 4
#define HOFD(N)                   (N % 8) // high order freq data
#define INIT_SND(N)               (N % 2) << 7


void main() {
  UINT8 n = 0;
  UWORD seed = 0;
  UWORD sweep_time = 0;
  UWORD sweep_inc_or_dec = 0;
  UWORD sweep_shift = 0;
  UWORD wav_duty = 0;
  UWORD snd_length = 0;
  UWORD default_envelope = 0;
  UWORD env_up_down = 0;
  UWORD envelope_steps = 0;
  UWORD wave_dat = 0;
  UWORD high_frewq_dat = 0;
  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels

  while (1) {
    if (joypad() & J_A) {
      break;
    }
  }

  seed = DIV_REG;
  seed |= (UWORD)DIV_REG << 8;
  
  // SND 1 rectangle waveform with sweep envelope
  

  while (1) {
    if (joypad() & J_A) {



        sweep_time =         rand();
        sweep_inc_or_dec =   rand();
        sweep_shift =        rand();
        wav_duty =           rand();
        snd_length =         rand();
        default_envelope =   rand();
        env_up_down =        rand();
        envelope_steps =     rand();
        wave_dat =           rand();
        high_frewq_dat =     rand();

        for (n = 0; n < 8; n++) {
          printf("\n");
        }
        printf("Sweep_time: %d\n", (UWORD) sweep_time % 8);
        printf("sweep_inc_or_dec %d\n", sweep_inc_or_dec);
        printf("sweep shift %d\n", sweep_shift);
        printf("wav duty %d\n", wav_duty);
        printf("snd length %d\n", snd_length);
        printf("default_envelope %d\n", default_envelope);
        printf("env_up_down %d\n", env_up_down);
        printf("envelope_steps %d\n", envelope_steps);
        printf("wav data %d\n", wave_dat);
        printf("HOFD: %d\n", high_frewq_dat);


        NR14_REG = INIT_SND(0) | HOFD(high_frewq_dat); // init sound off
        NR10_REG = SWEEP_TIME(sweep_time) | SWEEP_INC_OR_DEC(sweep_inc_or_dec) | SWEEP_SHIFT(sweep_shift);
        NR11_REG = WAV_DUTY(wav_duty) | SND_LENGTH(snd_length);
        NR12_REG = DEFAULT_ENVELOPE_VALUE(default_envelope) | ENVELOPE_UP_OR_DOWN(env_up_down) | ENVELOPE_STEPS(envelope_steps);
        NR13_REG = 0xF0; // waveform data one byte
        NR14_REG = INIT_SND(1) | HOFD(high_frewq_dat); // init sound on

        seed = DIV_REG;
        seed |= (UWORD)DIV_REG << 8;
    }
    wait_vbl_done();
  }
  
}