/*
	Jonathan Buch
	Section #1
	Lab #11
	April 16th, 2015

	BSTSA.h	(Binary Search Tree String Array)
*/

#include <iostream>
#include <string>


using namespace std;

class BSTree
{
	private:
		struct BSTNode
		{
			string title;
			int year1;	
			int year2;
			string website;
			string genre;
			string actors[20];
			BSTNode * left;
			BSTNode * right;
		};
		typedef BSTNode * BSTNodePtr;
		BSTNodePtr root;
		void PrintBSTInOrder( BSTNodePtr );
	public:
		BSTree()
		{
			root = NULL;
		}

		void AddBSTNode( string, int, int, string, string, string [] );		
		void PrintInOrder();
		void STRA( string );
		void SearchTitleRActors( BSTNodePtr, string );
		void SART( string );
		void SearchActorsRTitles( BSTNodePtr, string );
		void SDRT( int, int );
		void SearchDatesRTitles( BSTNodePtr, int, int );
};
