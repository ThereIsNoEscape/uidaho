#include<iostream>
using namespace std;
int main(){
	int x;
	int y;
	cin >> x;
	cin >> y;
	if((x >= 1 && x <= 5) && (y == 0 || (y%2 == 1))){
		cout << "1";
	}
	else{
		cout << "0";
	}
}
