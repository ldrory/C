#include <stdio.h>
#include <stdlib.h>

#define CHECKS_NULL(pointer) do{ if (pointer == NULL) \
    { fprintf(stderr, "Error: NULL pointer input\n"); return NULL; } } while(0)

#define CHECKS_ALLOCATE(pointer) do{ if (pointer == NULL) \
    {fprintf(stderr, "Error: Can't allocate memory\n"); return NULL; } } while(0)

#define NULL_TERMI '\0'
#define CALIB 1
#define NULL_ERROR "Can't freeString with a NULL pointer\n"
#define ERROR_M -1
#define _ERROR_ -2
#define ERROR_ZERO 0
#define EQUAL 0
#define STR1 1
#define STR2 -1


/**
 * unsigned int is the size
 * represent positive number
 * (length, count ,etc..)
 * */
typedef unsigned int size;

/**
 * the MyString struct
 * */
struct MyString
{
    char* string;  // holds the string
    size length;  // hold the length of the string
};

/**
 * the MyString struct
 * */
typedef struct MyString* MyStringP;

/**
 * allocates a new String containing the str1 char*
 * @param str1 a char*
 * @return a new MyString * struct contaning str1
 */
MyStringP createStringFromChars(const char* str1)
{
    // if pointer is null return null & Error message
    CHECKS_NULL(str1);

    // get memory for the struct we build
    MyStringP stringStruct = (MyStringP)malloc(sizeof(struct MyString));
    CHECKS_ALLOCATE(stringStruct);

    // initalized length 0 and increase it in the while loop
    size length = 0;
    while(*(str1 + length++) != NULL_TERMI);
    length--;

    // set information to struct
    stringStruct->length = length;
    stringStruct->string = (char*)malloc(sizeof(char)*(length + CALIB));
    CHECKS_ALLOCATE(stringStruct->string);

    // copy char by char to string in struct
    for(size i = 0; i<length; ++i)
    {
        *(stringStruct->string + i) = *str1++;
    }
    return stringStruct;
}

/**
 * allocates a new String which is a copy of str1
 * @param str1 a String
 * @return a copy of str1
 */
MyStringP createStringFromString(const MyStringP str1)
{
    // if pointer is null return null & Error message
    CHECKS_NULL(str1);

    // length of the string
    size length = str1->length;

    // allocate memory for the struct and string pointer
    MyStringP stringStruct = (MyStringP) malloc(sizeof(struct MyString));
    CHECKS_ALLOCATE(stringStruct);

    stringStruct->string = (char*) malloc(sizeof(char)*length);
    CHECKS_ALLOCATE(stringStruct->string);

    stringStruct->length = length;

    // copy by value
    for(size i = 0; i<length; ++i)
    {
        *(stringStruct->string + i) = *(str1->string + i);
    }

    return stringStruct;
}

/**
 * frees the allocated memory given to the struct
 * @param str1 the string to free
 */
void freeString(MyStringP str1)
{
    if (str1 == NULL)
    {
        fprintf(stderr, NULL_ERROR);
        return;
    }
    // free the string pointer
    free(str1->string);
    str1->string = NULL;

    // free the struct pointer
    free(str1);
    str1 = NULL;
}

/**
 * returns the lenght of the given String
 * @param str1 - the string
 * @return lenght of str1
 */
size lengthString(const MyStringP str1)
{
    if (str1 == NULL)
    {
        fprintf(stderr, NULL_ERROR);
        return ERROR_M; // return MAX int (-1) in unsigend
                   // for representing an error
    }

    return str1->length;
}

/**
 * returns the value of the given String
 * @param str1 - the string
 * @return the content of str1
 */
const char* cString(const MyStringP str1)
{
    CHECKS_NULL(str1);
    return str1->string;
}

/**
 * compares the 2 Strings by this logic:
 * compares the 2 strings by the first unmatched char.
 *
 * @param str1 the first string to compare
 * @param str2 the second string to compare
 * @return
 * 1 if the ASCII value of first unmatched character is greater in str1 then str2.
 * 0 if both strings are identical (equal)
 * -1 if the ASCII value of first unmatched character is less in str1 then str2.
 */
