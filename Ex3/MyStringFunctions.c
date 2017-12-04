#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQUAL 0
#define NOT_EQUAL 1


/**
 * @brief clone a string
 */
void* cloneStr(const void*  s)
{
    // let l be the string
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
    s = NULL;
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

    // hash func is to sum all the ascii char
	for (unsigned int i = 0; i < strlen((char*)s); ++i)
	{
		asciiSum += *((char*)s + i);
	}
	return (int)(asciiSum % tableSize);
}

/**
 * @brief print a string
 *  assuming key pointer to string
 * 
 */
void strPrint (const void*  s)
{
    // print string
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
    if (comp1 == NULL || comp2 == NULL)
    {
        return NOT_EQUAL;
    }
	return strcmp((char*) comp1, (char*) comp2);
}