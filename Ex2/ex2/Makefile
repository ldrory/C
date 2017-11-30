CFLAGS = -Wextra -Wall -Wvla -std=c99 -c
LDFLAGS = -lm
CC = gcc
STYLE = ~labc/www/codingStyleCheck
presubmit = ~labc/www/ex2/presubmit_ex2


make: MyString.o
	ar rcs MyString.a MyString.o

MyString.o: MyString.c MyString.h
	$(CC) $(CFLAGS) $(LDFLAGS) MyString.c -o MyString.o

BuggyLinkedList: BuggyLinkedList.o
	 $(CC) BuggyLinkedList.o -o BuggyLinkedList
	./BuggyLinkedList

BuggyLinkedList.o: BuggyLinkedList.c
	$(CC) $(CFLAGS) $(LDFLAGS) BuggyLinkedList.c -o BuggyLinkedList.o

tar:
	tar cvf ex2.tar MyString.c BuggyLinkedList.c Makefile

clean:
	rm -f ex2.tar *.o BuggyLinkedList MyString.a

style:
	$(STYLE) MyString.c
	$(STYLE) BuggyLinkedList.c

presubmit:
	$(presubmit) ex2.tar

.PHONY: make tar clean style presubmit
