

/*

lcc -c -o ROM_banking.o ROM_banking.c
lcc -wf-ba0 -c -o b0.o b0.c
lcc -wf-bo1 -wf-ba1 -c -o b1.o b1.c
lcc -wf-bo2 -wf-ba2 -c -o b2.o b2.c
lcc -wf-bo3 -wf-ba3 -c -o b3.o b3.c
lcc -Wl-yt2 -Wl-yo4 -Wl-ya4 -o ROM_banking.gb ROM_banking.o b0.o b1.o b2.o b3.o


-wf-ba0 (RAM bank 0), -wf-bax, where x specifies RAM bank

-wf-bo1 (ROM bank 1) -wf-box, where x specifies ROM bank

use in order ROM bank theren RAM bank as above.

-Wl-yt2 specifies MCB type. Your options are:

0 : ROM ONLY
1 : ROM+MBC1
2 : ROM+MBC1+RAM
3 : ROM+MBC1+RAM+BATTERY
5 : ROM+MBC2
6 : ROM+MBC2+BATTERY

we're using -Wl-yt2 = ROM+MBC1+RAM in this example.

-Wl-yo4 -Wl-ya4 specifie how many ROM and RAM banks are used.
Not sure if bank_fixed is ROM zero and if that's why -Wl-yo4?


*/

#include <gb/gb.h>
#include <stdio.h>

int var_internal; // Internal RAM
extern int var_0; // External RAM bank 0
extern int var_1; // External RAM bank 1
extern int var_2; // External RAM bank 2
extern int var_3; // External RAM bank 3

void bank_1(); // ROM bank 1
void bank_2(); // ROM bank 2
void bank_3(); // ROM bank 3

void bank_fixed() { // Presume this is ROM 0?
	puts("I'm in fixed ROM");
	puts("  ");
}

void main() {
	puts("Program start");
	puts("  ");

	ENABLE_RAM_MBC1; // Enable ROM banking
	var_internal = 1;

	SWITCH_RAM_MBC1(0); // Switch RAM bank to 0, assign value to var_0
	var_0 = 2;
	SWITCH_RAM_MBC1(1); // Switch RAM bank to 1, assign value to var_1
	var_1 = 3;
	SWITCH_RAM_MBC1(2); // Switch to RAM bank 2, assign value to var_2
	var_2 = 4;
	SWITCH_RAM_MBC1(3); // Switch to RAM bank 3, assign value to var_3
	var_3 = 5;

	bank_fixed(); 

	SWITCH_ROM_MBC1(1); // Switch to ROM bank 1 and call function from there
	bank_1();
	SWITCH_ROM_MBC1(2); // Switch to ROM bank 2 and call function from there
	bank_2();
	SWITCH_ROM_MBC1(3); // Switch to ROM bank 3 and call function from there
	bank_3();
	puts("  ");
	printf("var_internal is %u\n", var_internal);
	SWITCH_RAM_MBC1(0);
	printf("var_0 is %u\n", var_0);
	SWITCH_RAM_MBC1(1);
	printf("var_1 is %u\n", var_1);
	SWITCH_RAM_MBC1(2);
	printf("var_2 is %u\n", var_2);
	SWITCH_RAM_MBC1(3);
	printf("var_3 is %u\n", var_3);

	puts("End Program");
}