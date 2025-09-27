FLAGS=-Wall -Wextra -Wpedantic
LIB=lib/da.h lib/da_util.h
SRC=da.c da_util.c

example: $(SRC) $(LIB) examples/example.c 
	gcc -o da_example $(SRC) examples/example.c 
