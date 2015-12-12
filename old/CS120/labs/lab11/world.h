const int HEIGHT = 15;
const int WIDTH = 15;
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
			terrain[x][y] = -1;
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
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] == NULL) {
				switch(terrain[x][y]){
					case -1:
						attron(COLOR_PAIR(5));
						cout << ' ';
						attroff(COLOR_PAIR(5));
						break;
					case 0:
						attron(COLOR_PAIR(1));
						cout << 'T';
						attroff(COLOR_PAIR(1));
						break;
					case 1:
						attron(COLOR_PAIR(4));
						cout << '#';	// MAGIC
						attroff(COLOR_PAIR(4));
						break;
					case 2:
						attron(COLOR_PAIR(3));
						cout << ' ';	// Path
						attroff(COLOR_PAIR(3));
						break;
					case 3:
//						cout << attron(COLOR_PAIR(2));
						cout << '+';	// Water
//						cout << attroff(COLOR_PAIR(2));
						break;
				
				}
			}
			else {
				bots[x][y]->draw();
				if(terrain[x][y] == -1)
				terrain[x][y] = rand() % 4;
			}
		}
		cout << endl;
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				bots[x][y]->print();
				bots[x][y]->refresh();
				cout << endl;
			}
		}
	}
}

void world::update() {
	int tempx,tempy;
	robot *temp;
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				tempx = x;
				tempy = y;
				bots[x][y] -> move(tempx,tempy);
				if (tempx < 0 || tempx >= WIDTH) {
					tempx = x;
				}
				if (tempy < 0 || tempy >= HEIGHT) {
					tempy = y;
				}
				if (bots[tempx][tempy] == NULL) {
					temp = bots[x][y];
					bots[x][y] = NULL;
					bots[tempx][tempy] = temp;
				}
			}
		}
	}
}
