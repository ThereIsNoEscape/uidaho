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

int makearg( char *s, char*** args, char* delim );
int myexec(char* cmd, char* output);
char* rmvwhtspc(char* str);
char* replace(const char* str, const char* search, const char* replacement);
int envcommand(char* str);

char* ENV_PATH = "/usr/local/bin:/bin:/usr/bin";

int main(){
    int count = 0;
	char input[1000];		// Need an array to store input
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
	FILE* fname;
	
	while(1) {
		// Print prompt
    	printf( "?: " );
    	
    	// Check for .mshrc
    	if (dorc) {
    		if (access(".mshrc", F_OK) != -1)
	    		while (file not empty) {
	    			cmd = line;
	    			line++;
	    		}
    		else 
    			dorc = 0;
		} else {
	    	// Get input
	    	fgets( input, 1000, stdin );
		}
    	
    	// Remove new line from string
	   	for(i = 0; i < 1000; i++){
		    if(input[i] == '\n'){ 
	        	input[i] = '\0';
		    }
	    }
	    
        // Add string to history
        if (histpos < 4000) {
            history[histpos] = malloc(strlen(input) + 1);
            strcpy(history[histpos++], input);
        }
        
        // Process input into tokens for command chaining support ';'
        cmd = strtok(input, ";");
        while (cmd) {
			// Remove leading and trailing whitespace
			cmd = rmvwhtspc(cmd);
			
            // check for echo and export commands
            if (envcommand(cmd)) {
                cmd = strtok(NULL, ";"); // move to next command
                continue;
            }

            //replace $PATH with our ENV_PATH variable
            cmd = replace(cmd, "$PATH", ENV_PATH);
			
			if (strcmp(cmd, "exit") == 0) {
				printf("Exiting on request.\n");
				exit(0);
			} else if (strcmp(cmd, "history") == 0) {
                printf("Command History:\n");
                for (i = 0; i < histpos; i++) {
                    printf("%5d %s\n", i, history[i]);
                }
            } else if (strcmp(cmd, "!!") == 0) {
                if (history[histpos-2]) {
                    cmd = strdup(history[histpos-2]); // get the previous command
                    printf("%s\n", cmd); // display the previous command
                    // in history replace !! with the command actually used, like bash
                    history[histpos-1] = malloc(strlen(cmd) + 1);
                    strcpy(history[histpos-1], cmd);
					continue;
                } else {
                    printf("-msh: !!: history entry not found\n");
                }
            }
            // !
            else if (cmd[0] == '!') {
                memmove(cmd, cmd+1, strlen(cmd)); // strip first char '!'
                int pos = atoi(cmd); // convert to int
                if (pos >= 0 && history[pos] != NULL) {
                    cmd = strdup(history[pos]); // get the command from history
                    printf("%s\n", cmd); // display the command from history
                    // replace !# with the command actually used in history, like bash
                    history[histpos-1] = malloc(strlen(cmd) + 1);
                    strcpy(history[histpos-1], cmd);
					continue;
                } else {
                    printf("-msh: !%d: history entry not found\n", pos);
                }
			} else if (strchr(cmd, '|') == cmd) {
	        	pipecmd = strtok(cmd, "|");
	        	while (pipecmd) {
					// Remove leading and trailing whitespace
					pipecmd = rmvwhtspc(pipecmd); 
	        		// Execute first command
	        		myexec(pipecmd, output);
	        		// Advance to next command
	        		pipecmd = strtok(NULL, "|");
	        		// Remove leading and trailing whitespace
	        		pipecmd = rmvwhtspc(pipecmd);
	        		// Concat output of first command to next command
	        		char newcmd[4000];
	        		strcpy(newcmd, pipecmd);
	        		strcat(newcmd, output); 
	        		// Execute new command
	        		myexec(newcmd, output);
					// Print output
					printf("%s", output);
	        	}
	        } else {
	            // Execute command
				myexec(cmd, output);
				// Print output
				printf("%s", output);
	        }
			
			// Move to next command
			cmd = strtok(NULL, ";");
        }
    }
    
	return 0;
}

