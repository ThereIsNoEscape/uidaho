#include<iostream>
using namespace std;

int swap(int &,int &);

int main(){
	int x = 7;
	int y = 5;
	cout << "x is at " << &x << endl;
	cout << x << " " << y << endl;
	swap(x,y);
	cout << x << " " << y << endl;  // 5 7

}

int swap(int &x,int &y){						// PASS BY REFERENCE
	int swap1;
	cout << "x (in swap) is at " << &x << endl;
	swap1 = x;
	x = y;
	y = swap1;
}
