	/* COMMENTS
	Jonathan Buch
	Section 3
	Lab 8
	October 23, 2014	
	*/

#include<iostream>
#include<cstdlib>
using namespace std;

class fraction{
	private:
		int numer,denom;
	public:
		fraction();
		fraction(int,int);

		int getDen();
		int getNum();

		void setDen(int);
		void setNum(int);

		void reduce();
		bool equals(fraction);
		fraction add(fraction);
};

fraction::fraction() {
	setNum(0);
	setDen(1);
}

fraction::fraction(int n, int d){
	setNum(n);
	setDen(d);
}

int fraction::getNum(){
	return numer;
}

int fraction::getDen(){
	return denom;
}

void fraction::setNum(int n){
	numer = n;
}

void fraction::setDen(int d){
	if(d != 0){
		denom = d;
	}
	else{
		cerr << "Attemped Divide by zero!" << endl;
	}
} 

void fraction::reduce(){
	for(int i = numer; i > 1; i--){
		if(denom % i == 0 && numer % i == 0){
			denom = denom/i;
			numer = numer/i;
			reduce();
		}
	}
}

bool fraction::equals(fraction one){
	fraction fraction_reduced(getNum(), getDen());
	fraction_reduced.reduce();
	one.reduce();
	if(fraction_reduced.getNum() == one.getNum() && fraction_reduced.getDen() == one.getDen()){
		return 1;
	}
	else{
		return 0;
	}
}

fraction fraction::add(fraction one){
	int temp_denom,temp_numer1,temp_numer2,final_numer;
	fraction new_fraction;
	temp_denom = denom * one.getDen();
	temp_numer1 = numer * one.getDen();
	temp_numer2 = one.getNum() * denom;
	final_numer = temp_numer1 + temp_numer2;
	cout << temp_denom << endl;
	cout << final_numer << endl;
	new_fraction.setNum(final_numer);
	new_fraction.setDen(temp_denom);
	new_fraction.reduce();
	return new_fraction;
}
