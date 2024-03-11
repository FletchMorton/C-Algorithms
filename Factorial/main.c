//Fletcher Morton

#include <stdio.h>
#include <stdlib.h>

//Constructors
int factorial(int);

int main()
{
    int n;

    printf("Enter a number:\t");
    scanf("%d", &n);

    printf("\n%d! = %d\n", n, factorial(n));

    return 0;
}

//_________________________________________________

int factorial(int n)
{
    int prod = n;
    for(int i = (n-1); i > 0; i--) {
        prod *= i;
    }

    return prod;
}
