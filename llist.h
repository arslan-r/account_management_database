#include "record.h"
#ifndef LLIST_H
#define LLIST_H

#include <fstream>

using namespace std;

class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    void        writefile();
    record *    reverse(record *);
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();

    int addRecord(int, char[], char[]);
    int printRecord(int);
    int findRecords(char[]);
    int deleteRecord(int);
    void reverse();

    friend ostream & operator <<(ostream & out, llist LinkedList);
};

#endif