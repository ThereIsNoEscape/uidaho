#include<iostream>
using namespace std;
int main(){
	const int x = 5;
	x = x + 1;
	cout << x << endl;
	cout << "Enter a value for x" << endl;
	cin >> x;
	cout << x << endl;
}

