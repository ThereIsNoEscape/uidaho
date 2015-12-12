/*  testStack.cpp
 *
 *  Jonathan Buch
 *  Section #1
 *  Lab #9
 *  April 2nd, 2015
 *  Retrieved From Prof. Bruce Bolden on February 24th, 2015
 * 
 *  Stack test program
 *
 */

#include <iostream>

using namespace std;

#include "stack.h"

int main()
{
   Stack Stack1;
   Stack Stack2;
   Stack Stack3;
   Stack test1, test2, test3;
   Stack joinedStack;
   Stack tempStack;
   cout << "Stack 1" << endl;

   for( int i = 0 ; i < 5 ; i++ ) {
      Stack1.Push( i );       // push items onto the stack
      cout << i << ' ';
   }
   cout << endl;
   cout << endl;

   cout << "Stack 2" << endl;
   for( int i = 5 ; i > 0 ; i-- ) 
   {
      Stack2.Push( i );       // push items onto the stack
      cout << i << ' ';
   }
   cout << endl;
   cout << endl;
   
   cout << "Stack 3" << endl;
   for( int i = -3 ; i < 2 ; i++ )
   {
      Stack3.Push( i );
      cout << i << ' ';
   }
   cout << endl;
   cout << endl;

   cout << "Test Stack 2" << endl;
   test2.Push( -3 );
   cout << "-3" << endl;
   cout << endl;
   cout << endl;

   cout << "Test Stack 3" << endl;
   for( int i = -3 ; i < -1 ; i++ )
   {
      test3.Push( i );
      cout << i << ' ';
   }
   cout << endl;
   cout << endl;

   cout << "Test Stack 1 (Empty List) Remove Negatives" << endl;
   test1.DeleteNeg();
   cout << "Test Stack 2 (1 Item List) Remove Negatives" << endl;
   test2.DeleteNeg();
   cout << "Test Stack 3 (2 Item List) Remove Negatives" << endl;
   test3.DeleteNeg();

   cout << "Contents of Stack 1" << endl;
   Stack1.Print();          // output the stack contents
   cout << endl;

   cout << "Contents of Stack 2" << endl;
   Stack2.Print();
   cout << endl;

   cout << "Contents of Stack 3" << endl;
   Stack3.Print();
   cout << endl;

   cout << "Contents of Test Stack 1" << endl;
   test1.Print();
   cout << endl;

   cout << "Contents of Test Stack 2" << endl;
   test2.Print();
   cout << endl;

   cout << "Contents of Test Stack 3" << endl;
   test3.Print();
   cout << endl;

   cout << "Removing Negatives From Stack 3" << endl;
   Stack3.DeleteNeg();
   cout << endl;
   Stack3.Print();
   cout << endl;
 
   cout << endl;
   cout << "-------------------------------------" << endl;
   cout << "Zipped( Joined ) Stacks" << endl;
   joinedStack.joinstacks( Stack1, Stack2, joinedStack, tempStack );
   
   joinedStack.Print();
}
