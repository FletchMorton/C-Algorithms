//Fletcher Morton
//Insertion Sort

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

    printf("Insertion Sort\n================================\n");
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

// Insertion Sort. For each element, compare its value to the value of the previous element. If the previous element is greater, swap the elements. (Repeat until in correct place), then proceed to next element
void sort(int *array, int size)
{
    //For each element in the array
    for(int i = 1; i < size; i++) {
        //For every previous element, compare its value to the current value and swap if the previous element is smaller
        for(int j = i; j > 0 && array[j-1] > array[j]; j--)
            swap(&array[j], &array[j-1]);
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
