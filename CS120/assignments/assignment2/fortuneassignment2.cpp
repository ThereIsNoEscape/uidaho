   /* The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
    */


   /* COMMENTS
    * Jonathan Buch
    * Section 3
    * September 10th 2014
    * Assignment 2
    * Added two new variables in terms of strings, fname and lname
    * Changed the conditionals so they include the first name in all outputs
    * Changed conditionals of the fortunes as well as added two new conditionals
    * Lucky formula generation changed to include the length of the fname and lname variables
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
	string fname;
	string lname;
	// ------------- Get user input -------------------------
	cout << "What is your first name? ";
	cin >> fname;
	cout << "What is your last name? ";
	cin >> lname;
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your shoe size (regardless of gender): ";
	cin >> shoesize;
	lucky = (favorite*disliked+age-shoesize*fname.length()/lname.length()) % 10;
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(lucky < 0){
		cout << fname << ", try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky <= 1){
		cout << fname << ", think bigger!" << endl;
	}
	if(lucky >= 2 && lucky <= 3){
		cout << fname << ", today you should embrace technology." << endl;
	}
	if(lucky >= 4 && lucky <= 5){
		cout << fname << ", today is your lucky day!" << endl;
	}
	if(lucky >= 6 && lucky <= 7){
		cout << fname << ", try again!" << endl;
	}
	if(lucky >= 8 && lucky <= 9){
		cout << fname << ", you will have great conflict today." << endl;
	}
	if(age <= 15){
		cout << "Really, " << fname << endl;
	}
	if(age >= 16 && age <= 60){
		cout << "You are where you should be, "  << fname << endl;
	}
	if(age >= 61){
		cout << "Are you messing with the inputs " << fname << endl;
	}
	if(shoesize <= 0){
		cout << fname << ", do you not have feet?" << endl;
	}
	if(shoesize >= 1 && shoesize <= 6){
		cout << "You have small feet, " << fname << endl;
	}
	if(shoesize >= 7 && shoesize <= 10){
		cout << "You have average-sized feet, " << fname << endl;
	}
	if(shoesize >= 11){
		cout << "You have large feet, " << fname << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
