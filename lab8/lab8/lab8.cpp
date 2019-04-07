// See README.md for details of assignment.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct point {
public:
	void set_coord(int x, int y) {
		posX = x;
		posY = y;
	}
	int get_x_coord() { return posX; }
	int get_y_coord() { return posY; }
	vector<int> get_2d_coord() {
		vector<int> coord;
		coord.push_back(posX);
		coord.push_back(posY);
		return coord;
	}
	
private:
	int posX;
	int posY;
};

struct st_map {
public:
	point get_origin_pos() { return map_origin_pos; }
	point get_termination_pos() { return map_termination_pos; }

	void set_origin_pos(int x, int y) {	map_origin_pos.set_coord(x, y); }
	void set_termination_pos(int x, int y) { map_termination_pos.set_coord(x, y); }

private:
	point map_origin_pos;
	point map_termination_pos;
};

struct ship {
public:
	point get_ship_center() { return ship_center; }
	vector<point> get_ship_location() { return ship_location; }
	int get_ship_length() { return ship_length; }
	int get_ship_width() { return ship_width; }

	void set_ship_center(int x, int y) { ship_center.set_coord(x, y); }
	void set_ship_length(int length) { ship_length = length; }
	void set_ship_width(int width) { ship_width = width; }
	void add_hit(int x, int y) {
		num_hit++;
		point hit_pos;
		hit_pos.set_coord(x, y);
		hit_locations.push_back(hit_pos);
	}
	bool is_equals(point pt_a, point pt_b) {
		if (pt_a.get_x_coord() == pt_b.get_x_coord()) {
			if (pt_a.get_y_coord() == pt_b.get_y_coord()) {
				return true; }
			else return false;
		}
		else return false;
	}

	void cal_location() {
		vector<point> ship_loc;
		int x_left_bounds = ship_center.get_x_coord() - (ship_length / 2);
		int x_right_bounds = ship_center.get_x_coord() + (ship_length / 2);
		int y_down_bounds = ship_center.get_y_coord() - (ship_width / 2);
		int y_up_bounds = ship_center.get_y_coord() + (ship_width / 2);
		for (int x = x_left_bounds; x <= x_right_bounds; x++) {
			for (int y = y_down_bounds; y <= y_up_bounds; y++) {
				point temp;
				cout << "Ship location: " << x << ", " << y << endl;
				temp.set_coord(x, y);
				ship_loc.push_back(temp);
			}
		}
		ship_location = ship_loc;
	}

private:
	point ship_center;
	vector<point> ship_location;
	int num_hit;
	vector<point> hit_locations;
	int ship_length;
	int ship_width;
};

void redraw(st_map map, ship player_ship);
ship move_ship(st_map map, ship player_ship);

int main() {
	st_map map;
	ship player_ship;
	map.set_origin_pos(0, 0);
	map.set_termination_pos(10, 10);
	player_ship.set_ship_center(1, 1);
	player_ship.set_ship_length(2);
	player_ship.set_ship_width(2);
	player_ship.cal_location();

	redraw(map, player_ship);
	player_ship = move_ship(map, player_ship);

	return 0;
}

void redraw(st_map map, ship player_ship) {
	point map_origin = map.get_origin_pos();
	point map_bounds = map.get_termination_pos();
	for (int x = map_origin.get_x_coord(); x < map_bounds.get_x_coord(); x++) {
		for (int y = map_origin.get_y_coord(); y < map_bounds.get_y_coord(); y++) {
			point pos_a;
			pos_a.set_coord(x, y);
			vector<point> ship_location = player_ship.get_ship_location();
			bool ship_is_here = false;
			for (int i = 0; i < ship_location.size(); i++) {
				if (player_ship.is_equals(pos_a, ship_location[i])) {
					cout << "#";
					ship_is_here = true; }
			}
			if (ship_is_here) {
				//cout << "#";
			}
			else cout << "-";
		}
		cout << endl;
	}
}

ship move_ship(st_map map, ship player_ship) {
	ship temp_ship = player_ship;
	cout << "Player 1: Use W A S D to move the ship to where you want it, and press P when you're done." << endl;
	string player_input;
	point center = temp_ship.get_ship_center();
	int x = center.get_x_coord();
	int y = center.get_y_coord();
	while (player_input[0] != 'q') {
		std::getline(cin, player_input);
		char p_input = player_input[0];
		cout << "You entered " << p_input << "." << endl;
		/*if (p_input == 'w') {
			if (center.get_y_coord() < 9) {
				x++;
				temp_ship.set_ship_center(x, y);
			}
		}
		*/
	}
	return temp_ship;
}