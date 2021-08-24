/*
* Title: Lab 5 - Code Segments
* Course: CST8234 - C Language
* Term: Summer 2021
* Student Name: <<< Megan Machkouri (mach0079@algonquinlive.com) >>>
* Student Number: <<< 041006409 >>>
* Function Name: CodeSegments.c
* Purpose: Contains required Code Segments
* Version: 1.0
*/

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*This function will open in read mode.*/
void function1(){
    FILE *fPtr;
 
    fPtr=fopen("picnic.dat", "r");
	if(fPtr==NULL)
	{
		printf("Error in opening file");
		exit(1);
	}
}
/*This function will open in write mode.*/
void function2(){
    FILE *fPtr;
 
    fPtr=fopen("random.dat", "w");
	if(fPtr==NULL)
	{
		printf("Error in opening file");
		exit(1);
	}
}
/*This function will read data from file.*/
void function3(){
    FILE *fp;
    int studentID;
    char trailName[10];
    float currentGPA;
    fp=fopen("picnic.dat", "r");
	if(fp==NULL)
	{
		printf("Error in opening file");
		exit(1);
	}

    fscanf(fp,"%d %s %f", &studentID, trailName, &currentGPA);

}
/*This function will print data to file.*/
void function4(){
    FILE *fp;
    int studentID = 12345;
    char trailName[10] = "John Doe";
    float currentGPA = 3.95;
    fp=fopen("picnic.dat", "r");
	if(fp==NULL)
	{
		printf("Error in opening file");
		exit(1);
	}

    fprintf(fp,"%d %s %f", studentID, trailName, currentGPA);
}