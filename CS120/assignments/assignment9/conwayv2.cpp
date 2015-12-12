#include<cstdlib>
using namespace std;
#include"CursWin.h"
const int columns = 50;
const int rows = 20;
int main(){
	CursWin outmainwin(0,0,rows+1,columns+1);
	srand(time(NULL));
	int grid[rows][columns];
	int temp[rows][columns];
	int count;
	for(int i =0; i < rows; i++){
		for(int j =0; j < columns; j++){
			grid[i][j] = rand()%2;  // 0 or 1
			temp[i][j] = 0;  // start temp with all zeros
		}
	}
	while(1==1){
		for(int i =0; i < rows; i++){
			for(int j =0; j < columns; j++){
				outmainwin << Cmove(i,j) << grid[i][j];
			}
		}
		for(int i = 1; i < rows; i++){
			for(int j = 1; j < columns; j++){
				count = 0;
				count += grid[i-1][j-1];
				count += grid[i][j-1];
				count += grid[i+1][j-1];
				count += grid[i-1][j+1];
				count += grid[i][j+1];
				count += grid[i+1][j+1];
				count += grid[i-1][j];
				count += grid[i+1][j];
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
				grid[i][j] = temp[i][j];
			}
		}
		outmainwin << cflush;
	}
	int x;
	outmainwin >> x;
}
