CC = gcc

bin/customShell : src/shell.c
	gcc -o bin/customShell src/shell.c

clean :
	rm *.o bin/customShell
