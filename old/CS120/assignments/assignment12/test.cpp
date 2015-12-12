#include<iostream>
using namespace std;

class node{
    private:
	int data;
	node *next;
   public:
        void set_data(int x){data = x;}
        int get_data() {return data;}
        void set_next(node *n){next = n;}
        node *get_next(){return next;}
	void print();
};

int main(){
   node *head;  // the head node points to the linked list
   head = NULL; // make sure the list is initially empty
   node *temp;
   // this loop creates 10 new nodes and inserts them onto the beginning of the linked list
   for(int i = 0; i < 10; i++){
      temp = new node;  // create a new node
      temp->set_data(i);  // give it some data
      temp->set_next(head);  // make the new node point to the beginning of the linked list
      head = temp;  // make the head point to the new node/new beginning of the linked list
   }
   // print the list
   temp = head;  // make sure temp points to the beginning of the list
   while(temp != NULL){  // conitnue until you reach the end of the linked list, marked by a NULL
      temp = temp->get_next();  // make temp point to the next node in the list
   }
   cout << endl;
   head->print();
}

void node::print(){
	cout << data << "\t" << "Node " << data << " is done" << endl;
	if(next != NULL){
		next->print();
	}
}
