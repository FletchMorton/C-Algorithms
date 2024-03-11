
// Read numbers from input until -1 reached
// Print numbers read at end

#include <stdio.h>
#include <stdlib.h>

// The initial capacity of any newly created array list
#define INITIAL_CAP 10

// The array list struct
typedef struct ArrayList ArrayList;
struct ArrayList {
    int * arr;
    int size;   //The amount of elements in the array
    int cap;    //The maximum size of the array
};

// Prototypes
ArrayList * createArrayList();
void destroyArrayList(ArrayList *);
void addToList(ArrayList *, int);
void printArrayList(ArrayList *);

// The main function
int main() {
    int value = 0;

    // Create the list
    ArrayList * list = createArrayList();

    // Read in values and add them into the ArrayList
    while(value != -1) {
        scanf("%d", &value);
        if(value == -1) break;
        addToList(list, value);
    }

    // Print out the ArrayList's values
    printf("\n\n");
    printArrayList(list);

    // Clean up memory used
    destroyArrayList(list);

    // Exit the program
    return 0;
}

//________________________________________
// Function to create an array list
ArrayList * createArrayList()
{
    // Create the whole memory for the array list
    ArrayList * result;
    result = (ArrayList *) calloc(1, sizeof(ArrayList));

    // Initialize the values in the array list
    result->size = 0;
    result->cap = INITIAL_CAP;
    result->arr = (int *) calloc(result->cap, sizeof(int));

    // Return the section we created
    return result;
}

//_________________________________________
// Function to insert a value into an array list at
// the first empty spot
void addToList(ArrayList * list, int value)
{
    //If the size is the capacity, then the list should be full
    if(list->size == list->cap) {

        //Call realloc and increase the array's length
        list->arr = (int *) realloc(list->arr, list->cap * (2 * sizeof(int)));

        //Double the capacity
        list->cap *= 2;
    }

    //Insert the value at the first empty value in the array
    list->arr[list->size] = value;
    list->size++;
}

//________________________________________
// Function to destroy an array list
void destroyArrayList(ArrayList * list)
{
    free(list->arr);  //Free the dynamically allocated array
    free(list);       //Free the ArrayList
}

//________________________________________
// Function to print values
void printArrayList(ArrayList * list)
{
    for (int i = 0; i < list->size; i++) {
        printf("%d\n", list->arr[i]);
    }
}
