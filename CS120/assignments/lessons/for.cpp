#include<iostream>
using namespace std;
int main (){
	int sum;
	for(int j = 0; j < 10; j = j + 2){
		cout << "j = " << j << " ";
		sum = 0;
		for(int i = 0; i < 10; i = i + 1){
			cout << i << " ";
			sum = sum + i;
		}
		cout << "sum = " << sum;
		cout << "\n";	
	}
	cout << "\n";
}  
