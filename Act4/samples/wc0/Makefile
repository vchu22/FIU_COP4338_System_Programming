all:	wc0

wc0:	wc0.o
	gcc wc0.o -o wc0

wc0.o:	wc0.c
	gcc -Wall -c wc0.c -o wc0.o

clean:
	rm -f wc0 wc0.o core *~
