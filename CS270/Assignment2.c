/*	Jonathan Buch
	September 18th, 2015
	CS270
	Assignment #2
	Assignment2.c
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int makearg( char *s, char ***args );

int main(){
	char input[1000];			// Need an array to store input

	printf( "Enter string to be parsed: " );	
	fgets( input, 1000, stdin );		// Places user input into input array
	char **argv, str[] = "ls -l file";
	int argc = 0;
	int i;
						// Print String Before Parsing
	printf( "Orignal String Before Parsing: %s\n", input );	

	argc = makearg( input, &argv );	
						// Print Parsed Strings In Order	
	for( i = 0; i < argc; i++ ){
		printf( "Index: %d\t Parsed String: %s\n", i, argv[i] );
	}
	printf( "Total Number of Arguments Supplied: %d\n", argc );
	
	return 0;
}

int makearg( char *s, char ***args ){
	int count = 0;				// Start a count
	static char **nlist = NULL;		// nlist - newlist/array
	char *tok = strtok( s, " " );		// Tokenizing Function

	while( tok ){				// While there are still tokens
		count++;
		nlist = ( char** ) realloc( nlist, sizeof( char* ) * count ); 

		if( nlist == NULL ){
			free( nlist );
			return -1;
		}
		
		nlist[count - 1] = tok;		// Sets tokenized string to a pointer
				
		tok = strtok( NULL, " " );	// Increment to next token, if there
	}					// is one

	

	*args = nlist;				// Set original pointer passed to the
						// list of parsed strings that has 
						// been created

	return count;				// Return number of parsed arguements
}
