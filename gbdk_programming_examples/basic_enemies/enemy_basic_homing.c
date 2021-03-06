
/* Start of tile array. */
unsigned char tiles[] =
{
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xF7,
  0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F
};

/* End of TILES.C */

#define dungeonWidth 		20
#define dungeonHeight 		18
#define dungeonBank 		0
#define ENEMIES 			4
#define PLAYER_MS			3

unsigned char dungeon[] =
{
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00
};

/* End of DUNGEON.C */



unsigned char sprites[] =
{
  0xFF,0xC3,0xFF,0x81,0xFF,0x24,0xFF,0x18,
  0xFF,0x18,0xFF,0x24,0xFF,0x81,0xFF,0xC3,
  0x81,0x7E,0x7E,0x81,0x66,0x99,0x5A,0xA5,
  0x5A,0xA5,0x66,0x99,0x7E,0x81,0x81,0x7E
};

#include <gb/gb.h>

// function prototypes
void init();
void checkInput();
//void updateSwitches();
UINT8 collisionCheck(UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8);

UINT8 player[2]; // x,y positions for player
UINT8 enemy[ENEMIES]; // position of enemy

void main() {
	init(); // init game boy stuff
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	while (1) { // main loop
		checkInput();		// Check for user input (and act on it)
		wait_vbl_done();		// Wait until VBLANK to avoid corrupting memory
		wait_vbl_done();		// Wait until VBLANK to avoid corrupting memory
		
	}
}

void init() {
	int ce, enemies = ENEMIES;
	DISPLAY_ON; // turn the display on
	set_bkg_data(0, 2, tiles); // load the tiles into memory
	set_bkg_tiles(0,0,20,18, dungeon); 
	set_sprite_data(0, 2, sprites); // load the sprites

	set_sprite_tile(0,0); // Set the first movable sprite 0 to be the first tile
	
	player[0] = 12; // x 
	player[1] = 12; // y

	for (ce = 0; ce < ENEMIES; ce++) {
		set_sprite_tile(1+(ce),1); // enemy sprite. Sprite 1 gets next sprite after 0
		enemy[0+(ce*2)] = 45 + (ce*16);
		enemy[1+(ce*2)] = 45 + (ce*16);

	}
	
}

void checkInput() {
	int ce, skip = 0;
	if (joypad() & J_UP) { // This code will probably need optimizing...
		for (ce = 0; ce < 6; ce++) {
			if (collisionCheck(player[0], player[1] - PLAYER_MS, 8, 8, enemy[0+(ce*2)], enemy[1+(ce*2)], 8, 8) == 1) {
				skip = 1;
				set_sprite_tile(0, 0);
				break;
			} 
		} if (skip == 0) {
			player[1] -= PLAYER_MS; 
			set_sprite_tile(0, 1);
		} 
				
	}
	if (joypad() & J_DOWN) {
		for (ce = 0; ce < 6; ce++) {
			if (collisionCheck(player[0], player[1] + PLAYER_MS, 8, 8, enemy[0+(ce*2)], enemy[1+(ce*2)], 8, 8) == 1) {
				skip = 1;
				set_sprite_tile(0, 0);
				break;
			}
		} if (skip == 0) {
			player[1] += PLAYER_MS; 
			set_sprite_tile(0, 1);
		}  
		
	}
	if (joypad() & J_LEFT) {
		for (ce = 0; ce < 6; ce++) {
			if (collisionCheck(player[0] - PLAYER_MS, player[1], 8, 8, enemy[0+(ce*2)], enemy[1+(ce*2)], 8, 8) == 1) {
				skip = 1;
				set_sprite_tile(0, 0);
				break;
			} 	
		} if (skip == 0) {
			player[0] -= PLAYER_MS; 
			set_sprite_tile(0, 1);
		}
	}
	if (joypad() & J_RIGHT) { 
		for (ce = 0; ce < 6; ce++) {
			if (collisionCheck(player[0] + PLAYER_MS, player[1], 8, 8, enemy[0+(ce*2)], enemy[1+(ce*2)], 8, 8) == 1) {
				skip = 1;
				set_sprite_tile(0, 0);
				break;
			}
		} if (skip == 0) {
			player[0] += PLAYER_MS; 
			set_sprite_tile(0, 1);
		}
	}
	move_sprite(0, player[0], player[1]);

	for (ce = 0; ce < ENEMIES; ce++) {
		if (enemy[0+(ce*2)] < player[0]) enemy[0+(ce*2)] += 1;
		else if (enemy[0+(ce*2)] > player[0]) enemy[0+(ce*2)] -= 1;

		if (enemy[1+(ce*2)] < player[1]) enemy[1+(ce*2)] += 1;
		else if (enemy[1+(ce*2)] > player[1]) enemy[1+(ce*2)] -= 1;
	}
	
	for (ce = 0; ce < ENEMIES; ce++) {
		move_sprite(ce+1, enemy[0+(ce*2)], enemy[1+(ce*2)]);	
	}
	 
	
}

UINT8 collisionCheck(UINT8 x1, UINT8 y1, UINT8 w1, UINT8 h1, UINT8 x2, UINT8 y2, UINT8 w2, UINT8 h2) {

	if ((x1 < (x2+w2)) && ((x1+w1) > x2) && (y1 < (h2+y2)) && ((y1+h1) > y2)) {
		
		return 1;
	
	} else {
		
		return 0;
	
	}

}