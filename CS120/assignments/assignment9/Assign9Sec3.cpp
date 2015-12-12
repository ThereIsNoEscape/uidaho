	/* COMMENTS
	Jonathan Buch
	Section 3
	Assignment 9
	November 10th, 2014
	Created the Colourful Game of Life
	Created a file read where it can be changed to change the size of the window and all arrays
	Used pointers for this to practice, I understand that they are unneeded
	Created color pairs to make the ouput more visually appealing
	Created a check to see if the two states, grid and temp, were the same
	Attempt to create a third array to compare 3 states to identify blinkers was unsuccessful
	*/


#include<cstdlib>
#include<string>
#include<fstream>
#include<ncurses.h>
#include"CursWin.h"

using namespace std;

int *pointer1;									// Pointer Practice
int *pointer2;

int main(){
	ifstream readfile;
	readfile.open("life.txt");
	int rows1, columns1;
	while(!readfile.eof()){
		readfile >> rows1 >> columns1;
	}
	pointer1 = &rows1;							// Pointer Practice
	pointer2 = &columns1;
	int rows = *pointer1;
	int columns = *pointer2;
	CursWin outmainwin(0,0,rows + 1,columns + 1);
	srand(time(NULL));
	int grid[rows][columns];
	int temp[rows][columns];
	int compare[rows][columns];
	int count;
	int choice;
	int repeat = 0;
	string file_name;
	outmainwin << "Random Configuration?(1=yes, 0=no)" << cendl;		// Choice Input for Random or User input
	outmainwin >> choice;
	if(choice == 1){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				grid[i][j] = rand() & 1;
				temp[i][j] = 0;
			}
		}
	}
	else{									// User input for file read
		outmainwin << "File Name?" << cendl;
		outmainwin >> file_name;
		ifstream chosenfile;
		chosenfile.open(file_name.c_str());
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				chosenfile >> grid[i][j];
				temp[i][j] = 0;
			}
		}
	}	
	while(1==1){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				if(grid[i][j] == 1){
					start_color();				// Color Output
					init_pair(1, COLOR_GREEN, COLOR_BLUE);
					init_pair(2, COLOR_BLACK, COLOR_BLUE);
					attron(COLOR_PAIR(1));
					outmainwin << Cmove(i,j) << '+';
					attroff(COLOR_PAIR(1));
				}
				else{
					attron(COLOR_PAIR(2));
					outmainwin << Cmove(i,j) << ' ';
					attroff(COLOR_PAIR(2));
				}
				usleep(50);
			}
		}
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				count = 0;					
				count += grid[(i - 1 + rows) % rows][(j - 1 + columns) % columns];
				count += grid[(i   +   rows) % rows][(j - 1 + columns) % columns];
				count += grid[(i + 1 + rows) % rows][(j - 1 + columns) % columns];
				count += grid[(i - 1 + rows) % rows][(j   +   columns) % columns];
				count += grid[(i + 1 + rows) % rows][(j   +   columns) % columns];
				count += grid[(i - 1 + rows) % rows][(j + 1 + columns) % columns];
				count += grid[(i   +   rows) % rows][(j + 1 + columns) % columns];
				count += grid[(i + 1 + rows) % rows][(j + 1 + columns) % columns];
				if(count == 3){
					temp[i][j] = 1;
				}
				if(count == 2){
					temp[i][j] = grid[i][j];
				}
				if(count != 3 && count != 2){
					temp[i][j] = 0;
				}
			}
		}
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				if(grid[i][j] == temp[i][j]){
					repeat += 1;
				}
				if(repeat == rows*columns){
					return 0;
				}
			}
		}
		repeat = 0;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				compare[i][j] = grid[i][j];
				grid[i][j] = temp[i][j];
			}
		}
		outmainwin << cflush;
	}
	int x;
	outmainwin >> x;
}



