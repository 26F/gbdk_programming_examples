
#include <gb/gb.h>
#include "gbt_player.h"




// File created by mod2gbt


const unsigned char song0[] = {
  0x8c,0x35, 0x9c,0x37, 0x84,0x07, 0x00,
  0x00, 0x20, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00,
  0x93,0x35, 0x00, 0x84,0x07, 0x00,
  0x20, 0x00, 0x20, 0x00,
  0x8c,0x35, 0x9c,0x37, 0x00, 0x00,
  0x20, 0x20, 0x85,0x07, 0x00,
  0x91,0x35, 0x9d,0x37, 0x20, 0x00,
  0x00, 0x20, 0x85,0x07, 0x00,
  0x98,0x35, 0x00, 0x20, 0x00,
  0x20, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x85,0x07, 0x00,
  0x97,0x35, 0x00, 0x20, 0x00,
  0x20, 0x00, 0x87,0x07, 0x00,
  0x00, 0x00, 0x20, 0x00,
  0x8c,0x35, 0x00, 0x84,0x07, 0x00,
  0x00, 0x00, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00,
  0x93,0x35, 0x9c,0x37, 0x84,0x07, 0x00,
  0x20, 0x20, 0x20, 0x00,
  0x8c,0x35, 0x9a,0x37, 0x00, 0x00,
  0x20, 0x9c,0x37, 0x85,0x07, 0x00,
  0x91,0x35, 0x9a,0x37, 0x20, 0x00,
  0x00, 0x20, 0x85,0x07, 0x00,
  0x98,0x35, 0x98,0x37, 0x20, 0x00,
  0x20, 0x20, 0x00, 0x00,
  0x00, 0x93,0x37, 0x85,0x07, 0x00,
  0x97,0x35, 0x9f,0x37, 0x20, 0x00,
  0x20, 0x20, 0x87,0x07, 0x00,
  0x00, 0x00, 0x20, 0x00,
  0x8c,0x35, 0x9c,0x37, 0x84,0x07, 0x00,
  0x00, 0x20, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00,
  0x93,0x35, 0x00, 0x84,0x07, 0x00,
  0x20, 0x00, 0x20, 0x00,
  0x8c,0x35, 0x9c,0x37, 0x00, 0x00,
  0x20, 0x20, 0x85,0x07, 0x00,
  0x91,0x35, 0x9d,0x37, 0x20, 0x00,
  0x00, 0x20, 0x85,0x07, 0x00,
  0x98,0x35, 0x00, 0x20, 0x00,
  0x20, 0x00, 0x00, 0x00,
  0x00, 0xa4,0x37, 0x85,0x07, 0x00,
  0x97,0x35, 0x20, 0x20, 0x00,
  0x00, 0x00, 0x87,0x07, 0x00,
  0x00, 0x00, 0x20, 0x00,
  0x8c,0x35, 0xa1,0x37, 0x84,0x07, 0x00,
  0x20, 0x20, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x93,0x35, 0x9c,0x37, 0x84,0x07, 0x00,
  0x20, 0x20, 0x20, 0x00,
  0x8c,0x35, 0x9a,0x37, 0x00, 0x00,
  0x20, 0x9c,0x37, 0x85,0x07, 0x00,
  0x91,0x35, 0x9a,0x37, 0x20, 0x00,
  0x00, 0x20, 0x85,0x07, 0x00,
  0x98,0x35, 0x98,0x37, 0x20, 0x00,
  0x20, 0x20, 0x00, 0x00,
  0x00, 0x93,0x37, 0x85,0x07, 0x00,
  0x96,0x35, 0x87,0x37, 0x20, 0x00,
  0x20, 0x20, 0x87,0x07, 0x00,
  0x00, 0x00, 0x20, 0x00
};

const unsigned char * song_Data[] = {
    song0,
    0x0000
};


void main()
{
	disable_interrupts();

	gbt_play(song_Data, 2, 7);
	gbt_loop(0);

	set_interrupts(VBL_IFLAG);
	enable_interrupts();
	
	while(1)
	{
		wait_vbl_done();
		
		gbt_update(); // This will change to ROM bank 1.
	}
}
