all:	args

args:	args.o
	gcc args.o -o args

args.o:	args.c
	gcc -Wall -c args.c -o args.o

clean:
	rm -f args args.o core *~
