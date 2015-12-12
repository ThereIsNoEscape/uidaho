#include<iostream>
using namespace std;
int main(){
	//((<expression>) ? <True-replacement> : <False-replacement>)
	cout << ((7<8) ? "True" : "False") << endl;
	// Trinary operator ^
	int NumberofPets = 1;
	cout << "You have " << NumberofPets << ((NumberofPets == 1) ? " pet." : " pets." << endl;
}
