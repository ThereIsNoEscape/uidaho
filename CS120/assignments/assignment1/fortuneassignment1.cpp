   /* The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
    */


   /* COMMENTS
    * Jonathan Buch
    * Section 3
    * September 1st 2014
    * Assignment 1
    * Added two new variables
    * Added seven new conditionals based on new variables
    * Modified lucky number generation formula
    */

#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
        int disliked;  // create a variable to store the disliked number
	int lucky;     // create a variable to store the lucky number
	int age;       // create a variable to store the age
	int shoesize;  // create a variable to store the shoe size
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your shoe size (regardless of gender): ";
	cin >> shoesize;
	lucky = (favorite*disliked+age-shoesize) % 10;
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(lucky < 0){  // conditional, calues less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Today is your lucky day!" << endl;
	}
	if(age <= 15){
		cout << "Really?"  << endl;
	}
	if(age >= 16 && age <= 60){
		cout << "You are " << age << endl;
	}
	if(age >= 61){
		cout << "Are you messing with the inputs?" << endl;
	}
	if(shoesize <= 0){
		cout << "Do you not have feet?" << endl;
	}
	if(shoesize >= 1 && shoesize <= 6){
		cout << "You have small feet." << endl;
	}
	if(shoesize >= 7 && shoesize <= 10){
		cout << "You have average-sized feet." << endl;
	}
	if(shoesize >= 11){
		cout << "You have large feet." << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
