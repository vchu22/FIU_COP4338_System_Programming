all:	sizeof

sizeof:	sizeof.o
	gcc sizeof.o -o sizeof

sizeof.o:	sizeof.c
	gcc -c sizeof.c -o sizeof.o

clean:
	rm -f sizeof sizeof.o core *~
