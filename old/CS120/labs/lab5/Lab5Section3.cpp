	/* COMMENTS
	Jonathan Buch and Gabe Gibler
	Section 3
	Lab 5
	October 2nd, 2014
	*/
#include<iostream>
#include<cmath>
using namespace std;

const double pi = 3.14159;


int menu(); // 0:exit, 1-3: solids

double get_r();
double get_h();

double RCCY_vol(double r, double h);
double RCCY_sa(double r, double h);

double RCCO_vol(double r, double h);
double RCCO_sa(double r, double h);

double SPHERE_vol(double r);
double SPHERE_sa(double r);

int main(){

	int menu_choice;
	double r,h,vol,sa;	
	do {

		menu_choice = menu();

		switch(menu_choice) {
		case 0:
			cout << "Have a nice day!" << endl;
			break;
		case 1:
			r = get_r();
			h = get_h();
			
			vol = RCCY_vol(r,h);
			sa = RCCY_sa(r,h);

			cout << "\n\nFor a right circular cylinder with r = " << r << " and h = " << h << ":" << endl;
			break;
		case 2:
			r = get_r();
			h = get_h();

			vol = RCCO_vol(r,h);
			sa = RCCO_sa(r,h);

			cout << "\n\nFor a right circular cone with r = " << r << " and h = " << h << ":" << endl;
			break;
		case 3:
			r = get_r();

			vol = SPHERE_vol(r);
			sa = SPHERE_sa(r);

			cout << "\n\nFor a sphere with r = " << r << ":" << endl;
			break;
		default:
			cout << "Please enter a valid option!" << endl;
			break;

		}

		if(menu_choice > 0 && menu_choice <= 3) {
			cout << "\tThe volume is:         " << vol << endl;
			cout << "\tThe surface area is:   " << sa << endl;
			cout << "\tThe ratio is:          " << vol/sa  << "\n\n" << endl;
		}

	}while(menu_choice != 0);

}

int menu() {
	int choice = 0;
	
	do {
		cout << "Please make your choice for the calculation:" << endl;
		cout << "(1) Right circular cylinder" << endl;
		cout << "(2) Right circular cone" << endl;
		cout << "(3) Sphere" << endl;
		cout << "(0) Quit" << endl;
		cin >> choice;
	} while (choice < -1 && choice > 3);

	return choice;
}

double get_r() {
	double r;

	do {
		cout << "Please enter the radius: ";
		cin >> r;
		if (r < 0) {
			cout << endl << "Please enter a valid number for the radius (a number greater than or equal to zero)." << endl;
		}
	} while(r < 0);

	return r;
}

double get_h() {
	double h;

	do {
		cout << "Please enter the height: ";
		cin >> h;
		if (h < 0) {
			cout << endl << "Please enter a valid number for the height (a number greater than or equal to zero)." << endl;
		}
	} while(h < 0);

	return h;
}

double RCCY_vol(double r, double h){
	
	return pi*r*r*h;

}

double RCCY_sa(double r, double h){

	return 2.0*pi*r*(r+h);

}

double RCCO_vol(double r, double h){

	return (1.0/3.0)*pi*r*r*h;

}

double RCCO_sa(double r, double h){

	return pi*r*(r+sqrt((r*r)+(h*h)));

}

double SPHERE_vol(double r){
	
	return (4.0/3.0)*pi*r*r*r;

}

double SPHERE_sa(double r){

	return 4.0*pi*r*r;

}
