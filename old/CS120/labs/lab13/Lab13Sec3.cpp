/* COMMENTS
Jonathan Buch
Section 3
Lab 13
December 4th, 2014

Part 1
------
Added three different swap functions to test pass by reference, pass by pointer, and pass by value
Pass by value was the only function that didn't swap the variables correctly
Both pass by reference and pass by pointer correctly swapped the values of x and y

Part 2
------
Made a 10 interger array that contains the values 0,2,4,...,18
Created a pointer to point to the first element of the array/the array origin
Used a loop to print the elements of the array using only the pointer itself
Also included in the loop is a printing of the location in memory of the array
The upper bound increase caused the program to print the values in memory that were not included in the array. Most of these numbers not 0 and rather large
*/

#include<iostream>
using namespace std;

void swap1(float,float);
void swap2(float *,float *);
void swap3(float &,float &);

int main(){
	float x = 7;
	float y = 17;
	cout << "-------------------------------------------" << endl;
	cout << "Part 1" << endl;
	cout << x << " " << y << endl;
	// call the swap function
	swap1(x,y);
	cout << "Pass By Value Swap" << endl;
	cout << x << " " << y << endl;
	swap2(&x,&y);
	cout << "Pointer Swap" << endl;
	cout << x << " " << y << endl;
	swap3(x,y);
	cout << "Pass By Reference Swap" << endl;
	cout << x << " " << y << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Part 2" << endl;
	int nums = 10;
	int myArray[nums];
	for(int i = 0; i < nums; i++){
		myArray[i] = 2 * i;
	}
	int *ap;
	ap = myArray;
	for(int i = 0; i < nums; i++){
		cout << ap << "\t";
		cout << *ap++ << endl;
	} 
	cout << endl;
}

void swap1(float x, float y){
	float temp = x;
	x = y;
	y = temp;
}

void swap2(float *x, float *y){
	float temp = *x;
	*x = *y;
	*y = temp;
}

void swap3(float &x, float &y){
	float temp = x;
	x = y;
	y = temp;
}
