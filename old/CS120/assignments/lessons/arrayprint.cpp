void print(card a[], int size){
	for(int i = 0; i < size; i++){
		a[i].print();
	}
}

int main(){
	print(deck, 52);
	print(hand1, 5);
}
