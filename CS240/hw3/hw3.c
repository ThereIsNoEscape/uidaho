/*	Jonathan Buch
	March 30th, 2016
	CS240
	Assignment #3
	hw3.c
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int makearg( char *s, char*** args, char* delim );
int execute( char* cmd, char* output );
char* rmvwhtspc( char* str );
char* replace( const char* str, const char* search, const char* replacement );
int envcmd( char* str );

char* ENV_PATH = "/usr/local/bin:/bin:/usr/bin";

int main(){
    int count = 0;
	char input[1000];
    int argc = 0;
    int i;
    int childpid;
    char** argv;
	char* history[4000];
	int histpos = 0;
	char* cmd;
	char output[4000];
	char* pipecmd;
	int dorc = 1;
	int line = 0;
	int flag = 1;
	FILE* fname;
	
	while(1) {
		// Print prompt
    	printf( "?: " );
    	
    	// Check for .mshrc
    	/*
    	if ( dorc ) {
    		if ( access( ".mshrc", F_OK ) != -1 ){
    		    fname = fopen( ".mshrc", "r" );
    		    
	    		while ( getchar() != EOF ) {
	    			cmd = fgets( input, 1000, fname );
	    			line++;
	    			flag == 0;
	    		}
	    		fclose(fname);
    		}
    		else {
    			dorc = 0;
    			flag = 1;
    		}
		} else */ if( flag == 1 ){
	    	// Get input
	    	if( fgets ( input, 1000, stdin ));
		}
    	
    	// Remove new line from string
	   	for( i = 0; i < 1000; i++ ){
		    if( input[i] == '\n' ){ 
	        	input[i] = '\0';
		    }
	    }
	    
        // Add string to history
        if ( histpos < 4000 ) {
            history[histpos] = malloc( strlen( input ) + 1 );
            strcpy( history[histpos++], input );
        }
        
        // Process input into tokens for command chaining support ';'
        cmd = strtok( input, ";" );
        while ( cmd ) {
			// Remove whitespace
			cmd = rmvwhtspc( cmd );
			
            // Check for echo and export
            if ( envcmd( cmd )) {
                cmd = strtok( NULL, ";" ); // move to next command
                continue;
            }

            // Replace $PATH with new ENV_PATH variable
            cmd = replace( cmd, "$PATH", ENV_PATH );
			
			if ( strcmp( cmd, "exit" ) == 0 ) {
				printf( "Exiting on request.\n" );
				exit(0);
			} else if ( strcmp( cmd, "history" ) == 0 ) {
                printf( "Command History:\n" );
                for ( i = 0; i < histpos; i++ ) {
                    printf( "%5d %s\n", i, history[i] );
                }
            } else if ( strcmp( cmd, "!!" ) == 0 ) {
                if ( history[histpos-2] ) {
                    // Get the previous command
                    cmd = strdup( history[histpos-2] ); 
                    printf( "%s\n", cmd );
                    // In history, replace !! with the command
                    history[histpos-1] = malloc( strlen( cmd ) + 1 );
                    strcpy( history[histpos-1], cmd );
					continue;
                } else {
                    printf( "-msh: !!: history entry not found\n" );
                }
            }
            // !
            else if ( cmd[0] == '!' ) {
                // Strip first !
                memmove( cmd, cmd+1, strlen( cmd ));
                // Convert to int to find the line number
                int pos = atoi( cmd ); 
                if ( pos >= 0 && history[pos] != NULL ) {
                    // Get the command from history
                    cmd = strdup( history[pos] ); 
                    printf( "%s\n", cmd ); 
                    // In history, replace !# with the command
                    history[histpos-1] = malloc( strlen( cmd ) + 1 );
                    strcpy( history[histpos-1], cmd );
					continue;
                } else {
                    // Bash error report
                    printf( "-msh: !%d: history entry not found\n", pos );
                }
			} else if ( strchr( cmd, '|' ) == cmd ) {
	        	pipecmd = strtok( cmd, "|" );
	        	while( pipecmd ) {
					// Remove whitespace
					pipecmd = rmvwhtspc( pipecmd ); 
	        		// Execute first command
	        		execute( pipecmd, output );
	        		// Advance to next command
	        		pipecmd = strtok( NULL, "|" );
	        		// Remove whitespace
	        		pipecmd = rmvwhtspc( pipecmd );
	        		// Concat output of first command to next command
	        		char newcmd[4000];
	        		strcpy( newcmd, pipecmd );
	        		strcat( newcmd, output ); 
	        		// Execute new command
	        		execute( newcmd, output );
					// Print output
					printf( "%s", output );
	        	}
	        } else {
	            // Execute command
				execute( cmd, output );
				// Print output
				printf( "%s", output );
	        }
			
			// Move to next command
			cmd = strtok( NULL, ";" );
        }
    }
    
	return 0;
}

