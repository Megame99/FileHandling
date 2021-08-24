#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 ** Header (.H) file for Lab 5v- Transaction Processing
 **
 ** Purpose: Declarations of functions 
 ** @version 1.0
 **
 ** @authors
 ** Student #1: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
 **/
/*Max Size Of Database*/
#define MAX_NUM_RECORDS 100
/*Array Counter*/
int numOfAccounts;

void openFile();

/*Structure that represents a client objects*/
struct clientInfo
{
    int AccNo;
    char lastName[20];
    char firstName[20];
    double accBalance;

} Client;



#endif /* helper_h */