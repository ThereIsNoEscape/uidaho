/*	Jonathan Buch
	September 8th, 2015
	main.c
	CS 270
	Assignment #1
*/

#include <stdio.h>

void quicksort( int left, int right );
void bubblesort( int N );
void insertionsort( int N );

int GlobalArray1[10] = { 1, 2, 5, 7, 9, 3, 0, 6, 8, 4};
int GlobalArray2[10] = { 1, 2, 5, 7, 9, 3, 0, 6, 8, 4};
int GlobalArray3[10] = { 1, 2, 5, 7, 9, 3, 0, 6, 8, 4};

int main()
{
	quicksort( 0, 9 );
	
	bubblesort( 10 );
	
	insertionsort( 10 );
}
