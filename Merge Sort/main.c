//Fletcher Morton
//Merge Sort

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void sort(int *, int);

//Main
int main()
{
    int *array = (int *)calloc(10, sizeof(int));
    int size = 10;

    printf("Merge Sort\n================================\n");
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

/* Merge Sort. Using array[size/2] as the pivot (middle value), split the array in half repeatedly *
 * until there is only one element. Put each value into a temporary array in order of value.       */
void sort(int *array, int size)
{
    //If there is only one value in the array, it is already sorted. So just return
    if (size <= 1) return;

    //Break down the front half of the array
    sort(array, size/2);
    //Break down the back half of the array
    sort(array + (size/2), size - (size/2));

    int *temp = (int *)calloc(size, sizeof(int));

    //Merge the values in both halves into the temp array
    int frontPointer = 0;
    int backPointer = size/2;
    int mergePointer = 0;

    while (mergePointer < size) {

        //Front is empty/cleaned out
        if (frontPointer == size/2) {
            //Write the value into it's proper place in the temp array
            temp[mergePointer] = array[backPointer];
            //Advance
            mergePointer++;
            backPointer++;

        //If the back is empty/cleaned out
        } else if (backPointer == size) {
            //Write the value into it's proper place in the temp array
            temp[mergePointer] = array[frontPointer];
            //Advance
            mergePointer++;
            frontPointer++;

        //Neither back or front is empty. Compare front and back halves and use the smallest value to sort
        } else {
            //If the front value is the smaller one
            if (array[frontPointer] < array[backPointer]) {
                //Write the value into it's proper place in the temp array
                temp[mergePointer] = array[frontPointer];
                //Advance
                mergePointer++;
                frontPointer++;

            //If the back value is the smaller one
            } else {
                //Write the value into it's proper place in the temp array
                temp[mergePointer] = array[backPointer];
                //Advance
                mergePointer++;
                backPointer++;

            } //If/Else for smallest value

        } //If/Else for empty checks

    } //While loop


    //Copy each shipment from the merged array into the final array
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    //free the temp array
    free(temp);

}
