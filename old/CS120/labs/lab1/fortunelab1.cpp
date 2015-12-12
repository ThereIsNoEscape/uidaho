 /* The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
    */

 /* COMMENTS 
    * Jonathan Buch
    * Section 3
    * September 4th 2014
    * Lab #1
    * Added a Welcome Message
    * Changed forumla of calculated number as well as the messages
    * Added a conditional as well as changed the conditions for the messages
    */

#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int age;  // create a variable to store the age
        int disliked;  // create a variable to store the disliked number
	int doom;     // create a variable to store the doomed number
	// ------------- Get user input -------------------------
	cout << "Welcome to the Fortune Teller of DOOM!" << endl;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	doom = (age+disliked) * 666;
	cout << endl << "Unfortunatly for you, Your Doomed Number is: " << doom << endl;
	if(doom <= 0){
		cout << "You try to break the system? Well you can't! You are DOOMED FOR ETERNITY!!!!!" << endl;
	}
	if(doom >= 666 && doom < 19980){
		cout << "Are you wondering what will happen? Well you shouldn't be because you are DOOMED FOR THE NEXT 75 YEARS!!!!!" << endl;
	}
	if(doom >= 19980 && doom < 39960){ 
		cout << "Today you should embrace DOOM! DOOMED FOR THE NEXT 50 YEARS!!!!!" << endl;
	}
	if(doom >= 39960 && doom <= 99900){ 
		cout << "Today is your lucky day! Wait... \n\n\nToday is the day that YOU ARE DOOMED FOREVER!" << endl;
	}
	if(doom > 99900){
		cout << "Don't try your luck. YOU ARE DOOMED FOREVER!" << endl;
	}
	cout << "Hope you enjoy you enjoy your future of DOOM! You should stop by again in the future." << endl;
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to enjoy your life of DOOM." << endl;
	cin.ignore();
	return 0;
}
