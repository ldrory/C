#include <stdio.h>
#include <stdlib.h>

// TODO: change everything to cameCase;

/**
 * the MyString struct
 * */
struct MyString
{
    char* string;
    unsigned long length;
};

typedef struct MyString* MyStringP;

typedef unsigned long size_t;


MyStringP createStringFromChars(const char* str1)
{
    MyStringP stringStruct = malloc(sizeof(struct MyString));

    // initalized length -1 and increase it in the while loop
    size_t length = -1;

    while(*(str1 + ++length) != '\0');


    stringStruct->length = length;
    stringStruct->string = malloc(sizeof(char)*length);

    for(int i=0;i<length;++i)
    {
        *(stringStruct->string + i) = *str1++;
    }
    return stringStruct;
}


MyStringP createStringFromString(const MyStringP str1)
{
    // length of the string
    size_t length = str1->length;

    // allocate memory for the struct and string pointer
    MyStringP stringStruct = malloc(sizeof(struct MyString));
    stringStruct->string = malloc(sizeof(char)*length);

    stringStruct->length = length;

    // for each char copy by value
    for(int i=0; i<length; ++i)
    {
        *(stringStruct->string + i) = *(str1->string + i);
    }

    return stringStruct;
}


void freeString(MyStringP str1)
{
    free(str1->string);
    str1->string = NULL;
}


unsigned int lengthString(const MyStringP str1)
{
    return str1->length;
}


const char* cString(const MyStringP str1)
{
    return str1->string;
}


int cmpString(const MyStringP str1,const MyStringP str2)
{
    // get the shorter size
    size_t length_str1 = str1->length;
    size_t length_str2 = str2->length;

    size_t length = length_str1 > length_str2 ? length_str2 : length_str1;

    for(int i=0; i<length; ++i)
    {
        int diff = *(str1->string + i) - *(str2->string + i);
        int sign = diff > 0 ? 1 : diff < 0 ? -1 : 0;

        switch (sign) {
            case 0:
                continue;
            default:
                return sign;
        }

    }
    return 0;
}


MyStringP concatString(MyStringP str1,const MyStringP str2)
{
    // get the shorter size
    size_t length_str1 = str1->length;
    size_t length_str2 = str2->length;

    str1->string = realloc(str1->string, sizeof(char)*length_str1 + sizeof(char)*length_str2);

    // get to the end of str1
    char* end_of_str1 = (str1->string + length_str1);

    for (int i = 0; i < length_str2; ++i)
    {
        *(end_of_str1 + i) = *(str2->string + i);
    }

    str1->length = length_str1 + length_str2;

    return str1;
}


MyStringP deleteCharString(MyStringP str1,const char letter)
{
    char* lackString = malloc(sizeof(char) * (str1->length - 1));

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


unsigned int countSubStr(const MyStringP str1, const MyStringP str2, int isCyclic)
{
    // get the shorter size
    size_t length_str1 = str1->length;
    size_t length_str2 = str2->length;


    if (length_str1 == 0 || length_str2 == 0 || length_str1 < length_str2)
    {
        return 0;
    }

    int count = 0;

    char* countP = str2->string;

    for (int i=0; i<length_str1; ++i)
    {

        // if first char matches
        if (*countP == *(str1->string + i))
        {
            int j;
            for (j = 0; j < length_str2; ++j)
            {

                // if the jth char matches
                if (*(countP + j) != *(str1->string + i + j))
                {
                    break;
                }
            }

            if (j == length_str2)
            {
                count++;
            }

        }
    }

    return count;
}


int main()
{
//    printf("fuck it?");
    char *word = "Hey I am dog and i am a ddog too, what up dogg";
    MyStringP y = createStringFromChars(word);
    printf("%s\n", y->string);
    printf("%lu\n", y->length);
//
    char *word2 = "dog";
    MyStringP x = createStringFromChars(word2);
    printf("%s\n", x->string);
    printf("%lu\n", x->length);
//
//    printf("%d\n", cmpString(x,y));
//
//    MyStringP concat = concatString(x,y);
//
//    printf("%s\n", concat->string);
//    printf("%lu\n", concat->length);

//    MyStringP p = deleteCharString(y,'L');
//    printf("%s\n", p->string);
//    printf("%lu\n", p->length);

    printf("%d\n", countSubStr(y, x, 0));

}