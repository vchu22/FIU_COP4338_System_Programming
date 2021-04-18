P1 = thread1
P2 = thread2

program : $(P1) $(P2)

$(P1) : $(P1).c
	gcc -o $(P1) $(P1).c -lpthread

$(P2) : $(P2).c
	gcc -o $(P2) $(P2).c -lpthread

clean:
	rm $(P1) $(P2)
