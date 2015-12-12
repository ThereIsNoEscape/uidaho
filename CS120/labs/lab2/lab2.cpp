	/* Jonathan Buch
	 * Section 3
	 * September 11th 2014
	 * Created a three shape volume and surface area calculator
	 * Used 3 different conditionals to separate the different shapes
	 * Used the variable "shape" to choose which shape you are calculating for
	 */

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double S;
	double r;
	double h;
	double V;
	double ratio;
	const double pi = 3.14159;
	int shape;

	cout << "Welcome to the Right Circular Cylinder, Sphere, and Right Circular Cone, Volume and Surface Area Calculator!" << endl;
	cout << "Please enter the number of the shape of the object you are using (sphere=1, cylinder=2, cone=3): " << endl;
	cin >> shape;
	cout << "Please enter the radius of the object: ";
	cin >> r;
	cout << "Please enter the height of the object: ";
	cin >> h;
	cout << "\n";
	cout << "Please Wait..." << endl;
	if(shape == 1){
		V = (4.0/3.0)*pi*pow(r,3);
		cout << "\nVolume of Sphere = " << V << endl;
		S = 4.0*pi*pow(r,2);
		cout << "\nSurface Area of Sphere = " << S << endl;
		ratio = V/S;
		cout << "\nRatio of Volume to Surface Area: " << ratio << endl;
	}
	if(shape == 2){
		V = pi*pow(r,2)*h;
		cout << "\nVolume of Right Circular Cylinder = " << V << endl;
		S = 2.0*pi*r*(r+h);
		cout << "\nSurface Area of Right Circular Cylinder = " << S << endl;
		ratio = V/S;
		cout << "\nRatio of Volume to Surface Area: " << ratio << endl;
	}
	if(shape == 3){
		V = (1.0/3.0)*pi*pow(r,2)*h;
		cout << "\nVolume of Right Circular Cone = " << V << endl;
		S = pi*r*(r+sqrt(pow(r,2)+pow(h,2)));
		cout << "\nSurface Area of Right Circular Cone = " << S << endl;
		ratio = V/S;
		cout << "\nRatio of Volume to Surface Area: " << ratio << endl;
	}
	if(shape < 1){
		cout << "\nPlease exit and try again with a valid shape input. (Error: Number < 1)" << endl;
	}
	if(shape > 3){
		cout << "\nPlease exit and try again with a valid shape input. (Error: Number > 3)" << endl;
	}
	cout << "\nThank you for using this calculator!" << endl;
	cin.ignore();
	cout << "Press enter to quit" << endl;
	cin.ignore();
	return 0;
}		 

