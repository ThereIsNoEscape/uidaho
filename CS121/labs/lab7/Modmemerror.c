/* Modmemerror.c -- try to find (and fix!) all the memory-related errors
                 in this program that

   MODIFIED CODE

   Jonathan Buch
   Section #1
   Lab #7
   March 11th, 2015

   Code Retrieved from Bruce Bolden on March 8th, 2015

   Takes a string from the command line.  
   Makes a linked-list out of it in reverse order.  
   Traverse it to construct a string in reverse.  
   Clean up (release memory).
 */

#include <stdio.h>
#include <stdlib.h>

// #0
// String.h needs to be included for the functions strcpy
// and strlen to work correctly

#include <string.h>

typedef struct st_CharNode 
{
    char theChar;
    struct st_CharNode *next;
} CharNode;


void reverseIt( char *stringbuffer );


int main( int argc, char *argv[] )
{
    char *stringBuffer;

    //  Check number of user supplied arguments.  
    if( argc != 2 )
    {
        fprintf( stderr, "usage: %s string.  This reverses the string "
                 "given on the command line\n" );
        exit( -1 );
    }

    // Copy the argument so we can make changes to it

    // #1
    // strlen() Changes	- returns length of the string
    // Change needed a +1 for entire line including
    // the terminating character
    // Original: stringBuffer = malloc( strlen ( argv[1] ) );

    stringBuffer = malloc( strlen( argv[1] ) + 1 );	

    // #2
    // strcpy() Changes 
    // Needed to swap as the first
    // argument is the destination
    // while the second is the source
    // Original: strcpy( argv[1], stringBuffer );

    strcpy( stringBuffer, argv[1] );
    // Reverse the string
    reverseIt( stringBuffer );

    // Print the reversed string

    // #3
    // Needs to be passed the entire array, not the value
    // of the array as it was before. This causes a Segmentation
    // fault when attempting to access the *stringBuffer instead
    // of stringBuffer.
    // Original: printf( "the reversed string is '%s'\n", *stringBuffer );

    printf( "the reversed string is '%s'\n", stringBuffer );
    return 0;
}


// Build a linked list backwards, then traverse it.

void reverseIt( char *stringbuffer )
{
    CharNode *head, *node;
    char *scan, *stop;
    
    // initialize local vars
    head = node = NULL;

    // find the start and end of the string so we can walk it
    scan = stringbuffer;

    // #4
    // Stop wants the whole string NOT including the
    // terminating character
    // Original: stop = stringbuffer + strlen(stringbuffer) + 1;

    stop = stringbuffer + strlen(stringbuffer);	

    // walk the string
    while (scan < stop)
    {
        if (head == NULL)
        {
            head = malloc( sizeof(CharNode*) );
            head->theChar = *scan;
            head->next = NULL;
        }
        else
        {
            node = malloc( sizeof(CharNode*) );
            node->theChar = *scan;
            node->next = head;
            head = node;
        }
        scan++;
    }

    // Re-point to the buffer so we can drop the characters
    scan = stringbuffer;

    //  Traverse the nodes and add them to the string
    while( head != NULL )
    {
        *scan = head->theChar;
        free( head );
        node = head->next;
        head = node;
        scan++;
    }

    // Release head
    free( head );   
}

