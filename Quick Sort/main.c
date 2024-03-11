//Fletcher Morton
//Quick Sort

#include <stdio.h>
#include <stdlib.h>












//INCORRECT. NOT WORKING.


















//Prototypes
void sort(int *, int, int);
void swap (int *, int *);
int partition(int *, int, int);

//Main
int main()
{
    int *array = (int *)calloc(10, sizeof(int));
    int size = 10;

    printf("Quick Sort\n================================\n");
    printf("Enter 10 items to formulate an array:\n");

    //Populate the array
    for(int i = 0; i < 10; i++)
        scanf("%d", &array[i]);

    //Sort the array
    sort(array, 0, size-1);
    printf("\n\n\n");

    //Print the array
    for(int i = 0; i < 10; i++)
        printf("%d\n", array[i]);

    return 0;
}
//_________________________________________________________

// Quick Sort. Using array[(lo+hi)/2] as the pivot (estimation of the middle value), split the array in half and work on sorting each partition
void sort(int *array, int lo, int hi)
{
    //If pointers are in bounds
    if (lo < hi) {

        //Get a parting index (effectively partitions the array into two)
        int part = partition(array, lo, hi);

        //Sort front
        sort(array, lo, part - 1);
        //Sort rear
        sort(array, part + 1, hi);
    }
}

//_________________________________________________________

//Find two erroneous values in each partition and swap them
int partition(int *array, int lo, int hi)
{
    //Pivot is chosen from the middle of the array
    int pivot = array[(hi+lo)/2];

    while(lo <= hi) {
        //Find an element larger than pivot
        while(array[lo] < pivot) {
            lo++;
        }

        //Find an element smaller than pivot
        while(array[hi] > pivot) {
            hi--;
        }

        //Swap the two values
        if(lo <= hi) {
            swap(&array[lo], &array[hi]);
            lo++;
            hi--;
        }
    }

    return lo;

}

//_________________________________________________________
//Swaps two variables
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
