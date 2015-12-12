/* Hash.cpp
 *
 *  Jonathan Buch
 *  Section #1
 *  Lab #12
 *  April 23rd, 2015
 *  Retrieved from Professor Bolden on April 22nd, 2015
 *
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language,
 *     Second Edition, Prentice-Hall, 1988.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

#include "hash.h"


const int HASH_TABLE_SIZE = 50031;
static NListPtr hashT[HASH_TABLE_SIZE];

    //  Prototypes
static char *Strdup( const char * );  //  in cstring, but....



/*  Hash
 *  Generate hash value for string s
 */

unsigned Hash( char *s )			// Hashes the values of a char array
{
    unsigned hashVal;
    
    for( hashVal = 0 ; *s != '\0' ; s++ )
        hashVal = *s + 31 * hashVal;
        
    return  hashVal % HASH_TABLE_SIZE;
}


/*  Lookup
 *  Look for s in hashT
 */

NListPtr Lookup( char *s )			// Finds the char array that you are 
{						// searching for, else returns a Null
    NListPtr np;				// pointer
    
    for( np = hashT[Hash(s)] ; np != NULL ; np = np->next )
    {
        if( strcmp(s, np->name) == 0 )
            return np;    //  found
    }
    
    return NULL;          //  not found
}

/*  Insert
 *  Put (name, defn) in hash table
 */
 
NListPtr Insert( char *name, char *defn )	// Inserts a value into the hash table
{						// based on its hashed value
    unsigned hashVal;
    NListPtr np;
    
    if( (np = Lookup(name)) == NULL )  // not found
    {
        np = (NListPtr) malloc(sizeof(*np));
        if( np == NULL || (np->name = Strdup(name)) == NULL )
            return NULL;
        hashVal = Hash(name);
        np->next = hashT[hashVal];
        hashT[hashVal] = np;
    }
    else
    {      //  remove previous definition
        free( (void *)np->defn );
    }
    
    if( (np->defn = Strdup(defn)) == NULL )
        return NULL;
    
    return np;
}

void OpenFile( string FileName )		// Open a file
{
        ifstream input;
        string word;
        char* wordPtr;

        input.open( FileName.c_str() );
        while( getline( input, word ) )
        {
                wordPtr = new char[word.size() + 1];
                strcpy( wordPtr, word.c_str() );
                Insert( wordPtr, wordPtr );
		delete wordPtr;
        }
}

void PrintHash()
{
	NListPtr np;
	int count;
	double max = -( 1.0 / 0.0 );
	double min = ( 1.0 / 0.0 );
        int empty = 0;
	cout << "\nNumber of Buckets: " << HASH_TABLE_SIZE << endl;		// Prints Hash Table size
        for( int i = 0; i < HASH_TABLE_SIZE; i++ )
        {
		count = 0;
		np = hashT[i];
        	while( np != NULL )
        	{
//                	cout << setw(3) << i << ":    ";			// Prints the actual words
//                	cout << np->name;					// and definitions
//           		cout << endl;
             		np = np->next;
			count++;
        	}
		if( count == 0 )
		{
			empty++;				// If count = 0, add one to the empty 
		}						// bucket counter
		else
		{
			if( count < min )
			{
				min = count;
			}
		}
		if( count > max )
		{
			max = count;
		}
//		cout << "Number of Elements in Bucket #" << i << ": " << count << endl;
	}
        cout << "Number of Empty Buckets: " << empty << endl;
	cout << "Smallest Bucket Size: " << min << endl;
	cout << "Largest Bucket Size: " << max << endl;
}

/*  Strdup
 *  Make a duplicate copy of s
 */

static char *Strdup( const char *s )
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1);  /*  +1 for '\0'  */
    if( p != NULL )
        strcpy(p,s);

    return p;
}
