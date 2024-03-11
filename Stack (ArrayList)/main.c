//Fletcher Morton
//ArrayList Stack

#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct ArrayList {
    int *array;
    int size;
    int capacity;
}ArrayList;


//Prototypes
ArrayList *createStack();
void push(ArrayList *, int);
int pop(ArrayList *);
int peek(ArrayList *);
int isempty(ArrayList *);
int isfull(ArrayList *);


int main() {

    ArrayList *stack = createStack();

   push(stack, 3);
   push(stack, 5);
   push(stack, 9);
   push(stack, 1);
   push(stack, 12);
   push(stack, 15);

   printf("Element at top of the stack: %d\n", peek(stack));
   printf("Elements: \n");

   while(isempty(stack) == 0) {
      int data = pop(stack);
      printf("%d\n",data);
   }

   printf("Stack full: %d\n" , isfull(stack));
   printf("Stack empty: %d\n" , isempty(stack));

   return 0;
}

//_____________________________________________

ArrayList *createStack() {
    ArrayList *result = (ArrayList *)malloc(sizeof(ArrayList));

    result->array = (int *)calloc(8, sizeof(int));
    result->size = 0;
    result->capacity = 8;

    return result;
}

//_____________________________________________

void push(ArrayList *stack, int data) {

   if(isfull(stack) == 0) {
      stack->size++;
      stack->array[stack->size] = data;

   } else {
      printf("Could not insert data. Stack is full.\n");

   }
}

//_____________________________________________

int pop(ArrayList *stack) {
   int data;

   if(isempty(stack) == 0) {
      data = stack->array[stack->size];
      stack->size--;

      return data;

   } else {
      printf("Could not retrieve data, Stack is empty.\n");
      return 999999;
   }
}

//_____________________________________________

int peek(ArrayList *stack) {
   return stack->array[stack->size];
}

//_____________________________________________

int isempty(ArrayList *stack) {

   if(stack->size == 0) {
      return 1;

   } else {
      return 0;

   }
}

//_____________________________________________

int isfull(ArrayList *stack) {

   if(stack->size == stack->capacity) {
      return 1;

   } else {
      return 0;

   }
}
