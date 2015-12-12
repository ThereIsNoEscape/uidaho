/*	CLab.c
 *	Jonathan Buch
 *	Section #1
 *	Lab #6
 *	March 4th, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ShowHeader( FILE*, FILE*, char [], char [], double );
double max( double,  double );
double min( double, double ); 
double average( double, double );
double stdDev( double );

int main()
{
	double value;
	char ifname[20];					// Character Arrays for file names 
	char ofname[20] = "output.txt";
	FILE *input, *output;
	printf( "File Name: " );
	scanf( "%s", &ifname );					// Gets name of first file from user
	ShowHeader( input, output, ifname, ofname, value );
	return 0;
}

double max( double x, double y )				// Returns the larger of two values
{
	if( x > y )
		return x;	
	else
		return y;
}

double min( double x, double y )				// Returns the smaller of two values
{
	if( x < y )
		return x;	
	else
		return y;
}

double average( double x, double y )				// Returns the average of the data
{
	double avgVal;
	avgVal = ( x / y );
	return avgVal;	
}

double stdDev( double x )
{
	return sqrt( x );					// Returns the square root of variance of the data
}

void ShowHeader( FILE* file1, FILE* file2, char inum[], char onum[], double val )	// Main function of the program
{
	file1 = fopen( inum, "r" );
	file2 = fopen( onum, "w" );				// Opens both files
	if( file1 == NULL || file2 == NULL)			// If either are NULL, return an error
	{
		printf( "Unable to open\n" );
		exit( -1 );
	}
	else
	{
		int count = 0;
		double sum = 0;
		double vari[100];
		double final;
		double secValMax = -( 1.0 / 0.0 );		// Initialized to -inf - all numbers larger
		double secValMin = ( 1.0 / 0.0 );		// Initialized to inf - all numbers smaller

		while( !feof( file1 ) )
 
	// Loop that reads the file while it isn't at the end
		{
			if( fscanf( file1, "%lf", &val ) != 1 )	
				break;
			secValMax = max( val, secValMax );	// Stores the latest max and min values that it is reading
			secValMin = min( val, secValMin );
			vari[count] = val;			// Stores the data for use out of the program
			sum += val; 
			count++;
		}

		double result = 0; 
		int i = 0;
		int count2 = 0;

		while( i < count )				// Loop to get the variance of the data to be used with standard deviation
		{
			result += ( ( vari[count2] - average( sum, count ) ) * ( vari[count2] - average( sum, count ) ) );
			i++;
			count2++;
		}
		final = ( result / ( count - 1 ) );		// Variance
		// All file output, Average, Maximum, Minimum, and Standard Deviation	
		fprintf( file2, "Program by Jonathan Buch\nFile Name: %s\n\n", onum );
		fprintf( file2, "Average: %lf\n", average( sum, count ) );
		fprintf( file2, "Maximum: %lf\n", secValMax );
		fprintf( file2, "Minimum: %lf\n", secValMin );
		fprintf( file2, "Standard Deviation: %lf\n", stdDev( final ) );
	}
	fclose( file1 );					// Closes the files
	fclose( file2 );
}

