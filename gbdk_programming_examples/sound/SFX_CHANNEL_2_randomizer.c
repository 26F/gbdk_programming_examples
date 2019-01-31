
#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <rand.h>

// sound channel 2
#define SND_LENGTH(N)             (N % 64)
#define WAV_DUTY(N)               (N % 4) << 6
#define ENVELOPE_STEPS(N)         (N % 8)
#define ENVELOPE_UP_OR_DOWN(N)    (N % 2) << 3
#define DEFAULT_ENVELOPE_VALUE(N) (N % 16) << 4
#define HOFD(N)                   (N % 8) // high order freq data
#define INIT_SND(N)               (N % 2) << 7

void main() {
  UINT8 n = 0;
  UWORD seed = 0;
  UINT8 wav_duty = 0;
  UINT8 snd_length = 0;
  UINT8 def_env_val = 0;
  UINT8 env_up_down = 0;
  UINT8 env_steps = 0;
  UINT8 freqdat = 0;

  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels

  seed = 2;

  while (1) {   
    if (joypad() & J_A) {

        for(n = 0; n < 8; n++) {
          printf("\n");
        }

        wav_duty =    rand();
        snd_length =  rand();
        def_env_val = rand();
        env_up_down = rand();
        env_steps =   rand();
        freqdat =     rand();

        printf("wav duty:   %d\n", wav_duty);
        printf("snd_length: %d\n", snd_length);
        printf("def_env_val:%d\n", def_env_val);
        printf("env_up_down:%d\n", env_up_down);
        printf("env_steps:  %d\n", env_steps);
        printf("freq_data:  %d\n", freqdat);


        NR14_REG = INIT_SND(0);
        NR21_REG = WAV_DUTY(wav_duty) | SND_LENGTH(snd_length);
        NR22_REG = DEFAULT_ENVELOPE_VALUE(def_env_val) | ENVELOPE_UP_OR_DOWN(env_up_down) | ENVELOPE_STEPS(env_steps);
        NR23_REG = freqdat; // low order freq data
        NR24_REG = INIT_SND(1);
    }
    wait_vbl_done();
  }   
}