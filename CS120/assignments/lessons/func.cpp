#include<iostream>
using namespace std;

int increment(int x){
	int answer;
	answer = x + 1;
	return answer;
}

int main(){
	int z = 7;
	cout << z << endl;
	z = increment(z);
	cout << z << endl;
}
