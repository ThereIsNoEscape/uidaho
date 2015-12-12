#include<iostream>
#include<cmath>
using namespace std;

double get_height();
double get_radius();
double calc_volume_cylinder(double, double);
double h;
double r;
double part;
double Part;

int main(){
	double height,radius;
	double answer;
	height = get_height();
	radius = get_radius();
	answer = calc_volume_cylinder(height, radius);
	cout << answer << endl;
	cin >> part;
	cin >> Part;
	cout << part + Part << endl;
}

double get_height(){       //Stubs
	cout << "Please enter the height of the object: ";
	cin >> h;
	return h;
}

double get_radius(){
	cout << "Please enter the radius of the object: ";
	cin >> r;
	return r;
}

double calc_volume_cylinder(double h, double r){
	return h+r;
}
