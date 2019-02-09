
#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>

char string[25];

void main() {
  puts("Enter name\n");
  gets(string);

  gprintf("Hello %s", string);
  gotogxy(0,1); // in the form x, y
  gprintf("welcome");
}
