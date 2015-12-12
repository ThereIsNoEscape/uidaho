/*****************************************************
 * Lab12Sec3.cpp
 * 
 * CS 120
 * Section 3 
 * Jonathan Buch
 * Lab 12
 * COMMENTS
 * Included CursWin support
 * Colored the Terrain
 * Robot Adds Energy on first discovery of magic squares
 * Robot dies when at 0 energy
 * Added a death screen to show if a robot has died
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


