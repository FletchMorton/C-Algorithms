//Fletcher Morton
//Swap

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void swap(int *, int *);

int main()
{
    int x = 0;
    int y = 0;

    printf("Swap program\n================================\n");
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    //Pass the address of variables x and y
    swap(&x, &y);
    printf("\nSwapping...\n\nX is currently %d\nY is currently %d\n\n", x, y);
    return 0;
}

//Swaps two variables
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
