/*	CalcStack.h
 *	Jonathan Buch
 *	February 17th 2015
 *	Section #1
 *	Lab #4
 *	Used some code retrieved from Bruce Bolden on February 15th, 2015
 */


#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

class LLStack
{
	private:
		LinkedList topPtr;
	public:
		// constuctor

		LLStack();

		// destuctor		

		~LLStack();

		// pushes a value to the top of the list

		void Push( double x);

		// removes the top value off of the list

		double Pop();

		// checks if the list is empty

		bool IsEmpty();

		// Pops and adds the top two values on the stack, pushing the result

		void add();

		// Pops and subtracts the top two values on the stack, pushing the result

		void subtract();

		// Pops and multiplies the top two values on the stack, pushing the result

		void multiply();

		// Pops and divides the top two values on the stack, pushing the result

		void divide();

		// Pops the top value, squares it, then pushes the result

		void sq();
		
		// Pops the top 2 values on the stack and swaps them

		void swap();

		// Pops the top value, takes the squareroot, then pushes the result

		void squareroot();

		// duplicates the top value on the stack

		double dup( double x );

		// Prints the stack
		
		void PrintStack();

		// returns the number of values in the stack

		int Size();

		// Looks at the top of the stack

		double Peek();
}; 
