	/* COMMENTS
	Jonathan Buch
	Section 3
	Lab 10
	November 6th 2014
	Created sum, min, circumference, swap of two double variables, swap of array elements, and incrementing an array by 1 functions
	*/  

#include<iostream>
using namespace std;

int sum(int,int);
int min(int,int);
double circumference(double);
void swap(double&,double&);
void swap(int []);
int increment(int [],int);

const double PI = 3.1417;

int main(){
	int i = 2, s = 5;
	int arr_x[i];
	arr_x[i - i] = 2;
	arr_x[i - (i-1)] = 7;
	double x = 5, y = 4;
	int arr_y[s];
	cout << "------------------------------" << endl;
	cout << "INITIAL VALUES" << endl;
	cout << "Arr_x size = " << i << " Arr_y size = " << s << endl;
	cout << "x = " << x << " y = " << y << endl;
	cout << "Arr_x[0] = " << arr_x[i-i] << " Arr_x[1] = " << arr_x[i-(i-1)] << endl;
	cout << "------------------------------" << endl;
	cout << "Testing Sum..." << endl;
	cout << sum(x,y) << endl;
	cout << "Testing Minimum..." << endl;
	cout << min(x,y) << endl;
	cout << "Testing Circumference..." << endl;
	cout << circumference(x) << endl;
	cout << "Testing Swap..." << endl;
	swap(x,y);
	cout << "x now equals " << x << " and y now equals " << y << endl; 
	cout << "Testing Array Swap..." << endl;
	swap(arr_x);
	cout << arr_x[i - i] << " " << arr_x[i - (i-1)];
	cout << "\nTesting Array Increments..." << endl;
	increment(arr_y,s);
	for(int j = 0; j < s; j++){
		cout << arr_y[j] << endl;
	}
}

int sum(int a, int b){
	int total;
	total = a + b;
	if(a > 0 && b > 0 && total < 0){
		cout << "OVERFLOW ERROR" << endl;
		return 0;
	}
	return total;
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	if(b < a){
		return b;
	}
	if(a == b){
		cout << "They are equal" << endl;
		return 0;	
	}
}

double circumference(double r){
	double circ = 0;
	circ = 2*PI*r;
	return circ;
}

void swap(double &x, double &y){
	double temp;
	temp = x;
	x = y;
	y = temp;
}

void swap(int arr[]){
	int temp;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

int increment(int arr[], int s){
	for(int i = 0; i < s; i++){
		arr[i] = 0;
	}
	for(int i = 0; i < s; i++){
		arr[i] += 1;
	}
}
