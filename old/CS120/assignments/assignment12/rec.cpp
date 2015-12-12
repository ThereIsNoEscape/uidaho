#include<iostream>
#include<cstdlib>
using namespace std;

int recrel(int);

int main(int argc, char* argv[]){
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			cout << i << "\t";
			cout << recrel(atoi(argv[i])) << endl;
		}
	}
	else{
		cout << "No input Detected" << endl;
	}
	return 0;	
}

int recrel(int x){
	if(0 == x){
		return 0;
	}
	if(x > 0){
		return 2*(x-1)+1+recrel(x-1);
	}
}
