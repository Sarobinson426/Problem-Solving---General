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

	if (random == down) {
		x++;
	}
	else if (random == right) {
		y++;
	}
	else if (random == up) {
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
	int ant_breed;
	int dood_breed;
	int time_step;
	int ants_eaten;
	Organism* game[GRID][GRID];

public:
	Organism(int new_x = 0, int new_y = 0) : x_plane(new_x), y_plane(new_y), time_step(0), ants_eaten(0) {
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
	void eat_ant(int& x, int& y, int count);
	virtual void eat_an_ant();
	void dood_random_move(int& x, int& y);
	void ant_random_move(int& x, int& y);
	void breed_ant(int& x, int& y);
	void breed_doods(int& x, int& y);
	void ants_eaten_up(int& x, int& y);
	virtual int how_many_ants_eaten() { if (ants_eaten == NULL) { return 0; } else { return ants_eaten; } };

};

class Ants : public Organism {
private:
	char ants;
public:
	Ants(int new_x, int new_y) : Organism(new_x, new_y), ants('o') {
		ant_breed = 0;
	};
	virtual char symbol() { return ants; }
	
};

class Doods : public Organism {
private:
	char doods;

public:
	Doods(int new_x = 0, int new_y = 0) : Organism(new_x, new_y), doods('X') {
		dood_breed = 0;

	};
	virtual char symbol() { return doods; }
	virtual void eat_an_ant();
	virtual int how_many_ants_eaten() { return ants_eaten; };
};

int main()
{
	Organism o;
	char input;

	cout << "Press enter: ";
	cin.get(input);

	o.initial_world();
	while (input == '\n') {
		o.print_world();
		o.move();
		cout << endl;
		cin.get(input);
	}

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
	int count;
	time_step++;

	for (int x = 0; x < GRID; x++) {
		for (int y = 0; y < GRID; y++) {
			if (game[x][y] == nullptr) {
				continue;
			}
			if (game[x][y]->symbol() == 'X') {
				int new_x, new_y;
				bool good_move = false;

				count = 1;
				while (good_move == false && count <= 5) {
					new_x = x;
					new_y = y;

					if (count < 5) {
						eat_ant(new_x, new_y, count);
						if (game[new_x][new_y] != nullptr) {
							if (is_in_bounds(new_x, new_y)) {
								if (game[new_x][new_y]->symbol() == 'o') {
									game[x][y] = nullptr;
									game[new_x][new_y]->eat_an_ant();
									game[new_x][new_y] = new Doods(new_x, new_y);
									game[x][y] = nullptr;
									good_move = true;
								}
							}
						}
					}
					else if (count >= 5) {
						dood_random_move(x, y);
					}

					if ((time_step % 3) == 0) {
						if (game[x][y] == nullptr) {
							return;
						}
						else if (game[x][y]->how_many_ants_eaten() <= 0) {
							game[x][y] = nullptr;
						}
					}
					else if ((time_step % 3) == 0) {
						if (game[x][y]->how_many_ants_eaten() >= 1) {

							game[x][y]->ants_eaten = 0;

							breed_doods(x, y);
						}
					}
					count++;
				}
			}
		}
	}
	for (int x = 0; x < GRID; x++) {
		for (int y = 0; y < GRID; y++) {
			if (game[x][y] == nullptr) {
				continue;
			}
			if (game[x][y]->symbol() == 'o') {
				ant_random_move(x, y);
				if (time_step % 8 == 0) {
					breed_ant(x, y);
				}
			}
		}
	}
}

void Organism::dood_random_move(int& x, int& y) {
	int new_x, new_y, the_ants_eaten;
	bool good_move = false;
 
	while (good_move == false) {
		new_x = x;
		new_y = y;

		random_move(new_x, new_y);
		if (is_in_bounds(new_x, new_y)) {
			if (game[new_x][new_y] == nullptr) {
				game[new_x][new_y] = new Doods(new_x, new_y);
				game[x][y] = nullptr;
				good_move = true;
			}
		}
	}
}

void Organism::ant_random_move(int& x, int& y) {
	int new_x, new_y, num_tries;
	bool good_move = false, is_too_many = false;

	num_tries = 0;
	while (good_move == false && is_too_many == false) {
		new_x = x;
		new_y = y;
		num_tries++;

		random_move(new_x, new_y);
		if (is_in_bounds(new_x, new_y)) {
			if (num_tries < 5) {
				if (game[new_x][new_y] == nullptr) {
					game[x][y] = nullptr;
					game[new_x][new_y] = new Ants(new_x, new_y);
					good_move = true;
				}
			}
		}
		if (num_tries == 5) {
			is_too_many = true;
		}
	}
}

void Organism::eat_ant(int& x, int& y, int count) {

	if (count == 1) {
		x++; // down
	}
	else if (count == 2) {
		y--; // left
	}
	else if (count == 3) {
		x--; // down
	}
	else if (count == 4) {
		y++; // right
	}
}

void Organism::breed_ant(int& x, int& y) {
	int new_x, new_y, num_tries;
	bool good_move = false, is_too_many = false;

	num_tries = 0;
	while (good_move == false && is_too_many == false) {
		new_x = x;
		new_y = y;
		num_tries++;

		random_move(new_x, new_y);
		if (is_in_bounds(new_x, new_y)) {
			if (num_tries < 5) {
				if (game[new_x][new_y] == nullptr) {
					game[new_x][new_y] = new Ants(new_x, new_y);
					good_move = true;
					is_too_many = true;
				}
			}
		}
		if (num_tries == 5) {
			is_too_many = true;
		}
	}
}

void Organism::breed_doods(int& x, int& y) {
	cout << "Breed Doods!" << endl;
	int new_x, new_y;
	bool good_move = false;

	while (good_move == false) {
		new_x = x;
		new_y = y;

		random_move(new_x, new_y);
		if (is_in_bounds(new_x, new_y)) {
			if (game[new_x][new_y] == nullptr) {
				game[new_x][new_y] = new Doods(new_x, new_y);
				good_move = true;
			}
		}
	}
}

void Organism::ants_eaten_up(int& x, int& y) {
	ants_eaten++; 
	cout << "Nom nom nom ant!!" << endl;
}

void Organism::eat_an_ant() {
	ants_eaten++;
}

void Doods::eat_an_ant() {
	ants_eaten++;
}