#include <stdio.h>
#include <stdlib.h>
#include "GenericHashTable.h"
#include "TableErrorHandle.h"


#define CHECK_IF_NULL(pointer, error) do{ if (pointer == NULL) \
    { reportError(GENERAL_ERROR); return error; } } while(0)

#define CHECK_ALLOCATION(pointer, error) do{ if (pointer == NULL) \
    { reportError(MEM_OUT); return error; } } while(0)

#define EMPTY 0
#define NON_EMPTY 1
#define INITIALIZED_VALUE 1
#define RETURN_0_IF_NULL 0
#define EQUAL 0
#define NOT_EQUAL 1
#define SUCCESS 1


typedef void *DataP;
typedef struct Table *TableP;
typedef struct Object *ObjectP;
typedef const void *ConstKeyP;

static void expandTable(TableP table);

static ObjectP *mallocObjectArr(size_t size);

typedef struct Table
{
    // element that discribe the size
    size_t origSize;
    size_t size;
    int d;

    // pointer to array of objectP
    ObjectP* object;

    // pointer to functions
    CloneKeyFcn cloneKey;
    FreeKeyFcn freeKey;
    HashFcn hfun;
    PrintKeyFcn printKeyFun;
    PrintDataFcn printDataFun;
    ComparisonFcn fcomp;

} Table;

typedef struct Object
{
    // holds the key and the data
    DataP data;
    DataP key;
} Object;


/**
 * @brief Allocate memory for a hash table with which uses the given functions.
 * tableSize is the number of cells in the hash table.
 * If run out of memory, free all the memory that was already allocated by the function, 
 * report error MEM_OUT to the standard error and return NULL.
 */
TableP createTable(size_t tableSize, CloneKeyFcn cloneKey, FreeKeyFcn freeKey, HashFcn hfun, PrintKeyFcn printKeyFun,
                   PrintDataFcn printDataFun, ComparisonFcn fcomp)
{
    // checks for null pointers
    CHECK_IF_NULL(cloneKey, NULL);
    CHECK_IF_NULL(freeKey, NULL);
    CHECK_IF_NULL(hfun, NULL);
    CHECK_IF_NULL(printKeyFun, NULL);
    CHECK_IF_NULL(printDataFun, NULL);
    CHECK_IF_NULL(fcomp, NULL);

    // check for reasonable size of table
    if (tableSize <= 0)
    {
        fprintf(stderr, "tableSize must be bigger than 0\n");
        return NULL;
    }

    // allocates memory
    TableP table = malloc(sizeof(Table));
    CHECK_ALLOCATION(table, NULL);

    table->object = mallocObjectArr(tableSize);
    CHECK_ALLOCATION(table->object, NULL);

    // initialized Table
    table->origSize = tableSize;
    table->size = tableSize;
    table->d = INITIALIZED_VALUE;
    table->cloneKey = cloneKey;
    table->freeKey = freeKey;
    table->hfun = hfun;
    table->printKeyFun = printKeyFun;
    table->printDataFun = printDataFun;
    table->fcomp = fcomp;

    return table;
}


/**
 * @brief Insert an object to the table with key.
 * If all the cells appropriate for this object are full, duplicate the table.
 * If run out of memory, report
 * MEM_OUT and do nothing (the table should stay at the same situation
 * as it was before the duplication).
 * If everything is OK, return true. Otherwise (an error occured) return false;
 */
int insert(const TableP table, const void *key, DataP object)
{
    // checks for null pointer exception
    CHECK_IF_NULL(table, RETURN_0_IF_NULL);
    CHECK_IF_NULL(object, RETURN_0_IF_NULL);
    CHECK_IF_NULL(key, RETURN_0_IF_NULL);

    // get the index to insert to: i = d*H(k,n)
    int i = table->d * table->hfun(key, table->origSize);

    // search available place in range [i,i+d]
    for(int j = i; j < i + table->d; ++j)
    {
        // case 1: occupied
        if (table->object[j]->data != NULL
            && table->fcomp(table->object[j]->key, key) == EQUAL)
        {
            // same key - replace
            table->object[j]->data = object;
            return SUCCESS; // successful insert - true
        }
        else if (table->object[j]->data == NULL)
        { // case 2: available
            table->object[j]->data = object;
            table->object[j]->key = table->cloneKey(key);
            return SUCCESS; // successful insert - true
        }
    }
    // all occupied - double the hash table
    expandTable(table);

    // done expand and insert object to i+1
    table->object[i*2 + 1]->data = object;
    table->object[i*2 + 1]->key = table->cloneKey(key);
    return SUCCESS; // successful insert - true
}


/**
 * @brief remove an data from the table.
 * If everything is OK, return the pointer to the ejected data. Otherwise return NULL;
 */
