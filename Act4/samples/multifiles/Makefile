all: helloworld

helloworld: helloworld.o mystdio.o
	gcc helloworld.o mystdio.o -o helloworld

helloworld.o: helloworld.c
	gcc -c helloworld.c -o helloworld.o

mystdio.o: mystdio.c
	gcc -c mystdio.c -o mystdio.o

clean:
	rm -f helloworld.o mystdio.o helloworld core *~ 

