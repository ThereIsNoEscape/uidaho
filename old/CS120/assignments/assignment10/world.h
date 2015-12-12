const int HEIGHT = 15;
const int WIDTH = 15;

CursWin outmainwin(0,0,WIDTH+1,HEIGHT+1);

class world{
	private:
		int terrain[WIDTH][HEIGHT];
		robot *bots[WIDTH][HEIGHT];
	public:
		void set_up();
		void draw();
		void update();
};

void world::set_up() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bots[x][y] = NULL;
//			terrain[x][y] = -1;				// Can be changed
			terrain[x][y] = rand() % 5;
		}
	}
	bots[2][2] = new robot(1);
	bots[7][7] = new robot(2);
	bots[4][4] = new robot(3);
	bots[11][11] = new robot(4);
}

void world::draw() {
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLUE);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_MAGENTA);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] == NULL) {
				switch(terrain[x][y]){
					case -1:
						attron(COLOR_PAIR(5));
						outmainwin << Cmove(y,x) << ' ';
						attroff(COLOR_PAIR(5));
						break;
					case 0:
						attron(COLOR_PAIR(1));
						outmainwin << Cmove(y,x) << 'T';
						attroff(COLOR_PAIR(1));
						break;
					case 1:
						attron(COLOR_PAIR(4));
						outmainwin << Cmove(y,x) << '#';	// MAGIC
						attroff(COLOR_PAIR(4));
						break;
					case 2:
						attron(COLOR_PAIR(3));
						outmainwin << Cmove(y,x) << ' ';	// Wall
						attroff(COLOR_PAIR(3));
						break;
					case 3:
						attron(COLOR_PAIR(2));
						outmainwin << Cmove(y,x) << '+';	// Water
						attroff(COLOR_PAIR(2));
						break;
					case 4:
						outmainwin << Cmove(y,x) << 'X';	// Death
						break;
				}
			}
			else {
				attron(COLOR_PAIR(6));
				outmainwin << Cmove(y,x) << '!';
				attroff(COLOR_PAIR(6));
//				if(terrain[x][y] == -1){
//					terrain[x][y] = rand() % 5;
					bots[x][y]->terrainCost(terrain[x][y]);		// Terrain Cost Determinant
//				}
			}
		}
		outmainwin << cendl;
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				bots[x][y]->print();
				bots[x][y]->printTerrain(terrain[x][y]);
				bots[x][y]->refresh();
				if(bots[x][y]->hasEnergy() == 0){
					bots[x][y]->printDeath();
				}
				outmainwin << cendl;
			}
		}
	}
}

void world::update(){
	int tempx,tempy;
	robot *temp;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				tempx = x;
				tempy = y;
				bots[x][y]->move(tempx,tempy);
				if(terrain[x][y] == 3){
					bots[x][y]->swapDir();		// Vortex
				}
//				if(terrain[x][y] == 4){
//					bots[x][y] = NULL;		// Deletion
//				}
				if(tempx < 0 || tempx >= WIDTH) {
					tempx = x;
				}
				if(tempy < 0 || tempy >= HEIGHT) {
					tempy = y;
				}
				if(terrain[tempx][tempy] == 2){
					tempx = x;
					tempy = y;
				}
				if(terrain[tempx][tempy] != 2){
					if(bots[tempx][tempy] == NULL){
						temp = bots[x][y];
						bots[x][y] = NULL;		// Location for interaction
						bots[tempx][tempy] = temp;
					}
					if(bots[x][y] != NULL){
						temp = bots[x][y];
						bots[x][y] = NULL;
						bots[tempx][tempy] = temp;
					}
				}
			}
		}					
	}
}


