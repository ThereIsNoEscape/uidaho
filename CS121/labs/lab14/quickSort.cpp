/*  quickSort.cpp
 *
 *  Bruce M. Bolden
 *  November 18, 1998
 */

#include <iostream.h>
#include <fstream>

typedef int aType;


    //  prototypes
void Quicksort( aType a[], int first, int last );
int Pivot( aType a[], int first, int last );

void  Swap( aType &v1, aType &v2 );
void  PrintArray( aType A[], int nElements );


int main()
{ 
    aType testArray[] = { 7, 13, 1, 3, 10, 5, 2, 4 };
    int nA = sizeof(testArray)/sizeof(aType);

    cout << "nA: "  << nA << endl;

    cout << "Initial array contents:" << endl;
    PrintArray( testArray, nA );

    Quicksort( testArray, 0, nA-1 );

    cout << "Final array contents:" << endl;
    PrintArray( testArray, nA );
}

/*  Quicksort:  Sort an array a, using the quicksort
 *  algorithm.
 */

void Quicksort( aType a[], int first, int last ) 
{
    int pivot;

    if( first < last ) {
        pivot = Pivot( a, first, last );
        Quicksort( a, first, pivot-1 );
        Quicksort( a, pivot+1, last );
    }
}


/*  Pivot:  Find and return the index of pivot element.
 */

int Pivot( aType a[], int first, int last ) 
{
    int  p = first;
    aType pivot = a[first];

    for( int i = first+1 ; i <= last ; i++ ) {
        if( a[i] <= pivot ) {
            p++;
            Swap( a[i], a[p] );
        }
    }

    Swap( a[p], a[first] );

    return p;
}


/*  Swap:  Swap two item (by reference).
 */

void  Swap( aType &v1, aType &v2 )
{
    aType  tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
}


/*  PrintArray:  Print contents of an array.
 */

void  PrintArray( aType A[], int nElements )
{
    cout << "[ ";

    for( int i = 0 ; i < nElements ; i++ )
    {
        cout << A[i] ;
        if( i < nElements-1 )
           cout << ", ";
    }

    cout << " ] " << endl;
}

