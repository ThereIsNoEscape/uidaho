	/* COMMENTS
	Jonathan Buch
	Assignment 8
	Section 3
	October 27th, 2014
	Rewrote game.txt to have an escape theme with related messages
	Wrote into the game.txt the introduction to the game which is printed out
	Allowed the players to select their pieces that represent them on the boards
	Created a special square that moves the player a random distance
	Also included a square that changes everytime the game is played
	Added a function for points/score that adds based on square landed on
	Added a counting variable which limits the amount of rolls the players are able to take
	Also added a scoring output which shows the ending points of both of the players
	*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
                            // Declaration of the square class
class square{
  private:
    int move;
    int random;
    int points;
    string message;
    char symbol;
  public:
    square();
    void print();
    int action();
    int action2();
    void set(int,int,int,char,string);
};
                            // Function Prototypes
void print_board(square[], int, char);
void read_board(square[]);
void check_position(int &);
                           // Global variables
const int board_length = 20;

int main(){
  char player_symbol1,player_symbol2;
  int current_player = 1, roll;
  int count = 0;
  int player1_points = 0;
  int player2_points = 0;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length];  // declare an array of squares
  srand(time(NULL));
  read_board(the_board);
  cout << "Player 1 choose a character: ";
  cin >> player_symbol1;
  cout << "Player 2 choose a character: ";
  cin >> player_symbol2;
  cin.ignore();
  print_board(the_board,player1_position,player_symbol1);
  print_board(the_board,player2_position,player_symbol2);
  do{
      cout<<"\n\n\nPlayer "<<current_player<<" type enter to roll.\n";
      cin.ignore();
      roll = 1 + (rand() % 5);
      cout << "Player "<<current_player<<" rolled a "<<roll<<".\n";
      if(current_player == 1){
         player1_position += roll;
         check_position(player1_position);
	 player1_points += the_board[player1_position].action2();
         player1_position += the_board[player1_position].action();
         check_position(player1_position);
      }
     else{
         player2_position += roll;
         check_position(player2_position);
	 player2_points += the_board[player2_position].action2();
         player2_position += the_board[player2_position].action();
         check_position(player2_position);
     }
     count += 1;
     cout << 14 - count << " turns left before cave-in" << endl;
     print_board(the_board,player1_position,player_symbol1);
     print_board(the_board,player2_position,player_symbol2);
     current_player = (current_player % 2) + 1;
  }while(((player1_position<board_length-1) && (player2_position<board_length-1)) && count != 14);
  current_player = (current_player % 2) + 1;
  if(count == 14){
	cout << "Unfortunately, both of you were trapped in the cave and have died." << endl;
	cout << "Player one gained " << player1_points << " points" << endl;
	cout << "Player two gained " << player2_points << " points" << endl;
  }
  else{
  	cout << "\nPlayer " << current_player << " has managed to escape!!!\n";
	if(current_player == 1)
		player1_points += 10;
	else
		player2_points += 10;
	cout << "Player one gained " << player1_points << " points" << endl;
	cout << "Player two gained " << player2_points << " points" << endl;
  }
  cin.ignore();
  return 0;
}


void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move, square_rand, square_points;
     string square_message;
     char square_symbol;
     while(!infile.eof()){
         infile >> square_number >> square_move >> square_rand >> square_points >> square_symbol;
         getline(infile,square_message);
	 if(square_move == 0){
	 	cout << square_message << endl;
	 }
	 if(square_move != square_rand){
	 	square_move = 1 + rand() % square_rand;
	 }
	 if(square_number == 14){
	 	square_number = 2 + rand() % 17;
	 }
         if(square_number < board_length){
               b[square_number].set(square_move,square_rand,square_points,square_symbol,square_message);
	 }
     }
}
void print_board(square b[], int player_position, char player_number){
     for(int i = 0; i < board_length; i++){
         if(i != player_position)
             b[i].print();
        else
             cout << player_number;
    }
    cout << "Cave Exit\n";
    for(int i = 0; i < board_length; i++)
         cout << "-";
    cout << "\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = ' ';
     points = 1;
     move = 0;
     message = "";
}
int square::action(){
     cout << message << endl;
     return move;
}
int square::action2(){
     return points;
}
void square::print(){
     cout << symbol;
}
void square::set(int m, int r, int p, char s, string a_message){
     move = m;
     random = r;
     points = p;
     symbol = s;
     message = a_message;
}
