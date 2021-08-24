/***********************************************************************************************
 * Filename: main.c
 * Version: 1.3.1
 * Student Name: Megan Machkouri
 * Student Number: 041006409
 * Course Name/Number: CST 8234
 * Lab Section: 014
 * Assignment Name: Lab 05
 * Due Date: August 13
 * Submission Date: August 13th
 * Professor Name: Surbhi Barhi
 * Purpose: Allows for Program testing and execution
 * ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Client.c"

void printMenu();
/***********************************************************************************************
 * Function Name: main
 * Purpose: Allows for program execution and testing.
 * Function In parameters: nothing
 * Function Out parameters: 0 or 1 
 * Version: 1.3.1
 * Student Name: Megan Machkouri
***********************************************************************************************/


int main()
    {
    /*Variable that will be used to process data according to menu option entered*/
  
    char buffer[10];
    char menuChoice;
    /*Input return code for scanf*/
    int menuRC;
 
    /*For clearing the buffer*/
    char character;
    int i;
    do
    {
        /*A while loop that prompts user to enter valid menu option*/

        while (1)
        {
            /*prompt user to enter menu option. */
            printMenu();
            menuRC = scanf("%[^\n]", buffer);
            for ( i = 0; buffer[i] != '\0'; i++)
            {
                menuChoice = buffer[i];
            }

            if ((menuRC == 1)&&(menuChoice == 81 || menuChoice == 113|| menuChoice == 53 || menuChoice == 49|| menuChoice == 50|| menuChoice == 51|| menuChoice == 52))
            {

                printf("You pressed: %c", menuChoice);
                
                break;
            }
            do
            {
                scanf("%c", &character);
            } while (character != '\n');
            printf("\nInput not accepted. Please enter a valid option [1-4] or [5]\n");
            continue;

        }
        /*Clear buffer of any remaining data from menu option processing*/
        do
        {
            scanf("%c", &character);
        } while (character != '\n');
        /**/
        switch (menuChoice)
        {
        case '1':
            textFile();
            break;
        case '2':
            updateRecord();
            break;
        case '3':
            newRecord();
            break;
        case '4':
            deleteRecord();
            break;
        case '5':
        /*TODO: free up memory - maybe make a method that does it all?*/
            
            printf("\nHave a great day! :) \n");
            return EXIT_SUCCESS;
            break;
        default:
            printf("Unknown Operator: %c\n", menuChoice);
        }
        printf("\nWhat would you like to do next?\n");

    } while (menuChoice != '5');
    return EXIT_SUCCESS;
}

/*F5unction that prints main menu onto console*/
void printMenu()
{

    printf("\nPlease choose one of the following options:\n[1] Store client info into Text File\n[2] Update existing client information \n[3] Create new client account \n[4] Delete client account record\n[5] Quit \n");
    printf("Please enter action number: ");
}