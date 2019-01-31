#include <gb/gb.h>

unsigned char smily[] = {
  0x00,0x00,0x44,0x44,0x00,0x00,0x00,0x00,
  0x44,0x44,0x6C,0x6C,0x38,0x38,0x00,0x00,
  0x00,0x00,0x28,0x28,0x00,0x00,0x00,0x00,
  0x42,0x42,0x26,0x26,0x3C,0x3C,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void main() {
  UINT8 t = 0;
  set_sprite_data(0,2,smily);
  set_sprite_tile(0,0);
  move_sprite(0,80,72);
  DISPLAY_ON;
  SHOW_SPRITES;
  while(1) {
    if (t == 10) {
      set_sprite_tile(0,0);
    }
    else if (t == 20) {
      t = 0;
      set_sprite_tile(0,1);
    }
    t++;
    wait_vbl_done();
  }
}