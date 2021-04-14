P1 = writer
P2 = updater
P3 = reader

program : $(P1) $(P2)

$(P1) : $(P1).c
	gcc -o $(P1) $(P1).c

$(P2) : $(P2).c
	gcc -o $(P2) $(P2).c

$(P3) : $(P3).c
	gcc -o $(P3) $(P3).c

clean:
	rm $(P1) $(P2) $(P3)
