  /*  The game of NIM -
      *   a simple program introducing some
      *   fundamental programming concepts.
      */

  /* Comments
     Jonathan Buch
     Section 3
     September 17th 2014
     Assignment 3
     Added an input for the player's name
     Changed the ending message to make it more interesting and made it include the player's name
     Added a objects removed by player message
     Created the seed for the random number generator 
     Made it so the player can set the starting number objects above 10 instead of above zero in order to make it less one sided
     */

 #include<iostream>     // include two libraries
 #include<cstdlib>
 #include<time.h>
 using namespace std;
 int main()             // main() starts the actual program 
 {
    // ---------------- Variable declarations ---------------------
    int num_objects; 
    int current_player = 1; 
    int move;
    string fname;
    // ----------- Beginning of the main game loop ----------------
	srand(time(NULL));
	cout << "Welcome to the game of NIM!" << endl;
	cout << "This is a game of taking objects until there are no objects left." << endl;
	cout << "The goal of this game is to be the one that doesn't take the last object left." << endl;
	cout << "You are playing against the computer who will try its best to beat you." << endl;
	cout << "Please enter your first name: ";
	cin >> fname;
    do {
	cout << "\nPlease enter the desired amount of objects (above 10): ";
	cin >> num_objects;
	while(num_objects <= 10){
		cout << "Please enter a number of objects greater than 10: ";
		cin >> num_objects;
	}
    }while (num_objects <= 10);
	cout << num_objects << " total objects." << endl;
    do {                                      
       if (current_player == 1) {    // conditional: if
            cout << "Player 1 enter your move (1-3): ";  // output
            cin >> move;                 // input
            while (move < 1 || move > 3 || move > num_objects){
               cout << "Illegal move. \nEnter a new move (1-3): ";
               cin >> move;
            }
	    cout << "Player removed " << move << endl; 
       } else {                          // else part of conditional
            do {                         // make sure move is legal
               move = rand() % 3;    // random computer move
            } while (move < 1 || move > 3 || move > num_objects);
            cout << "Computer removed " << move << endl;
       }
       num_objects = num_objects - move;  // implement the move
       cout << num_objects << " objects remaining.\n";
       current_player = (current_player + 1) % 2;  // switch players
   } while (num_objects > 0);                    
   // ------------  end of the game loop --------------------------
   cout << "Player " << current_player << " has defeated their opponent in glorious combat!\n";
   if(current_player == 1)
	cout << "Congratulations " << fname << "! You Win!" << endl;
   if(current_player == 0)
	cout << fname << ", try again!" << endl;
   cin.ignore();
   cout << "\nPress enter to quit.\n";
   cin.ignore();
   return 0;
}
