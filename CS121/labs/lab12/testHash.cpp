/* TestHash.cpp
 *   Test the Hash table code.
 *
 *   Jonathan Buch
 *   Section #1
 *   Lab #12
 *   April 23rd, 2015
 *
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "hash.h"

void SSID( const string );			// Search String in Dictionary
						// Used to convert the string 
int main()					// to an acceptable char array
{  
	int NumWords = 0;

	OpenFile( "dict8.txt" );		// Open the file
	SSID( "phase" ); 			// Test some words
	SSID( "derp" ); 	
	SSID( "abbot" ); 	
	SSID( "acrobat" ); 	
	SSID( "juice" ); 	
	SSID( "ice" ); 	
	SSID( "flying" ); 	
	SSID( "cesspool" ); 	
	SSID( "twitch" ); 	
	SSID( "prime" ); 	
	PrintHash();

	return 0;         
}

void SSID( const string word )
{
	char *wordPtr = new char[word.size() + 1];
	strcpy( wordPtr, word.c_str() );

	if( Lookup( wordPtr ) != NULL )
	{
		cout << "Found: \"" << word << "\" in the file." << endl;
	}
	else
	{
		cout << "\"" << word << "\" not found in the file." << endl;
	}
}
