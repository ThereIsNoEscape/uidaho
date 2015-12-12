/*	Jonathan Buch
 *	Section #1
 *	January 29th, 2015
 *	Lab #2 Command Line Arguments
 *	ShowArgs.cpp
 */

#include<iostream>
#include<cstdlib>

using namespace std;

double multi( int, float );
double add( int, float );
double subtract( int, float );
double divide( int, float );

int main( int argc, char *argv[] ){
	int ArgInt;
	float ArgFlo;
	if( argc > 3 )
	{
		cout << "Arguments Entered: ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		for( int i = 0 ; i < argc ; i++ )					// Prints out all Arguments Entered, including argv[0], which is the file name
		{
			cout << argv[i];
			cout << endl;
		}
		cout << endl;

		cout << "Conversion of Arguments 2 and 3: " << endl;			// NOTE: When I convert argv[2] and argv[3], I know that they technically the third and fourth arguments.
		cout << "---------------------------------" << endl;			// and not the second and third. However, I wanted to not include argv[0] as it is the file name and instead 
		cout << "Argument 2 becomes an Integer" << endl;			// entered values that were entered second and third..
		cout << "Argument 3 becomes a Float\n" << endl;	
		ArgInt = atoi(argv[2]);							// Argument 2 becomes an integer 
		ArgFlo = atof(argv[3]);							// Argument 3 becomes a float
		
		cout << "Calculations: " << endl;
		cout << "--------------" << endl;
		cout << multi( ArgInt, ArgFlo ) << endl;				// Multiplies the Integer and Float
		cout << add( ArgInt, ArgFlo ) << endl;					// Adds ...
		cout << subtract( ArgInt, ArgFlo ) << endl;				// Subtracts ...
		cout << divide( ArgInt, ArgFlo ) << endl;				// Divides ...
	}
	else										// Error Handling for not enough inputs
	{
		cout << "No Input/Not Enough Input Detected: 3 Arguments Required";
		cout << endl;
	}

	return 0;
}

double multi( int a, float b )								// Functions for the manipulation of the entered values
{											// NOTE: If the entered argument was a string or some sort of letter, the value of the converted argument 
	cout << a << " * " << b << endl;						// automatically becomes 0. If the value was a number of some sort of the wrong type such as a double to int,
	return a * b;									// the value becomes the truncated result of the double. This is noted because I looked up some ways on how to 
}											// check if a value is a certian type, but all the answers I found didn't seem to work correctly.

double add( int a, float b )
{
	cout << a << " + " << b << endl;
	return a + b;
}

double subtract( int a, float b )
{
	cout << a << " - " << b << endl;
	return a - b;
}

double divide( int a, float b )
{
	cout << a << " / " << b << endl;
	return a / b;
}
 
