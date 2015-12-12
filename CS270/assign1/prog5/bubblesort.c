/*	Jonathan Buch
	September 8th, 2015
	bubblesort.c
	CS 270
	Assignment #1
*/

extern int GlobalArray1[];

void swap( int swap1, int swap2 );

void bubblesort( int N )
{
 int i, j;

 for (i = N - 1; i > 0; --i) 
  for (j = 1; j <= i; ++j) 
   if (GlobalArray1[j-1] > GlobalArray1[j]) 
    swap( j-1, j );
}

void swap( int swap1, int swap2 )
{
	int temp;

	temp = GlobalArray1[swap1];
	GlobalArray1[swap1] = GlobalArray1[swap2];
	GlobalArray1[swap2] = temp;
}

