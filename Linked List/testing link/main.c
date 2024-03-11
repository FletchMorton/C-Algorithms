#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STUMAX 5

typedef struct Student
{
    int id;
    char sName[100];
    int sCrn[4];
    char sPrefix[4][8];
    int sCredit[4];
    int valid;
    struct Student *next;

} student;

void callMenu(student sList[], int[], int[], char[][8], int);
student *resetProgram(student sList[], int);
student *addStudent(student sList[], int[], int[], char [][8]);
student *populateStudent(student sList[], int[], int[], char [][8], int[]);
student *addClass(student sList[], int[], int[], char [][8], int);
student *populateClass(student sList[], int[], int[], char [][8]);
void courseConfig(student sList[], int[], int[], char [][8]);
void configMenu(student sList[], int[], int[], char [][8], int, int);
int length(student sList[]);

int main()
{
    student *sList = NULL;
    int crn[] = {4587, 4599, 8997, 9696, 1232, 9856, 8520, 8977};
    char prefix[][8] = {"MAT 236", "COP 220", "GOL 124", "COP 100", "MAC 531", "STA 100", "TNV 400", "CMP 100"};
    int credit[] = {4, 3, 1, 3, 5, 2, 5, 1};
    int option = 999;

    printf("====================TEMP PROGRAM====================\n\n");
    callMenu(sList, crn, credit, prefix, option);

    return 0;
}

student *resetProgram(student sList[], int refresh)
{

    if(refresh == 999) {

        //Deletes a student
        sList->id = 0;
        strcpy(sList->sName, "NULL");

        for(int i = 0; i < 4; i++) {
            sList->sCrn[i] = 0;
            sList->sCredit[i] = 0;
            strcpy(sList->sPrefix[i], "NULL");
        }

        return sList;
    }

    if(refresh != 999) {

        //Deletes a class
        sList->sCrn[refresh] = 0;
        sList->sCredit[refresh] = 0;
        strcpy(sList->sPrefix[refresh], "NULL");

        for(int i = 0; i < 4; i++) {
            if(sList->sCrn[(refresh+(i+1))] != 0 && sList->sCrn[(refresh+(i+1))] != NULL) {
                sList->sCrn[refresh] = sList->sCrn[(refresh+(i+1))];
                sList->sCredit[refresh] = sList->sCredit[(refresh+(i+1))];
                strcpy(sList->sPrefix[refresh], sList->sPrefix[(refresh+(i+1))]);
            } else {
                sList->sCrn[refresh+(i+1)] = 0;
                sList->sCredit[refresh+(i+1)] = 0;
                strcpy(sList->sPrefix[refresh+(i+1)], "NULL");
            }
        }

        return sList;
    }

    printf("\n\nFATAL ERROR\n\n");

    return sList;
}

void callMenu(student *sList, int crn[], int credit[], char prefix[][8], int option)
{

    do {
        option = 999;

        printf("Choose from one of the following options:\n");
        printf("\t1 - Add a new student\n\t2 - Add/Delete a course\n\t3 - Search for a student\n\t4 - Print fee invoice\n\t0 - Exit the program\n\n");
        printf("Enter your selection: ");

        scanf("%d", &option);

        switch(option) {
            case 0:
                printf("\n\n====================GOODBYE=====================\n\n");
                exit(0);
                break;
            case 1:
                sList = addStudent(sList, crn, credit, prefix);
                break;
            case 2:
                courseConfig(sList, crn, credit, prefix);
                break;
            case 3:
                //call searchStudent
                break;
            case 4:
                //call print
                break;
            default:
                //call relaunch
                break;
        }

    } while(option != 0);

    return;
}

student *addStudent(student *sList, int crn[], int credit[], char prefix[][8])
{
    int i = 0;
    int idBank[100];
    student *temp = sList;

    //Creates a student if none exist yet
    if(sList == NULL) {
        sList = malloc(sizeof(student));
        sList->next = NULL;
        sList = resetProgram(sList, 999);
        sList = populateStudent(sList, crn, credit, prefix, idBank);

        return sList;
    }

    if(sList->id == 0 && sList->next == NULL) sList = populateStudent(sList, crn, credit, prefix, idBank);

    //Points to last student in array
    while(temp->next != NULL) {
        idBank[i] = temp->id;
        temp = temp->next;
        i++;
    }

    if(sList->id == 0 && sList->next == NULL) sList = populateStudent(sList, crn, credit, prefix, idBank);

    //Add another student to the end of the array
    temp->next = malloc(sizeof(student));
    temp = temp->next;
    temp = populateStudent(temp, crn, credit, prefix, idBank);
    temp->next = NULL;

    return sList;

}

student *populateStudent(student *sList, int crn[], int credit[], char prefix[][8], int idBank[])
{
    int j;
    int id;
    int courses;
    student *temp = sList;

    //Enter ID
    printf("\n\tEnter the student's id: ");
    scanf("%d", &id);

    //Check for invalid ID number
    while(id == 0) {
        printf("\n\t\tInvalid id number. Please re-enter.\n\n");
        printf("\n\n\t\t\tEnter the student's id: ");
        scanf("%d", &id);
    }

    //Checks for matching IDs
    for(int i = 0; i < 3; i++) {
        if(id == idBank[i]) {
            printf("\nThis student has already been entered.\n\n-----------------------------------------------\n\n");

            return sList;
        }
    }

    //Assign id to current student
    temp->id = id;
    fflush(stdin);

    printf("\n\tEnter the student's full name: ");
    gets(temp->sName);

    printf("\n\tHow many courses is %s taking (Up to 4): ", temp->sName);
    scanf("%d", &courses);

    temp = addClass(temp, crn, credit, prefix, courses);

    return sList;
}

