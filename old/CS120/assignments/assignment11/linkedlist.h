class linkedlist{
	private:
		int count;
		node *head;
	public:
		linkedlist();
		void insert(robot *);
		void print();
		void turnLeft();
		void turnRight();
		void forward();
		void remove(int);
		void *search(int);
		void iLeft(int);
		void iRight(int);
		void iForward(int);
};

linkedlist::linkedlist(){
	head = NULL;
	count = 0;
}

void linkedlist::insert(robot *rp){
	node *n;
	n = new node;
	n->set_data(rp);
	n->set_next(head);
	head = n;
	count++;
}

void linkedlist::remove(int n){
	if(head == NULL){
		return;
	}
	if((head->get_data())->getID() == n){
		node *temp;
		temp = head;
		head = head->get_next();
		temp->remove_data();
		delete temp;
		count--;
	}
	else{
		if(head->remove(n) == 1){
			count--;
		}
	}
}

void linkedlist::iLeft(int x){					// (4) These only work on the last robot in the list for some reason unknown to me
	if(head == NULL){
		return;
	}
	if((head->get_data())->getID() == x){
		head->iLeft(x);
		cout << endl;
	}
}

void linkedlist::iRight(int x){					// (4)
	if(head == NULL){
		return;
	}
	if((head->get_data())->getID() == x){
		head->iRight(x);
		cout << endl;
	}
}

void linkedlist::iForward(int x){				// (4)
	if(head == NULL){
		return;
	}
	if((head->get_data())->getID() == x){
      		head->iForward(x);
		cout << endl;
	}
}

void *linkedlist::search(int p){				// (5)
	if(head == NULL){					// This function doesn't work, multiple attempts at solving it were tested but all had failed
		return NULL;
	}
	if((head->get_data())->getID() == p){
//		data->print();
	}
}

void linkedlist::print(){
	cout << "There are " << count;
	cout << " robots in the list: \n";
	if(head != NULL){
		head->print();
	}
}

void linkedlist::turnLeft(){
	if(head != NULL){
		head->turnLeft();
	}
}

void linkedlist::turnRight(){
	if(head != NULL){
		head->turnRight();
	}
}

void linkedlist::forward(){
	if(head != NULL){
		head->forward();
	}
}

