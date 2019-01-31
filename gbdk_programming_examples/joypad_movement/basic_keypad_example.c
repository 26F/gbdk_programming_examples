#include <gb/gb.h>
#include <stdio.h>

void init() {
	DISPLAY_ON; // turn on the display
	NR52_REG = 0x8f; // turn on the sound
	NR51_REG = 0x11; // Enable sound channels
	NR50_REG = 0x77; // Increase the volume to max
}

void checkInput() {
	if (joypad() & J_B) {
		printf("B");
		delay(100);
		wait_vbl_done();
	}
}

void main() {
	init();
	while(1) {
		checkInput();
	}
}

// also waitpad waitpadup
