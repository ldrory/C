/**
(a) the algorithm i used based on double converting
    (originalNumber)_base -> (originalNumber)_10 -> (originalNumber)_newBase
(b) complexity of my algorithm is: 
        number to decimal - O(n) when n is the number of digits
        decimal to newBase - O(Log_base(k))) number of itaration is
                                        log of k - is the number in decemal
                                        we know k <= n

        therefore => O(n) + O(Log_base(n))) ==> O(n)
**/
#include <stdio.h>
#include <math.h>

#define SIZE_OF_LINE 13
#define MAX 32
#define ZERO_CONVERT 0
#define ZERO_CASE "0\n"
#define NUMBER__AT_NEW_BASE "%c", digits[i-j-1] + '0'
#define ENTER "\n"
#define DECEMAL_BASE 10
#define INVALID "invalid!!\n"
#define FAILED -1
#define DECEMAL_NUMBER "%d\n", decemal
#define USAGE_INPUT "%hu %hu %d"
#define USAGE "Usage: <original base> <new base> <number in original base> \n"

/**
 * Function:  decimalToBase 
 * --------------------
 * convert decimal to base
 *
 *  decemal:    the number @ decimal conver to new base
 *  newBase:    the new base to convert to
 *
 *  returns:    void
 **/
void decimalToBase(unsigned int decemal, unsigned short newBase)
{

    char digits[MAX];

    // 0 is 0 in every base
    if (decemal == ZERO_CONVERT)
    {
        printf(ZERO_CASE);
        return;
    }

    if (newBase == DECEMAL_BASE)
    {
        printf(DECEMAL_NUMBER);
        return;
    }

    int i = 0;

    // change every digit to new base
    while(decemal)
    {
        digits[i++] = decemal % newBase;
        decemal /= newBase;
    }

    // print the digits in new base
    for (int j = 0; j < i; j++)
    {
        // print from END TO START [defualt representation]
        printf(NUMBER__AT_NEW_BASE);
    }
    printf(ENTER);
    return;
}


/**
 * Function:  convertToDecemal 
 * --------------------
 * convert number to decemal
 *
 *  numberInOriginalBase:    the number to convert
 *  originalBase:            the original base of number
 *
 *  returns: the number @ decemal base
 **/
int convertToDecemal(unsigned int numberInOriginalBase, 
                     unsigned int originalBase)
    
{
    int decemal = 0;
    unsigned short currentBit;
    int i = 0;

    while( numberInOriginalBase != ZERO_CONVERT)
    {
        if (originalBase == DECEMAL_BASE)
        {
            decemal = numberInOriginalBase;
            break;
        }

        currentBit = numberInOriginalBase % DECEMAL_BASE;

        // check invalid base case
        if (!(currentBit < originalBase))
        {
            printf(INVALID);
            return FAILED;
        }

        decemal += currentBit * (int)pow(originalBase, i++);

        numberInOriginalBase /= DECEMAL_BASE;
        //i++;
    }

    return decemal;
}

/**
 * Function:  convertToDecemal 
 * --------------------
 * convert number @ some base to number @ new base
 *
 *
 *  returns: FAILED: -1 SUCCESSES: other than -1
 **/
int main()
{
    char line[SIZE_OF_LINE];            // line - is an array size of 13*1 bytes
    unsigned short originalBase;        // originalBase - unsigned shot - holds numbers between 2-10
    unsigned short newBase;             // newBase - unsigned short - holds numbers between 2-10
    unsigned int numberInOriginalBase;  // numberInOriginalBase - unsigned int - max 6 digits

    printf(USAGE);
    
    // read input from the user onlt the size of line[13] - so we wont get overflow
    if (fgets(line, sizeof(line), stdin))
    {
        // scan the input to a pattern - 
        // sccanf is saftly used because it read only from the fgets buffer
        if (sscanf(line, USAGE_INPUT, &originalBase, &newBase, &numberInOriginalBase))
        {
            int decemal = convertToDecemal(numberInOriginalBase, originalBase);
            
            // failed case
            if (decemal == FAILED)
            {
                return FAILED;
            }

            // change decimal to new base
            decimalToBase(decemal, newBase);

        }


    } 

}
