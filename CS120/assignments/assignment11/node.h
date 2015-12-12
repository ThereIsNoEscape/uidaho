class node{
	private:
		node *next;
		robot *data;
	public:
		node();
		void set_next(node *n) {next = n;}
		void set_data(robot *d) {data = d;}
		node *get_next() {return next;}
		robot *get_data() {return data;}
		void print();
		void turnLeft();
		void turnRight();
		void forward();
		int remove(int);
		node *search(int);
		void remove_data() {delete data;}
		int iLeft(int);
		int iRight(int);
		int iForward(int);
};

node::node(){
	next = NULL;
	data = NULL;
}

void node::print(){					// (1)
	if(next != NULL){
		next->print();
	}
	data->print();	
	cout << endl;
}

void node::turnLeft(){					// (2)
	data->turnLeft();
	if(next != NULL){
		next->turnLeft();
	}
	data->print();
	cout << endl;
}

void node::turnRight(){					// (2)
	data->turnRight();
	if(next != NULL){
		next->turnRight();
	}
	data->print();
	cout << endl;
}

void node::forward(){					// (2)
	data->forward();
	if(next != NULL){
		next->forward();
	}
	data->print();
	cout << endl;
}

int node::remove(int n){
	if(next != NULL){
		if((next->data)->getID() == n){
			node *temp;
			temp = next;
			next = next->next;
			temp->remove_data();
			delete temp;
			return(1);
		}
		else{
			return(next->remove(n));
		}
	}
	return 0;
}

node *node::search(int p){			// This function doesnt work correctly
	if(next != NULL){			// I tried multiple different ways, and this one was the closest
		if(data->getID() == p){		// (5)
			node *temp;
			temp = next;
			cout << endl;;
			return temp;
		}
		else{
			return(next->search(p));
		}
	}
	return NULL;
}

int node::iLeft(int a){				// These functions only work on the last robot on the list
	if(next != NULL){			// I don't know why it only affects the last robot, but it does work according to the executable
		if(data->getID() == a){		// (4)
			data->turnLeft();
			data->print();
			cout << endl; 
		}else{
			return(next->iLeft(a));
		} 
	}
}

int node::iRight(int b){			// (4)
	if(next != NULL){
		if(data->getID() == b){
			data->turnRight();
			data->print();
			cout << endl;
		}else{
			return(next->iRight(b));
		}
	}
}

int node::iForward(int c){			// (4)
	if(next != NULL){
		if(data->getID() == c){
			data->forward();
			data->print();	
			cout << endl;
		}else{
			return(next->iForward(c));
		}
	}
}
