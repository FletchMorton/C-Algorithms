//Fletcher Morton

//CIRCULAR

#include <stdio.h>
#include <stdlib.h>

//Constructors
typedef struct Node Node;
typedef struct LL LL;

struct Node {
    int value;
    Node * next;
};

struct LL {
    Node * head;
    Node * tail;
};

LL * createList();
Node * createNewNode(int);
void removeHead(LL *);
void addtoEnd(LL *, int);
void freeList(LL *);
void printList(LL *);

int main()
{
    LL * list;
    list = createList();

    int value;
    scanf("%d", &value);

    //Allow the user to enter as many values as they want. Scanning process ends when the user enters "-1"
    while(value != -1) {
        addtoEnd(list, value);
        scanf("%d", &value);
    }

    printf("\n\n\n");

    printList(list);
    freeList(list);

    return 0;
}

//________________________________________________________________
LL * createList()
{
    LL * result;
    result = (LL *) malloc(sizeof(LL));

    //head and tail will be null if the list is empty
    result->head = NULL;
    result->tail = NULL;

    //give caller the created list
    return result;
}

//________________________________________________________________
Node * createNewNode(int value)
{
    //Allocate space for the node
    Node * newNode = (Node *) malloc(sizeof(Node));
    //Assign the passed integer as Node's value
    newNode->value = value;
    //Assign the newly created Node's next node as NULL, since this will be inserted at the end of the list
    newNode->next = NULL;

    return newNode;
}

//________________________________________________________________
void removeHead(LL * list)
{
    //if the list is empty
    if(list->head == NULL) {
        return;
    }

    //if there is only one element
    if(list->head == list->tail) {
        //make the list empty
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    //If there are more than one elements in the list
    Node * oldHead = list->head;
    Node * newHead = oldHead->next;
    free(oldHead);
    list->head = newHead;

    return;
}

//________________________________________________________________
void addtoEnd(LL * list, int value)
{

    //if the list in empty
    if(list->head == NULL) {
        list->head = createNewNode(value);
        list->tail = list->head;
        list->tail->next = NULL;
        return;
    }

    //if there is only one element
    if(list->head == list->tail) {
        list->head->next = createNewNode(value);
        list->tail = list->head->next;
        return;
    }

    //if there is more than one element
    list->tail->next = createNewNode(value);
    list->tail = list->tail->next;
    return;
}

//________________________________________________________________
void freeList(LL * list)
{
    //Remove all nodes
    while(list->head != NULL) {
        removeHead(list);
    }

    free(list);
    return;
}

//________________________________________________________________
void printList(LL * list)
{
    //Simply sweeps through the list and prints out the value at each node
    Node * racer = list->head;
    while(racer != NULL) {
        printf("%d\n", racer->value);
        racer = racer->next;
    }
    return;
}
