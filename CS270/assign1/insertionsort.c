/*	Jonathan Buch
	September 8th, 2015
	insertionsort.c
	CS 270
	Assignment #1
*/

extern int GlobalArray3[];

void insertionsort( int N )
{ 
 int i, j, v;

 for (i = 1; i < N; ++i)
 {
  v = GlobalArray3[i];
  j = i;

  while (j > 0 && GlobalArray3[j-1] > v) 
  {
    GlobalArray3[j] = GlobalArray3[j-1];
    j = j-1;
  }

  GlobalArray3[j] = v;
 }
}
