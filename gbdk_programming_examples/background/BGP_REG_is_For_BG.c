#include <gb/gb.h>
// tested works fine

void main() {
  UINT8 c = 0;
  while (1) {
    BGP_REG = c;
    delay(20); // use delay before using wait_vbl_done();
    wait_vbl_done(); // always use wait_vbl_done()
    c++;
    if (c >= 4) {
      c = 0;
      }
  }
}