P1 = cptr
P2 = $(P1)2

program : $(P1) $(P2)

$(P1) : $(P1).c
	gcc -o $(P1) $(P1).c

$(P2) : $(P2).c pointPrint.h pointPrint.c
	gcc -Wall pointPrint.c -o $(P2) $(P2).c

clean:
	rm $(P1) $(P2)