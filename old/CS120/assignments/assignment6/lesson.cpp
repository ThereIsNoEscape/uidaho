#include<iostream>
using namespace std;

// create a class for rectangles information about height,
// width, area, perimeter (x,y)

class rectangle{
	private:
		double height;
		double width;
	public:
		double set_height(double);
		double set_width(double);
		double area();
		double perimeter();
};
int main (){
	rectangle r1;
	r1.area();
	r1.set_height(10.6);
}

double rectangle::set_height(double h){
	if(h >= 0){
		height = h;
	}
	else{
		cout << "Set to absolute....";
		height = h * -1;
	}
}

double rectangle::area(){
	return height+width;
}
