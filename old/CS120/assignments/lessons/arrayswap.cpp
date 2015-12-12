#include<iostream>
using namespace std;

void swap(int []);

int main(){
	int a[5] = {1,2,4,8,16};
	for(int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	swap(a);
	for(int i = 0; i < 5; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap (int b[]){
	b[2] = 99;
}
