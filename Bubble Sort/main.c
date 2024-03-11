//Fletcher Morton
//Bubble Sort

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

    printf("Bubble Sort\n================================\n");
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

// Bubble Sort. For each element, compare its value to the value immediately next. If the next element is smaller, swap the elements. Requires size-1 passes
void sort(int *array, int size)
{
    //Is the array sorted?
    int done = 0;

    //For each element in the array
    for(int i = 0; i < size-1; i++) {
        done = 1;

        //For every element, compare its value to the next elemental value and swap if the next element is smaller
        for(int j = 0; j < size-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                done = 0; //Indicate that the array was not sorted at the beginning of this passthrough
        }

        //If the array is sorted, break
        if(done == 1) break;
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
