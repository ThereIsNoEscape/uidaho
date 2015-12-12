/*	
	Jonathan Buch
	Section #1
	Lab #11
	April 16th, 2015

	testTree.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "BSTSA.h"

using namespace std;

int main()
{
	BSTree tree1;
	string genre, website;
	string copy, copy2;
	string title;
	int val1,val2;
	string trash[20];
	string actors[20];
	int count = 0;
	ifstream input;
	input.open( "testfile.txt" );
	while( !input.eof() )				// Open the input file
	{
		getline( input, title, '(' );		// Get all of the input
		getline( input, copy, '-' );		// from the file and 
		getline( input, copy2, ')' );		// store them in their
		val1 = atoi( copy.c_str() );		// respective slots
		val2 = atoi( copy2.c_str() );
		input >> genre;			
		input >> website;

		getline( input, trash[count] );		// The first string caused
							// program to loop only once
		count = 0;				// Saved "" maybe?
		do
		{
			getline( input, actors[count] );	// Put all actors into a string
								// array
//			cout << "Actor Name:" << actors[count] << endl;	
			count++;
		}
		while( actors[count - 1] != "" );
		actors[count] = "";
		tree1.AddBSTNode( title, val1, val2, genre, website, actors);	// Add the 
	}									// data to 
	cout << "List of Movie Titles" << endl;					// the tree
	cout << "-----------------------" << endl;
	tree1.PrintInOrder();
	cout << endl;
	cout << "The Saint Actors" << endl;			// OUTPUT
	tree1.STRA( "The Saint " );	
	cout << endl;
	cout << endl;
	cout << "Newhart Actors" << endl;
	tree1.STRA( "Newhart " );
	cout << endl;
	cout << endl;
	cout << "Dexter's Laboratory Actors" << endl;
	tree1.STRA( "Dexter's Laboratory " );
	cout << endl;
	cout << endl;
	cout << "M*A*S*H* Actors" << endl;
	tree1.STRA( "M*A*S*H " );
	cout << endl;
	cout << endl;
	cout << "Happy Days' Actors" << endl;
	tree1.STRA( "Happy Days " );
	cout << endl;
	cout << endl;
	cout << "Andy Griffith Shows" << endl;
	tree1.SART( "Andy Griffith" );
	cout << endl;
	cout << endl;
	cout << "Robert Conrad Shows" << endl;
	tree1.SART( "Robert Conrad" );
	cout << endl;
	cout << endl;
	cout << "Nancy Cartwright Shows" << endl;
	tree1.SART( "Nancy Cartwright" );
	cout << endl;
	cout << endl;
	cout << "Markie Post Shows" << endl;
	tree1.SART( "Markie Post" );
	cout << endl;
	cout << endl;
	cout << "Hank Azaria Shows" << endl;
	tree1.SART( "Hank Azaria" );
	cout << endl;
	cout << endl;
	cout << "Bob Denver Shows" << endl;
	tree1.SART( "Bob Denver" );
	cout << endl;
	cout << endl;
	cout << "Movies from 1960 to 1970" << endl;
	cout << "------------------------------------" << endl;
	tree1.SDRT( 1960, 1970 );
	cout << endl;
	cout << "Movies from 1980 to 1990" << endl;
	cout << "------------------------------------" << endl;
	tree1.SDRT( 1980, 1990 );
	cout << endl;
}
