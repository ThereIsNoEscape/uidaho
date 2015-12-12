/*  selSort.cpp
 *
 *  Selection Sort test program.
 *
 *  Bruce M. Bolden
 *  November 16, 1998
 */

#include <iostream.h>


#define  aType  int

   //  prototypes
void  SelectionSort( aType A[], int nElements );
int IndexOfSmallest( aType A[], int iStart, int iEnd );

void  PrintArray( aType A[], int nElements );


int main()
{
    aType testArray[] = { 7, 13, 1, 3, 10, 5, 2, 4 };
    int nA = sizeof(testArray)/sizeof(aType);

    cout << "nA: "  << nA << endl;

    cout << "Initial array contents:" << endl;
    PrintArray( testArray, nA );

    SelectionSort( testArray, nA );

    cout << "Final array contents:" << endl;
    PrintArray( testArray, nA );
}


/*  SelectionSort:  Sort and array, A, using a selection
 *  sort algorithm.
 */

void  SelectionSort( aType A[], int nElements )
{
    int iSmallest;
    aType  tmp;
   
    cout << "------------------------" << endl;
    cout << "In SelectionSort():" << endl;

    for( int i = 0 ; i < nElements ; i++ )
    {
        cout << " Pass: " << i << endl;
        iSmallest = IndexOfSmallest( A, i, nElements-1 );
            //  swap
        if( iSmallest > i )
        {
            tmp = A[i];
            A[i] = A[iSmallest];
            A[iSmallest] = tmp;
        }

        PrintArray( A, nElements );
    }

    cout << "SelectionSort() finished" << endl;
    cout << "------------------------" << endl;
}


/*  IndexOfSmallest:  Find index of smallest value.
 */

int IndexOfSmallest( aType A[], int iStart, int iEnd )
{
    int    index = -1;
    aType  aMin = A[iStart];

    for( int i = iStart ; i <= iEnd ; i++ )
    {
        if( A[i] < aMin )
        {
            aMin = A[i];
            index = i;
        }
    }

    cout << "IndexOfSmallest:  " << index << endl;

    return index;
}


/*  Print contents of an array.
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

