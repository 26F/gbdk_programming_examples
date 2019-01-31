lcc -c -o ROM_banking.o ROM_banking.c
lcc -wf-ba0 -c -o b0.o b0.c
lcc -wf-bo1 -wf-ba1 -c -o b1.o b1.c
lcc -wf-bo2 -wf-ba2 -c -o b2.o b2.c
lcc -wf-bo3 -wf-ba3 -c -o b3.o b3.c
lcc -Wl-yt2 -Wl-yo4 -Wl-ya4 -o ROM_banking.gb ROM_banking.o b0.o b1.o b2.o b3.o

