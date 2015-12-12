  /*  The game of NIM -
      *   a simple program introducing some
      *   fundamental programming concepts.
      */

  /* Comments
     Jonathan Buch
     Section 3
     September 24th 2014
     Assignment 4
     Added an "announcer" to speak on how the game is progressing
     Added a graphical output of the number of objects in a column so it's easier to understand
     Changed the computer's moveset so that below 5 objects, it makes the smart play
     Added a game tracking output
     Added a play again game option
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
    int pa;
    int pwin = 0;
    int cwin = 0;	
    // ----------- Beginning of the main game loop ----------------
	srand(time(NULL));
	cout << "Welcome to the game of NIM!" << endl;
	cout << "This is a game of taking objects until there are no objects left." << endl;
	cout << "The goal of this game is to be the one that doesn't take the last object left." << endl;
	cout << "You are playing against the computer who will try its best to beat you." << endl;
	cout << "Please enter your first name: ";
	cin >> fname;
  do {
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
             do {
		if(num_objects == 4){
		move = 3;
		}
	        if(num_objects == 3){
	        move = 2;
		}
		if(num_objects == 2){
		move = 1;
		}
		if(num_objects == 1){
		move = 1;
		}
		if(num_objects >= 5){
                move = rand() % 3;
		}
             } while (move < 1 || move > 3 || move > num_objects);
             cout << "Computer removed " << move << "\n" << endl;
        }
        num_objects = num_objects - move;  // implement the move
        cout << num_objects << " objects remaining.\n\n";
        current_player = (current_player + 1) % 2;  // switch players
	if(num_objects <= 15 && num_objects >= 10){
		cout << "The game is getting close.\n" << endl;
	}
	if(num_objects < 10 && num_objects >= 5){
		cout << "Its almost over!\n" << endl;
	}
	if(num_objects < 5 && num_objects > 0){
		cout << "The next few moves will end it!!!\n" << endl;
	}
	for(int i = 0; i < num_objects; i++){
		cout << "*" << endl;
	}
   } while (num_objects > 0);                   
   // ------------  end of the game loop --------------------------
   cout << "Player " << current_player << " has defeated their opponent in glorious combat!\n";
   if(current_player == 1){
	cout << "Congratulations " << fname << "! You Win!" << endl;
	pwin = pwin + 1;
   }
   if(current_player == 0){
	cout << fname << ", try again!" << endl;
	cwin = cwin + 1;
   }
   cout << "\n\n\nCurrent Record: " << pwin << " Player Win(s) and " << cwin << " Computer Win(s)" << endl;
   cout << "Do you want to play again? Enter 1 for Yes and 0 for No: ";
   cin >> pa;
  }while(pa == 1);
   cin.ignore();
   cout << "\nPress Enter to Exit.\n";
   cin.ignore();
   return 0;
}
