CC=gcc
src=./src/main.c ./src/slist.c ./src/node.c
include=./include/node.h ./include/slist.h
flags=-Wall -Werror
out=./bin/data-structures

all:
	$(CC) $(src) $(include) $(flags) -o $(out)

run:
	$(out)
