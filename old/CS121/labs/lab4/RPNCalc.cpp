/*	RPNCalc.cpp
 *	Jonathan Buch
 *	Section #1
 *	February 9th, 2015
 *	Lab #4
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "CalcStack.h"


int main()
{
	LLStack LLStack1;
        string input;
        string token;
	int flag = 0;
	double number;

        cout << "RPN Calculator by Jonathan Buch" << endl;				// Requested Output
	
	while( flag == 0 )								// While "quit" has not been typed
	{
	if( LLStack1.IsEmpty() )							// Print if Stack is empty
	{
		cout << "RPN (empty) > ";
	}
	else
	{
		cout << "RPN " << LLStack1.Peek() << " > ";				
	}
	getline( cin, input );								// Get the line of user input
	istringstream splitter( input );						// Split the input using istringstream

       	while( splitter >> token )							// While there are tokens still being still being made 
      		{
		  if( istringstream( token ) >> number )				// Checks if the string can be placed in a double
		  {
		    LLStack1.Push( number );						// Pushes the inputted strings onto the stack
		  }
		  else
		  {
		      if( token == "+" )
		      {
		        LLStack1.add();							// Adds the top 2 values on the stack and pushes the result
		      }
		      else
		      {
		        if( token == "-" )
		        {
		          LLStack1.subtract();						// Subtracts the top 2 values on the stack and pushes the result
		        }
                        else
			{
		          if( token == "*" )
		          {
		            LLStack1.multiply();					// Multiplies the top 2 values on the stack and pushes the result
		          }
		          else
		          {
		            if( token == "/" )
		            {
		              LLStack1.divide();					// Divides the top 2 values on the stack and pushes the result
		            }
		            else
		            {
		              if( token == "sq" )
		              {
		                LLStack1.sq();						// Takes the square of the top of the stack and pushes the result 
		              }
		              else
		              {
		                if( token == "sqrt" )
		                {
		                  LLStack1.squareroot(); 				// Takes the square root of the top of the stack and pushes the result
		                }
		                else
		                {
		                  if( token == "dup" )					// Duplicates the top of the stack
		                  {
		                    LLStack1.Push( LLStack1.Peek() );
		                  }
		                  else
		                  {
		                    if( token == "swap" )				// Swaps the top 2 values on the stack 
		                    {
				      LLStack1.swap();
				    }
		                    else
				    {
				      if( token == "ps" )				// Prints the Stack
				      {
				        cout << "Stack Contents: ";
				        LLStack1.PrintStack();
				      }
		                      else
		                      {
				        if( token == "quit" )				// Quits the program, stops the loop
		                        {
		                          flag = 1;
		                        }
		                        else
		                        {
				    	  cout << "Error: Not valid input" << endl;
		                        }
		                      }
		                    }
		                  }
		                }
		              }
	 	            }
		          }
		        }
		      }	
		    }
	}
	if( flag == 1 )									// Reruns the output after the flag has been changed shown on the requirements
	{
		if( LLStack1.IsEmpty() )
		{
			cout << "RPN (empty) > " << endl;
		}
		else
		{
			cout << "RPN " << LLStack1.Peek() << " > " << endl;
		}
	}
	}	
	return 0;
}
