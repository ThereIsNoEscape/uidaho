	/* COMMENTS
	Jonathan Buch
	Section 3
	Assignment 6
	October 12th, 2014
	Added a player loss if the pet is overfed
	Added money which allows the player to feed their pet
	Added player loss if they run out of money to feed their pet
	Added a random function that triggers 1/20 times with five different events
	*/

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int money;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      int check_health();   // public member function
      int random_event();
};
int main()
{
   srand(time(NULL));
   pet pet1;
   int choice;
   int health_check;
   int random;
   do{
       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
      }
// sometimes:
// generate a random number 1-100
// if the number < 10 then call random_event
      random = 1 + rand() % 100;
      if(random < 5){
	   pet1.random_event();
      }
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     money = 10;
     cout << "Pet's name? (One word) ";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n Pet Show (3) \n ";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         break;
    case(2):
         happy += 5;
         hunger += 1;
         break;
    case(3):
	 money += 3;
	 hunger += 5;
	 happy -= 1;
	 break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    cout << "\nMMM, Yummy!\n";
    hunger -= 5;
    money -= 2;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << endl;
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Total Money: " << money << endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(hunger <= 0){
	cout << "\nYour pet has been overfed and has died.\n";
	return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    if(money <= 0){
         cout << "\nYou have lost all of your money and your pet has starved.\n :( \n";
	 return 1;
    }
    return 0;
}
int pet::random_event(){
      int random;
	random = 1 + rand() % 5;
	switch(random){
	case 0:
		cout << "Lost your wallet. Lose 5 money" << endl;
		money -= 5;
		break;
	case 1:
		cout << "Nothing special happens." << endl;
		break;
	case 2:
		cout << "Found a wallet. Gain 5 money" << endl;
		money += 5;
		break;
	case 3:
		cout << "Broke a pet toy. Lose 5 Happiness" << endl;
		happy -= 5;
		break;
	case 4:
		cout << "Toy store gives out free toys. Gain 10 Happiness" << endl;
		happy += 10;
		break;
	case 5:
		cout << "Pet is absurdly hungry. Gain 5 Hunger" << endl;
		hunger += 5;
		break;
	default:
		break;
	}
	return 0;
}
