#include<iostream>
using namespace std;

void print(int a[], int);

int main(){
	int array1[10] = {1,2,3,4,5,6,7,8,9,10};
	array1[5] = 99;
	print(array1, 10);
//	for(int i = 0; i < 10; i++){
//		cout << array1[i] << endl;
//	}
}

void print(int a[], int size){
	for(int i = 0; i < size; i++){
		cout << a[i] << endl;
	}
}

//void print(card a[]){
//	for(...){
//		a[i].print();
//	}
//}
