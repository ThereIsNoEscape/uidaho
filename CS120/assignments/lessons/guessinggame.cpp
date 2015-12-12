#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main(){
	int number;
	int guess;
	int guesses = 0;
	srand(time(NULL));
	cout << "Welcome to the Glorious Guessing Game!" << endl;
	cout << "You have to guess the number that the computer picks between 1-10." << endl;
	cout << "You have 5 chances." << endl;
	cout << "Good Luck!" << endl;
	do{
		number = 1 + rand() % 10;
	}while (number == 0);
	if(number >= 1 && number <=10){
		cout << "The computer has chosen." << endl;
		cout << "Make your guess (1-10): "; 
		cin >> guess;
	}
	while(guess < 1 || guess > 10){
		cout << "Enter a guess between 1 and 10 (No decimals)" << endl;
		cin >> guess;
	}
	do{
		if(guess > number){
			cout << "Your number is too high, guess again: ";
			cin >> guess;
		}
		if(guess < number){
			cout << "Your number is too low, guess again: ";
			cin >> guess;
		}
	}while(guess != number);
	cout << "Congratulations, you win!" << endl;
	cin.ignore();
	cout << "\nPress enter to quit.\n";
	cin.ignore();
	return 0;
}
