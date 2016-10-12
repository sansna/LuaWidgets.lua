all:
	gcc -Wall -shared -fPIC -o part.so -llua part.c
