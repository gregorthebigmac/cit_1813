#include "pch.h"
#include "geometry_calculator.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int user_shape_choice();

geometry_calculator shape;

int main() {
	bool done = false;
	while (!done) {
		int user_choice = user_shape_choice();
		switch (user_choice) {
		case 1:
			cout << endl << "Area is " << shape.trapezoid_area_calc() << endl << endl;
			break;
		case 2:
			cout << endl << "Area is " << shape.triangle_area_calc() << endl << endl;
			break;
		case 3:
			cout << endl << "Area is " << shape.elipse_area_calc() << endl << endl;
			break;
		case 4:
			cout << endl << "Goodbye!" << endl << endl;
			done = true;
			return 0;
			break;
		default:
			cout << "I'm sorry, but " << user_choice << " is not a valid option. Try again." << endl << endl;
			break;
		}
	}
	return 0;
}

int user_shape_choice() {
	int user_choice;
	bool done = false;
	while (!done) {
		cout << "########## Enhanced Area Calculator ##########" << endl << endl
			 << "1) Trapezoid" << endl
			 << "2) Triangle" << endl
			 << "3) Ellipse" << endl << endl
			 << "4) Quit" << endl << endl
			 << "Enter the number for the shape area that needs to be calculated:" << endl;
		cin >> user_choice;
		cin.ignore();	// nasty hack to ignore extra carriage return.
		if (user_choice > 0 && user_choice < 5) {
			cout << "You entered " << user_choice << ". Is this correct? y/n" << endl;
			string user_confirm;
			getline(cin, user_confirm);
			if (user_confirm[0] == 'Y' || user_confirm[0] == 'y')
				done = true;
		}
	}
	cout << endl << endl;
	return user_choice;
}