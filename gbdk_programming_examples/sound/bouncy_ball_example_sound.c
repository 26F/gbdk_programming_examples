#include <gb/gb.h>

// sound channel 2
#define SND_LENGTH(N)             (N % 64)
#define WAV_DUTY(N)               (N % 4) << 6
#define ENVELOPE_STEPS(N)         (N % 8)
#define ENVELOPE_UP_OR_DOWN(N)    (N % 2) << 3
#define DEFAULT_ENVELOPE_VALUE(N) (N % 16) << 4
#define HOFD(N)                   (N % 8) // high order freq data
#define INIT_SND(N)               (N % 2) << 7

UWORD paldat[] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_BLACK, RGB_RED};

unsigned char ball[] =
{
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x3C,
  0x3C,0x3C,0x18,0x18,0x00,0x00,0x00,0x00
};


void playbeep() {
        NR14_REG = INIT_SND(0);
        NR21_REG = WAV_DUTY(6) | SND_LENGTH(4);
        NR22_REG = DEFAULT_ENVELOPE_VALUE(3) | ENVELOPE_UP_OR_DOWN(0) | ENVELOPE_STEPS(3);
        NR23_REG = 0xFA; // low order freq data
        NR24_REG = INIT_SND(1);
}

void main() {
  UINT8 ballx = 76;
  UINT8 bally = 75;
  UINT8 xdir = 0;
  UINT8 ydir = 0;
  DISPLAY_ON;
  NR52_REG = 0x80; // sound on
  NR50_REG = 0x7F; // master volume
  NR51_REG = 0xFF; // enables channels
  set_sprite_palette(0,1,paldat);
  SPRITES_8x8;
  set_sprite_data(0,0,ball);
  set_sprite_tile(0,0);
  set_sprite_prop(0,0);
  move_sprite(0,80,72);

  SHOW_SPRITES;

  while (1) {
    if (ballx < 6) {
      xdir = 1;
      playbeep();
    }
    if (ballx > 164) {
      xdir = 0;
      playbeep();
    }
    if (bally < 14) {
      ydir = 1;
      playbeep();
    }
    if (bally > 155) {
      ydir = 0;
      playbeep();
    }
    if (ydir == 0) {
      bally--;
    } else {
      bally++;
    }
    if (xdir == 0) {
      ballx--;
    } else {
      ballx++;
    }
    move_sprite(0,ballx,bally);
    wait_vbl_done();
  }

}