int cmpString(const MyStringP str1, const MyStringP str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        fprintf(stderr, NULL_ERROR);
        return _ERROR_;
    }

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;

    size length = lengthStr1 > lengthStr2 ? lengthStr2 : lengthStr1;

    for(size i = 0; i<length; ++i)
    {
        // get the difference between each char
        int diff = *(str1->string + i) - *(str2->string + i);
        // if diff>0 gets 1, diff<0 gets -1, equal gets 0
        int sign = diff > 0 ? STR1 : diff < 0 ? STR2 : EQUAL;

        switch (sign) 
        {
            case EQUAL:
                continue;
            default:
                return sign;
        }
    }

    // all char are equal, now return value by the length
    // lenStr1 == lenStr2 return 0, lenStr1 < lenStr2 return -1, lenStr1 > lenStr2 return 1.
    return lengthStr1 == lengthStr2 ? EQUAL : lengthStr1<lengthStr2 ? STR2 : STR1;

}

/**
 * concatenate the 2 Strings in to one String
 * @param str1 the first string in the result, the method will change the value of str1
 * @param str2 the second string in the result
 * @return the result of the concatenate
 */
MyStringP concatString(MyStringP str1, const MyStringP str2)
{
    CHECKS_NULL(str1);
    CHECKS_NULL(str2);

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;
    size resLen =  lengthStr1 + lengthStr2 + CALIB;

    str1->string = realloc(str1->string, (size) resLen);
    CHECKS_ALLOCATE(str1->string);

    // get to the end of str1
    char* endOfStr1 = (str1->string + lengthStr1);

    size i;
    for ( i = 0; i < lengthStr2; ++i)
    {
        *(endOfStr1 + i) = *(str2->string + i);
    }

    str1->length = lengthStr1 + lengthStr2;

    return str1;
}

/**
 * deletes a certain char from the String
 * @param str1 the string, changes his value according to the result
 * @param letter the letter to delete from the String
 * @return the result.
 */
MyStringP deleteCharString(MyStringP str1, const char letter)
{
    CHECKS_NULL(str1);

    char* lackString = (char*)calloc(sizeof(char), (str1->length + CALIB));
    CHECKS_ALLOCATE(lackString);

    // pass all text and when letter is shown, skip it
    size j = 0;
    size del = 0;
    size i;
    for(i = 0; i<str1->length; ++i)
    {
        if(*(str1->string + i) == letter)
        {
            del++;
            continue;
        }
        else
        {
            *(lackString + j) = *(str1->string + i);
            j++;
        }
    }

    free(str1->string);
    str1->string = lackString;
    str1->length = str1->length - del;
    return str1;
}

/**
 * Counts the amount of str1 substrings that are equal to str2.
 * In case one (or two) of the strings is empty- returns 0.
 * @str1 - the string
 * @str2 -  the substring
 * @isCycic != 0 - search also for cyclic appearnce
 * @return number appearance of str2 as substring of str1
 */
size countSubStr(const MyStringP str1, const MyStringP str2, int isCyclic)
{
    if (str1 == NULL || str2 == NULL)
    {
        fprintf(stderr, NULL_ERROR);
        return ERROR_ZERO;
    }

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;

    // corner case
    if (lengthStr1 == 0 || lengthStr2 == 0)
    {
        return 0;
    }

    // initial
    size count = 0;
    char* str2String = str2->string;

    // find matches
    size i;
    for (i = 0; i<lengthStr1; ++i)
    {

        // if first char matches
        if (*str2String == *(str1->string + i))
        {
            size j;
            for (j = 0; j < lengthStr2; ++j)
            {
                // if it is end of the str1 and cyclic isn't on
                // break
                if (i + j == lengthStr1 && isCyclic == 0)
                {
                    break;
                }

                // if the jth char matches
                if (*(str2String + j) != *(str1->string + ((i + j) % lengthStr1) ))
                {
                    break;
                }


            }

            // if every char is matches then count++
            if (j == lengthStr2)
            {
                count++;
            }

        }
    }

    return count;
}
