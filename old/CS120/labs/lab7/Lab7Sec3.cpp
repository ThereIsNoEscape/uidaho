	/*COMMENTS
	Jonathan Buch
	Section 3 
	Lab 7
	October 16th, 2014	
	Created the class card
	Created constant strings to hold the names of each of the cards
	Created a constructor that sets the rank and suit of a card to a default value
	Creaded a constructor that creates a new card object with that rank and suit
	Created a set funtion that changes the object to have a different rank and suit
	Created a Random function that prints a random card
	Created a cheat function to change the card to the ace of spades
	Created a print function that prints cards
	*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

const string RANKNAME[14] = {
	"Invalid",	// [0]
	"Two",		// [1]
	"Three",	// [2]
	"Four",		// [...]
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Jack",
	"Queen",
	"King",
	"Ace",
};

const string SUITNAME[5] = {
	"Invalid",
	"Clubs",
	"Diamonds",
	"Hearts",
	"Spades",
};

class card{
	private:
		int rank,suit;
	public:
		card();
		card(int,int);
		// other member functions
		void set(int,int);
		void random();
		void cheat();
		void print();

		// int getrank() (return rank;)
		// int getsuit() (return suit;)
};

/*

class deck{
	private:
		int num_cards;
		int current_loc;
		card card_array[150];
	public:
		deck();
		deck(int);
		deck(int,card[]);
		
		void shuffle();
		card draw();
		print();
};

*/

int main(){
	srand(time(NULL));
	card card1(1,1);
	card1.print();
	
	for(int suit = 0; suit < 4; suit++) {
		for(int rank = 0; rank < 13; rank++) {
			card1.set(rank+1,suit+1);
			card1.print();
		}
	}
	
	cout << "-------------------------" << endl;
	cout << "RANDOM" << endl;
	card1.random();
	card1.print();
	
	cout << "-------------------------" << endl;
	cout << "CHEAT" << endl;
	card1.cheat();
	card1.print();
	
	cout << "-------------------------" << endl;
	cout << "5 RANDOM CARDS" << endl;
	for(int i = 0; i < 5; i++){
		card1.random();
		card1.print();
	}

}

card::card() {
	rank = suit = 0;
}

card::card(int r,int s) {
	rank = r;
	suit = s;
}

void card::set(int r,int s) {
	if(rank <= 13 && rank >= 1){
		rank = r;
	}
	if(suit <= 4 && suit >= 1){
		suit = s;
	}
}

void card::random() {
	rank = rand() % 13 + 1;
	suit = rand() % 4 + 1;
}
void card::cheat() {
	rank = 13;
	suit = 4;
}
void card::print() {
	cout << "The " << RANKNAME[rank] << " of ";
	cout << SUITNAME[suit] << endl;
}

/*

deck::deck() {
	num_cards = 52;
	current_loc = 0;
	for(int i = 0; i < 52; i++){
		card_array[i].set(i%13+1,i/13+1)
	}
}

deck::deck(int Num, card d[]) {
	num_cards = Num;
	current_loc = 0;
	for(int i = 0; i < num_cards; i++) {
		card_array[i].set(d[i].getrank(),d[i].getsuit());
	}
}

void deck::shuffle() {
	card temp;
	int loc1,loc2;
	for(int i = 0; i < (num_cards * 5); i++) {
		loc1 = rand() % num_cards;
		loc2 = rand() % num_cards;
		
		temp = card_array[loc1];
		card_array[loc1] = card_array[loc2];
		card_array[loc2] = temp;

card deck::draw() {
	return drawshuffle();
}

card deck::drawshuffle() {
	if(current_loc > num_cards / 3.0 * 2)) {
		shuffle();
		
*/
