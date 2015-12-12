#include<iostream>
using namespace std;
int main(){	
	double x;
	double largest = 0;
	for(int i = 0; i < 10; i++){
		cout << i+1 << ") " << "Enter a number: ";
		cin >> x;
		if(x > largest || i == 0){
			largest = x;
		}
	}
	cout << largest << " is the largest" << endl;
}
