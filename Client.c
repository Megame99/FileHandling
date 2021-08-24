/*
* Title: Lab 5 - Transaction Processing Program
* Course: CST8234 - C Language
* Term: Summer 2021
* Student Name: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>\
* Student Number: <<< 041006409 >>>
* Function Name: Client
* Purpose: Contains main methods and data tructures for Transaction processing program.
* Version: 1.0
*/
#define Client_c
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Array of pre-existing clients*/
struct clientInfo accounts[MAX_NUM_RECORDS] = {
    {29, "Brown", "Peter", -121.01},
    {33, "Dunn", "George", 142.23},
    {37, "Barker", "Gee", 0.01},
    {88, "Smith", "David", 248.15},
    {99, "Stone", "Sam", 35.68}
    
};

/*This function will print the accounts database to file.*/
void printToFile()
{
    FILE *fp;
    int i;
    /*Attempt to open in write mode if null notify user that file cannot be opened*/
    if ((fp = fopen("accounts.dat", "w")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        /*Print Table Headers*/
        fprintf(fp, "accNo.\tlastName\tfirstName\taccBalance\t\n");
        /*Iterate accounts array*/
        for (i = 0; i < numOfAccounts; i++)
        {
            /*Write Client Info to File*/
            fprintf(fp, "%d\t\t%s\t\t%s\t\t%f\n", accounts[i].AccNo, accounts[i].lastName, accounts[i].firstName, accounts[i].accBalance);
        }

        /*Close File*/
        fclose(fp);
    }
}
/*This function will take in user input in order to modify user attributes and rewrite to file.*/
void textFile()
{
    /*Reset number of accounts*/
    numOfAccounts = 5;

    /*Call Print Function*/
    printToFile();
}

/*This function will take in user input in order to modify user attributes and rewrite to file.*/
void updateRecord()
{
    /*Function Variables*/
    FILE *fp;
    int i = 0;
    int number;
    int input;
    char method;
    double amount;
    char buff[10];
    
    struct clientInfo client;
    /*Attempt to open in append mode if null notify user that file cannot be opened*/
    if ((fp = fopen("accounts.txt", "a+")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        /*Check if database is empty*/
        if (numOfAccounts == 0)
        {
            printf("\nAccount Database is empty.\n");
            return;
        }
        /*Prompt user for account number*/
        printf("\nEnter the account number of the client to be modified: ");
        /*Scan number*/
        input = scanf("%d", &number);
        while (getchar() != '\n')
        {
            /* Chomp stdin (prevents infinite loop)*/
        }
        /*Input Check*/
        if ((input == 1))
        {
            /*Scan Table Header (Garbage Values)*/
            fscanf(fp, "%s %s %s %s", buff, buff, buff, buff);
            /*Iterate Accounts array*/
            for (i = 0; i < numOfAccounts; i++)
            {
                /*Scan Data for match*/
                fscanf(fp, "%d %s %s %lf", &client.AccNo, client.lastName, client.firstName, &client.accBalance);

                if (client.AccNo == number)
                {
                    while (1)
                    {
                        /*Prompt User For charge of payment*/
                        printf("\nEnter charge (+) or payment (-):");
                        scanf("%c%lf", &method, &amount);

                        while (getchar() != '\n')
                        {
                            /* Chomp stdin (prevents infinite loop)*/
                        }
                        /*Add Payment to Account*/
                        if (method == '+')
                        {
                            client.accBalance = client.accBalance + amount;
                            break; /*Exit Loop*/
                        }
                        /*Deduct charge from account*/
                        else if (method == '-')
                        {
                            client.accBalance = client.accBalance - amount;
                            break; /*Exit Loop*/
                        }
                    }
                    /*Reset Client to new balance*/
                    accounts[i].accBalance = client.accBalance;
                    /*Print to File*/
                    printToFile();
                    /*Close File*/
                    fclose(fp);
                    return;
                }
            }
         
        }
        /*Invalid Input*/
        else
        {
            printf("\nInvalid Input. Please Try Again.");
        }
        /*Close File*/
        fclose(fp);
    }
}
/*This function will take in user input for each of the client attributes to be added to the database and written to the file.*/
void newRecord()
{
    /*Function Variables*/
    FILE *fp;
    int i = 0;
    int number;
    int input;
    char buff[10];
    /*Dynamically allocate memory at runtime for new client object*/
    struct clientInfo client;

    /*Attempt to open in append mode if null notify user that file cannot be opened*/
    if ((fp = fopen("accounts.txt", "a+")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        while (1)
        {
            /*Prompt user for new number*/
            printf("\nEnter new account number: ");
            input = scanf("%d", &number);
            while (getchar() != '\n')
            {
                /* Chomp stdin (prevents infinite loop)*/
            }
            /*Input Check*/
            if ((input == 1))
            {
                /*Scan Table Header (Garbage Values)*/
                fscanf(fp, "%s %s %s %s", buff, buff, buff, buff);
                /*Iterate Accounts array*/
                for (i = 0; i < numOfAccounts; i++)
                {
                    /*Check to make sure account number is unique*/
                    fscanf(fp, "%d %s %s %lf", &client.AccNo, client.lastName, client.firstName, &client.accBalance);
                    if (client.AccNo == number)
                    {
                        /*Output Error Message if Duplicate Found*/
                        printf("\nError - Account # %d already exists. \n", number);
                        return;
                    }
                }
                /*Otherwise set account number*/
                client.AccNo = number;
                while (1)
                {
                    /*Prompt User for new info*/
                    printf("\nEnter last name, first Name, balance:\n ");
                    input = scanf("%s %s %lf", client.lastName, client.firstName, &client.accBalance);
                    /*Input Format Check*/
                    if (input != 3)
                    {
                        /*Notify User if Input Format is incorrect*/
                        printf("\nInvalid input. Please enter a string, string and float value.");
                        while (getchar() != '\n')
                        {
                            /* Chomp stdin (prevents infinite loop)*/
                        }
                    }

                    while (getchar() != '\n')
                    {
                        /* Chomp stdin (prevents infinite loop)*/
                    }
                }
                /*Print New Client Info At Bottom Of File*/
                fprintf(fp, "%d\t\t%s\t\t%s\t\t%f\n", client.AccNo, client.lastName, client.firstName, client.accBalance);
                /*Add Account To Database*/
                accounts[numOfAccounts] = client;
                /*Increment Counter*/
                numOfAccounts++;
                break;
            }
            /*Invalid Input Case*/
            else
            {
                printf("\nInvalid Input. Please Try Again.");
                continue;
            }
        }
    }
    /*Close File*/
    fclose(fp);
}
/*This function will take in user input in order to remove an employee from the database and file.*/
void deleteRecord()
{
    /*Function Variables*/
    FILE *fp;
    int i = 0, z;
    int number;
    int input;
    char buff[10];
   
    struct clientInfo client;

    /*Attempt to open in append mode if null notify user that file cannot be opened*/
    if ((fp = fopen("accounts.txt", "a+")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        /*Check if database is empty*/
        if (numOfAccounts == 0)
        {
            printf("\nAccount Database is empty.\n");
            return;
        }
        /* Prompt number for account number*/
        printf("\nEnter account number you wish to delete: ");
        input = scanf("%d", &number);
        while (getchar() != '\n')
        {
            /* Chomp stdin (prevents infinite loop)*/
        }
        /* Input Check */
        if ((input == 1))
        {
            /*Scan Table Header (Garbage Values)*/
            fscanf(fp, "%s %s %s %s", buff, buff, buff, buff);
            /*Iterate Accounts array*/
            for (i = 0; i < numOfAccounts; i++)
            {
                /*Check For Match*/
                fscanf(fp, "%d %s %s %lf", &client.AccNo, client.lastName, client.firstName, &client.accBalance);
                if (client.AccNo == number)
                {
                    /*Delete Corrresponding index*/
                    for (z = i; z < numOfAccounts - 1; z++)
                    {
                        accounts[z] = accounts[z + 1];
                    }
                    /*Decrement Counter*/
                    numOfAccounts--;

                    /*Print Database to FIle*/
                    printToFile();
                    return;
                }
            }
            /*If account number not found Notify User*/
            printf("\nAccount Number does not exist.");
        }
        /*Invalid Input Case*/
        else
        {
            printf("\nInvalid input. Please enter a numerical value.");
        }
    }
    /*Close File*/
    fclose(fp);
}
