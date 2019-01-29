#include "pch.h"
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

int main() {
	bool done = false;
	float area;
	while (!done) {
		int user_choice = user_shape_choice();
		if (user_choice == 1)
			area = trapezoid_area_calc();
		else if (user_choice == 2)
			area = triangle_area_calc();
		else if (user_choice == 3)
			area = elipse_area_calc();
		cout << "Area is " << area << endl;
	}
	return 0;
}

int user_shape_choice() {
	int user_choice;
	bool done = false;
	while (!done) {
		string user_confirm;
		cout << "########## Enhanced Area Calculator ##########" << endl
			 << "1) Trapezoid" << endl
			 << "2) Triangle" << endl
			 << "3) Ellipse" << endl
			 << "Enter the number for the shape area that needs to be calculated:" << endl;
		cin >> user_choice;
		if (user_choice > 0 && user_choice < 4) {
			cout << "You entered " << user_choice << ". Is this correct? y/n" << endl;
			getline(cin, user_confirm);
			cin.ignore();	// nasty hack to ignore extra carriage return.
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
	cout << "##### Area of A Triangle Shape #####" << endl;
	int i_base, i_height;
	float f_base, f_height, _area;
	bool done = false;
	while (!done) {
		cout << "Enter the base length:" << endl;
		cin >> i_base;
		cout << "Enter the height length:" << endl;
		cin >> i_height;
		cout << "You entered:" << endl
			 << "Base = " << i_base << endl
			 << "Height = " << i_height << endl
			 << "Is this correct? y/n" << endl;
		string user_confirm;
		getline(cin, user_confirm);
		cin.ignore();	// nasty hack to ignore extra carriage return.
		if (user_confirm[0] != 'Y' && user_confirm[0] != 'y')
			cout << "Very well. Try again." << endl;
		else {
			f_base = i_base;
			f_height = i_height;
			_area = f_base * f_height;
			done = true;
			return (_area / 2);
		}
	}
}

float elipse_area_calc() {
	const double pi = 3.14159265358979;
	cout << "##### Area of an Elipse Shape #####" << endl;
	int i_axis1, i_axis2;
	double d_axis1, d_axis2, d_area;
	bool done = false;
	string user_confirm;
	while (!done) {
		cout << "Enter the length of the first axis:" << endl;
		cin >> i_axis1;
		cout << "Enter the length of the second axis:" << endl;
		cin >> i_axis2;
		cout << "You entered:" << endl
			<< "Axis 1 = " << i_axis1
			<< "Axis 2 = " << i_axis2
			<< "Correct? y/n" << endl;
		getline(cin, user_confirm);
		cin.ignore();	// nasty hack to ignore extra carriage return.
		if (user_confirm[0] != 'Y' && user_confirm[0] != 'y')
			cout << "Very well. Try again." << endl;
		else {
			d_axis1 = i_axis1;
			d_axis2 = i_axis2;
			d_area = pi * d_axis1 * d_axis2;
			done = true;
			return d_area;
		}
	}
}

float trapezoid_area_calc() {
	int i_base1, i_base2, i_height;
	float f_base1, f_base2, f_height, _area;
	bool done = false;
	cout << "##### Area of Trapezoid Shape #####" << endl;
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
		getline(cin, user_confirm);
		cin.ignore();	// nasty hack to ignore extra carriage return.
		if (user_confirm[0] != 'Y' && user_confirm[0] != 'y')
			cout << "Very well. Try again." << endl;
		else {
			f_base1 = i_base1;
			f_base2 = i_base2;
			f_height = i_height;
			_area = f_base1 + f_base2;
			_area = _area / 2;
			return (_area * f_height);
		}
	}
}