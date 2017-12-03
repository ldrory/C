CC = gcc
CFLAGS = -Wextra -Wall -Wvla -std=c99


prog: HashIntSearch.o GenericHashTable.o MyIntFunctions.o TableErrorHandle.o
	$(CC) -o prog HashIntSearch.o GenericHashTable.o MyIntFunctions.o TableErrorHandle.o

HashIntSearch.o: HashIntSearch.c GenericHashTable.h MyIntFunctions.h
	$(CC) $(CFLAGS) -c HashIntSearch.c

GenericHashTable.o: GenericHashTable.c GenericHashTable.h TableErrorHandle.h
	$(CC) $(CFLAGS) -c GenericHashTable.c

MyIntFunctions.o: MyIntFunctions.c Key.h
	$(CC) $(CFLAGS) -c MyIntFunctions.c

TableErrorHandle.o: TableErrorHandle.c TableErrorHandle.h
	$(CC) $(CFLAGS) -c TableErrorHandle.c
