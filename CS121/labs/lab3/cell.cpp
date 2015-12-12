/* 	cell.cpp
	
	Jonathan Buch
	Section #1
	February 5th, 2015
	Lab #3
 */

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;


int main()
{
	srand(time(NULL));
	int generation = 0;
	int ArrSize = 128;										// Size of the Array
	int FileInt;
	int choice;
	int *ArrPtrOriginal = NULL;
	int *ArrPtrDisplay = NULL;
	ArrPtrOriginal = new int[ArrSize];
	ArrPtrDisplay = new int[ArrSize];
	cout << "Random or File? (0 or 1)" << endl;
	cin >> choice;
	if( !choice )											// Either Random = 0 or File = 1
	{
		for( int i = 0; i < ArrSize; i++ )							// Sets the Values of the Array via pointer to either 0 or 1 randomly
		{
			ArrPtrOriginal[i] = rand() % 2;
		}
	}
	else
	{
		ifstream infile;
		infile.open("file.txt");
		for( int i = 0; i < ArrSize; i++ )
		{	
			infile >> ArrPtrOriginal[i];							// Reads the inputs from a file
		}
	}
	for( int i = 0; i < ArrSize; i++ )								// Sets the second Array, the display array, equal to the first array 
	{
		ArrPtrDisplay[i] = ArrPtrOriginal[i];
	}
	
	while( generation != 20 )									// Runs 20 times for some changes to be observed
	{
		for( int i = 0; i < ArrSize; i++ )							// Prints ArrPtr value for all elements of the array
		{
			cout << ArrPtrDisplay[i];
		}

		cout << "\tGeneration #" << generation + 1 << endl; 					// Prints the generation number

		for( int i = 0; i < ArrSize; i++ )
		{
			if( ArrPtrOriginal[i] == 0 )							// Checks to see if the Array has a value of 1 or 0
			{
				if( ArrPtrOriginal[i - 1] == 1 || ArrPtrOriginal[i + 1] == 1 )		// If it has a 0, it checks if there is a 1 on the element before or after it 
				{
					ArrPtrDisplay[i] = 1;						// If either have a value of 1, the Display array with the same index gets it value changed to 1
				}
			}		 
			else
			{
				ArrPtrDisplay[i] = 0;							// If it has a 1, it is automatically set in the display array to 0	
			}
		}
		for( int i = 0; i < ArrSize; i++ )			
		{
			ArrPtrOriginal[i] = ArrPtrDisplay[i];						// This makes the original array equal to the Display array, which then carries over the changes 
		}

	generation++;

	}
	delete ArrPtrOriginal;										// Pointers are deleted to release memory
	delete ArrPtrDisplay;

	return 0;
}
