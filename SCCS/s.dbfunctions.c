h41152
s 00000/00002/00562
d D 1.3 19/04/15 16:33:07 arslanr 3 2
c wtf
e
s 00003/00003/00561
d D 1.2 19/03/10 15:04:52 arslanr 2 1
c edited bugs
e
s 00564/00000/00000
d D 1.1 19/03/10 14:58:41 arslanr 1 0
c date and time created 19/03/10 14:58:41 by arslanr
e
u
U
f e 0
t
T
I 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

extern int debugMode;


/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Takes in proper inputs to add in a record
//
//  Parameters:    struct record **next, int arAccountNo, char arName[ ],char arAddress[ ]
//
//
//  Return values:  0 : success
//                  -1: Record was not added
//
//
****************************************************************/

int addRecord(struct record **next, int arAccountNo, char arName[], char arAddress[])
{
    int exitIfZeroOrNegativeOne;
    struct record *current;
    struct record *temp;

    if (debugMode == 1)
    {

        printf("\nFunction called - : addRecord\n");
        printf("Address passed in is: %p\n", (void *)next);
        printf("User entered the following account number: %d\n", arAccountNo);
        printf("Name user entered is: %s", arName);
        printf("Address user entered is:  %s\n\n", arAddress);

    }

    current = (struct record *)malloc(sizeof(struct record));
    temp = (struct record *)malloc(sizeof(struct record));
    current = *next;
    temp->accountno = arAccountNo;
    strcpy(temp->name, arName);
    strcpy(temp->address, arAddress);
    temp->next = NULL;



    exitIfZeroOrNegativeOne = 1;

    while (exitIfZeroOrNegativeOne == 1)
    {

        if (*next == NULL)
        {
            *next = temp;
            current = *next;
            exitIfZeroOrNegativeOne = 0;
            printf("\nRecord added!\n");
            
        }
        else if (current->accountno == arAccountNo)
        {

            free(temp);
            temp = NULL;
            exitIfZeroOrNegativeOne = -1;
D 2
            //printf("\nRecord with the account number already exists!\n");
E 2
I 2
D 3
            
E 2

E 3

        }
        else if (current->next == NULL)
        {

            current->next = temp;
            current = temp;
            exitIfZeroOrNegativeOne = 0;
            printf("\nRecord added!\n");

        }
        else
        {

            current = current->next;

        }

    }



    return exitIfZeroOrNegativeOne;
}

/*****************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   prints a record based on the account number
//
//  Parameters:    struct record *next, int prAccountNo
//
//
//  Return values:  0 : success
//					-1: Failure
//
//
****************************************************************/