char* rmvwhtspc(char* str) {
    char *end;

    while (isspace(*str)) str++; // remove leading spaces
    if (*str == 0)  // make sure str is not empty now
        return str;
    end = str + strlen(str) - 1; // adjust size
    while (end > str && isspace(*end)) // remove trailing spaces
        end--;
    *(end+1) = 0; // put a new null terminator at the end

    return str;
}

int myexec(char* cmd, char* output){
    char buffer[4000];
    FILE *fp;
    int lines = 0;

    // Fork and execute command using popen()
    if ((fp = popen(cmd, "r")) == NULL) {
        perror("pipe");
    }
    
    strcpy(output, "");
    
    // Read the output of popen()
    while (fgets(buffer, 4000, fp) != NULL) {
    	strcat(output, buffer);
    }
    pclose(fp);
    return 0;
}

int makearg( char *s, char ***args, char* delim ){
	int i;
	char* p;
	int count = 0;				// Start a count
	static char **nlist = NULL;		// nlist - newlist/array
	char *tok = strtok( s, delim );		// Tokenizing Function

	while( tok ){				// While there are still tokens
		count++;
		nlist = ( char** ) realloc( nlist, sizeof( char* ) * count ); 

		if( nlist == NULL ){
			free( nlist );
			return -1;
		}
		
		nlist[count - 1] = tok;		// Sets tokenized string to a pointer
				
		tok = strtok( NULL, delim );	// Increment to next token, if there
	}					// is one

	

	*args = nlist;				// Set original pointer passed to the
						// list of parsed strings that has 
						// been created

	return count;				// Return number of parsed arguements
}


/*
 * replace takes an original string, a search string, and a replacement string.
 * Inside tht replaces all instances of the search string with the replacement
 * string and then returns a pointer to the newly created string.
 */
char *replace(const char *str, const char *search, const char *replacement) {
    char *ret, *r;
    const char *p, *q;
    size_t count;

    // search for instances of string
    for (count = 0, p = str; (p = strstr(p, search)); p += strlen(search))
        count++;
    // return a new string sans the search
    ret = malloc(count * (strlen(replacement) - strlen(search)) + strlen(str) + 1);
    if (!ret) // if malloc failed return null string
        return NULL;
    // replace all instances with replacement string
    for (r = ret, p = str; (q = strstr(p, search)); p = q + strlen(search)) {
        count = q - p;
        memcpy(r, p, count);
        r += count;
        strcpy(r, replacement);
        r += strlen(replacement);
    }

    strcpy(r, p);
    return ret;
}


/*
 * envcommand splits a string into tokens and then tests and handles various
 * enviornment commands such as export and echo. Returns 1 when the function
 * handles a command, else 0.
 */
int envcommand(char *str) {
    int status = 0;
    char *first, *rest, *context, *context2, *var, *assign;
    char *mystr = (char*) calloc(strlen(str) + 1, sizeof(char));
    strncpy(mystr, str, strlen(str)); // make a copy of string, strtok is destructive

    first = strtok_r(mystr, " ", &context); // call thread safe version of strtok
    rest = context;

    if (strcmp(first, "export") == 0) { // is first token the export command?
        status = 1;
        var = strtok_r(rest, "=", &context2);
        assign = context2;
        if (strcmp(var, "PATH") == 0) {
          assign = replace(assign, "$PATH", ENV_PATH);
          ENV_PATH = assign;
        }
    }
    else if (strcmp(first, "echo") == 0) { // else is first token the echo command?
        status = 1;
        if (strcmp(rest, "$PATH") == 0) {
            printf("%s\n", ENV_PATH);
        } else {
            printf("%s\n", rest);
        }
    }

    free(mystr);
    return status;
}