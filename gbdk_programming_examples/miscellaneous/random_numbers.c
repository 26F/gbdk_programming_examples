

#include <gb/drawing.h>
#include <gb/gb.h>
#include <rand.h>

UWORD seed;
UINT8 x;
UINT8 y;
UINT8 val;

void main() {
  // set_bkg_data(0,6, sprite_data);
  // set_bkg_tiles(0,0, 20,18, snake_map);
  // SHOW_BKG;
  // DISPLAY_ON;

  waitpad(J_START);
  waitpadup();
  seed = DIV_REG;

  waitpad(J_START);
  waitpadup();
  seed |= (UWORD)DIV_REG << 8;

  initarand(seed);

  while (1) {
  	gprintf("     ");
  	gotogxy(0,0);
  	val = rand();
  	gprintf("%u", val);
  	gotogxy(0,0);

  	waitpad(J_START);
  	waitpadup();
  }
}

