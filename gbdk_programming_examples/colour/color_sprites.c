#include <gb/gb.h>

UWORD spritepalette[] = { // 4 colors per palette
	RGB_RED, RGB_DARKRED, RGB_PINK, RGB_PURPLE,
	RGB_BLUE, RGB_DARKBLUE, RGB_CYAN, RGB_AQUA,
	RGB_BLACK, RGB_DARKGRAY, RGB_LIGHTGRAY, RGB_WHITE,
	RGB_YELLOW, RGB_DARKYELLOW, RGB_GREEN, RGB_DARKGREEN,
	RGB_LIGHTFLESH, RGB_BROWN, RGB_ORANGE, RGB_TEAL,
	}; 

// sprite data
unsigned char spritetiles[] = {
	173,173,173,173,203,203,171,171,169,169,0,0,0,0,0,0,
	72,72,168,168,170,170,170,170,69,69,0,0,0,0,0,0,
	148,148,149,149,137,137,137,137,8,8,0,0,0,0,0,0,
	152,152,84,84,88,88,84,84,148,148,0,0,0,0,0,0,
	196,196,170,170,202,202,170,170,164,164,0,0,0,0,0,0,
	152,152,144,144,152,152,144,144,216,216,0,0,0,0,0,0,
	};

void main() {
	set_sprite_palette(0,5,spritepalette);
	SPRITES_8x8;
	set_sprite_data(0,6,spritetiles);

	// set sprite tiles
	set_sprite_tile(0,0); // setting up which display for each sprite
	set_sprite_tile(1,1); // as is (sprite, tile) as input
	set_sprite_tile(2,2);
	set_sprite_tile(3,3);
	set_sprite_tile(4,4);
	set_sprite_tile(5,5);

	set_sprite_prop(0,0); // (sprite, palette)
	set_sprite_prop(1,1);
	set_sprite_prop(2,2);
	set_sprite_prop(3,3);
	set_sprite_prop(4,4);
	set_sprite_prop(5,0);

	move_sprite(0,20,20);
	move_sprite(1,28,20);
	move_sprite(2,36,20);
	move_sprite(3,44,20);
	move_sprite(4,52,20);
	move_sprite(5,60,20);

	SHOW_SPRITES;
}