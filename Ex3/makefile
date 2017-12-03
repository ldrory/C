CC = gcc
CFLAGS = -Wextra -Wall -Wvla -std=c99

all: progInt progStr

progInt: HashIntSearch.o GenericHashTable.o MyIntFunctions.o TableErrorHandle.o
	$(CC) -o $@ $^

progStr: HashStrSearch.o GenericHashTable.o MyStringFunctions.o TableErrorHandle.o
	$(CC) -o $@ $^

HashIntSearch.o: HashIntSearch.c GenericHashTable.h MyIntFunctions.h
HashStrSearch.o: HashStrSearch.c GenericHashTable.h MyStringFunctions.h
GenericHashTable.o: GenericHashTable.c GenericHashTable.h TableErrorHandle.h
MyIntFunctions.o: MyIntFunctions.c Key.h
TableErrorHandle.o: TableErrorHandle.c TableErrorHandle.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

tar: ex3.tar
ex3.tar: HashIntSearch.c HashStrSearch.c GenericHashTable.c

clean:
	rm -rf *.o *.a ~* Prog*

.PHONY: clean all tar