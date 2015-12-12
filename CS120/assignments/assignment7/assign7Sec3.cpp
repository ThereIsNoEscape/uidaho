
	/*COMMENTS
	Jonathan Buch
	Section 3 
	Assignment 7
	October 19th, 2014	
	Created 2 new funtions, one that accepts an array and an integer and prints the cards in the array
	and the other takes the array and an interger manages to randomize the cards/deck
	Created a string array called DECK that has all 52 cards
	Created a print function to print the deck
	Created within the printdeck function is the printing of the randomized deck
	Created 2 new arrays, hand1 and hand2 which take the first 10 cards of the randomized deck
	Hand 1 takes cards [0] through [4] and Hand 2 takes cards [5] through [9]
	Created a function which makes both hands print as the final addition
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

string DECK[52] = {									// Wanted to use RANKNAME and SUITNAME, but couldn't figure out how					
	"The Two of Clubs",								// Defaulted to this to make sure it worked
	"The Three of Clubs",
	"The Four of Clubs",
	"The Five of Clubs",
	"The Six of Clubs",
	"The Seven of Clubs",
	"The Eight of Clubs",
	"The Nine of Clubs",
	"The Ten of Clubs",
	"The Jack of Clubs",
	"The Queen of Clubs",
	"The King of Clubs",
	"The Ace of Clubs",
	"The Two of Diamonds",
	"The Three of Diamonds",
	"The Four of Diamonds ",
	"The Five of Diamonds",
	"The Six of Diamonds",
	"The Seven of Diamonds",
	"The Eight of Diamonds",
	"The Nine of Diamonds",
	"The Ten of Diamonds",
	"The Jack of Diamonds",
	"The Queen of Diamonds",
	"The King of Diamonds",
	"The Ace of Diamonds",
	"The Two of Hearts",
	"The Three of Hearts",
	"The Four of Hearts",
	"The Five of Hearts",
	"The Six of Hearts",
	"The Seven of Hearts",
	"The Eight of Hearts",
	"The Nine of Hearts",
	"The Ten of Hearts",
	"The Jack of Hearts",
	"The Queen of Hearts",
	"The King of Hearts",
	"The Ace of Hearts",
	"The Two of Spades",
	"The Three of Spades",
	"The Four of Spades",
	"The Five of Spades",
	"The Six of Spades",
	"The Seven of Spades",
	"The Eight of Spades",
	"The Nine of Spades",
	"The Ten of Spades",
	"The Jack of Spades",
	"The Queen of Spades",
	"The King of Spades",
	"The Ace of Spades",
};

class card{
	private:
		int rank,suit;
		string hand1[5];
		string hand2[5];
	public:
		card();
		card(int,int);
		// other member functions
		void set(int,int);
		void random();
		void cheat();
		void print();
		void arraysizeprint(string DECK[], int);
		void shuffledeck(string DECK[], int);
//	 	int getrank();
//		int getsuit();
		void printdeck();
		void printhands();
};


/*											// IGNORE START
							
class deck{
	private:
		int num_cards;
		int current_loc;
		card card_array[52];
	public:
		deck();
		deck(int);
		deck(int,card[]);
		
		void shuffle();
		void shuffledeck(int cardprint[], int);
		card draw();
//		card drawshuffle();
		void print();
};

*/											// IGNORE END

int main(){
	srand(time(NULL));
	card card1(1,1);
	card deck[52];
/*											// IGNORE START
	for(int i = 1; i <= 13; i++){
		deck[i-1].set(i,"Clubs");
	}
	for(int i = 1; i <= 13; i++){
		deck[i+12].set(i,"Diamonds");
	}
	for(int i = 1; i <= 13; i++){
		deck[i+25].set(i,"Hearts");
	}
	for(int i = 1; i <= 13; i++){
		deck[i+38].set(i,"Spades");
	}
	OR
	for(int i = 0; i <= 12; i++){
		for(int j = 0; j < 4; j++){
			deck[(j*13+i)-1].set(i,j);
		}
	} 
*/											// IGNORE END
	card1.print();
	cout << "-------------------------" << endl;
	cout << "COMPLETE DECK" << endl;
	int cardprint[52];
	card1.printdeck();
	
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
	cout << "-------------------------" << endl;
	cout << "Cards and Size Print" << endl;
	card1.arraysizeprint(DECK, 5);

	cout << "-------------------------" << endl;
	cout << "Cards Randomized" << endl;
	card1.shuffledeck(DECK, 52);
	card1.printhands();
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

void card::print() {									// Prints the card when called
	cout << "The " << RANKNAME[rank] << " of ";				
	cout << SUITNAME[suit] << endl;
}

void card::printdeck() {								// Prints the entire deck using the above function
	for(int suit = 0; suit < 4; suit++) {
		for(int rank = 0; rank < 13; rank++) {
			set(rank+1,suit+1);
			print();
		}
	}
}	

void card::arraysizeprint(string DECK[], int size){ 					// Takes arguments and prints the specific cards in the array size that can be changed
        for(int i = 0; i < size; i++){
                cout << DECK[i] << endl;
        }
}


void card::shuffledeck(string DECK[], int size) {					// Shuffles the deck as well as printing the deck based on strings
	string temp;
	int loc1,loc2;
	for(int i = 0; i < 150; i++) {
		loc1 = rand() % size;
		loc2 = rand() % size;
		
		temp = DECK[loc1];
		DECK[loc1] = DECK[loc2];
		DECK[loc2] = temp;
	}
	arraysizeprint(DECK, 52);
	for(int i = 0; i < 5; i++){							// Changes the values of the string arrays of hand1 and hand2 to match the first ten cards of the
		hand1[i] = DECK[i];							// randomized deck
		hand2[i] = DECK[i+5];
	}	
}
void card::printhands(){								// Prints the newly formed hands
	cout << "------------------------------------" << endl;
	cout << "HAND ONE" << endl;
	for(int i = 0; i < 5; i++){
		cout << "CARD " << i+1 << endl;
		cout << hand1[i] << endl;
	}
	cout << "------------------------------------" << endl;
	cout << "HAND TWO" << endl;
	for(int i = 0; i < 5; i++){
		cout << "CARD " << i+1 << endl;
		cout << hand2[i] << endl;
	}
}


/*											// IGNORE START

deck::deck() {
	num_cards = 52;
	current_loc = 0;
	for(int i = 0; i < 52; i++){
		card_array[i].set(i%13+1,i/13+1);
	}
}

deck::deck(int Num, card d[]) {
	num_cards = Num;
	current_loc = 0;
	for(int i = 0; i < num_cards; i++) {
		card_array[i].set(d[i].getrank(),d[i].getsuit());
	}
}


			

card deck::draw() {
	return drawshuffle();
}

card deck::drawshuffle() {
	if(current_loc > num_cards / 3.0 * 2)) {
		shuffle();
*/											// IGNORE END

	
