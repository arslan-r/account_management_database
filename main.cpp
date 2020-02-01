/*****************************************************************
//
//  NAME:        Arslan Rakhmankulov
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 12, 2019
//
//  FILE:        main.cpp
//
//  DESCRIPTION: main function for project 2
//               big thank you to leetcode.com, geeksforgeeks.com, and cplusplus.com
//
//
****************************************************************/

#include <iostream>
#include "llist.h"
#include <cstdlib>
#include <cstring>
using namespace std;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:  provides UI for the user
//
//  Parameters:
//                 
//
//  Return values:  0 : success
//
//
****************************************************************/


int main()
{
    char userSelection[100];
    char userAddress[80];
    char userAccNo[100];
    int userInt;
    char *userString;
    int exitIfOne;
    int position;
    int strngLength;
    int runProg = 0;
    char name[25];
    llist LinkedList;

    while (runProg == 0)
    {
        cout << "\n\nChose an option by typing in its number\n";
        cout << "1. Add a new record in the database\n";
        cout << "2. Print information about a record using the account number as the key\n";
        cout << "3. Print all information in the database\n";
        cout << "4. Print records whose names start with the given string as a key\n";
        cout << "5. Delete an existing record from the database using the account number as a key\n";
        cout << "6. Reverse the list of records\n";
        cout << "7. Quit the program\n";


        cin >> userSelection;


        while ((userSelection[0] < '1') || (userSelection[0] > '7'))
        {

            cout << "You did not enter 1 through 6! Try again : ";
            cin >> userSelection;

        }
        cin.ignore();


        if (userSelection[0] == '1')
        {
            exitIfOne = 0;
            while (exitIfOne == 0)
            {
                printf("\nEnter your account number: \n");
                cin.getline(userAccNo, 100);
                userInt = strtol(userAccNo, &userString, 10);
                if (*userString == '\0')
                {
                    exitIfOne = 1;
                    cout << "User entered the number :" << userInt << "\n";
                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            cout << "Enter your name :\n";

            cin.getline(name, 25);
            position = 0;
            strngLength = strlen(name);
            while (position < strngLength)
            {
                if ((name[position] == '0') || (name[position] == '1') || (name[position] == '2') || (name[position] == '3') || (name[position] == '4') || (name[position] == '5') || (name[position] == '6') || (name[position] == '7') || (name[position] == '8') || (name[position] == '9'))
                {
                    cout << "Lets try enter your name again. Letters only!";
                    cin.getline(name, 25);
                    position = 0;
                }
                else
                {
                    position++;
                }
            }


            cout << "Enter your address(es). Enter * when you are finished to submit: ";

            cin.getline(userAddress, 80, '*');

            LinkedList.addRecord(userInt, name, userAddress);

        }



        if (userSelection[0] == '2')
        {

            exitIfOne = 0;
            while (exitIfOne == 0)
            {
                printf("\nEnter your account number: \n");
                cin.getline(userAccNo, 100);
                userInt = strtol(userAccNo, &userString, 10);
                if (*userString == '\0')
                {
                    exitIfOne = 1;
                    cout << "User entered the number :" << userInt << "\n";
                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            LinkedList.printRecord(userInt);

        }

        if (userSelection[0] == '3')
        {

            cout << LinkedList;
        }

        if (userSelection[0] == '4')
        {
            cout << "Enter your name :\n";

            cin.getline(name, 25);
            position = 0;
            strngLength = strlen(name);
            while (position < strngLength)
            {
                if ((name[position] == '0') || (name[position] == '1') || (name[position] == '2') || (name[position] == '3') || (name[position] == '4') || (name[position] == '5') || (name[position] == '6') || (name[position] == '7') || (name[position] == '8') || (name[position] == '9'))
                {
                    cout << "Lets try enter your name again. Letters only!";
                    cin.getline(name, 25);
                    position = 0;
                }
                else
                {
                    position++;
                }
            }

            LinkedList.findRecords(name);
        }

        if (userSelection[0] == '5')
        {

            exitIfOne = 0;
            while (exitIfOne == 0)
            {
                printf("\nEnter your account number: \n");
                cin.getline(userAccNo, 100);
                userInt = strtol(userAccNo, &userString, 10);
                if (*userString == '\0')
                {
                    exitIfOne = 1;
                    cout << "User entered the number :" << userInt << "\n";
                }
                else
                {
                    printf("Try again. Please enter numbers 0 - 9\n");
                }
            }

            LinkedList.deleteRecord(userInt);
        }

        if (userSelection[0] == '6')
        {

            LinkedList.reverse();

        }

        if (userSelection[0] == '7')
        {


            cout << "Goodbye!\n";
            runProg = 1;
        }

    }
    return 0;

}

