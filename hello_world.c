#include <stdio.h>
#include <stdlib.h>

bool characteristic(char numString[], int& c);
bool mantissa(char numString[], int& numerator, int& denominator);

// Main function
void main()
{
	char number[] = "123.456";
	int c, n, d;

	//if the conversion from C string to integers can take place
	if(characteristic(number, c) && mantissa(number, n, d))
	{	
		//do some math with c, n, and d
	}
	else
	{
		//handle the error on input
	}
}

bool characteristic(char numString[], int& c)
{
	// Loop through numString[] and check for white space
		// If char is in ASCII range for +/- and numbers then good
		
		// store characteristic once found in variable
			// Convert to integer
			
			// Store in reference variable c
			
	// return true
}

bool mantissa(char numString[], int& numerator, int& denominator)
{
	// loop through and check for white space (at end) 
	
	// Make sure element is in the ASCII range 
		// Check length of mantissa and store in variable to be used for denomiator
		
		// Store the denomiator as 10^(sizeof(mantissa));
		
		// Store numerator
		
	// return true
	
}
