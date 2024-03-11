#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

int length(node *);
node *add(node *, int);
node *remov(node *, int);
void printR(node *); //recursive

int main()
{
    node *list = NULL;

    list = add(list, 45);
    list = add(list, 89);
    list = add(list, 123);
    list = add(list, 753);

    list = remov(list, 45);

    printR(list);
    printf("\nThere are %d nodes\n", length(list));

    return 0;
}

node *add(node *list, int data)
{
    node *temp = list;

    //operation for if the list is new
    if(list == NULL) {
        list = malloc(sizeof(node));
        list->data = data;
        list->next = NULL;

        return list;
    }

    //points to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    //adds another
    temp->next = malloc(sizeof(node));
    temp->next->data = data;
    temp->next->next = NULL;

    return list;
}

int length(node *list)
{
    int counter = 0;
    node *temp = list;

    //counting nodes
    while(temp != NULL) {
        counter++;
        temp->next;
    }

    return counter;
}

node *remov(node *head, int data)
{
    node *temp = head;

    if(head == NULL) {
        return;
    }

    if(head->data == data) {
        head = head->next;

        return head;
    }

    while(temp->next != NULL) {
        if(temp->next->data == data) {
            temp->next = temp->next->next;

            return;
        }

        temp = temp->next;
    }

    return head;
}

void printR(node *list)
{
    if(list == NULL) {
        return;
    }

    printf("%d-> ", list->data);
    printR(list->next);
}
