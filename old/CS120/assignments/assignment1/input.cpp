#include<iostream>
using namespace std;

int main(){
	int age;
	string fname;
	string lname;
	int l;
	cout << "Please enter your age: ";
	cin >> age;
	cout << "Please enter your first name: ";
	cin >> fname;
	cout << "Please enter your last name: ";
	cin >> lname;
	cout << fname << endl;
	cout << lname << endl; 
	cout << age << endl;
	l = fname.size();
	cout << l << "\n";
	cout << "Answer = " << l/age << "\n";
}
