/* COMMENTS
Jonathan Buch
Section 3
Assignment 11
December 8th, 2014
Made it so the robots printed in order (1) - This number is where the change took place
Made it so all robots can turn left and right and go forward as a group (2)
Attempted to have the robots turn individually, but only the final robot works for some reason (4)
Attempted to add a search function, but it didn't work after many failed attempts
*/


#include<iostream>
#include<cstdlib>
using namespace std;
#include "robot.h"
#include "node.h"
#include "linkedlist.h"

int main(){
	linkedlist ll;
	const int num_robots = 5;
	robot *robot_ptr;
	for(int i = 0; i < num_robots; i++){
		robot_ptr = new robot(i);
		ll.insert(robot_ptr);
	}
	ll.print();
	cout << "Turn all robots left: " << endl;
	ll.turnLeft();
	cout << "Turn all robots right: " << endl;
	ll.turnRight();
	cout << "Forward Robots!" << endl;
	ll.forward();
	cout << "Find Robot 4" << endl;
	ll.search(4);
	cout << "Left Robot 4" << endl;
	ll.iLeft(4);
	cout << "Right Robot 4" << endl;
	ll.iRight(4);
	cout << "Forward Robot 4" << endl;
	ll.iForward(4);
//	robot_ptr = new robot(99);
	ll.insert(robot_ptr);
	ll.remove(2);
	ll.print();
	return 0;
}


