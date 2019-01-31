
#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>

void cls();

char string[25];
void main() {
  puts("Enter name\n");
  gets(string);
  cls();

  gprintf("Hello %s", string);
  gotogxy(0,1); // in the form x, y
  gprintf("welcome");
}