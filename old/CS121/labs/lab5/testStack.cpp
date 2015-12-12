/*  testStack.cpp
 *
 *  Jonathan Buch
 *  Section #1
 *  Lab #5
 *  Retrieved From Prof. Bruce Bolden on February 24th, 2015
 * 
 *  Stack test program
 *
 */

#include <iostream>

using namespace std;

#include "stack.h"

main()
{
   Stack iStack;

   cout << "Pushing integers onto iStack" << endl;

   for( int i = 0 ; i < 5 ; i++ ) {
      iStack.Push(i);       // push items onto the stack
      cout << i << ' ';
   }
   cout << endl;
   
   cout << "Contents of iStack" << endl;
   iStack.Print();          // output the stack contents


   cout << endl << "Popping integers from iStack" << endl;

   while( !iStack.IsEmpty() )
      cout << iStack.Pop() << ' ';

   cout << endl;
   iStack.Print();          // output the stack contents


   if( iStack.IsEmpty() )
       cout << "The stack is empty" << endl;
   else
       cout << "The stack is not empty" << endl;

   return 0;
}
