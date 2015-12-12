	/* Comments
	   Jonathan Buch
	   Section 3
	   September 17th 2014
	   Lab #3
	   Obseved and tested specific Boolean equations
	*/

#include<iostream>
using namespace std;
int main(){
	cout << "1) " << (7 < 8) << endl;
	cout << "2) " << (10 > 10) << endl;
	cout << "3) " << ((7 < 10) || (7 > 10)) << endl;
	cout << "4) " << ((7 < 10) && (7 > 10)) << endl;
	cout << "5) " << (-5 >= 5) << endl;
	cout << "6) " << ((7 > 10) || (-5 == 5)) << endl;
	cout << "7) " << !(6 == 7) << endl;
	cout << "8) " << ((10 != 11) && (7 > 8)) << endl;
	cout << "9) " << ((7 == 6) || (7 == 7) || (7 == 8)) << endl;
	cout << "10) " << (6 < (8 && 9)) << endl;
	cout << "11) " << (1 == (6 < 8)) << endl;
	cout << "12) " << (0 == (0 || 1)) << endl;
	cout << "13) " << (6 < (5 + 2)) << endl;
	cout << "14) " << (6 + (5 == 5)) << endl;
	cout << "15) " << ((6 < 7) + (7 >= 5)) << endl;
}
