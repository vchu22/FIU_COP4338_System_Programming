CC = gcc
FLAGS = -Wall -Wextra -std=c99 -pedantic
FNAME = funcact

program: funcact funcact2

funcact: funcact.c encode.h encode.c
	$(CC) $(FLAGS) encode.c -o $(FNAME).o $(FNAME).c

funcact2: funcact2.c decode.h decode.c
	$(CC) $(FLAGS) decode.c -o $(FNAME)2.o $(FNAME)2.c

clean:
	rm *.o *.err
