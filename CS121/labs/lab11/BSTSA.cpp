/*
	Jonathan Buch
	Section #1
	Lab #11
	April 16th, 2015
	
	BSTSA.cpp ( Binary Search Tree String Array )
*/

#include <iostream>

#include "BSTSA.h"

using namespace std;

void BSTree::AddBSTNode( string title1, int year1, int year2, string genre, string website, string actorArray[] ) 
{
	BSTNodePtr newPtr;

	newPtr = new BSTNode;			// Put all the data into their fields
	newPtr->title = title1;
	newPtr->year1 = year1;
	newPtr->year2 = year2;
	newPtr->genre = genre;
	newPtr->website = website;
	for( int i = 0; i < 20; i++ )		// Store all actors in the array
	{
		newPtr->actors[i] = actorArray[i];
	}
	newPtr->left = NULL;
	newPtr->right = NULL;

	if( root == NULL )
	{
		root = newPtr;
	}					// Find where to place the node
	else
	{
		BSTNodePtr Ptr1 = root;
		BSTNodePtr target;
		
		while( Ptr1 != NULL )
		{
			target = Ptr1;
			if( title1 == Ptr1->title ) 
			{
				return;
			}
			else
			{
				if( title1 < Ptr1->title )
				{
					Ptr1 = Ptr1->left;
				}
				else
				{
					if( title1 > Ptr1->title )
					{
						Ptr1 = Ptr1->right;
					}
				}
			}
		}
		if( title1 < target->title )
		{
			target->left = newPtr;
		}
		else
		{
			target->right = newPtr;
		}
	}
}			
							// Print the tree in order
void BSTree::PrintBSTInOrder( BSTNodePtr ptr1 )
{
	if( ptr1 != NULL )
	{
		PrintBSTInOrder( ptr1->left );
		cout << ptr1->title << endl;
		PrintBSTInOrder( ptr1->right );
	}
}

void BSTree::PrintInOrder()				// Used with PrintBSTInOrder
{							// to print the list with the
	PrintBSTInOrder( root );			// root
}

void BSTree::STRA( string title )			// Used with SearchTitlesRActors
{							// to search for a given title within 
	SearchTitleRActors( root, title );		// all of the nodes, and returns the 
}							// actor array

void BSTree::SearchTitleRActors( BSTNodePtr ptr, string title )
{
	if( ptr != NULL )
	{
		SearchTitleRActors( ptr->left, title );
		if( title == ptr->title )
		{
			int i = 0;
			while( ptr->actors[i] != "" )
			{
				cout << ptr->actors[i] << endl;
				i++;
			}
		}
		SearchTitleRActors( ptr->right, title );
	}
}

void BSTree::SART( string actorName )			// Used with SearchActorsRTiltles
{							// to search the tree for an actor
	SearchActorsRTitles( root, actorName );		// and returns all movies that they 
}							// are apart of

void BSTree::SearchActorsRTitles( BSTNodePtr ptr, string actorName )
{
	if( ptr != NULL )
	{
		SearchActorsRTitles( ptr->left, actorName );
		int i = 0;
		while( ptr->actors[i] != "" )
		{
			if( actorName == ptr->actors[i] )
			{
				cout << ptr->title << endl;
			}
			i++;
		} 
		SearchActorsRTitles( ptr->right, actorName );
	}
}

void BSTree::SDRT( int a, int b )
{							// Used with SearchDatesRTitles
	SearchDatesRTitles( root, a, b );		// to search the tree for any nodes
}							// where they fall within the years
							// specified

void BSTree::SearchDatesRTitles( BSTNodePtr ptr, int first, int second )
{
	if( ptr != NULL )
	{
		SearchDatesRTitles( ptr->left, first, second );
		if( ptr->year1 >= first && ptr->year1 <= second )
		{
			cout << ptr->title << endl;
		}
		else	
		{
			if( ptr->year2 >= first && ptr->year2 <= second )
			{
				cout << ptr->title << endl;
			}
		}
		SearchDatesRTitles( ptr->right, first, second );
	}
}
