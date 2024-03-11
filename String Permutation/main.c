//Fletcher Morton

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Prototypes
void permute(char str[], int startIndex, int lastIndex);
void swap(char *a, char *b);

int main()
{
    char temp[100];
    printf("Enter your string: ");
    scanf("%s", temp);

    //Dynamically allocate the string
    char *str = malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(str, temp);

    printf("\nPermutation:\n========================================\n");
    permute(str, 0, strlen(str)-1); //string length minus one because mind the null terminator

    free(str);
    return 0;
}

//______________________________________________

void permute(char str[], int startIndex, int lastIndex)
{
    int i;
    if(startIndex == lastIndex) {
        for(i = 0; i <= lastIndex; i++) { //print out the string
            printf("%c", str[i]);
        }

        printf("\t");
    } else {
        for(i = startIndex; i <= lastIndex; i++) {
            swap(&str[startIndex], &str[i]);
            permute(str, startIndex+1, lastIndex); //run the function again, but now your starting index has increased by one. This continues until start=end
            swap(&str[startIndex], &str[i]);
        }
    }
}

//______________________________________________

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