int printRecord(struct record *next, int prAccountNo)
{
    int returnVal;
    returnVal = -1;

    if (debugMode == 1)
    {

        printf("\nFunction called - : printRecord\n");
        printf("Address passed in is: %p\n", (void *)next);
        printf("User entered the following account number: %d\n\n", prAccountNo);

    }

    do
    {

        if (next->accountno == prAccountNo)
        {

            printf("\n %d \n", next->accountno);
            printf(" %s", next->name);
            printf(" %s \n", next->address);
            returnVal = 0;

        }

        next = next->next;

    } while (next != NULL);

    if (returnVal == -1)
    {

        printf("No such records were found!");

    }



    return returnVal;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   prints all records
//
//  Parameters:    struct record *next
//
//
//  Return values:  void
//
//
****************************************************************/

void printAllRecords(struct record *next)
{

    if (debugMode == 1)
    {
        printf("\n\nFunction called - : printAllRecords\n");
        printf("Address passed in is: %p\n\n", (void *)next);
    }

    if (next == NULL)
    {

        printf("\nNo records exist!\n");

    }
    else
    {
        do
        {

            printf("\n %d \n", next->accountno);
            printf(" %s", next->name);
            printf(" %s \n", next->address);
            next = next->next;

        } while (next != NULL);

    }



}

/*****************************************************************
//
//  Function name: findRecords
//
//  DESCRIPTION: finds a record based on name
//
//  Parameters:  struct record *next, char frName[ ]
//
//
//  Return values:  0 : success
//					-1: Failure
//
//
****************************************************************/

int findRecords(struct record *next, char frName[])
{
    int sizeOfInt;
    int returnVal;
    returnVal = -1;

    if (next == NULL)
    {

    }
    else
    {



        sizeOfInt = strlen(frName);


        if (debugMode == 1)
        {
            printf("\nFunction called - : findRecords\n");
            printf("Address passed in is: %p\n", (void *)next);
            printf("Name user entered is: %s\n\n", frName);
        }

        do
        {
            if (strncmp(next->name, frName, sizeOfInt - 1) == 0)
            {
                printf("\n %d \n", next->accountno);
                printf(" %s", next->name);
                printf(" %s \n", next->address);
                returnVal = 1;
            }

            next = next->next;

        } while (next != NULL);

    }

    if (returnVal == -1)
    {
        printf("\nNo such records were found!\n");
    }
    

    return returnVal;

}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: deletes a record based on account number
//
//  Parameters:  struct record **next, int drAccountNo
//
//
//  Return values:  0 : success
//					-1: Failure
//
//
****************************************************************/

int deleteRecord(struct record **start, int drAccountNo)
{
    struct record *prev;
    struct record *current;
    int returnVal;

    returnVal = 0;

    if (debugMode == 1)
    {
        printf("\n\nFunction called - : deleteRecord\n");
        printf("Address of this struc is: %p\n", (void *)start);
        printf("User entered the following account number: %d\n\n", drAccountNo);
    }

    if (*start == NULL)
    {

        returnVal = -1;
        printf("No such record exists!\n\n");

    }

    current = *start;
    prev = *start;

    while (returnVal == 0)
    {
        if (current->accountno == drAccountNo)
        {
            if (current->next == NULL)
            {
                if (prev == current)
                {

                    free(current);
                    current = NULL;
                    prev = NULL;
                    *start = NULL;
                    printf("\nRecord %d deleted!\n\n", drAccountNo);
                    returnVal = 1;

                }
                else
                {

                    prev->next = NULL;
                    free(current);
                    printf("\nRecord %d deleted!\n\n", drAccountNo);
                    current = NULL;
                    returnVal = 1;

                }
            }
            else if (prev == current)
            {

                prev = prev->next;
                current = current->next;
                free(*start);
                printf("\nRecord %d deleted!\n\n", drAccountNo);
                *start = current;
                returnVal = 1;

            }
            else
            {

                prev->next = current->next;
                free(current);
                printf("\nRecord %d deleted!\n\n", drAccountNo);
                current = prev->next;
                returnVal = 1;

            }

        }
        else if (current->next == NULL)
        {

            printf("\nNo such record exists!\n\n");
            returnVal = -1;

        }
        else if (prev == current)
        {

            current = current->next;

        }
        else
        {

            prev = prev->next;
            current = current->next;

        }

    }


    return returnVal;

}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION: : If a file exists, it reads it, and populates the database with its records
//
//  Parameters: struct record **, char []
//
//
//  Return values:  0 : success
//                  -1: Failure. File was not read.
//
//
****************************************************************/

int readfile(struct record **start, char fileName[])
{



    FILE * recordTxt;
    int returnVal;
    char c;
    int addRecordAccNumber;
    char addRecordName[25];
    char addRecordAddress[80];

    recordTxt = fopen(fileName, "r");
    returnVal = 1;

    if (debugMode == 1)
    {
        printf("\nFunction called - : readfile\n");
        printf("Address passed in is: %p\n", (void *)start);
D 2
        printf("User entered the following file name: %d\n\n", fileName);
E 2
I 2
        printf("User entered the following file name: %s\n\n", fileName);
E 2
    }

    if (recordTxt == NULL)
    {
        printf("There was a problem opening the file %s \n\n", fileName);
        returnVal = -1;
    }
    else
    {
        printf("File read in: %s\n\n", fileName);
        while (returnVal == 1)
        {
            if ((c = getc(recordTxt)) == EOF)
            {
                returnVal = 0;

            }
            else
            {
                ungetc(c, recordTxt);
                fscanf(recordTxt, "%d\n", &addRecordAccNumber);
                fgets(addRecordName, 25, recordTxt);
                fgets(addRecordAddress, 80, recordTxt);
                addRecord(start, addRecordAccNumber, addRecordName, addRecordAddress);
            }
        }
        fclose(recordTxt);
    }



    return returnVal;

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION: : If a file exists, it writes to it, otherwise, it creates one
//
//  Parameters: struct record *, char []
//
//
//  Return values:  0 : success
//                  -1: Failure. There are no records to write
//
//
****************************************************************/

int writefile(struct record *start, char fileName[])
{



    int returnVal;
    FILE * recordTxt;
    recordTxt = fopen(fileName, "w");

    if (debugMode == 1)
    {
        printf("\nFunction called - : writefile\n");
        printf("Address passed in is: %p\n", (void *)start);
D 2
        printf("User entered the following file name: %d\n\n", fileName);
E 2
I 2
        printf("User entered the following file name: %s\n\n", fileName);
E 2
    }

    if (start == NULL)
    {

        printf("No records exist!\n\n");
        returnVal = -1;

    }
    else
    {
        do
        {

            fprintf(recordTxt, "%d\n", start->accountno);
            fprintf(recordTxt, "%s", start->name);
            fprintf(recordTxt, "%s\n", start->address);
            start = start->next;

        } while (start != NULL);

        returnVal = 0;

    }

    fclose(recordTxt);


    return returnVal;

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION: : If a file exists, it writes to it, otherwise, it creates one
//
//  Parameters: struct record *, char []
//
//
//  Return values:  0 : success
//                  -1: Failure. There are no records to write
//
//
****************************************************************/

void cleanup(struct record *start)
{


    struct record *current;

    if (debugMode == 1)
    {
        printf("\nFunction called - : cleanup\n");
        printf("Address of this pointer is: %p\n\n", (void *)start);
    }

    if (start == NULL)
    {

    }
    else
    {
        do
        {

            current = start;
            start = start->next;
            free(current);

        } while (start != NULL);
    }
}


E 1
