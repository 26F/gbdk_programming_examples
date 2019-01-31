
#include <gb/gb.h>

unsigned char alphabet[] =
{
  0x00,0x00,0x38,0x38,0x68,0x68,0x48,0x48,
  0x48,0x48,0x5C,0x5C,0x74,0x74,0x00,0x00,
  0x20,0x20,0x20,0x20,0x20,0x20,0x38,0x38,
  0x2C,0x2C,0x24,0x24,0x24,0x24,0x3C,0x3C,
  0x00,0x00,0x3C,0x3C,0x60,0x60,0x40,0x40,
  0x40,0x40,0x40,0x40,0x60,0x60,0x3C,0x3C,
  0x04,0x04,0x04,0x04,0x04,0x04,0x1C,0x1C,
  0x34,0x34,0x24,0x24,0x24,0x24,0x3C,0x3C,
  0x00,0x00,0x00,0x00,0x3C,0x3C,0x64,0x64,
  0x44,0x44,0x5C,0x5C,0x60,0x60,0x3E,0x3E,
  0x00,0x00,0x0C,0x0C,0x08,0x08,0x08,0x08,
  0x3C,0x3C,0x08,0x08,0x08,0x08,0x08,0x08,
  0x00,0x00,0x1C,0x1C,0x24,0x24,0x24,0x24,
  0x3C,0x3C,0x04,0x04,0x3C,0x3C,0x00,0x00,
  0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,
  0x3C,0x3C,0x26,0x26,0x22,0x22,0x00,0x00,
  0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
  0x00,0x00,0x08,0x08,0x00,0x00,0x08,0x08,
  0x08,0x08,0x08,0x08,0x30,0x30,0x00,0x00,
  0x00,0x00,0x10,0x10,0x12,0x12,0x14,0x14,
  0x18,0x18,0x18,0x18,0x14,0x14,0x12,0x12,
  0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7C,0x7C,0x52,0x52,0x52,0x52,0x42,0x42,
  0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,
  0x78,0x78,0x44,0x44,0x44,0x44,0x44,0x44,
  0x00,0x00,0x00,0x00,0x38,0x38,0x44,0x44,
  0x44,0x44,0x44,0x44,0x38,0x38,0x00,0x00,
  0x00,0x00,0x1E,0x1E,0x12,0x12,0x12,0x12,
  0x1C,0x1C,0x10,0x10,0x10,0x10,0x00,0x00,
  0x00,0x00,0x00,0x00,0x38,0x38,0x48,0x48,
  0x48,0x48,0x38,0x38,0x08,0x08,0x08,0x08,
  0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x14,
  0x18,0x18,0x10,0x10,0x10,0x10,0x10,0x10,
  0x00,0x00,0x1C,0x1C,0x30,0x30,0x1C,0x1C,
  0x04,0x04,0x0C,0x0C,0x70,0x70,0x00,0x00,
  0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x10,0x7C,0x7C,0x10,0x10,
  0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x22,
  0x22,0x22,0x22,0x22,0x3C,0x3C,0x20,0x20,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x42,0x42,0x24,0x24,0x24,0x24,0x18,0x18,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x42,0x42,0x52,0x52,0x52,0x52,0x7C,0x7C,
  0x00,0x00,0x42,0x42,0x24,0x24,0x18,0x18,
  0x18,0x18,0x24,0x24,0x42,0x42,0x00,0x00,
  0x00,0x00,0x00,0x00,0x24,0x24,0x3C,0x3C,
  0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,
  0x00,0x00,0x00,0x00,0x3E,0x3E,0x02,0x02,
  0x04,0x04,0x18,0x18,0x20,0x20,0x3E,0x3E,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char blank[] = {
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,
	26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,

};

void main() {
	unsigned char * text = "orangeA";
	unsigned char * textb = "appleA";
	unsigned char * textc = "pizzaA";
	UINT8 temp;
	UINT8 c;
	UINT8 * metatemp = NULL;
	UINT8 * metatempc = NULL;
	set_bkg_data(0, 26, alphabet);
	set_bkg_tiles(0,0, 20, 18, blank);
	for (c = 0; *(text) != 'A'; c++) {
		temp =  *(text++) - 97;
		set_bkg_tiles(c,0, 1,1, &temp);
	}
	DISPLAY_ON;
	SHOW_BKG;
	while (1) {

		if (joypad() & J_A) {
			metatemp = textb;
			HIDE_BKG;
			waitpadup();
			set_bkg_tiles(0,0, 20, 18, blank); // reset background
			for (c = 0; *(textb) != 'A'; c++) {
				temp = *(textb++) - 97;
				set_bkg_tiles(c,0, 1,1, &temp);
			}
			textb = metatemp;
			SHOW_BKG;
		}
		if (joypad() & J_B) {
			metatempc = textc;
			HIDE_BKG;
			waitpadup();
			set_bkg_tiles(0,0, 20, 18, blank); // reset background
			for (c = 0; *(textc) != 'A'; c++) {
				temp = *(textc++) - 97;
				set_bkg_tiles(c,0, 1,1, &temp);
			}
			textc = metatempc;
			SHOW_BKG;
		}

		wait_vbl_done();
	}
}