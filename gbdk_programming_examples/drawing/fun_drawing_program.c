#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

unsigned char x = 0;
unsigned char y = 0;

void main() {
	while(1) {
		if (joypad() == J_UP) y--;
		if (joypad() == J_DOWN) y++;
		if (joypad() == J_LEFT) x--;
		if (joypad() == J_RIGHT) x++;
		plot(x,y,2);
		delay(20);
		wait_vbl_done();

	}
}