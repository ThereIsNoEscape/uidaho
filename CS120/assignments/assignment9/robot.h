int windowlength = 51;
CursWin outsecwin(20,0,25,windowlength);
CursWin deathScreen(30,0,35,18);
class robot{
private:
	int direction;
	int energy;
	int ID;
	int moved;
	void turnLeft();
	void turnRight();
	void forward(int &, int &);
	int died;

public:
	robot(int);
	void refresh() {moved = 0;}
	void draw();
	void print();
	void move(int &, int &);
	bool hasEnergy();
	void addEnergy();
	void printTerrain(int);
	void printDeath();
};

robot::robot(int id) {
	energy = 50;
	ID = id;
	moved = 0;
	died = 0;
	direction = rand() % 4;
}


void robot::turnLeft() {
	if(hasEnergy() == 1){
		energy--;
		direction = (direction+3)%4;
	}
}

void robot::turnRight() {
	if(hasEnergy() == 1){
		energy--;
		direction = (direction+1)%4;
	}
}

void robot::forward(int &x, int &y) {
	if(hasEnergy() == 1){
		energy-=1;
		switch(direction) {
		case 0:
			y--;
			break;
		case 1:
			x++;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
			break;
		}
	}
}
/*
void robot::draw() {
	if(has_colors == FALSE)
		outmainwin << "F";
	else
		outmainwin << "R";
}	
*/
void robot::print() {
	outsecwin << "ID: " << ID << "   Energy = " << energy << " " << " Direction = " << direction << " ";
}

void robot::move(int &x, int &y){
	if(hasEnergy() == 1){
		if (moved == 1) return;
		switch(rand() % 4) {
		case 0:
			turnLeft();
			break;
		case 1:
			turnRight();
			break;
		case 2:
		case 3:
			forward(x,y);
			break;
		default:
			break;
		}
		moved = 1;
	}
}

bool robot::hasEnergy(){
	if(energy >= 1){
		return 1;
	}
	else{
	if(died == 0){
		died = 1;
	}
		return 0;
	}
}

void robot::addEnergy(){
	energy += 5;
}

void robot::printTerrain(int a){
	outsecwin << "Terrain: ";
	switch(a){
		case -1:
			outsecwin << "ERROR ";
			break;
		case 0:
			outsecwin << "Forest";
			break;
		case 1:
			outsecwin << "Magic ";
			break;
		case 2:
			outsecwin << "Path  ";
			break;
		case 3:
			outsecwin << "Water ";
	}
}

void robot::printDeath(){
	if(died == 1){
		deathScreen << "Robot " << ID << " has died!";
		died = 2;
		deathScreen << cflush;
	}
}

