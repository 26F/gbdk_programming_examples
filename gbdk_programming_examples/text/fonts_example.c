
#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>

void main() {
    font_t ibm_font, italic_font, min_font;
    // first inithe font system
    font_init();
    // load all the fonts 
    ibm_font = font_load(font_ibm); // 96 tiles
    italic_font = font_load(font_italic); // 93 tiles

    color(WHITE, DKGREY, SOLID); // white fg, dark bg

    min_font = font_load(font_min);

    // turn scrolling off
    mode(get_mode() | M_NO_SCROLL);

    // print some stuff
    font_set(ibm_font); // IBM font
    printf("IBM B machines\n");

    font_set(italic_font);
    printf("Italics\n");

    font_set(min_font);
    printf("only 36 tiles\n");

    font_set(ibm_font);
    printf("\nDone");

}