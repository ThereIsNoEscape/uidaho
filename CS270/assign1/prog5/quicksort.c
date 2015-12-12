/*	Jonathan Buch
	September 8th, 2015
	quicksort.c
	CS 270
	Assignment #1
*/


extern int GlobalArray2[];

void quicksort( int left, int right );
void swapv2( int swap1, int swap2 ); 

void quicksort( int left, int right ) 
{
 int i, j, v;

 if (right > left)
 {
  v = GlobalArray2[right];
  i = left - 1;
  j = right;

  do
  {
   do
    i = i + 1;
   while ( GlobalArray2[i] < v);

   do
    j = j - 1;
   while (j >= left && GlobalArray2[j] > v);

   if (i < j)
    swapv2( i, j );
  }
  while (j > i);

  swapv2( i, right );

  quicksort( left, i-1 );
  quicksort( i+1, right );
 }

}

void swapv2( int swap1, int swap2 )
{
	int temp;

	temp = GlobalArray2[swap1];
	GlobalArray2[swap1] = GlobalArray2[swap2];
	GlobalArray2[swap2] = temp;
}
	
