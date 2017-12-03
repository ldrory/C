CC = gcc
CFLAGS = -g -Wextra -Wall -Wvla -std=c99
VALFLAGS = --leak-check=full --undef-value-errors=yes --track-origins=yes --show-reachable=yes --show-mismatched-frees=yes

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

val: valdbgInt valdbgStr
valdbg%: prog%
	valgrind $(VALFLAGS) --log-file='$@' ./$< 5 3 > $*.out

tar: ex3.tar
ex3.tar: HashIntSearch.c HashStrSearch.c GenericHashTable.c

clean:
	rm -rf *.o *.a ~* prog* *.out valdbg*

.PHONY: clean all tar val