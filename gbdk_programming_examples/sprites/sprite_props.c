
#include <gb/gb.h>

// sprite A
unsigned char TileLabel[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,
  0x2F,0x31,0x2F,0x3F,0x38,0x28,0x38,0x38
};


void main() {
	SPRITES_8x8;
	set_sprite_data(0,0, TileLabel);
	move_sprite(0, 72, 72);
	SHOW_SPRITES;
	while (1) {
		if (joypad() & J_UP) set_sprite_prop(0, S_FLIPY);
		if (joypad() & J_DOWN) set_sprite_prop(0, !(S_FLIPY));
		if (joypad() & J_LEFT) set_sprite_prop(0, S_FLIPX);
		if (joypad() & J_RIGHT) set_sprite_prop(0, !(S_FLIPX));
 
		wait_vbl_done();
	}

}