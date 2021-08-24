
/*Program to understand the use of fwrite()*/
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct record
{
	char name[20];
	int roll;
	float marks;
}student;
int main()
{
	FILE *fptr;
	char ch;
	if((fptr=fopen("myfile.txt", "w"))==NULL)
	{
		printf("File does not exist");
		
	}
	else
	{
		printf("Enter text:\n");
		while((ch=getchar())!=EOF)
			fputc(ch, fptr);
	}
	fclose(fptr);
	return EXIT_SUCCESS;
}
