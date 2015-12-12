#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double pi;
	int k;
	int x;
	double sum;
	double term;
	double answer;
	for(k = 1; k < 100000; k = k + 1){
                answer = (pow(-1, k+1)/(2.0*k-1));
		sum = sum + answer;
		cout << "Accuracy: " << k << " " << "Value of Pi: " << 4*sum << endl;
	}
}
