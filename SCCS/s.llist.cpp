h35195
s 00700/00000/00000
d D 1.1 19/04/15 15:59:38 arslanr 1 0
c date and time created 19/04/15 15:59:38 by arslanr
e
u
U
f e 0
t
T
I 1
#include <cstring>
#include <iostream>
#include <fstream>
#include "llist.h"
#include "record.h"

using namespace std;

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION: : If a file exists, it reads it, and populates the database with its records
//
//  Parameters:
//
//
//  Return values:  0 : success
//                  -1: Failure. File was not read.
//
//
****************************************************************/

int llist::readfile()
{

    ifstream inFile;
    inFile.open(filename);
    int returnVal;
    int addRecordAccNumber;
    char addRecordName[25];
    char addRecordAddress[80];
    returnVal = 1;

#ifdef DEBUGMODE

    cout << "\nFunction called : readfile\n";

#endif

    if (!inFile.is_open())
    {
        returnVal = -1;
    }
    else
    {
        while (returnVal == 1)
        {
            if (inFile.eof())
            {
                returnVal = 0;

            }
            else
            {

                inFile >> addRecordAccNumber;
                inFile.ignore(1, '\n');
                inFile.getline(addRecordName, 25, '\n');
                inFile.getline(addRecordAddress, 80, '*');
                addRecord(addRecordAccNumber, addRecordName, addRecordAddress);
            }
        }

        inFile.close();
    }



    return returnVal;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION: : If a file exists, it writes to it, otherwise, it creates one
//
//  Parameters:
//
//
//  Return values:  0 : success
//                  -1: Failure. There are no records to write
//
//
****************************************************************/

void llist::writefile()
{

    ofstream outFile;
    outFile.open(filename);


#ifdef DEBUGMODE

    cout << "\nFunction called : writefile\n";

#endif

    if (start == NULL)
    {

    }
    else
    {
        do
        {

            outFile << start->accountno << "\n";
            outFile << start->name << "\n";
            outFile << start->address << '*' << "\n";
            start = start->next;

        } while (start != NULL);

    }

    outFile.close();

}

/*****************************************************************
//
//  Function name: reverse
//
//  DESCRIPTION: : reverses the linked list
//
//  Parameters: struct record *
//
//
//  Return values:  struct record *
//
//
****************************************************************/

record * llist::reverse(record * node)
{

#ifdef DEBUGMODE

    cout << "\nFunction called : reverse\n";
    cout << "Object taken in is a struct record pointer " << node << "\n";

#endif

    struct record * current;
    struct record * returnVal;

    if (node == NULL)
    {
        cout << "There are no records to reverse!";
        returnVal = node;
    }
    else if (node->next == NULL)
    {
        returnVal = node;
    }
    else
    {

        current = reverse(node->next);

        node->next->next = node;
        node->next = NULL;
        start = current;
        returnVal = current;
    }


    return returnVal;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION: : cleans up
//
//  Parameters:
//
//
//  Return values:  void
//
//
****************************************************************/

void llist::cleanup()
{
#ifdef DEBUGMODE

    cout << "\nFunction called : cleanup\n";

#endif

    struct record *current;
    if (start == NULL)
    {

    }
    else
    {
        do
        {

            current = start;
            start = start->next;
			delete current;

        } while (start != NULL);
    }


}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION: : constructs a list
//
//  Parameters:
//
//
//  Return values:
//
//
****************************************************************/

llist::llist()
{
#ifdef DEBUGMODE

    cout << "\nFunction called : llist constructor\n";

#endif

    strcpy(filename, "recordTxt");
    start = NULL;
    readfile();


}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION: : constructs a list with an array
//
//  Parameters:    char arrName[]
//
//
//  Return values:
//
//
****************************************************************/

llist::llist(char arrName[])
{

#ifdef DEBUGMODE

    cout << "\nFunction called : llist constructor\n";
    cout << "Object input is : a character array " << arrName << "\n";

#endif
}

/*****************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION: : list deconstructor
//
//  Parameters:
//
//
//  Return values:
//
//
****************************************************************/

llist::~llist()
{
#ifdef DEBUGMODE

    cout << "\nFunction called : llist destructor\n";
#endif

    writefile();
    cleanup();

}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Takes in proper inputs to add in a record
//
//  Parameters:    int arAccountNo, char arName[ ],char arAddress[ ]
//
//
//  Return values:  0 : success
//                  -1: Record was not added
//
//
****************************************************************/

int llist::addRecord(int arAccountNo, char arName[], char arAddress[])
{

    int exitIfZeroOrNegativeOne;
    struct record *current;
    struct record *temp;

#ifdef DEBUGMODE

    cout << "\nFunction called - : addRecord\n";
    cout << "User entered the following account number: " << arAccountNo << "\n";
    cout << "Name user entered is: " << arName << "\n";
    cout << "Address user entered is:  " << arAddress << "\n\n";
#endif

    current = new record;
    temp = new record;

    current = start;
    temp->accountno = arAccountNo;
    strcpy(temp->name, arName);
    strcpy(temp->address, arAddress);
    temp->next = NULL;



    exitIfZeroOrNegativeOne = 1;

    while (exitIfZeroOrNegativeOne == 1)
    {

        if (start == NULL)
        {
            start = temp;
            current = start;
            exitIfZeroOrNegativeOne = 0;
            cout << "\nRecord added!\n";

        }
        else if (current->accountno == arAccountNo)
        {

            delete temp;
            temp = NULL;
            exitIfZeroOrNegativeOne = -1;
            cout << "\nRecord with the account number already exists!\n";


        }
        else if (current->next == NULL)
        {

            current->next = temp;
            current = temp;
            exitIfZeroOrNegativeOne = 0;
            cout << "\nRecord added!\n";

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

int llist::printRecord(int prAccountNo)
{
    int returnVal;
    returnVal = -1;
    struct record *temp;
    temp = new record;
    temp = start;

#ifdef DEBUGMODE

    cout << "\nFunction called - : printRecord\n";
    cout << "User entered the following account number: " << prAccountNo << "\n\n";

#endif


    do
    {

        if (temp->accountno == prAccountNo)
        {
            cout << temp->accountno << "\n";
            cout << temp->name << "\n";
            cout << temp->address << "\n";
            returnVal = 0;
        }


        temp = temp->next;

    } while (temp != NULL);

    if (returnVal == -1)
    {

        cout << "No such records were found!";

    }

    delete temp;
    return returnVal;
}

/*****************************************************************
//
//  Function name: findRecords
//
//  DESCRIPTION: finds a record based on name
//
//  Parameters:  char frName[ ]
//
//
//  Return values:  0 : success
//					-1: Failure
//
//
****************************************************************/

int llist::findRecords(char frName[])
{
    int sizeOfInt;
    int returnVal;
    returnVal = -1;

    struct record *temp;
    temp = new record;
    temp = start;


    if (temp == NULL)
    {

    }
    else
    {


        sizeOfInt = strlen(frName);

#ifdef DEBUGMODE

        cout << "\nFunction called - : findRecords\n");
        cout << "Name user entered is: " << frName << "\n\n";

#endif
        do
        {
            if (strncmp(temp->name, frName, sizeOfInt - 1) == 0)
            {
                cout << temp->accountno << "\n";
                cout << temp->name << "\n";
                cout << temp->address << "\n";
                returnVal = 1;
            }

            temp = temp->next;

        } while (temp != NULL);

    }

    if (returnVal == -1)
    {
        printf("\nNo such records were found!\n");
    }

    delete temp;
    return returnVal;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: deletes a record based on account number
//
//  Parameters:  int drAccountNo
//
//
//  Return values:  0 : success
//					-1: Failure
//
//
****************************************************************/

int llist::deleteRecord(int drAccountNo)
{
    struct record *prev;
    struct record *current;
    int returnVal;

    returnVal = 0;

#ifdef DEBUGMODE

    cout << "\n\nFunction called - : deleteRecord\n";
    cout << "User entered the following account number: " << drAccountNo << "\n\n";

#endif

    if (start == NULL)
    {

        returnVal = -1;
        printf("No such record exists!\n\n");

    }

    current = start;
    prev = start;

    while (returnVal == 0)
    {
        if (current->accountno == drAccountNo)
        {
            if (current->next == NULL)
            {
                if (prev == current)
                {


                    current = NULL;
                    prev = NULL;
                    start = NULL;
                    delete current;
                    cout << "\nRecord " << drAccountNo << " deleted!\n\n";
                    returnVal = 1;

                }
                else
                {

                    prev->next = NULL;
                    delete current;
                    cout << "\nRecord " << drAccountNo << " deleted!\n\n";
                    current = NULL;
                    returnVal = 1;

                }
            }
            else if (prev == current)
            {

                prev = prev->next;
                current = current->next;
                delete start;
                cout << "\nRecord " << drAccountNo << " deleted!\n\n";
                start = current;
                returnVal = 1;

            }
            else
            {

                prev->next = current->next;
                delete current;
                cout << "\nRecord " << drAccountNo << "deleted!\n\n";
                current = prev->next;
                returnVal = 1;

            }

        }
        else if (current->next == NULL)
        {

            cout << "\nNo such record exists!\n\n";
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
//  Function name: reverse
//
//  DESCRIPTION: : public reverses the linked list
//
//  Parameters: struct record *
//
//
//  Return values:  struct record *
//
//
****************************************************************/

void llist::reverse()
{

#ifdef DEBUGMODE

    cout << "\nFunction called : reverse\n";

#endif

    reverse(start);

}

/*****************************************************************
//
//  Function name: <<
//
//  DESCRIPTION: : friend function to print all records
//
//  Parameters: llist
//
//
//  Return values:
//
//
****************************************************************/

ostream & operator <<(ostream & out, llist LinkedList)
{
#ifdef DEBUGMODE

    cout << "\nFunction called : Overloaded << operator\n";
    cout << "Object being passed in is : LinkedList\n";
    cout << "Object being passed in is : out stream\n";

#endif

    if (LinkedList.start == NULL)
    {

        out << "\nNo records exist!\n";

    }
    else
    {
        do
        {

            out << LinkedList.start->accountno << "\n" << LinkedList.start->name << "\n" << LinkedList.start->address << "\n";
            LinkedList.start = LinkedList.start->next;

        } while (LinkedList.start != NULL);

    }

    return out;
}

E 1