// Removes whitespace from a supplied string
char* rmvwhtspc(char* str) {
    char *end;
    // Remove beginning whitespace
    while ( isspace( *str )) str++; 
    if ( *str == 0 )  
        return str;
    end = str + strlen( str ) - 1; 
    // Remove trailing spaces
    while( end > str && isspace( *end ))
        end--;
    // Place a null at the end of the string
    *( end+1 ) = 0;

    return str;
}

int execute( char* cmd, char* output ){
    char buffer[4000];
    FILE* fp;
    int lines = 0;

    // Fork and execute command using popen() instead of execvp
    if ( ( fp = popen( cmd, "r" )) == NULL ) {
        perror( "pipe" );
    }
    
    strcpy( output, "" );
    
    // Read the output of popen()
    while ( fgets( buffer, 4000, fp ) != NULL ) {
    	strcat( output, buffer );
    }
    pclose( fp );
    return 0;
}

int makearg( char *s, char ***args, char* delim ){
	int i;
	char* p;
	int count = 0;				    // Start a count
	static char **nlist = NULL;		// nlist - newlist/array
	char* tok = strtok( s, delim );	// Tokenizing Function

	while( tok ){			    	// While there are still tokens
		count++;
		nlist = ( char** ) realloc( nlist, sizeof( char* ) * count ); 

		if( nlist == NULL ){
			free( nlist );
			return -1;
		}
		
		nlist[count - 1] = tok;		    // Sets tokenized string to a pointer
				
		tok = strtok( NULL, delim );	// Increment to next token, if there
	}					                // is one

	// Set original pointer passed to the
	// list of parsed strings that has 
	// been created

	*args = nlist;				

    // Return number of parsed arguements
	return count;				
}


// Replace(char, char, char) Takes three strings which when completed,
// successfully substitutes a string you want to replace inside of a another
// string with a with a string of your choice

char* replace( const char *str, const char *search, const char *sub ) {
    char *newstr, *r;
    const char *p, *q;
    size_t count;

    // Find the string
    for ( count = 0, p = str; ( p = strstr( p, search )); p += strlen( search ))
        count++;
    // Return the string without the found string
        newstr = malloc( count * ( strlen( sub ) - strlen( search )) + strlen( str ) + 1);
    // Replace the instance with the new string
    for ( r = newstr, p = str; ( q = strstr( p, search )); p = q + strlen( search )) {
        count = q - p;
        memcpy( r, p, count );
        r += count;
        strcpy( r, sub );
        r += strlen( sub );
    }

    strcpy( r, p );
    return newstr;
}


/*
 * envcmd splits a string and checks for the environment commands echo
 * and export
 */
int envcmd( char* str ) {
    int status = 0;
    char* first, *rest, *nstr, *mstr, *var, *assign;
    char* str1 = ( char* ) calloc( strlen( str ) + 1, sizeof( char ));
    // Make a copy of the string
    strncpy( str1, str, strlen( str )); 

    first = strtok_r( str1, " ", &nstr );
    rest = nstr;

    // When echo is found
    if ( strcmp( first, "echo" ) == 0 ) { 
        status = 1;
        if ( strcmp( rest, "$PATH" ) == 0 ) {
            printf( "%s\n", ENV_PATH );
        } else {
            printf( "%s\n", rest );
        }
    }
    // If export was found
    else if ( strcmp( first, "export" ) == 0 ) {
        status = 1;
        var = strtok_r( rest, "=", &mstr );
        assign = mstr;
        if ( strcmp( var, "PATH" ) == 0 ) {
          assign = replace( assign, "$PATH", ENV_PATH );
          ENV_PATH = assign;
        }
    }

    free( str1 );
    return status;
}
