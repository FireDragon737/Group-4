#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool characteristic(char numString[], int *c);
bool mantissa(char numString[], int *numerator, int *denominator);

// Main function
int main()
{
	// Test array
	char number[] = "123.456";
	int c, n, d;
	// if the conversion from C string to integers can take place
	
	//if(characteristic(number, &c) && mantissa(number, &n, &d))
	if(characteristic(number, &c) && mantissa(number, &n, &d))
	{	
		
		printf("\n--------\nThe characteristic is: %d\n", c);
		printf("--------\nThe numerator is: %d\n", n);
		printf("--------\nThe denominator is: %d\n--------", d);
	
	}
	else
	{
		//handle the error on input
		printf("INPUT ERROR\n");
		
	}
	
return 0;
}

/*
Function: characterisitc()
Algorithm: Loops through the characters until the decimal is found. After,
the decimal is replaced with the terminating character '\0' to end the 
array on the last number before the decimal. Once the array is updated the
function atoi() converts the string in the char array to an int and is stored
in reference variable c.
Pre-condition: A char array and reference variable are passed in.
Post-condition: Returns boolean based on success.
REMAINING: Check for white space (easy).
*/
bool characteristic(char numString[], int *c)
{
	// Declare variables
	int index = 0;
	char strNum;

	// Loop over white space
	while(numString[index] == ' ')
	{
		index++;
	}
	
	// Loop through numString[] and check for white space
	while(numString[index] != '.' && numString[index] != '\0')
	{
		// Place holder
		strNum = numString[index];

		// If char is in ASCII range for +/- and numbers then good
		if(!(strNum >= '0' && strNum <= '9') && !(strNum == '-' || strNum == '+'))
		{
			// Return false for invalid characters
			return false;
		}
		index++;
	}
	// End the array on the dedcimal with termiinating charcter '\0'
	numString[index] = '\0';
	// Set number to the reference variable c as an int
	*c = atoi(numString);
	// Reset the decimal to original posoition
	numString[index] = '.';

	// Return success
	return true;
}

/*
Function: mantissa()
Algorithm: Finds the number that is after the decimal by impleneting
a nested for loop. The inner loop will enter once the decimal is reached.
Starting with the next charcter after the decimal the inner loop will use
both indexes to move the mantissa values to the front. Once the end is reached
the '\0' character is placed last to end the array with jus the mantissa.
Pre-condition: A charater array and two reference varaiables are passed.
Post-condition: Success returned as Boolean 
*/
bool mantissa(char numString[], int *numerator, int *denominator)
{
	// Declare variables
	int swaps, outIndex = 0, inIndex = 0, iter = 0;
	char strNum, temp;
	//printf("\nThe value at 3 is : %c\n", numString[3]);

	while(numString[iter] == ' ')
	{
		iter++;
	}

	
	// loop through  
	while(numString[outIndex] != '\0')
	{
		// Holds current char at outIndex position in array
		strNum = numString[outIndex];
		//printf("The strNum in mantissa is: %c\n", strNum);

		// Return false if not in ASCII range
		if(!(strNum >= '0' && strNum <= '9') && !(strNum == '-' || 
			strNum == '+' || strNum == '.' || strNum == ' '))
		{
			// return failure
			return false;
		}
		// Check when decimal is found
		if(strNum == '.')
		{	
			// While not at the end of mantissa
			while(numString[outIndex + 1] != '\0' && numString[outIndex + 1] != ' ')
			{
				if(numString)
				// Moves the mantissa to the front of array
				temp = numString[inIndex];
				numString[inIndex] = numString[outIndex + 1];
				numString[outIndex + 1] = temp;
				inIndex++;
				outIndex++;
			}
			// Place the terminating character '\0' at end of mantissa
			numString[inIndex] = '\0';
			numString[outIndex + 1] = '\0';
		}
		// Increment outer index so loop will terminate after inner loop does
		outIndex++;
	}
		// Set numerator to reference variable 
		*numerator = atoi(numString);
		numString[inIndex] = '.';
		//power to apply to 10
		swaps = inIndex;

		// Use value of inIndex for the mantissa length
			// Denominator will be 10^(length of mantissa)
		*denominator = pow(10,swaps);
		
		outIndex -= (swaps + iter);
		inIndex = 0;
		// Loop puts the oriignal array back together 
		while(inIndex < swaps)
		{
			// Store value temporarily to prevent loss
			temp = numString[inIndex];
			numString[inIndex] = numString[outIndex];
			numString[outIndex] = temp;
			// Increment both indexes
			inIndex++;
			outIndex++;
		}
	// Return success		
	return true;	
}
