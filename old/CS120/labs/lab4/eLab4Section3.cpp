	/* COMMENTS
	Jonathan Buch
	Section 3
	Lab #4
	September 25th, 2014
	Calculated the approximation of pi using a user generated upper boundary
	*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double e;
	int k;
	double sum;
	double answer;
	double factorial = 1;;
	int upper_bound;
	cout << "Please enter upper loop bound(Recommended: 7-15): ";
	cin >> upper_bound;
	cout << "Accuracy: " << "0" << " " << "Value of e: " << "1" << endl;
	for(k = 1; k <= upper_bound; k = k + 1){
		factorial *= k;
		answer = (1/factorial);
		sum = sum + answer; 
		e = sum;
		cout << "Accuracy: " << k << " " << "Value of e: " << e+1 << endl;
	}
}
