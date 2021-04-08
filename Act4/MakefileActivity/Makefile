CC = gcc
FLAGS = -Wall
CFLAG = -c
FNAME = funcact

EN = encode
DE = decode

program: $(FNAME) $(FNAME)2 clean

$(FNAME): $(FNAME).c $(EN)
	$(CC) $(FLAGS) $(EN).o -o $(FNAME) $(FNAME).c

$(EN): $(EN).h $(EN).c
	$(CC) $(CFLAG) $(EN).c

$(FNAME)2: $(FNAME)2.c $(DE)
	$(CC) $(FLAGS) $(DE).o -o $(FNAME)2 $(FNAME)2.c

$(DE): $(DE).h $(DE).c
	$(CC) $(CFLAG) $(DE).c

clean:
	rm *.o
