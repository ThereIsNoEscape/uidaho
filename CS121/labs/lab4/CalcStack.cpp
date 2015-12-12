/*	CalcStack.cpp
 *	Jonathan Buch	February 17th 2015
 *      Lab #4		Section 1
 *	Used some code retrieved from Bruce Bolden on February 15th, 2015 
 */

#include <iostream>
#include <cmath>
#include <assert.h>
#include <string>
#include <cstdlib>

using namespace std;

#include "CalcStack.h"						// Include the header file 

LLStack::LLStack()						// No code needed as the LL class covers this
{
}

LLStack::~LLStack()
{
	while( !IsEmpty() )
	{
		double n = topPtr.FirstNode();
		topPtr.DeleteNode( n );
	}
}

void LLStack::Push( double n )					// Add an element to the stack
{
	topPtr.AddNode( n );
}

double LLStack::Pop()						// Take an element off of the stack
{
	assert( !IsEmpty() );

	double n = topPtr.FirstNode();
	topPtr.DeleteNode( n );
	return n;
}

bool LLStack::IsEmpty()						// Checks if the stack is empty
{
	int n = topPtr.Size();
	return ( n == 0 );
}

void LLStack::sq()						// Pops the top element( if there is one ) and squares it, pushing the result
{
	if( topPtr.Size() >= 1 )
	{
		double x = Pop();
		Push( x * x );
	}
	else
	{
		cout << "Need More Arguments" << endl;
	}
}

void LLStack::squareroot()					// Pops the top element( if there is one ) and takes the square root, then pushes the result
{
	if( topPtr.Size() >= 1 )
	{
		double x = Pop(); 
		Push( sqrt( x ) );
	}
	else
	{
		cout << "Need More Arguments" << endl;
	}
}

void LLStack::PrintStack()					// Prints the elements in the stack
{
	topPtr.PrintNodes();
}

double LLStack::Peek()						// Looks at the top element	
{
	double n = topPtr.FirstNode();				
	return n;
}

int LLStack::Size()						// Returns the size of the stack
{
	return topPtr.Size();
}

void LLStack::add()						// Pops the top 2 elements off of the stack( if there are 2 or more ), adds them, then pushes the result
{
	if( Size() >= 2 )
	{
		Push( Pop() + Pop() );
	}
	else
	{
		cout << "Need More Arguments( 2 or More )" << endl;
	}
}

void LLStack::subtract()					// Pops the top 2 elements off of the stack( if there are 2 or more ), subracts them, then pushes the result
{
	if( Size() >= 2 )
	{
		double first,second;
		first = Pop();
		second = Pop();
		Push( second - first );
	}
	else
	{
		cout << "Need More Arguments( 2 or More )" << endl;
	}
}

void LLStack::multiply()					// Pops the top 2 elements off of the stack( if there are 2 or more ), multiplies them, then pushes the result
{
	if( Size() >= 2 )
	{
		Push( Pop() * Pop() );
	}
	else
	{
		cout << "Need More Arguments( 2 or More )" << endl;
	}
}

void LLStack::divide()						// Pops the top 2 elements off of the stack( if there are 2 or more ), divides them, then pushes the result
{
	if( Size() >= 2 )
	{
		double first,second;
		first = Pop();
		second = Pop();
		Push( second / first );
	}
	else
	{
		cout << "Need More Arguments( 2 or More )" << endl;
	}
}

void LLStack::swap()						// Pops the top 2 elements off of the stack( if there are 2 or more ), and swaps them by pushing the first
{								// element first then pushing the second element back on
	if( Size() >= 2 )
	{
		double first,second;
		first = Pop();
		second = Pop();
		Push( first );
		Push( second );
	}
	else
	{
		cout << "Need More Arguments( 2 or More )" << endl;
	}
}

