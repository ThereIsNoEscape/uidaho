/*	Jonathan Buch
	February 18th, 2016
	CS240
	Assignment #3
	Assign2.c
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int makearg( char *s, char ***args );

int main(){
    char* p;
    int count = 0;
	char input[1000];		// Need an array to store input
    do{
    	printf( "?: " );
    	input[1000] = ' ';
    	fgets( input, 1000, stdin );		// Places user input into input array
    	char **argv;
    	int argc = 0;
    	int i;
    	int childpid;
    	argc = makearg( input, &argv );
    	for(i = 0; i < argc; i++){
	    	if((p = strchr(argv[i], '\n')) != NULL) 
    	    	*p = '\0';
    	}

    	if( (childpid = fork()) != 0 ){
        	if(strcmp(argv[0], "exit") == 0) {
    		    exit(0);
        	}
            wait();

    	}
    	else{
            execvp( *argv, argv );
    	    exit(0);
    	}
		count++;
    }while(count != 10);
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
