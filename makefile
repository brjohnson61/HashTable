CC=gcc
CFLAGS=-Wall -I -ggdb -g

all: DisplayTable.o DataPair.o HashTable.o
	$(CC) -o display DisplayTable.c DataPair.c HashTable.c $(CFLAGS)

.PHONY: clean
.PHONY: run

clean:
	rm *.o display

run:
	./display