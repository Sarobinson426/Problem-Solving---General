#include <iostream>
#include <ctime>
using namespace std;

const int GRID = 20;
const int ANTS = 100;
const int DOODS = 5;

void random_initialization(int &x, int &y) { // for world initialization
	x = rand() % 20;
	y = rand() % 20;
}

void random_move(int& x, int& y) {
	int up, right, down, left, random;

	random = (rand() % 4) + 1;
	up = 1;
	right = 2;
	down = 3;
	left = 4;

	if (random == up) {
		x--;
	}
	else if (random == right) {
		y++;
	}
	else if (random == down) {
		x--;
	}
	else if (random == left) {
		y--;
	}
}

bool is_in_bounds(int& x_plane_move, int y_plane_move) {
	if (x_plane_move >= 20 || x_plane_move < 0 || y_plane_move >= 20 || y_plane_move < 0) {
		return false;
	}
	else {
		return true;
	}
}

class Organism {
protected:
	int x_plane;
	int y_plane;
	Organism* game[GRID][GRID];
public:
	Organism(int new_x = 0, int new_y = 0) : x_plane(new_x), y_plane(new_y) {
		for (int x = 0; x < GRID; x++) {
			for (int y = 0; y < GRID; y++) {
				game[x][y] = nullptr;
			}
		}
	};

	void initial_world();
	void print_world();

	virtual char symbol() { return '-'; }
	void move();
};

class Ants : public Organism {
private:
	char ants;
public:
	Ants(int new_x, int new_y) : Organism(new_x, new_y), ants('o') {};
	virtual char symbol() { return ants; }
	
};

class Doods : public Organism {
private:
	char doods;
public:
	Doods(int new_x, int new_y) : Organism(new_x, new_y), doods('X') {};
	virtual char symbol() { return doods; }

	void eat_ant(int& x, int& y);
	
};

int main()
{
	Organism o;

	o.initial_world();
	o.print_world();
	o.move();
	cout << endl;
	o.print_world();

	return 0;
}

void Organism::initial_world() {
	int num_ants, num_doods;

	num_doods = 0;
	while (num_doods < DOODS) {
		int new_x, new_y;
		
		random_initialization(new_x, new_y);
		if (game[new_x][new_y] == nullptr) {
			game[new_x][new_y] = new Doods(new_x, new_y);
			num_doods++;
		}
	}

	num_ants = 0;
	while (num_ants < ANTS) {
		int new_x, new_y;
		
		random_initialization(new_x, new_y);
		if (game[new_x][new_y] == nullptr) {
			game[new_x][new_y] = new Ants(new_x, new_y);
			num_ants++;
		}
	}
}

void Organism::print_world() {
	for (int x = 0; x < GRID; x++) {
		for (int y = 0; y < GRID; y++) {
			if (game[x][y] != nullptr) {
				cout << game[x][y]->symbol();
			}
			else {
				cout << '-';
			}
		}
		cout << endl;
	}
}

void Organism::move() {
	for (int x = 0; x < GRID; x++) {
		for (int y = 0; y < GRID; y++) {
			if (game[x][y] == nullptr) {
				continue;
			}
			else if (game[x][y]->symbol() == 'X') {
				if ((game[x + 1][y] != nullptr) && (game[x + 1][y]->symbol() == 'o')) {
					game[x][y] = nullptr;
					game[x + 1][y] = nullptr;
					game[x + 1][y] = new Doods((x + 1), y);
				}
				else if ((game[x - 1][y] != nullptr) && (game[x - 1][y]->symbol() == 'o')) {
					game[x][y] = nullptr;
					game[x - 1][y] = nullptr;
					game[x - 1][y] = new Doods((x + 1), y);
				}
				else if ((game[x][y + 1] != nullptr) && (game[x][y + 1]->symbol() == 'o')) {
					game[x][y] = nullptr;
					game[x][y + 1] = nullptr;
					game[x][y + 1] = new Doods((x + 1), y);
				}
				else if ((game[x][y - 1] != nullptr) && (game[x][y - 1]->symbol() == 'o')) {
					game[x][y] = nullptr;
					game[x][y - 1] = nullptr;
					game[x][y - 1] = new Doods((x + 1), y);
				}
			}
			else if (game[x][y]->symbol() == 'o') {
				int new_x, new_y;
				bool good_move = false;

				while (good_move == false) {
					new_x = x;
					new_y = y;
					random_move(new_x, new_y);
					good_move = is_in_bounds(new_x, new_y);
				}

				if (game[new_x][new_y] == nullptr) {
					game[x][y] = nullptr;
					game[new_x][new_y] = new Ants(new_x, new_y);
				}
			}
		}
	}
}

