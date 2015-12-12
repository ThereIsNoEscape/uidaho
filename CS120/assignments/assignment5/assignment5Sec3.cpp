	/* COMMENTS
	   Jonathan Buch
	   Section 3
	   Assignment 5
	   October 1st 2014
	   The program now exits without printing the answer
	   Added subtraction and multiplication options
	   Added a random function that gives a number based on the upperbound recieved from the user
	   Added a function to calculate the surface area of a right circular cone
	*/

/* A simple calculator program,
controlled by a menu and 
divided into separate functions */
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cmath>
using namespace std;
//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
int get_upperbound();
//--------------  Main ------------------
int main(){
srand(time(NULL));
     double operand1, operand2, answer;
     const double pi = 3.14159;
     int choice, valid_choice, random;
     do{
           print_menu();
           cin >> choice;
           valid_choice = 1;           // assume choice is valid
           switch(choice){
           case 0:                    // program will exit
                  break;
           case 1:                    // addition
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 + operand2;
                   break;
           case 2:                    // division
                   operand1 = get_value();
                   operand2 = get_value();
                   answer = divide(operand1,operand2);
                   break;
           case 3:                    // multiplication
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 * operand2;
                  break;
	   case 4:
		  operand1 = get_value();
		  operand2 = get_value();
		  answer = operand1 - operand2;
		  break;
	   case 5:
		  random = get_upperbound();
		  do{
		  	answer = 1 + rand() % random;
		  }while(answer <= 0 || answer > random);
		  break;
	   case 6:
		  operand1 = get_value();
		  operand2 = get_value();
			answer = pi*operand1*(operand1+sqrt(pow(operand2, 2)+pow(operand1, 2)));  
		  break;
	   case 7:
		  operand1 = get_value();
		  operand2 = get_value();
		  if(operand1 > operand2){
		  	answer = operand2;
		  }
		  else{
		  	answer = operand1;
		  }
		  break;
            default:
                   valid_choice = 0;   // choice is invalid
                   cout << "Invalid Choice." << endl;
            }
            if(valid_choice == 1 && choice != 0){   // if choice is valid, print the answer
                   cout << endl << "Answer = " << answer << endl;
            }
      }while(choice != 0);    // if not 0, loop back to start
      return 0;
}

//--------------  Functions -------------------
double divide(double dividend, double divisor){
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
//----------------- get_value function ----------------
double get_value(){
      	double temp_value;
      	cout << "Please, enter a value (If you chose choice 6, please enter the radius then the height): ";
      	cin >> temp_value;
      	cout << "Thanks." << endl;
      	return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
     cout << endl;
     cout << "Add                                     (1)" << endl;
     cout << "Divide                                  (2)" << endl;
     cout << "Multiply                                (3)" << endl;
     cout << "Subtract                                (4)" << endl;
     cout << "Random                                  (5)" << endl;
     cout << "Surface Area of a Right Circular Cone   (6)" << endl;
     cout << "Minimum                                 (7)" << endl;
     cout << "Exit                                    (0)" << endl;
     cout << "Enter your choice: ";
}
int get_upperbound(){
	int temp_value;
	cout << "Please enter an integer for the upper bound: ";
	cin >> temp_value;
	cout << "Thanks" << endl;
	return temp_value;
}

