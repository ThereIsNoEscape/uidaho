/*  mergeSort.cpp
 *
 *  Bruce M. Bolden
 *  November 18, 1998
 */

#include <iostream.h>

typedef int aType;   //  array type

const int MAX_ARRAY = 25;

    //  prototypes
void  Mergesort( aType a[], int first, int last );
void  Merge( aType a[], 
             int firstLeft,  int lastLeft, 
             int firstRight, int lastRight );

void  Swap( aType &v1, aType &v2 );
void  PrintArray( aType A[], int nElements );

int main()
{
    //aType testArray[] = { 7, 13, 1, 3, 10, 5, 2, 4 };
    aType testArray[] = { 7, 13, 1, 4 };
    int nA = sizeof(testArray)/sizeof(aType);

    cout << "nA: "  << nA << endl;

    cout << "Initial array contents:" << endl;
    PrintArray( testArray, nA );

    Mergesort( testArray, 0, nA-1 );

    cout << "\nFinal array contents:" << endl;
    PrintArray( testArray, nA );
}


/*  Mergesort:  Do a mergesort on array a.  
 *  Note:  This is a recursive routine.
 */

void Mergesort( aType a[], int first, int last ) 
{
    int  middle;

    cout << "\nMergesort:" << endl;
    cout << "Mergesort::first: " << first << endl;
    cout << "Mergesort::last:  " << last  << endl;

    if( first < last ) {
        middle = (first + last)/2;
        cout << "Mergesort::middle:  " << middle << endl;
        Mergesort( a, first, middle);
        Mergesort( a, middle+1, last );
        Merge( a, first, middle, middle+1, last );
    }
}

/*  Merge:  Merge two segments of an array together.  
 */

void Merge( aType a[], 
            int firstLeft,  int lastLeft, 
            int firstRight, int lastRight ) 
{
    aType tempArray[MAX_ARRAY];
    int  index = firstLeft;
    int  firstSave = firstLeft;

    cout << "Merge::firstLeft:  " << firstLeft   << endl;
    cout << "Merge::lastLeft:   " << lastLeft    << endl;
    cout << "Merge::firstRight: " << firstRight  << endl;
    cout << "Merge::lastRight:  " << lastRight   << endl;

        //  Merge segments (array subsets)
    while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
    {
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
    for( index = firstSave ; index <= lastRight ; index++ )
        a[index] = tempArray[index];
}


/*  Swap:  Swap two items (by reference).
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

