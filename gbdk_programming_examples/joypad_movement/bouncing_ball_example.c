#include <gb/gb.h>

UWORD paldat[] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_BLACK, RGB_RED};

unsigned char ball[] =
{
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x3C,
  0x3C,0x3C,0x18,0x18,0x00,0x00,0x00,0x00
};


void playbeep() {
  NR10_REG = 0x90;
  delay(6);
  NR11_REG = 0x90;
  delay(6);
  NR12_REG = 0x90;
  delay(6);
  NR13_REG = 0x90;
  delay(6);
  NR14_REG = 0x90;
  delay(6);

  delay(5);

  NR10_REG = 0x00;
  NR11_REG = 0x00;
  NR12_REG = 0x00;
  NR13_REG = 0x00;
  NR14_REG = 0x00;
  delay(5);

}

void main() {
  UINT8 ballx = 76;
  UINT8 bally = 75;
  UINT8 xdir = 0;
  UINT8 ydir = 0;
  DISPLAY_ON;
  NR52_REG = 0x80;
  NR51_REG = 0x11;
  NR50_REG = 0xFF;
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