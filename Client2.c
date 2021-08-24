/*
* Title: Assignment 2 - Employee Database Implementation
* Course: CST8234 - C Language
* Term: Summer 2021
* Team:
* Student #1: <<< Hanieh Salimian (sali0100@algonquinlive.com) >>>
* Student #2: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
* Function Name: employee
 * Purpose: Allows declaration and initialization of employees to be added to database
 * Version: 1.0
*/
#define Client_c
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int numOfAccounts;

struct clientInfo
{
    int AccNo;
    char lastName[20];
    char firstName[20];
    double accBalance;
    struct Client *next;
}Client;
struct clientInfo *head;

struct clientInfo accounts[5] = {
                        {29, "Brown", "Peter", -121.01},
                        {33, "Dunn", "George", 142.23},
                        {37, "Barker", "Gee", 0.01},
                        {88, "Smith", "David", 248.15},
                        {99, "Stone", "Sam", 35.68}
                    };
void addToDatabase(struct clientInfo newClient)
{
    /* Allocate employee node to memory */
    struct clientInfo *client= (struct clientInfo *)malloc(sizeof(struct clientInfo));
    /*When the database is empty, head is initialised and is used to store the new employee's attributes*/
    if (numOfAccounts == 0)
    {
        head = (struct clientInfo *)malloc(sizeof(struct clientInfo));
        strcpy(head->lastName, newClient.lastName);
        head->AccNo = newClient.AccNo;
        head->accBalance = newClient.accBalance;
        strcpy(head->firstName, newClient.firstName);
        head->next = NULL;
    }
    /*If the database is populated, the new employee is added to the head of the (database) linked list*/
    else
    {
        /*Assign the employee attributes to the new memory that holds the struct employee*/
        strcpy(client->lastName, newClient.lastName);
        client->AccNo = newClient.AccNo;
       client->AccNo = newClient.AccNo;
       strcpy(client->firstName, newClient.firstName);
        /*Assign the value of head to the next part of inserted Employee node and now newly inserted employee node points to the next node which WAS the beginning node */
        client->next = head;
        /*Head will now point to the newly inserted node, which is the first node of the LL*/
        head = client;
    }
    printf("Newly added employee information: %s %s %d %f\n", head->lastName, head->firstName, head->AccNo, head->accBalance);
    numOfAccounts++;
}

void textFile(){
FILE *fp;
int i;
struct clientInfo client1 = {29, "Brown", "Peter", -121.01}; 
struct clientInfo client2 = {33, "Dunn", "George", 142.23}; 
struct clientInfo client3 = {37, "Barker", "Gee", 0.01}; 
struct clientInfo client4 = {88, "Smith", "David", 248.15};
struct clientInfo client5 = {99, "Stone", "Sam", 35.68};
addToDatabase(client1);
addToDatabase(client2);
addToDatabase(client3);
addToDatabase(client4);
addToDatabase(client5);
struct clientInfo *ptr = head;
    if((fp=fopen("accounts2.dat","wb"))==NULL){
        printf("File could not be opened\n");
    }
    else{
        fprintf(fp, "accNo.\tlastName\tfirstName\taccBalance\t\n");
        while(ptr != NULL){
            fprintf(fp, "%d\t\t%s\t\t%s\t\t%f\n", ptr->AccNo, ptr->lastName, ptr->firstName, ptr->accBalance); 
            ptr = ptr->next;
        }
        
            
           
       fclose(fp);
        
    }

}



void updateRecord(){
    struct clientInfo client;
    FILE *fp, *fp2;
    int i = 0;
    int number;
    int input;
    char method;
    double amount;
    char buff[10];
   
    if((fp=fopen("accounts2.dat","a+"))==NULL){
        printf("File could not be opened\n");
    }
    else{
       
       printf("\nEnter the account number of the client to be modified: ");
       input = scanf("%d", &number);
       while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
    if ((input == 1))
    {
        fscanf(fp,"%s %s %s %s", buff, buff, buff, buff);
        for (i = 0; i < numOfAccounts;i++){
            fscanf(fp,"%d %s %s %f", client.AccNo, client.lastName, client.firstName, client.accBalance);
            if (client.AccNo == number)
            {
                while (1)
                    {
               printf("\nEnter charge (+) or payment (-):");
                scanf("%c%f", &method, &amount);
                while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
                    if (method == '+'){
                        client.accBalance = client.accBalance + amount;
                        break;
                    }
                    else if (method == '-'){
                        client.accBalance = client.accBalance - amount;
                        break;
                    }
                }
                    accounts[i].accBalance = client.accBalance;
                    
        if((fp2=fopen("accounts2.dat","wb"))==NULL){
            printf("File could not be opened\n");
         }
        else{
            fprintf(fp2, "accNo.\tlastName\tfirstName\taccBalance\t\n");
            for (i = 0; i < (sizeof(accounts)/sizeof(accounts[0])); i++)
            {
                fprintf(fp2, "%d\t\t%s\t\t%s\t\t%f\n", accounts[i].AccNo, accounts[i].lastName, accounts[i].firstName, accounts[i].accBalance); 
            }
        
                i = numOfAccounts;     
           
                fclose(fp2);
        
         }

        i = numOfAccounts;     
        }
           
          
        
        
        /* code */
    }
    
       fclose(fp);
        
    }    
    }

}

void newRecord(){
    struct clientInfo client;
    FILE *fp;
    int i = 0;
    int number;
    int input;
    char buff[10];
   
    if((fp=fopen("accounts2.dat","a+"))==NULL){
        printf("File could not be opened\n");
    }
    else{
       
       printf("\nEnter new account number: ");
       input = scanf("%d", &number);
       while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
    if ((input == 1))
    {
        fscanf(fp,"%s %s %s %s", buff, buff, buff, buff);
        for (i = 0; i < numOfAccounts;i++){
            fscanf(fp,"%d %s %s %f", &client.AccNo, client.lastName, client.firstName, &client.accBalance);
            if (client.AccNo == number)
            {
                printf("\nError - Account # %d already exists. \n", number);
                return;
            }
        }
        client.AccNo = number;
        printf("\nEnter last name, first Name, balance:\n ");
        input = scanf("%s %s %f",client.lastName, client.firstName, &client.accBalance);
         while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
        fprintf(fp, "%d\t\t%s\t\t%s\t\t%f\n", client.AccNo, client.lastName, client.firstName, client.accBalance);
        accounts[numOfAccounts] = client;
        numOfAccounts++;
        }
    }
    fclose(fp);
}

void deleteRecord(){
        struct clientInfo client;
    FILE *fp;
    int i = 0;
    int number;
    int input;
    char buff[10];
   
    if((fp=fopen("accounts2.dat","a+"))==NULL){
        printf("File could not be opened\n");
    }
    else{
       
       printf("\nEnter new account number: ");
       input = scanf("%d", &number);
       while (getchar() != '\n')
                {
                    /* Chomp stdin (prevents infinite loop)*/
                }
    if ((input == 1))
    {
        fscanf(fp,"%s %s %s %s", buff, buff, buff, buff);
        for (i = 0; i < numOfAccounts;i++){
            fscanf(fp,"%d %s %s %f", &client.AccNo, client.lastName, client.firstName, &client.accBalance);
            if (client.AccNo == number)
            {
        
                fprintf(fp, "%d\t\t%s\t\t%s\t\t%f\n", 0, "", "", 0);
                return;
            }
        }
        }
    }
    fclose(fp);
}