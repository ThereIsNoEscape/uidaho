/*COMMENTS
Jonathan Buch
Section 3
Lab 14
December 11th, 2014
Made a recurrence relation that counts the number of 1's in binary form
*/

#include<iostream>
#include<cstdlib>
using namespace std;

int recur(int);

int main(int argc, char *argv[]){
	cout << "  # of Element" << "\t\t" << "# of 1's in the #'s binary form" << endl;
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			cout << "\t";
			cout << i << "\t\t\t\t"; 
			cout << recur(atoi(argv[i])) << endl;
		}
	}
	else{
		cout << "No input detected" << endl;
	}
	return 0;
}

int recur(int x){
	if(0 >= x){
		return 0;
	}
	if(0 < x){
		if(x&1){
			return (1+recur(x-1));
		}
		else{
			return recur(x/2);
		}
	}
}
