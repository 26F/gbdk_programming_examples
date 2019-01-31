#include <gb/gb.h>
#include <gb/drawing.h>

void main() {
	// 1 light grey, 2 dark grey 3 black, 4 white
	plot(10,15,3); // pixel
	circle(50,50,3); // circle
	box(20,20,40,40); // box
	line(10,10,50,50); // line
	gotogxy(10,10); // x, y coords for gprintf
	gprintf("hi homie");
}
