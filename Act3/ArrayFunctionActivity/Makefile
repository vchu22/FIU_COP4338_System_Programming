program : array1 arrayname2 funcact funcact2

array1 : array1.c
	gcc -o array1 array1.c

arrayname2 : arrayname2.c
	gcc -o arrayname2 arrayname2.c

funcact : funcact.c encode.h encodecode.c
	gcc -Wall -Wextra -std=c99 -pedantic encodecode.c -o funcact funcact.c

funcact2 : funcact2.c encode.h encodecode.c
	gcc -Wall -Wextra -std=c99 -pedantic encodecode.c -o funcact2 funcact2.c
