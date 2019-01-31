#include <gb/gb.h>
#include <stdio.h>

void main() {
	printf("brainfuck notepad:\n\n");
	while (1) {
		if (joypad() & J_B) {
			printf("-");
			delay(400);
		}
		if (joypad() & J_UP) {
			printf(".");
			delay(400);
		}
		if (joypad() & J_DOWN) {
			printf(",");
			delay(400);
		}
		if (joypad() & J_A) {
			printf("+");
			delay(400);
		}
		if (joypad() & J_RIGHT) {
			printf(">");
			delay(400);
		}
		if (joypad() & J_LEFT) {
			printf("<");
			delay(400);
		}
		if (joypad() & J_START) {
			printf("]");
			delay(400);
		}
		if (joypad() & J_SELECT) {
			printf("[");
			delay(400);
		}
	}
}