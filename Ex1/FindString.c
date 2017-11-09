#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define READ "r"
#define SIZE_OF_LINE 256
#define ONE_FILE 1
#define NOT_FOUND NULL
#define FIRST_FILE 2
#define LINE_WITH_SEARCHWORD "%s", line
#define FILE_NAME_LINE_WITH_SEARCHWORD "%s:%s", argv[i + FIRST_FILE], line
#define NO_FILES 0
#define NO_INPUT 1
#define FAILED -1
#define OFFSET 2
#define WORD 1
#define SUCCESS 0
#define FILE_NOT_FOUND stderr, "grep: %s: No such file or directory\n", argv[i + FIRST_FILE]
/**
 * Enum:  Boolean 
 * --------------------
 * for simplify use in boolean as in other languages
 **/
typedef enum BOOLEAN
{
    FALSE = 0,
    TRUE = 1
} bool;

/**
 * Function:  checkStringInFiles 
 * --------------------
 * find a search word inside a files and print the line where it found it
 *
 *  numberOfFiles: how many files to seach in
 *  searchWord:    the word to search in every file
 *  argv[]:        the input from the user (PROGRAM_NAME, SEARCH WORD, FILE_1, ...,FILE_N)

 *  returns: void.
 **/
int checkStringInFiles(int numberOfFiles, char * searchWord, char* argv[])
{
    char line[SIZE_OF_LINE]; // change that to line size
    bool failed = FALSE;

    // for every file that the user is demand to search
    // search for the searchWord in every line in every file
    for (int i = 0; i < numberOfFiles; ++i)
    {
        // file pointer at the i=0,..,n'th file
        FILE* file = fopen(argv[i + FIRST_FILE], READ);

        if (file == NULL) 
        {
            fprintf(FILE_NOT_FOUND);
            failed = TRUE;
            continue;
        }

        while (fgets(line, sizeof(line), file)) 
        {
            char c;
            int j = 0;
            char str [SIZE_OF_LINE];
            strcpy(str, line);

            // for non-caseSensetive - every char to lower case 
            while (str[j])
            {
              c = str[j];
              str[j] = tolower(c);

              c = searchWord[j];
              searchWord[j] = tolower(c);

              j++;
            }

            // find the seatchWord in the line
            if (strstr(str, searchWord) != NOT_FOUND)
            {

                // one file print case
                if (numberOfFiles == ONE_FILE)
                {
                    printf(LINE_WITH_SEARCHWORD); 
                } 

                // more than one file print case
                else 
                {
                    printf(FILE_NAME_LINE_WITH_SEARCHWORD); 
                }
            } 


        }

        fclose(file);

    }

    if (failed == TRUE)
    {
        return FAILED;
    }

    return SUCCESS;
}


/**
 * Function:  main 
 * --------------------
 * find a search word inside a files and print the line where it found it
 *
 *  argv[]:        the input from the user (PROGRAM_NAME, SEARCH WORD, FILE_1, ...,FILE_N)
 *  argc:          the number of inputs from the user
 *
 *  returns: int, FAILED: -1 SUCCESS: non negative
 **/
int main(int argc, char* argv[])
{
    int numberOfFiles = argc - OFFSET;
    char* searchWord = argv[WORD]; 

    // if there are no file insert return -1
    // if argc is no bigger than 1 than there is no inputs
    if (numberOfFiles == NO_FILES || !(argc > NO_INPUT))
    {
        return FAILED;
    }

    // find the string in the files
    int stat = checkStringInFiles(numberOfFiles, searchWord, argv);

    if (stat == FAILED)
    {
        return FAILED;
    }

    return SUCCESS;
} 


