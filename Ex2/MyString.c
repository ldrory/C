#include <stdio.h>
#include <stdlib.h>

#define CHECKS_NULL(pointer) do{ if (pointer == NULL) \
    {fprintf(stderr, "Error: NULL pointer input\n"); return NULL;} } while(0)

#define CHECKS_ALLOCATE(pointer) do{ if (pointer == NULL) \
    {fprintf(stderr, "Error: Can't allocate memory\n"); return NULL;} } while(0)


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
    MyStringP stringStruct = malloc(sizeof(struct MyString));
    CHECKS_ALLOCATE(stringStruct);

    // initalized length 0 and increase it in the while loop
    size length = 0;
    while(*(str1 + length++) != '\0');
    length--;

    // set information to struct
    stringStruct->length = length;
    stringStruct->string = malloc(sizeof(char)*length);
    CHECKS_ALLOCATE(stringStruct->string);

    for(int i=0;i<length;++i)
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
    MyStringP stringStruct = malloc(sizeof(struct MyString));
    CHECKS_ALLOCATE(stringStruct);

    stringStruct->string = malloc(sizeof(char)*length);
    CHECKS_ALLOCATE(stringStruct->string);

    stringStruct->length = length;

    // copy by value
    for(int i=0; i<length; ++i)
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
        fprintf(stderr, "Can't freeString with a NULL pointer\n");
        return;
    }

    free(str1->string);
    str1->string = NULL;
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
        fprintf(stderr, "Can't length with a NULL pointer\n");
        return -1; // return MAX int (-1) in unsigend
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
int cmpString(const MyStringP str1,const MyStringP str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        fprintf(stderr, "Can't cmpString with a NULL pointer\n");
        return 2;
    }

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;

    size length = lengthStr1 > lengthStr2 ? lengthStr2 : lengthStr1;

    for(int i=0; i<length; ++i)
    {
        // get the difference between each char
        int diff = *(str1->string + i) - *(str2->string + i);

        // if diff>0 gets 1, diff<0 gets -1, equal gets 0
        int sign = diff > 0 ? 1 : diff < 0 ? -1 : 0;

        switch (sign) {
            case 0:
                continue;
            default:
                return sign;
        }
    }

    // all char are equal, now return value by the length
    // lenStr1 == lenStr2 return 0, lenStr1 < lenStr2 return 1, lenStr1 > lenStr2 return -1.
    return lengthStr1 == lengthStr2 ? 0 : lengthStr1<lengthStr2 ? 1 : -1;

}

/**
 * concatenate the 2 Strings in to one String
 * @param str1 the first string in the result, the method will change the value of str1
 * @param str2 the second string in the result
 * @return the result of the concatenate
 */
MyStringP concatString(MyStringP str1,const MyStringP str2)
{
    CHECKS_NULL(str1);
    CHECKS_NULL(str2);

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;

    str1->string = realloc(str1->string, sizeof(char)*lengthStr1 + sizeof(char)*lengthStr2);
    CHECKS_ALLOCATE(str1->string);

    // get to the end of str1
    char* endOfStr1 = (str1->string + lengthStr1);

    for (int i = 0; i < lengthStr2; ++i)
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
MyStringP deleteCharString(MyStringP str1,const char letter)
{
    CHECKS_NULL(str1);
    CHECKS_NULL(letter);

    char* lackString = malloc(sizeof(char) * (str1->length - 1));
    CHECKS_ALLOCATE(lackString);

    // pass all text and when letter is shown, skip it
    int j =0;
    for(int i=0; i<str1->length; ++i)
    {
        if(*(str1->string + i) == letter)
        {
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
    CHECKS_NULL(str1);
    CHECKS_NULL(str2);

    // get the shorter size
    size lengthStr1 = str1->length;
    size lengthStr2 = str2->length;

    // corner case
    if (lengthStr1 == 0 || lengthStr2 == 0 || lengthStr1 < lengthStr2)
    {
        return 0;
    }

    // initial
    size count = 0;
    char* str2String = str2->string;

    // find matches
    for (int i=0; i<lengthStr1; ++i)
    {

        // if first char matches
        if (*str2String == *(str1->string + i))
        {
            int j;
            for (j = 0; j < lengthStr2; ++j)
            {
                // if it is end of the str1 and cyclic isn't on
                // break
                if (i+j == lengthStr1 && isCyclic == 0)
                {
                    break;
                }

                // if the jth char matches
                if (*(str2String + j) != *(str1->string + ((i+j) % lengthStr1) ))
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


//int main()
//{
//    char *word = "abababab";
//    MyStringP str1 = createStringFromChars(word);
//    printf("%s\n", str1->string);
//    printf("%d\n", str1->length);
//
//    char *word2 = "baba";
//    MyStringP str2 = createStringFromChars(word2);
//    printf("%s\n", str2->string);
//    printf("%d\n", str2->length);
//
//    printf("%d\n", cmpString(str1,str2));
//
//    MyStringP concat = concatString(x,y);
//
//    printf("%s\n", concat->string);
//    printf("%lu\n", concat->length);

//    MyStringP p = deleteCharString(y,'L');
//    printf("%s\n", p->string);
//    printf("%lu\n", p->length);

//    printf("\ncounts: %d\n", countSubStr(str1, str2, -3));

//}