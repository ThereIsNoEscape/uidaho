#include<iostream>
using namespace std;

class node{
	private:
		int data;
		node *next;
	public:
		void set_data(int x){data = x;}
		int get_data(){return data;}
		void set_next(node *n){next = n;}
		node *get_next(){return next;}
};

int main(){
	node *head;
	head = new node;
	head -> set_data(8);			// USE ARROW NOTATION SINCE HEAD IS A POINTER
	head -> set_next(NULL);
	cout << head -> get_data() << endl;
	node *temp;
	for(int i = 0; i < 10; i++){
		temp = new node;		// INSERTS ALL NODES BEFORE HEAD
		temp -> set_data(i);
		temp -> set_next(head);
		head = temp;
	}
	// print the list
	temp = head;
	while(temp != NULL){
		cout << temp -> get_data() << " ";
		temp = temp -> get_next();
	}
	cout << endl;
}
