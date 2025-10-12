FLAGS=-Wall -Wextra -Wpedantic
LIB=lib/da.h
SRC=src/da.c src/da_util.c

example: $(SRC) $(LIB) examples/example.c
	gcc -o da_example $(SRC) examples/example.c 

# Ignore this
test: $(SRC) $(LIB) testing.c
	gcc -o test $(SRC) testing.c
