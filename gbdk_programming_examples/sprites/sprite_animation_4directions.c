#include <gb/gb.h>

unsigned char r[] =
{
  0x00,0x00,0x18,0x18,0x18,0x18,0x3C,0x3C,
  0x7E,0x7E,0xFF,0xFF,0x00,0x00,0x00,0x00,
  0x20,0x20,0x30,0x30,0x38,0x38,0x3E,0x3E,
  0x3E,0x3E,0x38,0x38,0x30,0x30,0x20,0x20,
  0x00,0x00,0x00,0x00,0xFF,0xFF,0x7E,0x7E,
  0x3C,0x3C,0x18,0x18,0x18,0x18,0x00,0x00,
  0x04,0x04,0x0C,0x0C,0x1C,0x1C,0x7C,0x7C,
  0x7C,0x7C,0x1C,0x1C,0x0C,0x0C,0x04,0x04
};

void checkinp() {
  if (joypad() & J_UP) {
    set_sprite_tile(0,0);
  }
  if (joypad() & J_DOWN) {
    set_sprite_tile(0,2);
  }
  if (joypad() & J_LEFT) {
    set_sprite_tile(0,3);
  }
  if (joypad() & J_RIGHT) {
    set_sprite_tile(0,1);
  }
}

void main() {
  UINT8 t = 0;
  set_sprite_data(0,4,r);
  set_sprite_tile(0,0);
  move_sprite(0,80,72);
  SHOW_SPRITES;
  DISPLAY_ON;
  while(1) {
    checkinp();
    wait_vbl_done();
    wait_vbl_done();

  }
}