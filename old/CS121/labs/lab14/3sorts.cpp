/*	Jonathan Buch
	Section #1
	Lab #14
	May 7th, 2015

	3sorts.cpp
*/


#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ARRAY = 10000;

// Quicksort Functions
void Quicksort( int a[], int first, int last, int &swapcount, int &comparisons );
int Pivot( int a[], int first, int last, int &swapcount, int &comparisons );
void  Swap( int &v1, int &v2, int &swapcount );
void  PrintArray( int A[], int nElements );

// Selectionsort Functions
void  SelectionSort( int A[], int nElements, int &swapcount, int &comparisons );
int IndexOfSmallest( int A[], int iStart, int iEnd, int &comparisons );

// Mergesort Functions
void  Mergesort( int a[], int first, int last, int &swapcount, int &comparisons );
void  Merge( int a[], int firstLeft, int lastLeft, int firstRight, int lastRight, int &swapcount, int &comparisons );

int main()
{
	int size = 10000;
	int store[size];
	int temp1[size];
	int i = 0;
	int swapcount = 0;
	int comparisons = 0;

	ifstream datafile;
	datafile.open( "rand100.txt" );
	cout << "Filename: rand100.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 99, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 99, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 100, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "rand1000.txt" );
	cout << "Filename: rand1000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 1000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "rand10000.txt" );
	cout << "Filename: rand10000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 9999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 9999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 10000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortHL100.txt" );
	cout << "Filename: sortHL100.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 99, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 99, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 100, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortHL1000.txt" );
	cout << "Filename: sortHL1000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 1000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortHL10000.txt" );
	cout << "Filename: sortHL10000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 9999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 9999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 10000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortLH100.txt" );
	cout << "Filename: sortLH100.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 99, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 99, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 100, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortLH1000.txt" );
	cout << "Filename: sortLH1000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 1000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	i = 0;
	cout << "-----------------------------------------------------------------" << endl;
	datafile.open( "sortLH10000.txt" );
	cout << "Filename: sortLH10000.txt\n" << endl;
	while( !datafile.eof() )
	{
		datafile >> temp1[i];
		i++;
	}
	datafile.close();
	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
		store[i] = temp1[i];
	}
	
	Mergesort( temp1, 0, 9999, swapcount, comparisons );
	
	cout << "Number of Swaps with Mergesort: " << swapcount << endl;
	cout << "Number of Comparisions with Mergesort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	Quicksort( temp1, 0, 9999, swapcount, comparisons );

	cout << "Number of Swaps with Quicksort: " << swapcount << endl;
	cout << "Number of Comparisions with Quicksort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		temp1[i] = store[i];
	}

	SelectionSort( temp1, 10000, swapcount, comparisons );

	cout << "Number of Swaps with Selectionsort: " << swapcount << endl;
	cout << "Number of Comparisions with Selectionsort: " << comparisons << endl;

	swapcount = 0;
	comparisons = 0;

	for( int i = 0; i < size; i++ )
	{
		store[i] = 0;
	}
	for( int i = 0; i < size; i++ )
	{
		temp1[i] = 0;
	}
	cout << "-----------------------------------------------------------------" << endl;
}

void Mergesort( int a[], int first, int last, int &swapcount, int& comparisons ) 
{
    int  middle;

    if( first < last ) {
        middle = (first + last)/2;
        Mergesort( a, first, middle, swapcount, comparisons );
        Mergesort( a, middle+1, last, swapcount, comparisons );
        Merge( a, first, middle, middle+1, last, swapcount, comparisons );
    }
}

void Merge( int a[],
            int firstLeft,  int lastLeft,
            int firstRight, int lastRight, int &swapcount, int &comparisons )
{
    int tempArray[MAX_ARRAY];
    int  index = firstLeft;
    int  firstSave = firstLeft;

        //  Merge segments (array subsets)
    while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
    {
        comparisons++;
        if( a[firstLeft] < a[firstRight] )
        {
           tempArray[index] = a[firstLeft];
           firstLeft++;
        }
        else
        {
           tempArray[index] = a[firstRight];
           firstRight++;
        }
	index++;
    }
        //  Copy remainder of left array into tempArray
    while( firstLeft <= lastLeft )
    {
        tempArray[index] = a[firstLeft];
        firstLeft++;
        index++;
    }

        //  Copy remainder of right array into tempArray
    while( firstRight <= lastRight )
    {
        tempArray[index] = a[firstRight];
        firstRight++;
        index++;
    }

        //  Copy back into original array
    for( index = firstSave ; index <= lastRight ; index++ ){
       a[index] = tempArray[index];
	swapcount++;
    }
}

/*  Swap:  Swap two items (by reference).
 */
void  Swap( int &v1, int &v2, int &swapcount )
{
    int  tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
    swapcount++;
}

void  SelectionSort( int A[], int nElements, int &swapcount, int &comparisons )
{
    int iSmallest;
    int  tmp;

//    cout << "------------------------" << endl;
//    cout << "In SelectionSort():" << endl;

    for( int i = 0 ; i < nElements ; i++ )
    {
//        cout << " Pass: " << i << endl;
        iSmallest = IndexOfSmallest( A, i, nElements-1, comparisons );
            //  swap
        if( iSmallest > i )
        {
            tmp = A[i];
            A[i] = A[iSmallest];
            A[iSmallest] = tmp;
	    swapcount++;
        }
    }

//    cout << "SelectionSort() finished" << endl;
//    cout << "------------------------" << endl;
}

int IndexOfSmallest( int A[], int iStart, int iEnd, int &comparisons )
{
    int index = -1;
    int aMin = A[iStart];

    for( int i = iStart ; i <= iEnd ; i++ )
    {
	comparisons++;
        if( A[i] < aMin )
        {
            aMin = A[i];
            index = i;
        }
    }

//    cout << "IndexOfSmallest:  " << index << endl;

    return index;
}

void Quicksort( int a[], int first, int last, int &swapcount, int &comparisons )
{
    int pivot;

    if( first < last ) {
        pivot = Pivot( a, first, last, swapcount, comparisons );
        Quicksort( a, first, pivot-1, swapcount, comparisons );
        Quicksort( a, pivot+1, last, swapcount, comparisons );
    }
}

int Pivot( int a[], int first, int last, int &swapcount, int &comparisons )
{
    int  p = first;
    int pivot = a[first];

    for( int i = first+1 ; i <= last ; i++ ) {
        comparisons++;
        if( a[i] <= pivot ) {
            p++;
            Swap( a[i], a[p], swapcount );
        }
    }

    Swap( a[p], a[first], swapcount );

    return p;
}

