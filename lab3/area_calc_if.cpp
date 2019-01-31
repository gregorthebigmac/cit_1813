#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int user_shape_choice();
float triangle_area_calc();
float elipse_area_calc();
float trapezoid_area_calc();

const float pi = 3.14159265358979;

int main() {
	bool done = false;
	if (user_choice == 1) {
	}
	return 0;
}

int user_shape_choice() {
	bool done = false;
	while (!done) {
		cout << "########## Enhanced Area Calculator ##########" << endl;
		cout << "1) Trapezoid" << endl
			<< "2) Triangle" << endl
			<< "3) Ellipse" << endl
			<< "Enter the number for the shape area that needs to be calculated:" << endl;
		int user_choice;
		cin >> user_choice;
		if (user_choice > 0 && user_choice < 4) {
			cout << "You entered " << user_choice << ". Is this correct? y/n" << endl;
			string user_confirm = getline(cin.ignore());
			if (user_confirm[0] == 'Y' || user_confirm[0] == 'y') {
				done = true;
				return user_choice;
			}
		}
		else
			cout << "I'm sorry, but " << user_choice << " is not a number between 1 and 3. Try again." << endl;
	}
}

float triangle_area_calc() {
	float _area;
	return _area;
}

float elipse_area_calc() {
	float _area;
	return _area;
}

float trapezoid_area_calc() {
	int i_base1, i_base2, i_height;
	float f_base1, f_base2, f_height;
	bool done = false;
	cout << "##### Area of Trapezoid Shape #####" << endl
	while (!done) {
		string user_confirm;
		cout << "Enter the first base length:" << endl;
		cin >> i_base1;
		cout << "Enter the second base length:" << endl;
		cin >> i_base2;
		cout << "Enter the height:" << endl;
		cin >> i_height;
		cout << "You entered:" << endl
			 << "Base 1 = " << i_base1 << endl
			 << "Base 2 = " << i_base2 << endl
			 << "Height = " << i_height << endl
			 << "Is this correct? y/n" << endl;
			string user_confirm = getline(cin.ignore());
			if (user_confirm[0] != 'Y' && user_confirm != 'y')
				cout << "Very well. Try again." << endl;
			else {
				
			}
		float area;
	}
	return area;
}