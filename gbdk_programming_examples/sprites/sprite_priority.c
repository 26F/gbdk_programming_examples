
#include <gb/gb.h>


/*

A bad example of sprite priority.

The in cgb mode the first sprites in have higher priority, eg, 
they are foreground, whereas last sprites in are underneath. 
So in cgb mode put foreground objects into sprite memory first.
Then objects underneath.

In DMG mode, the sprite with the smaller x value is always on top.

*/

UWORD spal[] = {RGB_LIGHTGRAY,RGB_DARKGRAY,RGB_RED, RGB_BLACK};

unsigned char shipAB[] =
{
  0x04,0x04,0x04,0x04,0x4C,0x4C,0x54,0x5C,
  0x64,0x7C,0x7D,0x45,0xFE,0x87,0xFC,0x83,
  0xFF,0x80,0xFF,0x80,0xCF,0xB0,0x7E,0x71,
  0x0E,0x0D,0x02,0x03,0x02,0x03,0x01,0x01,
  0x20,0x20,0x20,0x20,0x32,0x32,0x2A,0x3A,
  0x26,0x3E,0xBE,0xA2,0x7F,0xE1,0x3F,0xC1,
  0xFF,0x01,0xFF,0x01,0xF3,0x0D,0x7E,0x8E,
  0x70,0xB0,0x40,0xC0,0x40,0xC0,0x80,0x80,
  0x02,0x02,0x02,0x02,0x03,0x03,0x43,0x42,
  0xE7,0xE4,0xA4,0xA7,0xAC,0xAB,0xB4,0xBB,
  0xA7,0xB8,0xC1,0xFE,0xC3,0xBF,0xFC,0x84,
  0x78,0x48,0x30,0x30,0x20,0x20,0x20,0x20,
  0x40,0x40,0x40,0x40,0xC0,0xC0,0xC2,0x42,
  0xE7,0x27,0x25,0xE5,0x35,0xD5,0x2D,0xDD,
  0xE5,0x1D,0x83,0x7F,0xC3,0xFD,0x3F,0x21,
  0x1E,0x12,0x0C,0x0C,0x04,0x04,0x04,0x04,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

UINT8 ship_A_x = 70;
UINT8 ship_A_y = 72;
UINT8 ship_B_x = 80;
UINT8 ship_B_y = 72;
UINT8 tempx = 0;
UINT8 tempy = 0;

UINT8 sp = 0;

void flip_sprite_priority() {
	HIDE_SPRITES;
	if (sp) {
		// shipA
		set_sprite_tile(0,0);
		set_sprite_tile(1,2);
		// shipB
		set_sprite_tile(2,4);
		set_sprite_tile(3,6);		
		sp = 0;
	}
	else {
		// shipA
		set_sprite_tile(0,4);
		set_sprite_tile(1,6);
		// shipB
		set_sprite_tile(2,0);
		set_sprite_tile(3,2);
		sp = 1;

	}

	// shipA
	move_sprite(0, ship_A_x, ship_A_y);
	move_sprite(1, ship_A_x + 8, ship_A_y);
	
	// shipB
	move_sprite(2, ship_B_x, ship_B_y);
	move_sprite(3, ship_B_x + 8, ship_B_y);

	SHOW_SPRITES;
	
}

void main() {

	// set sprite palette
	set_sprite_palette(0, 1, spal);

	SPRITES_8x16;
	set_sprite_data(0, 8, shipAB); // there are 2 16x16 tiles. One 16x16 tile is composed of
	//								 4 regular 8x8 tiles. Thus 2 * 4 = 8
	
	// set sprite tile: sprite index, given tile(s)
	// in this case given tiles goes up by 2 because we're using 8x16.

	// shipA
	set_sprite_tile(0,0);
	set_sprite_tile(1,2);
	// shipB
	set_sprite_tile(2,4);
	set_sprite_tile(3,6);

	set_sprite_prop(0,0); // assign sprite 0 palette 1
	set_sprite_prop(1,0);
	set_sprite_prop(2,0);
	set_sprite_prop(3,0);
	
	// shipA
	move_sprite(0, ship_A_x, ship_A_y);
	move_sprite(1, ship_A_x + 8, ship_A_y);
	
	// shipB
	move_sprite(2, ship_B_x, ship_B_y);
	move_sprite(3, ship_B_x + 8, ship_B_y);

	SHOW_SPRITES;

	while (1) {
		if (joypad() & J_A) {
			waitpadup();
			tempx = ship_A_x;
			tempy = ship_A_y;
			ship_A_y = ship_B_y;
			ship_A_x = ship_B_x;
			ship_B_y = tempy;
			ship_B_x = tempx;
			flip_sprite_priority();
		}
		wait_vbl_done();

	}
}
