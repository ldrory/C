#include<stdio.h>
#include<stdlib.h>

typedef struct node nodeStruct;

/**
 * struct node
 * holds: 
 *      data: the data of the node
 *      nodeStruct: pointer to the next node
 * 
 */
struct node 
{
    int data;
    nodeStruct *next;
}; 
// * cannot used in type of struct

struct node* head;  // probably this is what was intendent
int sizeOfNodes;


/**
 * adds the data in the last place of the list
 * @param dataToAdd the data to add
 */
void addToEnd(int dataToAdd)
{
    nodeStruct *temp, *right;
    temp = (struct node *) malloc(sizeof(struct node));
//    temp->data = (int) malloc(sizeof(int));
//    deleted because there is no need for int alocation
    temp->data = dataToAdd;
    right = head; //(struct node *) is no needed here (they're the same type)

    while(right->next != NULL)
    {
        right = right->next;
    }

    right->next = temp;
    right = temp;
    right->next = NULL;
}

/**
 * adds the data in the first place of the list
 * @param dataToAdd the data to add
 */
void addFirst(int dataToAdd)
{
    nodeStruct *tempNode;
    tempNode = (struct node *)malloc(sizeof(struct node));
//    tempNode->data = (int) malloc(sizeof(int)); like i said earlier, there is no need
//    for malloc an int.
    tempNode->data = dataToAdd;
    if (head == NULL) 
    {
        head = tempNode;
        head->next = NULL;
    }
    else 
    {
        // switched statements because we can not
        // make head look at tempNode and then tempNode look to head
        // because head look at tempNode and then it will look at it self
        // instead of the head, and we will lose the pointer to head.
        tempNode->next = head;
        head = tempNode;
    }

}

/**
 * adds a new data in a given place to add
 * @param dataToAdd the data to add
 * @param placeToAdd the place to add
 */
void addInPlace(int dataToAdd, int placeToAdd)
{
    int i;
    nodeStruct *temp, *left, *right;
    right = head;
    left = right; //initialized left
    for(i = 0; i<placeToAdd; i++)
    {
        // we need to get the the placeToAdd+1
        // but the right=right->next will make it to placeToAdd+1
        left = right;
        right = right->next;
    }

    temp = (struct node *)malloc(sizeof(struct node));
//    temp->data = (int) malloc(sizeof(int)); NO NEED! as we said earlier
    temp->data = dataToAdd;
    left->next = temp;
//    left=temp; redundant line (we can put directly temp->next = right
    temp->next = right;
    return;
    // TODO: check if we need to assume the list is big enogth (if not if put it last in the list)
}


/**
 * inserts a new data number
 * the data is inserted in ascending order, from the lowest to highest
 * @param dataToAdd the data to insert
 * @param numberOfNodes the current number of nodes
 */
void insert(int dataToAdd, int *numberOfNodes)
{
    int c = 0;
    nodeStruct *temp;
    temp = head;
    if(temp == NULL)
    {
        addFirst(dataToAdd);
    }
    else
    {
        while(temp != NULL && temp->data < dataToAdd)
            // wiser way to do it (not getting infinite loop and
        {
            c++;
            temp = temp->next;
        }

        if(c == 0) 
        {
            addFirst(dataToAdd);
        }
        else if(c < *numberOfNodes)
        {
            addInPlace(dataToAdd, c);
        }
        else
        {
            addToEnd(dataToAdd);
        }
    }
    (*numberOfNodes)++; // if you wanted to increase the number that how you should do it
}


/**
 * deletes the first node with the number num
 * @param dataToDelete the data to delete
 * @param numberOfNodes the number of nodes
 * @return
 */
int delete(int dataToDelete, int *numberOfNodes)
{
    nodeStruct *temp, *prev;
    temp = head;
    while(temp != NULL)
    {
        if(temp->data == dataToDelete)
        {
            if(temp == head)
            {
                head = temp->next;
                free(temp);

            }
            else {
                prev->next = temp->next;
                free(temp);
            }
            (*numberOfNodes)--; //like i said in the prev func
            return 1;

        }
        else
        {
            prev = temp;
            temp = temp->next;
            // we have to check that there is a next node.
            if (temp == NULL)
            {
                return 0;
            }
            //
        }
    }

    return 0;
}

/**
 * should print all the nodes in the linked list in this format:
 * number of nodes: <numberOfNodes>\n
 * <firstNodeData> --> <secondNodeData> --> .... <lastNodeData>\n
 * @param startingNodeToPrint the first node to print
 */
void  display(nodeStruct *startingNodeToPrint)
{
    printf("number of nodes: %d\n", sizeOfNodes);
    if(startingNodeToPrint == NULL)
    {
        return;
    }
    while(startingNodeToPrint != NULL)
    {
        printf("%d --> ", startingNodeToPrint->data);
        startingNodeToPrint = startingNodeToPrint->next;
    }
    printf("NULL\n");
}




void basicTest()
{
    int data0 = 0;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    insert(data1, &sizeOfNodes);
    insert(data2, &sizeOfNodes);
    insert(data3, &sizeOfNodes);
    insert(data2, &sizeOfNodes);
    insert(data1, &sizeOfNodes);
    insert(data2, &sizeOfNodes);
    insert(data1, &sizeOfNodes);
    insert(data0, &sizeOfNodes);
    display(head);

    delete(data1, &sizeOfNodes);
    delete(data2, &sizeOfNodes);
    display(head);
    delete(data2, &sizeOfNodes);
    delete(data3, &sizeOfNodes);
    delete(data2, &sizeOfNodes);
    display(head);
    delete(data1, &sizeOfNodes);
    delete(data1, &sizeOfNodes);
    delete(data0, &sizeOfNodes);
    display(head);
}

void hardTest()
{
    for (int i = 0; i<100; i++)
    {
        insert(i, &sizeOfNodes);
    }
    display(head);

    for (int i = 0; i<100; i++)
    {
        insert(i, &sizeOfNodes);
    }

    display(head);
    for (int i = 0; i<100; i++)
    {
        delete(i, &sizeOfNodes);
    }
    display(head);
    for (int i = 0; i<100; i++)
    {
        delete(i, &sizeOfNodes);
    }
    display(head);

}



int  main()
{

    basicTest();
    hardTest();

    return 0;
}