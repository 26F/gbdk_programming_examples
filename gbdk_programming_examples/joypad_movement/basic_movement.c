
#include <gb/gb.h>

unsigned char alpha[] = {
  0x7C,0x7C,0x86,0x86,0x8A,0x8A,0x92,0x92,0xA2,0xA2,0xC2,0xC2,0x7C,0x7C,0x00,0x00,0x10,0x10,0x30,0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x02,0x02,0x1C,0x1C,0x60,0x60,0x80,0x80,0xFE,0xFE,0x00,0x00,0xFE,0xFE,0x04,0x04,0x18,0x18,0x04,0x04,0x02,0x02,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x0C,0x0C,0x14,0x14,0x24,0x24,0x44,0x44,0x84,0x84,0xFE,0xFE,0x04,0x04,0x00,0x00,0xFC,0xFC,0x80,0x80,0xFC,0xFC,0x02,0x02,0x02,0x02,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x7C,0x7C,0x80,0x80,0x80,0x80,0xFC,0xFC,0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,0xFE,0xFE,0x82,0x82,0x04,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x82,0x82,0x7C,0x7C,0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,0x7C,0x7C,0x82,0x82,0x82,0x82,0x7E,0x7E,0x02,0x02,0x02,0x02,0x7C,0x7C,0x00,0x00,
  0x00,0x00,0x30,0x30,0x30,0x30,0x00,0x00,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x00,0x00,0x30,0x30,0x10,0x10,0x20,0x20,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x08,0x08,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0x01,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,0x00,
  0x7C,0x7C,0x82,0x82,0x9A,0x9A,0xAA,0xAA,0xBC,0xBC,0x80,0x80,0x7C,0x7C,0x00,0x00,0x38,0x38,0x44,0x44,0x82,0x82,0x82,0x82,0xFE,0xFE,0x82,0x82,0x82,0x82,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0xFC,0xFC,0x82,0x82,0x82,0x82,0xFC,0xFC,0x00,0x00,0x7C,0x7C,0x82,0x82,0x80,0x80,0x80,0x80,0x80,0x80,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0xF8,0xF8,0x84,0x84,0x82,0x82,0x82,0x82,0x82,0x82,0x84,0x84,0xF8,0xF8,0x00,0x00,0xFE,0xFE,0x80,0x80,0x80,0x80,0xFC,0xFC,0x80,0x80,0x80,0x80,0xFE,0xFE,0x00,0x00,
  0xFE,0xFE,0x80,0x80,0x80,0x80,0xFC,0xFC,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x7C,0x7C,0x82,0x82,0x80,0x80,0x80,0x80,0x8E,0x8E,0x82,0x82,0x7E,0x7E,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0xFE,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00,0x7C,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x7C,0x00,0x00,
  0x1E,0x1E,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x84,0x84,0x78,0x78,0x00,0x00,0x84,0x84,0x88,0x88,0x90,0x90,0xF0,0xF0,0x88,0x88,0x84,0x84,0x82,0x82,0x00,0x00,
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7E,0x7E,0x00,0x00,0x82,0x82,0xC6,0xC6,0xAA,0xAA,0x92,0x92,0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00,
  0x82,0x82,0xC2,0xC2,0xA2,0xA2,0x92,0x92,0x8A,0x8A,0x86,0x86,0x82,0x82,0x00,0x00,0x7C,0x7C,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0x82,0x82,0xFC,0xFC,0x80,0x80,0x80,0x80,0x00,0x00,0x7C,0x7C,0x82,0x82,0x82,0x82,0x92,0x92,0x8A,0x8A,0x84,0x84,0x7A,0x7A,0x00,0x00,
  0xFC,0xFC,0x82,0x82,0x82,0x82,0x84,0x84,0xF8,0xF8,0x84,0x84,0x82,0x82,0x00,0x00,0x7C,0x7C,0x80,0x80,0x80,0x80,0x7C,0x7C,0x02,0x02,0x02,0x02,0xFC,0xFC,0x00,0x00,
  0xFE,0xFE,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x7C,0x7C,0x00,0x00,
  0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,0x00,0x00,0x82,0x82,0x82,0x82,0x82,0x82,0x92,0x92,0xAA,0xAA,0xC6,0xC6,0x82,0x82,0x00,0x00,
  0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,0x28,0x28,0x44,0x44,0x82,0x82,0x00,0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0xFE,0xFE,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0xFE,0xFE,0x00,0x00,0x1C,0x1C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1C,0x1C,0x00,0x00,
  0x80,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00,0x00,0x70,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x70,0x00,0x00,
  0x10,0x10,0x28,0x28,0x44,0x44,0x82,0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00
};

unsigned char helloWorld[] = {
  0x30,0x18,0x15,0x1C,0x1C,0x1F,0x30,0x30,0x30,0x30,
  0x30,0x27,0x1F,0x22,0x1C,0x14,0x30,0x30,0x30,0x30
};

unsigned char blankScreen[] = {
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30
};

unsigned char sprites[] = {
  0x7E,0x7E,0x81,0x81,0xA5,0xA5,0x81,0x81,
  0x81,0x81,0xBD,0xBD,0x81,0x81,0x7E,0x7E,
  0x7E,0x7E,0x81,0x81,0xA5,0xA5,0x81,0x81,
  0x99,0x99,0xA5,0xA5,0x81,0x81,0x7E,0x7E
};


// 20 by 18 tiles
// 160 by 144 pixels

UINT8 player[2];

void init() {
  DISPLAY_ON;
  set_bkg_data(0,47,alpha);
  set_bkg_tiles(0,6,10,2,helloWorld);
  set_sprite_data(0,1,sprites); // load sprite data into memory
  set_sprite_tile(0,0);
  player[0] = 80u; // use u at the end of expressions if variable meant to be unsigned....
  player[1] = 72u;

  HIDE_WIN;
  SHOW_SPRITES;
  SHOW_BKG;

}
void checkInput() {
  if (joypad() & J_B) {
    set_bkg_tiles(0,0,20,18,blankScreen);
  }
  if (joypad() & J_UP) {
    player[1]--;
  }
  if (joypad() & J_DOWN) {
    player[1]++;
  }
  if (joypad() & J_LEFT) {
    player[0]--;
  }
  if (joypad() & J_RIGHT) {
    player[0]++;
  }
  move_sprite(0, player[0],player[1]);
}



void main() {
  init();
  while(1) {
    checkInput();
    wait_vbl_done();
  }
}