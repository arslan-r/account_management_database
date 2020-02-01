h27485
s 00004/00000/00008
d D 1.2 19/04/15 16:56:50 arslanr 2 1
c added indef guards
e
s 00008/00000/00000
d D 1.1 19/03/10 14:59:38 arslanr 1 0
c date and time created 19/03/10 14:59:38 by arslanr
e
u
U
f e 0
t
T
I 1
I 2
#ifndef RECORD_H
#define RECORD_H

E 2
struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;

};
E 1
I 2
#endif
E 2
