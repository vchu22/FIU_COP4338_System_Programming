CC = gcc

all:	mytest yourtest

mytest:	mytest.o libmylib.a
	$(CC) mytest.o -o $@ -L. -lmylib

libmylib.a:	myatoi.o myprintf.o
	ar -cvq libmylib.a myatoi.o myprintf.o
	ranlib libmylib.a

myatoi.o:	myatoi.c mylib.h
	$(CC) -Wall -c $< -o $@

myprintf.o:	myprintf.c mylib.h
	$(CC) -Wall -c $< -o $@

yourtest:	mytest.o libyourlib.so
	$(CC) mytest.o -o $@ -L. -lyourlib

libyourlib.so:	youratoi.o yourprintf.o
	$(CC) -shared -o $@ youratoi.o yourprintf.o
#	$(CC) -shared -Wl,-soname,libyourlib.so.1 -o $@ youratoi.o yourprintf.o

youratoi.o:	myatoi.c mylib.h
	$(CC) -Wall -fPIC -c $< -o $@

yourprintf.o:	myprintf.c mylib.h
	$(CC) -Wall -fPIC -c $< -o $@

mytest.o:	mytest.c mylib.h
	$(CC) -Wall -c $< -o $@

clean:
	$(RM) mytest yourtest
	$(RM) *.o *.a *.so