student *addClass(student *sList, int crn[], int credit[], char prefix[][8], int courses)
{

    int currentIndex;

    //Check for invalid course number
    while(courses > 4 || courses < 0) {
        printf("\n\t\tSorry, we cant process this time-invalid number of courses.");
        printf("\n\n\t\t\tEnter amount of courses (Up to 4): ");
        scanf("%d", &courses);
    }

    switch(courses) {
        case 0:
            printf("\nThank you.");
            break;

        case 1:
            printf("\n\tEnter your course number: ");

            for(int i = 0; i < 4; i++) {
                if(sList->sCrn[i] == 0) {
                    scanf("%d", &sList->sCrn[i]);
                    currentIndex = (i+1);
                    break;
                }
            }

            sList = populateClass(sList, crn, credit, prefix);

            if(sList->valid != currentIndex) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                sList = resetProgram(sList, 999);
                return sList;
            }
            break;

        case 2:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < 4; i++) {
                if(sList->sCrn[i] == 0) {
                    scanf("%d %d", &sList->sCrn[i], &sList->sCrn[(i+1)] );
                    currentIndex = (i+1);
                    break;
                }
            }

            sList = populateClass(sList, crn, credit, prefix);

            if(sList->valid != (currentIndex+1)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                sList = resetProgram(sList, 999);
                return sList;
            }
            break;

        case 3:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < 4; i++){
                if(sList->sCrn[i] == 0) {
                    scanf("%d %d %d", &sList->sCrn[i], &sList->sCrn[(i+1)], &sList->sCrn[(i+2)] );
                    currentIndex = (i+1);
                    break;
                }
            }

            sList = populateClass(sList, crn, credit, prefix);

            if(sList->valid != (currentIndex+2)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                sList = resetProgram(sList, 999);
                return sList;
            }
            break;

        case 4:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < 4; i++) {
                if(sList->sCrn[i] == 0) {
                    scanf("%d %d %d %d", &sList->sCrn[i], &sList->sCrn[(i+1)], &sList->sCrn[(i+2)], &sList->sCrn[(i+3)] );
                    currentIndex = (i+1);
                    break;
                }
            }

            sList = populateClass(sList, crn, credit, prefix);

            if(sList->valid != (currentIndex+3)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                sList = resetProgram(sList, 999);
                return sList;
            }

            break;

        default:
            exit(0);
    }

    printf("\nSuccess!\n\n-----------------------------------------------\n\n");

    return sList;
}

student *populateClass(student sList[], int crn[], int credit[], char prefix[][8])
{
    sList->valid = 0;

    for(int i = 0; i < STUMAX; i++){
        if(sList->sCrn[i] > 0) {
            for(int j = 0; j < 8; j++) {
                if(sList->sCrn[i] == crn[j]) {
                    sList->sCredit[i] = credit[j];
                    strcpy(sList->sPrefix[i], prefix[j]);
                    sList->valid++;
                }
            }
        }
    }

    return sList;
}

void courseConfig(student sList[], int crn[], int credit[], char prefix[][8])
{
    int id;
    int courses;

    printf("\n\tEnter the student's id: ");
    scanf("%d", &id);

    while(id == 0) {
        printf("\n\tInvalid id number. Please re-enter.\n\n");
        printf("\n\n\t\tEnter the student's id: ");
        scanf("%d", &id);
    }

    for(int i = 0; i < STUMAX; i++) {
        if(id == sList[i].id) {
            printf("\nHere are the courses that %s is taking:\n", sList[i].sName);

            printf("\tCRN\t  PREFIX\tCR. HOURS\n");
            for(int j = 0; j < 4; j++) {
                if(sList[i].sCrn[j] == 0) {
                    break;
                }

                printf("\t%d\t  %s\t%d\n", sList[i].sCrn[j], sList[i].sPrefix[j], sList[i].sCredit[j]);
                ++courses;
            }

            configMenu(sList, crn, credit, prefix, i, courses);
            return;
        }
    }

    printf("\nNo student found!\n\n-----------------------------------------------\n\n");
    return;
}

void configMenu(student sList[], int crn[], int credit[], char prefix[][8], int currentStudent, int courses)
{
    char choice;
    int addSub;

    printf("\nChoose from:\n\tA - Add a new course for %s\n\tD - Delete a course from %s's schedule\n\tC - Cancel operation\n\nEnter your selection: ", sList[currentStudent].sName, sList[currentStudent].sName);
    scanf(" %c", &choice);

    switch(toupper(choice)) {
        case 'A':
            if((4 - courses) == 0) {
                printf("\n\t\tMaximum amount of courses already assigned (4).");
                return;
            }

            printf("\n\t%s is able to take %d more courses. How many will you add: ", sList[currentStudent].sName, (4-courses));
            scanf("%d", &addSub);

            if((addSub + courses) > 4) {
                printf("\nThis would exceed the course limit (4).\n");
                return;
            }

            addClass(sList, crn, credit, prefix, addSub);
            return;
            break;
        case 'D':
            exit(0);
            break;
        case 'C':
            exit(0);
            break;
        default:
            exit(0);
            break;
    }
}

int length(student sList[])
{
    int counter = 0;
    student *temp = sList;

    //counting students
    while(temp != NULL) {
        counter++;
        temp = temp->next;
    }

    return counter;
}
