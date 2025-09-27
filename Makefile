FLAGS=-Wall -Wextra -Wpedantic
LIB=lib/da.h

example: da.c $(LIB) examples/example.c
	gcc -o da_example da.c examples/example.c 
