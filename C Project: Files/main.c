#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include <string.h> //For string functions
#include "Project0.h"  //Include our own header file for the Employee struct.


int main()
{
	//1.  Open the file Input.txt and read in the first line of the file to determine how many Employees we need for our array, and use malloc() to dynamically allocate an array of this size.
	
	//file is opened, then check is done to make sure file opened succesfully
	FILE *fp;
	fp = fopen("Input.txt", "r");

	if(fp == NULL)
	{
		printf("ERROR: could not open file");
	}

	//if file opens successfully, first line is read using fscanf, put into a string, and then converted to an int to malloc the array
	else
	{
	
		int size;
		char length[10];

		fscanf(fp, "%s", length);
		size = atoi(length);

		Employee *myArray = (Employee*)malloc(size * sizeof(Employee));	
	
	//2.  Use a loop to read the Employee information from Project0.txt and write the information to the entries of your array.  Suggestion:  read a single line of the file using fgets() then use sscanf() to parse out the variables from the line.  

		//string, int and double variables created to hold data from file and transfer to array
		char word[10];
		int num;
		double digit;
		int count = 0;

		//using a counter to determine when end of file reached, loop gets data and puts it into employee array
		while(count != size)
		{
			fscanf(fp, "%s %d %lf", word, &num, &digit);
			strcpy(myArray[count].name, word);
			myArray[count].id = num;
			myArray[count].hourlyRate = digit;

			count = count + 1;
		}	

	
	//3.  Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) should be on a single line.  The name should be left justified in a column of width 10.  The IDs are each 6 digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 decimal places.
	
		//using a for loop, prints out each line of info from the array
		int i;


		for(i = 0; i < size; i++)
		{
			//"-10" used to create left-aligned 10-width column, "0.2" used to reduce double to 2 decimal places

			printf("%-10s%d %0.2f\n", myArray[i].name, myArray[i].id, myArray[i].hourlyRate);
		}
		
		//array is freed as task is complete
		free(myArray);

	}

	//file is closed
	close(fp);

	return 0;
}
