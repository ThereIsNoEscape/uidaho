/*	Jonathan Buch
	Section #1
	Lab #13
	April 30th, 2015
	
	filterPtr.cpp
*/

#include <iostream>

using namespace std;

void filterArrayAD( int[], int&, int );
void filterArrayBD( int[], int&, int );
void filter( int[], int&, int, void (*funcPtr)( int[], int&, int ) );

int main()
{
	int count1 = 10;
	int count2 = 10;
	int filt = 5;
	int filter1[] = { 1, 5, 2, 7, 9, 2, 3, 1, 8, 5 };
	int filter2[] = { 4, 7, 11, 25, 15, 2, 1, 7, 0, 8 };
	cout << "Filter 1 Contents" << endl;
	for( int i = 0; i < count1; i++ )
	{
		cout << filter1[i] << endl;
	}
	filter( filter1, count1, filt, &filterArrayAD );
	cout << "Filter 1 contents after filtering values above: " << filt << endl;
	for( int i = 0; i < count1; i++ )
	{
		cout << filter1[i] << endl;
	}
	cout << "Filter 2 Contents" << endl;
	for( int i = 0; i < count2; i++ )
	{
		cout << filter2[i] << endl;
	}
	filter( filter2, count2, filt, &filterArrayBD );
	cout << "Filter 2 contents after filtering values below: " << filt << endl;
	for( int i = 0; i < count2; i++ )
	{
		cout << filter2[i] << endl;
	}
}

void filter( int a[], int& count, int funcconst, void (*funcPtr)( int[], int&, int ) )
{
	funcPtr( a, count, funcconst );
}

void filterArrayAD( int change[], int &count, int filterconst )
{                                                               // AD = Above, Destructive
        int temp[10];
        int track = 0;
        int value = 0;
        int loop = count;
        for( int i = 0; i < loop; i++ )
        {
                if( change[i] <= filterconst )
                {
                        temp[value] = change[i];                // If its in the array
                        value++;                                // and not above the
                }                                               // threshold, increment
                else                                            // both. Otherwise, only
                {                                               // increment i. Also, keep
                        count--;                                // track of the amount of
                        track++;                                // filtered out values
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
{                                                               // BD = Below, Destructive
        int temp[10];
        int track = 0;
        int value = 0;
        int loop = count;
        for( int i = 0; i < loop; i++ )
        {
                if( change[i] >= filterconst )
                {
                        temp[value] = change[i];                // Same as above, just with
                        value++;                                // below the threshold values
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

