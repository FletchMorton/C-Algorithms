//Fletcher Morton

#include <stdio.h>
#include <stdlib.h>

#define PARENT(x)   (((x)-1)/2)
#define LEFT(x)     ((x)*2+1)
#define RIGHT(x)    (((x)+1)*2)

#define DEFAULT_CAP  10

//typedefs
typedef struct ArrayList ArrayList;
typedef struct ArrayList Heap;

//structs
struct ArrayList {
    int * array; // type of the array is the type of data that goes into heap
    int size, cap;
};

// Array List Prototypes
ArrayList * createList();
void append(ArrayList *, int);
void deleteList(ArrayList *);

// Heap Prototypes
Heap * createHeap();
void deleteHeap(Heap *);
void heapAdd(Heap *, int);
void heapRemove(Heap *);
void percolateUp(Heap *, int);
void percolateDown(Heap *, int);
void swap(Heap *, int, int);
void printList(Heap *);
int front(Heap *);

int main() {
    Heap * heap = createHeap();
    int command = 0;
    int value;

    while(command != 5) {
        printf("Enter a command:\n\t1 - Insert\n\t2 - Remove\n\t3 - Print\n\t4 - Front\n\t5 - Kill\n\n> ");
        scanf("%d", &command);

        switch(command) {
            case 1:
                //Insert to the heap
                printf("\n\tEnter the value that you would like to insert into the heap:\n\t> ");
                scanf("%d", &value);

                printf("\n\tInserting %d...\n\n", value);
                heapAdd(heap, value);
                break;

            case 2:
                //Remove from the heap
                printf("\n\tEnter the value that you would like to remove from the heap:\n\t> ");
                scanf("%d", &value);

                printf("\n\tRemoving %d...\n\n", value);
                heapRemove(heap);
                break;

            case 3:
                //Print out the ArrayList that represents the heap
                printList(heap);
                break;

            case 4:
                //Access the front of the heap
                printf("\n\tThe value at the front of the heap is %d\n", front(heap));
                break;

            default:
                ;
        }

    }

    //Kill the heap
    while (heap->size != 0) {
        int value = front(heap);
        printf("Extra Removing %d...\n", value);
        heapRemove(heap);
    }

    deleteHeap(heap);

    return 0;
}

//_________________________________________________________________________

//--------------------------Array List Functions--------------------------
ArrayList * createList()
{
    ArrayList * result = (ArrayList *) malloc(sizeof(ArrayList));

    result->size = 0;
    result->cap = DEFAULT_CAP;
    result->array = (int *) malloc(sizeof(int) * result->cap);

    return result;
}

//_________________________________________________________________________

void append(ArrayList * list, int value)
{
    //If the ArrayList is completely full, increase the maximum capacity and reallocate
    if (list->size == list->cap) {
        list->cap *= 2;
        list->array = (int *) realloc(list->array, list->cap * sizeof(int));
    }

    list->array[list->size] = value;
    list->size++;
}

//_________________________________________________________________________

void deleteList(ArrayList * list)
{
    free(list->array);
    free(list);
}

//_________________________________________________________________________

//-----------------------------Heap Functions-----------------------------
Heap * createHeap()
{
    return createList();
}

//_________________________________________________________________________

void deleteHeap(Heap * heap)
{
    deleteList(heap);
}

//_________________________________________________________________________

void heapAdd(Heap * heap, int value)
{
    //Add to the end
    append(heap, value);

    //Move into the correct position
    percolateUp(heap, heap->size - 1);
}

//_________________________________________________________________________

void heapRemove(Heap * heap)
{
    //Check that the heap actually exists
    if(heap->size == 0) {
        printf("\nCatastrophic error.\n");
        return;
    }

    //Swap the value to remove (highest priority value / value at the root) with the last value in the heap
    swap(heap, 0, heap->size - 1);

    // potentially free here if dynamic memory was used
    // free the contents at location heap->size - 1

    //Decrement the size of the heap
    heap->size--;

    //Move the value into the correct position
    percolateDown(heap, 0);
}

//_________________________________________________________________________

int front(Heap * heap)
{
    //Check that the heap actually exists
    if(heap->size == 0) {
        printf("\nCatastrophic error.\n");
        return;
    }

    //return the value at the front of the heap
    return heap->array[0];
}

//_________________________________________________________________________

void percolateUp(Heap * heap, int index)
{
    //Cannot percolate up the root
    if(index == 0) return;

    //Get the the index of the parent "Node"
    int parentIndex = PARENT(index);

    //If the current value is less than the parent value (if cur is higher priority), swap the two and percolate the parent up
    if(heap->array[index] < heap->array[parentIndex]) {
        swap(heap, parentIndex, index);
        percolateUp(heap, parentIndex);
    }
}

//_________________________________________________________________________

void percolateDown(Heap * heap, int index)
{
    int bestIndex = index;
    int rightIndex = RIGHT(index);
    int leftIndex = LEFT(index);

    //Check if right child is a better index than the "best"
    if (rightIndex < heap->size && heap->array[bestIndex] > heap->array[rightIndex]) {
        bestIndex = rightIndex;
    }

    //Check if left child is a better index than the "best"
    if (leftIndex < heap->size && heap->array[bestIndex] > heap->array[leftIndex]) {
        bestIndex = leftIndex;
    }

    if (index != bestIndex) {
        swap(heap, bestIndex, index);
        percolateDown(heap, bestIndex);
    }
}

//_________________________________________________________________________

void swap(Heap * heap, int index1, int index2)
{
    int tmp = heap->array[index1];
    heap->array[index1] = heap->array[index2];
    heap->array[index2] = tmp;
}

//_________________________________________________________________________

void printList(Heap * heap)
{
    //Simply print out the list
    printf("\n[%d", heap->array[0]);

    for(int i = 1; i < heap->size; i++) {
        printf(", %d", heap->array[i]);
    }

    printf("]\n");
}
