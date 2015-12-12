/*****************************************************
 * Assignment10Sec3.cpp
 * 
 * CS 120
 * Section 3 
 * Jonathan Buch
 * Assignment 12
 * COMMENTS
 * Added a terrain cost function that determines how much energy the bot uses when entering a square
 * Added terrain that is impassible(Wall), some that are vortexes(Water), and some that kill the bot(Death)
 * Added Robots that destroy each other on contact
 * 
 *****************************************************/

#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "CursWin.h"

using namespace std;

#include "robot.h"
#include "world.h"

int main() {
	srand(time(NULL));
	
	world robot_world;
	
	robot_world.set_up();

	do {
		robot_world.update();
		robot_world.draw();
		usleep(100000);
	}while(1);
	return 0;
}


