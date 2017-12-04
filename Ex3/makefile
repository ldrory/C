CC = gcc
CFLAGS = -g -Wextra -Wall -Wvla -std=c99
CPPFLAGS = -DNDEBUG
VALFLAGS = --leak-check=full --undef-value-errors=yes --track-origins=yes \
 			--show-reachable=yes --show-mismatched-frees=yes

.DEFAULT_GOAL = default

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
include $(DEPS)

all: HashIntSearch HashStrSearch

default: HashIntSearch
	./$< 1 0

HashIntSearch: HashIntSearch.o MyIntFunctions.o libgenericHashTable.a
HashStrSearch: HashStrSearch.o MyStringFunctions.o libgenericHashTable.a
%: %.o
	$(CC) -o $@ -L./ $^

GenericHashTable: libgenericHashTable.a
libgenericHashTable.a: GenericHashTable.o TableErrorHandle.o
	ar -rcs $@ $^

%.d: %.c
	$(CC) -MM $< > $@;\
	sed -i 's/\($*\.o\):/\1 $@:/g' $@

$(OBJS): %.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

val: valdbgInt valdbgStr
valdbg%: prog%
	valgrind $(VALFLAGS) --log-file='$@' ./$< 5 3 > $*.out

tar: ex3.tar
ex3.tar: GenericHashTable.c MyIntFunctions.c MyStringFunctions.c \
	MyIntFunctions.h MyStringFunctions.h Key.h makefile
	tar -cvf $@ $^

clean:
	rm -rf *.o *.a ~* prog* *.out valdbg* *.d

.PHONY: clean all tar val default GenericHashTable
