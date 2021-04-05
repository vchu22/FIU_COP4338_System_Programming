all: filecopy unixfilecopy

filecopy: filecopy.c
	gcc -Wall filecopy.c -o filecopy

unixfilecopy: unixfilecopy.c
	gcc -Wall unixfilecopy.c -o unixfilecopy

clean:
	$(RM) filecopy unixfilecopy
