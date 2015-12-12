  /*  The game of NIM -
      *   a simple program introducing some
      *   fundamental programming concepts.
      */
 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;
 int main()             // main() starts the actual program 
 {
    // ---------------- Variable declarations ---------------------
    double num_objects = 23.0; 
    int current_player = 1; 
    double move;
    int compmove;
    // ----------- Beginning of the main game loop ----------------
    do {                                      
       if (current_player == 1.0) {    // conditional: if
            cout << "Player 1 enter your move (1-3): ";  // output
            cin >> move;
            num_objects = num_objects - move;                  // input
            while (move < 1.0 || move > 3.0 || move > num_objects){
               cout << "Illegal move. \nEnter a new move (1-3): ";
               cin >> move;  
            }
       } else {                          // else part of conditional
            do {                         // make sure move is legal
              compmove =  1+ rand() % 3;    // random computer move
            } while (compmove < 1 || compmove > 3 || move > num_objects);
            cout << "Computer removed " << compmove << endl;
       }
       num_objects = num_objects - compmove;  // implement the move
       cout << num_objects << " objects remaining.\n";
       current_player = (current_player + 1) % 2;  // switch players
   } while (num_objects > 0);                    
   // ------------  end of the game loop --------------------------
   cout << "Player " << current_player << " wins!!!\n";
   cin.ignore();
   cout << "\nPress enter to quit.\n";
   cin.ignore();
   return 0;
}
