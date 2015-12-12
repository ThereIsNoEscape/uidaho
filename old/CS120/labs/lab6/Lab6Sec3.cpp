	/* COMMENTS
	   Jonathan Buch
	   Section 3
	   Lab 6
	   October 9th, 2014
	   Created a default case in the main menu to prevent invalid choices
	   Added additional output messages for when the user plays with their pet
	   Added the ability of the pet to go to a pet show under the Play menu
	   Added the ability of the user to give the pet a type(string)
	   Added Money as an additional quality
	   Added a conditional that makes the user lose when pet is overfed
	*/
	// Side Note: The random at the end will be used for a later addition
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
      string type;
      int happy;            // private data member
      int money;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      int check_health();   // public member function
      void random_event();
};
int main()
{
   pet pet1;
   int choice;
   int health_check;
   do{
       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 0:
	   break;
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
       default:
	   cout << "Invalid choice, Please choose a valid choice" << endl;
	   break;
      }
// sometimes:
// generate a random number 1-100
// if the number < 10 then call random_event
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
     cout << "Type of pet? (One word) " ;
     cin >> type;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Do Nothing (0) \n Fetch (1) \n Roll over (2) \n Pet Show (3) \n ";
    cin >> choice;
    switch(choice){
    case(0):
	 happy -= 3;
	 hunger += 3;
	 cout << "You decided to not do anything with your pet." << endl;
	 cout << "Why are you just standing there?" << endl;
	 break;
    case(1):
         happy += 10;
         hunger += 5;
	 cout << "Your pet succefully played fetch." << endl;
	 cout << "Again please!" << endl;
         break;
    case(2):
         happy += 5;
         hunger += 1;
	 cout << "Your pet rolled over for you. It seems to be enjoying your company." << endl;
	 cout << "Yay fun!" << endl;
         break;
    case(3):
	 money += 3;
	 hunger += 5;
	 happy -= 3;
	 cout << "Your pet did not like this at all, but you still earned some money." << endl;
	 cout << "Pet Shows are not fun >:(" << endl;
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
    cout << "\nYour pet " << name << " is a " << type << endl;
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
void random_event(){
	int number;	
	number = 1 + rand() % 100;
}
