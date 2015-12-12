/*	Jonathan Buch
	Section #1
	Lab #10
	April 9th, 2015
	
	filtertest.cpp
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

void filterArrayAD( int [], int &, int );
void filterArrayBD( int [], int &, int );
void cpyfilterAND( int [], int [], int &, int );
void cpyfilterBND( int [], int [], int &, int );

int main()
{
	LinkedList LinkedList1, LinkedList2, LinkedList3, LinkedList4, temp1, temp2;
	int constant = 10;
	int filterconst = 5;
	int count = constant;
	int count2, count3, count4;
	for( int i = 0; i < constant; i++ )		// All Linked Lists with same
	{						// values
		LinkedList1.AddNode( i );
		LinkedList2.AddNode( i );
		LinkedList3.AddNode( i );
		LinkedList4.AddNode( i );
	}
	
	cout << "Print contents of LinkedLists" << endl;	

	LinkedList1.Print();				// Print all the Lists
	cout << endl;
	LinkedList2.Print();
	cout << endl;
	LinkedList3.Print();
	cout << endl;
	LinkedList4.Print();
	cout << endl;

	cout << "Activating LinkedList Filters... Threshold = " << filterconst << endl;
	LinkedList1.DRemoveAboveLimit( filterconst );	// Call each filter function
	LinkedList2.DRemoveBelowLimit( filterconst );
	LinkedList3.NDRemoveAboveLimit( filterconst, temp1 );
	LinkedList4.NDRemoveBelowLimit( filterconst, temp2 );
	cout << "Printing Contents Again" << endl;

	LinkedList1.Print();
	LinkedList2.Print();
	temp1.Print();
	temp2.Print();
	cout << endl;
	cout << endl;

	
	int filter1[] = { 1, 5, 2, 7, 9, 2, 3, 1, 8, 5 };	// Declare all of the Arrays
	int filter2[] = { 6, 1, 3, 9, 1, 3, 4, 8, 5, 2 };
	int filter3[] = { 7, 3, 1, 5, 9, 4, 1, 2, 8, 6 };
	int filter4[] = { 12, 5, 2, 1, 8, 9, 7, 6, 4, 2 };	
	int newfilter[constant];
	int newfilter2[constant];
	count2 = count;
	count3 = count;
	count4 = count;
	cout << "Print Elements in Each Array" << endl;

	cout << "1) ";
	for( int i = 0; i < constant; i++ )
	{
		cout << filter1[i] << " ";
	}
	cout << endl;
	cout << "2) ";
	
	for( int i = 0; i < constant; i++ )
		{
		cout << filter2[i] << " ";
	}
	cout << endl;
 	cout << "3) ";
	for( int i = 0; i < constant; i++ )
	{
		cout << filter3[i] << " ";
	}
	cout << endl;
	cout << "4) ";
	for( int i = 0; i < constant; i++ )
	{
		cout << filter4[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << endl;
	cout << "Activating Filters... Threshold = " << filterconst << "\n1 = DestructiveAbove, 2 = Destructive Below, 3 = NonDestructiveAbove, 4 = NonDestructiveBelow" << endl;

	filterArrayAD( filter1, count, filterconst );			// Call the fucntions to 
									// filter the arrays
	filterArrayBD( filter2, count2, filterconst );

	cpyfilterAND( filter3, newfilter, count3, filterconst );

	cpyfilterBND( filter4, newfilter2, count4, filterconst );

	cout << "1) ";
	for( int i = 0; i < count; i++ )
	{
		cout << filter1[i] << " ";
	}
	cout << endl;
	cout << "2) ";
	
	for( int i = 0; i < count2; i++ )
		{
		cout << filter2[i] << " ";
	}
	cout << endl;
 	cout << "3) ";
	for( int i = 0; i < count3; i++ )
	{
		cout << newfilter[i] << " ";
	}
	cout << endl;
	cout << "4) ";
	for( int i = 0; i < count4; i++ )
	{
		cout << newfilter2[i] << " ";
	}
	cout << endl;
}

void filterArrayAD( int change[], int &count, int filterconst )
{								// AD = Above, Destructive
	int temp[10];
	int track = 0;
	int value = 0;
	int loop = count;
	for( int i = 0; i < loop; i++ )
	{
		if( change[i] <= filterconst )
		{
			temp[value] = change[i];		// If its in the array
			value++;				// and not above the 
		}						// threshold, increment
		else						// both. Otherwise, only
		{						// increment i. Also, keep
			count--;				// track of the amount of
			track++;				// filtered out values
		}
	}
	for( int i = 0; i < count; i++ )
	{
		change[i] = temp[i];
	} 
	for( int i = count; i < count + track; i++ )
	{
		change[i] = NULL;
	}
}  

void filterArrayBD( int change[], int &count, int filterconst )
{								// BD = Below, Destructive
	int temp[10];
	int track = 0;
	int value = 0;
	int loop = count;
	for( int i = 0; i < loop; i++ )
	{
		if( change[i] >= filterconst )
		{
			temp[value] = change[i];		// Same as above, just with
			value++;				// below the threshold values
		}
		else
		{
			count--;
			track++;
		}
	}
	for( int i = 0; i < count; i++ )
	{
		change[i] = temp[i];
	} 
	for( int i = count; i < count + track; i++ )
	{
		change[i] = NULL;
	}
}  

void cpyfilterAND( int change[], int temp[], int &count, int filterconst )
{								// AND = Above, Non-Destructive
	int track = 0;
	int value = 0;
	int loop = count;
	for( int i = 0; i < loop; i++ )
	{
		if( change[i] <= filterconst )
		{
			temp[value] = change[i];
			value++;
		}
		else
		{
			count--;
			track++;
		}
	}
	for( int i = count; i < count + track; i++ )		// Similar to the above functions
	{							// but instead change the temp array
		temp[i] = NULL;					// instead of the original
	}
}  

void cpyfilterBND( int change[], int temp[], int &count, int filterconst )
{								// BND = Below, Non-Destructive
	int track = 0;
	int value = 0;
	int loop = count;
	for( int i = 0; i < loop; i++ )
	{
		if( change[i] >= filterconst )
		{
			temp[value] = change[i];
			value++;
		}
		else
		{
			count--;
			track++;
		}
	}
	for( int i = count; i < count + track; i++ )
	{
		temp[i] = NULL;
	}
}  