DataP removeData(TableP table, const void *key)
{
    // check if null pointer exception
    CHECK_IF_NULL(table, NULL);
    CHECK_IF_NULL(key, NULL);

    // get the index to insert to: i = d*H(k,n)
    int i = table->d * table->hfun(key, table->origSize);

    // search in range [i,i+d]
    for(int j = i; j < i + table->d; ++j)
    {
        if (table->object[j]->data != NULL
            && table->fcomp(table->object[j]->key, key) == EQUAL)
        {
            // get the ejectedData and make the cell[j] available
            DataP ejectedData = table->object[j]->data;
            table->freeKey(table->object[j]->key);
            table->object[j]->data = NULL;
            table->object[j]->key = NULL;
            return ejectedData;
        }
    }
    // not found
    return NULL;
}

/**
 * @brief Search the table and look for an object with the given key.
 * If such object is found fill its cell number into arrCell (where 0 is the
 * first cell).
 * If the key was not found, fill both pointers with value of -1.
 * return pointer to the data or null
 */
DataP findData(const TableP table, const void *key, int *arrCell)
{
    // check if null pointer exception
    CHECK_IF_NULL(table, NULL);
    CHECK_IF_NULL(key, NULL);
    CHECK_IF_NULL(arrCell, NULL);

    // get the index to insert to: i = d*H(k,n)
    int i = table->d * table->hfun(key, table->origSize);

    // search in range [i,i+d]
    for(int j = i; j < i + table->d; ++j)
    {
        // case 1: compare i'th cell with key
        if (table->object[j]->data != NULL
            && table->fcomp(table->object[j]->key, key) == EQUAL)
        {
            *arrCell = j;
            return table->object[j]->data;
        }
    }
    // not found
    *arrCell = -1;
    return NULL;
}


/**
 * @brief return a pointer to the data that exist in the table in cell number arrCell (where 0 is the
 * first cell).
 * If such data not exist return NULL
 */
DataP getDataAt(const TableP table, int arrCell)
{
    // check if null pointer exception
    CHECK_IF_NULL(table, NULL);

    // check arrCell in [0,tableSize-1]
    if (arrCell > (int)table->size - 1 || arrCell < 0)
    {
        fprintf(stderr, "Boundry Error: arrCell Must be in [0,sizeTable-1]");
        return NULL;
    }

    // return the pointer to the data
    return table->object[arrCell]->data;
}


/**
 * @brief return the pointer to the key that exist in the table in cell number arrCell (where 0 is the
 * first cell).
 * If such key not exist return NULL
 */
ConstKeyP getKeyAt(const TableP table, int arrCell)
{
    // check if null pointer exception
    CHECK_IF_NULL(table, NULL);

    // check arrCell in [0,tableSize-1]
    if (arrCell > (int)table->size - 1 || arrCell < 0)
    {
        fprintf(stderr, "Boundry Error: arrCell Must be in [0,sizeTable-1]");
        return NULL;
    }

    // return the pointer to the key
    return table->object[arrCell]->key;
}


/**
 * @brief Print the table (use the format presented in PrintTableExample).
 */
void printTable(const TableP table)
{
    // print every cell
    for (size_t i = 0; i < table->size; ++i)
    {
        int status = table->object[i]->data == NULL ? EMPTY : NON_EMPTY;

        switch (status)
        {
            case EMPTY:
                printf("[%lu]\t\n", i);
                break;

            case NON_EMPTY:
                printf("[%lu]\t", i);
                table->printKeyFun(table->object[i]->key);
                printf(",");
                table->printDataFun(table->object[i]->data);
                printf("\t\n");
                break;

        }

    }
}


/**
 * @brief Free all the memory allocated for the table.
 * It's the user responsibility to call this function before exiting the program.
 */
void freeTable(TableP table)
{
    // check table isn't null
    if (table == NULL)
    {
        return;
    }

    // free all the members
    for (size_t i = 0; i < table->size; ++i)
    {
        // free every key cell & free object pointer
        table->freeKey(table->object[i]->key);
        free(table->object[i]);
        table->object[i] = NULL;
    }

    // free object**
    free(table->object);
    table->object = NULL;

    // free table
    free(table);
    table = NULL;
}

static void expandTable(TableP table)
{
    // create new object array with double the size
    ObjectP *expanded = mallocObjectArr(table->size * 2);
    if (expanded == NULL)
    {
        exit(-1);
    }

    // every cell (i) in the table will move to cell (i*2)
    for (size_t i = 0; i < table->size; ++i)
    {
        free(expanded[i*2]);
        expanded[i * 2] = table->object[i];
    }

    // free all the objectP & set new objects
    free(table->object);
    table->object = expanded;

    // increase the d = sizeTable/sizeOrig and the size of table
    table->d *= 2;
    table->size *= 2;
}

static ObjectP* mallocObjectArr(size_t size)
{
    // allocate array of ObjectP*size
    ObjectP *obj = malloc(sizeof(ObjectP) * size);
    CHECK_ALLOCATION(obj, NULL);

    // initialized every cell in object
    for (size_t i = 0; i < size; ++i)
    {
        obj[i] = malloc(sizeof(Object));
        CHECK_ALLOCATION(obj[i], NULL);

        // initialized all the cells to null
        obj[i]->data = NULL;
        obj[i]->key = NULL;
    }
    return obj;
}




