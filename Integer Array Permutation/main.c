//Fletcher Morton

#include <stdlib.h>
#include <stdio.h>

//Prototypes
void permute(int nums[], int startIndex, int lastIndex);
void swap(int *a, int *b);

int main()
{
    int count;
    printf("Number of digits in your array:\t");
    scanf("%d", &count);

    //Dynamically allocate the memory
    int *nums;
    nums = (int *) calloc(count, sizeof(int));

    //Reads space separated integers into an array
    printf("Input your %d numbers now:\t", count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &nums[i]);
    }

    printf("\nPermutation:\n========================================\n");
    permute(nums, 0, count-1);

    free(nums);
    return 0;
}

//______________________________________________

void permute(int nums[], int startIndex, int lastIndex)
{
    int i;
    if(startIndex == lastIndex) {
        for(i = 0; i <= lastIndex; i++) { //print out the numbers
            printf("%d ", nums[i]);
        }

        printf("\n");
    } else {
        for(i = startIndex; i <= lastIndex; i++) {
            swap(&nums[startIndex], &nums[i]);
            permute(nums, startIndex+1, lastIndex); //run the function again, but now your starting index has increased by one. This continues until start=end
            swap(&nums[startIndex], &nums[i]);
        }
    }
}

//______________________________________________

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
