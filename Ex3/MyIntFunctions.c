#include <stdio.h>
#include <stdlib.h>

#define EQUAL 0
#define NOT_EQUAL 1

/**
 * @brief clone an int
 */
void* cloneInt(const void* i)
{
	// allocate memory for the int cloned
	int* cloned = (int*) malloc(sizeof(int));
	*cloned = *((int*) i);
	return (void*) cloned;
}

/**
 * @brief free an int
 */
void freeInt( void* i)
{
	// free the i pointer to int
	free(i);
}

/**
 * @brief hash value of key for HashTable with size tableSize
 *  assuming key pointer to an int
 * @return number between 0-(tableSize-1)

 */
int intFcn (const void* key, size_t tableSize)
{
    int posKey = *(int*)key;
	while(posKey < 0) { posKey += tableSize; };
	return (posKey % tableSize);
}

/**
 * @brief print a string
 *  assuming key pointer to an int
 * 
 */
void intPrint (const void* key)
{
	// print the int
	printf("%d", *((int*)key));
}

/**
 *  intCompare - pointer to int comparison function:
 * @brief compare 2 ints
 *   returns zero int if both ints are equal, otherwise
 *   returns non-zero.
 * 
 */
int intCompare (const void* comp1, const void* comp2)
 {
 	return *(int*)comp1 == *(int*)comp2 ? EQUAL : NOT_EQUAL;
 }