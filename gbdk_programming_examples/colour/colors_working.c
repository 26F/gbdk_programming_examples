#include <gb/gb.h>

// color palette
UWORD backgroundpalette[] = {RGB_PINK, RGB_DARKRED, RGB_PURPLE, RGB_DARKGREEN, // 0 1 2 3
							 RGB_BLUE,RGB_DARKBLUE, RGB_WHITE, RGB_AQUA}; // 0 1 2 3

// bkg tile data
unsigned char backgroundcharacters[] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,
	0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
	}; 

// tile map data
unsigned char bgmap[] = {
	0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3
	}; 

// 0 for RGB_PINK, RGB_DARKRED, RGB_PURPLE, RGB_DARKGREEN,
// 1 for RGB_BLUE,RGB_DARKBLUE, RGB_WHITE, RGB_AQUA
// as defined in backgroundpalette
unsigned char cgbmap[] = {
	0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0
	}; 

void main() {
	//       first palette, n palettes 4 colors in 1 palette
	set_bkg_palette(0,2,backgroundpalette);
	// load in the tile data
	set_bkg_data(0,4,backgroundcharacters);
	
	// Setup to change palette selection data
	VBK_REG = 1;
	// setup palette selection data for the tiles in the map
	set_bkg_tiles(0,0,20,1,cgbmap);

	// setup to change actual tile data
	VBK_REG = 0;
	// change the actual tile data
	set_bkg_tiles(0,0,20,1,bgmap);
	// display
	SHOW_BKG;
	DISPLAY_ON;

}

