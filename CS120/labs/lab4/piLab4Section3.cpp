	/* COMMENTS
	Jonathan Buch
	Section 3
	Lab #4
	September 25th, 2014
	Calculated the appoximation of pi using an upper boundary
	*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double pi;
	int k;
	double sum;
	double answer;
	for(k = 1; k <= 140000; k = k + 1){
                answer = (pow(-1, k+1)/(2.0*k-1));
		sum = sum + answer;
		pi = sum;
		cout << "Accuracy: " << k << " " << "Value of Pi: " << 4*pi << endl;
	}
}
