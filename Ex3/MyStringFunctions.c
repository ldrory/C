#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief clone a string
 */
void* cloneStr(const void*  s)
{
	char* l = (char*) s;

	// allocate memory for the string cloned
	char* cloned = malloc(strlen(l)+1);
	cloned = memcpy(cloned, l, strlen(l)+1);

	return (void*)cloned;
}

/**
 * @brief free an string
 */
void freeStr(void* s)
{
	free(s);
}


/**
 * @brief hash value of key for HashTable with size tableSize
 *  assuming key pointer to string
 * @return number between 0-(tableSize-1)
 */
int strFcn (const void*  s, size_t tableSize)
{

	// initialiez ascii sum to be 0
	int asciiSum = 0;

	for (unsigned int i = 0; i < strlen((char*)s); ++i)
	{
		asciiSum += *((char*)s + i);
	}
	return asciiSum % tableSize;
}

/**
 * @brief print a string
 *  assuming key pointer to string
 * 
 */
void strPrint (const void*  s)
{
	printf("%s", ((char*)s));
}

/**
 *  strCompare - pointer to int comparison function:
 * @brief compare 2 strings
 *   returns zero int if both strings are equal, otherwise
 *   returns non-zero.
 */
int strCompare (const void* comp1, const void* comp2)
{
	return strcmp((char*) comp1, (char*) comp2);
}