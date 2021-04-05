all:	mystruct deque

mystruct:	mystruct.c
	gcc -Wall $< -o $@

deque:	deque.c
	gcc -Wall $< -o $@

clean:
	rm -f mystruct deque *.o core *~
