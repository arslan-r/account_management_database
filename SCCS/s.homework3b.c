h18777
s 00308/00000/00000
d D 1.1 19/03/10 15:29:41 arslanr 1 0
c date and time created 19/03/10 15:29:41 by arslanr
e
u
U
f e 0
t
T
I 1
/*****************************************************************
//
//  NAME:        Arslan Rakhmankulov
//
//  HOMEWORK:    homework3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 7, 2019
//
//  FILE:        homework3b.c
//
//  DESCRIPTION: Gives user a menu to chose what they want to do with their records
//               Asks user for proper input. Manages a database.
//
//
//
****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "dbfunctionsheaders.h"


void getaddress (char gaInt[ ], int gaIndex);
int debugMode = 0;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Gives user a menu to chose what they want to do with their records
//                 Asks user for proper input.
//
//  Parameters:
//
//
//  Return values:  0 : success
//
//
****************************************************************/

int main(int argc, char** argv)
{
    int index = 0;
    char userSelection[100];
    char userAddress[80];
    struct record * start;
    char userAccNo[100];
    int userInt;
    char *userString;
    int exitIfOne;
    int i;
    int position;
    int strngLength;
    int runProg = 0;
    char name[25];
    char filepath[] = "recordTxt";

    start = NULL;

    

    if (argc == 2)
    {
        if ((strcmp("debug", argv[1]) == 0))
        {

            debugMode = 1;

        }
        else
        {

            printf("debug: missing file operand \n");
            printf("Try 'debug' if you want to debug\n");
            exit(0);

        }
    }
    else if (argc == 1)
    {

        printf("Try 'debug' if you want to debug\n");

	}
	else if (argc > 2)
	{
		printf("debug: missing file operand \n");
		printf("Try 'debug' if you want to debug\n");
		exit(0);
	}

    if (debugMode == 1)
    {

        printf("Function called - : main\n");
        printf("argc is %d\n", argc);
        printf("argv arguments are as follows\n");

        for(i = 1; i < argc; i++)
        {

            printf("%s", argv[i]);

        }
        printf("\n");

    }

	readfile(&start, filepath);

    while (runProg == 0)
    {

        printf("\n\nChose an option by typing in its number\n");
        printf("1. Add a new record in the database\n");
        printf("2. Print information about a record using the account number as the key\n");
        printf("3. Print all information in the database\n");
        printf("4. Print records whose names start with the given string as a key\n");
        printf("5. Delete an existing record from the database using the account number as a key\n");
        printf("6. Quit the program\n");

        userSelection[0] = getchar();
        while (getchar() != '\n');

        while ((userSelection[0] != '1') && (userSelection[0] != '2') && (userSelection[0] != '3') && (userSelection[0] != '4') && (userSelection[0] != '5') && (userSelection[0] != '6') && (userSelection[1] != '\n'))
        {

                printf("You did not enter 1 through 6! Try again : ");
                userSelection[0] = getchar();
                while (getchar() != '\n');


        }

        if (userSelection[0] == '1')
        {
            exitIfOne = 0;
            while (exitIfOne == 0)
            {
                printf("\nEnter your account number: \n");
                fgets(userAccNo, sizeof(userAccNo), stdin);
                userInt = strtol(userAccNo, &userString, 10);
                if (*userString == '\n')
                {
                    exitIfOne = 1;
                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            printf("Enter your name: \n");

            fgets(name, 25, stdin);
            position = 0;
            strngLength = strlen(name);
            while (position < strngLength)
            {
                if ((name[position] == '0') || (name[position] == '1') || (name[position] == '2') || (name[position] == '3') || (name[position] == '4') || (name[position] == '5') || (name[position] == '6') || (name[position] == '7') || (name[position] == '8') || (name[position] == '9'))
                {
                    printf("Lets try enter your name again. Letters only!");
                    fgets(name, 25, stdin);
                    position = 0;
                }
                else
                {
                    position++;
                }
            }

            getaddress(userAddress, index);
            addRecord(&start, userInt, name, userAddress);


        }

        if (userSelection[0] == '2')
        {

            exitIfOne = 0;
            while (exitIfOne == 0)
            {

                printf("Enter your account number: \n");
                fgets(userAccNo, sizeof(userAccNo), stdin);
                userInt = strtol(userAccNo, &userString, 10);

                if (*userString == '\n')
                {

                    exitIfOne = 1;

                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            printRecord(start, userInt);
        }

        if (userSelection[0] == '3')
        {
            printAllRecords(start);
        }

        if (userSelection[0] == '4')
        {
            printf("\nEnter your name: \n");

            fgets(name, 25, stdin);
            position = 0;
            strngLength = strlen(name);
            while (position < strngLength)
            {
                if ((name[position] == '0') || (name[position] == '1') || (name[position] == '2') || (name[position] == '3') || (name[position] == '4') || (name[position] == '5') || (name[position] == '6') || (name[position] == '7') || (name[position] == '8') || (name[position] == '9'))
                {
                    printf("Lets try enter your name again. Letters only!");
                    fgets(name, 25, stdin);
                    position = 0;
                }
                else
                {
                    position++;
                }
            }


            findRecords(start, name);
        }

        if (userSelection[0] == '5')
        {

            exitIfOne = 0;
            while (exitIfOne == 0)
            {

                printf("\nEnter your account number: \n");
                fgets(userAccNo, sizeof(userAccNo), stdin);
                userInt = strtol(userAccNo, &userString, 10);
                if (*userString == '\n')
                {
                    exitIfOne = 1;
                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            deleteRecord(&start, userInt);
        }

        if (userSelection[0] == '6')
        {

            writefile(start, filepath);
            cleanup(start);
            printf("Goodbye!");
            runProg = 1;
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   asks users for their address.
//
//  Parameters:
//
//
//  Return values:  void
//
//
****************************************************************/

void getaddress (char gaArr[ ], int gaIndex)
{
    int startingIndex = gaIndex;
    char c = EOF;
    printf("Enter your address(es). Enter * when you are finished to submit: ");
    while ((c = getchar()) != '*')
    {
        gaArr[gaIndex++] = c;
    }
    gaArr[gaIndex] = '\0';
    while (getchar() != '\n');

    if (debugMode == 1)
    {
        printf("\n\nFunction called - : getaddress\n");
        printf("Address user entered is:  %s\n", gaArr);
        printf("Starting index is %d, final index is %d\n\n", startingIndex, gaIndex);
    }
}
E 1
