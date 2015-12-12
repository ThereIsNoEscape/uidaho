	/* COMMENTS
	Jonathan Buch
	Section 3
	Lab 9
	October 30th, 2014
	Created a base to int conversion
	Created a check to make sure the base is legal
	Created a check to make sure all input values are legal
	Created a convert digit function that converts characters to values
	*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int basetoint(string, int);
int convertDig(char, int);

int main(){
	int val, base, result;
	string strng;
	while(1){
		cout << "Enter a string of digits, followed by a base ";
		cin >> strng >> base;
		result = basetoint(strng, base);
		if(result < 0) cout << "\nAn error occurred\n" << endl;
		else cout << "\nThe result is " << result << endl;
	} // END while
} // END main

int basetoint(string str, int base){
	int length;
	if(base <= 1 || base >= 17){
		cout << "\nBase must be between 2-16" << endl;
		return -1;
	}
	length = str.length();
	int sum = 0;
	for(int i = 0; i < length; i++){
		int digit = convertDig(str[length-i-1], base);
		if(digit == -1) {
			return -1;
		}
		else{
			sum += digit * pow(base, i);
		}
	}
	return sum;
}

int convertDig(char c, int base){
	int n;
	if(c >= '0' && c <= '9')
		n = c - '0';	
	else if(c >= 'a' && c <= 'f')
		n = c - 'a' + 10;
	else if(c >= 'A' && c <= 'F')
		n = c - 'A' + 10;
	else
		n = -1;
	if(n >= base)
		n = -1;
	return n;
}	
