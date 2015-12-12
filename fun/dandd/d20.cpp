#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
	srand(time(NULL));
	int d20;
	int i;
	int sum;
	int avg;
	for(i = 0; i <= 100000000; i++){
		d20 = 1 + rand() % 20;
		sum = sum + d20;
		avg = sum/100000000;
	}
	cout << "Accurate: " << avg << endl;
	cout << "Roll: " << d20 << endl;
	return 0; 
}
	
