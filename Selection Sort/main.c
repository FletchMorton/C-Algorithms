//Fletcher Morton
//Selection Sort

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void sort(int *, int);
void swap(int *, int *);

//Main
int main()
{
    int *array = (int *)calloc(10, sizeof(int));
    int size = 10;

    printf("Selection Sort\n================================\n");
    printf("Enter 10 items to formulate an array:\n");

    //Populate the array
    for(int i = 0; i < 10; i++)
        scanf("%d", &array[i]);

    //Sort the array
    sort(array, size);
    printf("\n\n\n");

    //Print the array
    for(int i = 0; i < 10; i++)
        printf("%d\n", array[i]);

    return 0;
}
//_________________________________________________________

// Selection Sort. Takes the minimum element, swaps it with the first element in the array and then moves the lower bound upward
void sort(int *array, int size)
{
    int smallest = 0;
    int smallIndex = 0;

    //For each element in the array compare its value to all others
    for(int i = 0; i < size; i++) {
        smallest = array[i];
        smallIndex = i;

        //If any elements are smaller than the smallest number, record its index
        for(int j = i; j < size; j++) {
            if(smallest > array[j]) {
                smallest = array[j];
                smallIndex = j;
            }
        }

        //Swap smallest index to the front of the array (this theoretically forms a sub-array that is sorted)
        swap(&array[smallIndex], &array[i]);
    }
}

//_________________________________________________________

//Swaps two variables
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
