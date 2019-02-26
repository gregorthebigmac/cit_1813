/*
**********Enhanced Area Calculator**********
main()	// loop until user quits
	print_menu()
		Trapezoid()
		Triangle()
		Ellipse()
*/

#include "pch.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int print_menu();
double triangle();
double trapezoid();
double elipse();

int main() {
	bool done = false;
	string user_done, shape_name;	// is using a string for a one-letter answer overkill? Yeah, but at least you don't have to use cin.ignore() to overcome the cin double-carriage-return.
	double area = -1;
	while (!done) {
		int user_choice = print_menu();
		if (user_choice == 1) {
			area = triangle();
			shape_name = "triangle";
		}
		else if (user_choice == 2) {
			area = trapezoid();
			shape_name = "trapezoid";
		}
		else if (user_choice == 3) {
			area = elipse();
			shape_name = "elipse";
		}
		else continue;	// restart the loop if we get something outside the acceptable range
		cout << "The area of your " << shape_name << " is " << area << "." << endl << endl;
		cout << "Do another? y/n" << endl;
		std::getline(cin, user_done);
		if (user_done[0] == 'y' || user_done[0] == 'Y')
			continue;
		else 
			done = true;	// I don't care if the user doesn't actually press 'n' or 'N'. If they press anything other than 'y' or 'Y' it quits.
	}
	return 0;
}

int print_menu() {
	bool done = false;
	int choice = -1;
	while (!done) {
		cout << "|---------Enhanced Area Calculator---------|" << endl;
		cout << "| Main Menu                                |" << endl;
		cout << "|                                          |" << endl;
		cout << "| Choose from the list of shapes below,    |" << endl;
		cout << "| using the corresponding number.          |" << endl;
		cout << "|                                          |" << endl;
		cout << "| 1) Triangle                              |" << endl;
		cout << "| 2) Trapezoid                             |" << endl;
		cout << "| 3) Elipse                                |" << endl;
		cout << "|                                          |" << endl;
		cout << "|------------------------------------------|" << endl;
		cin >> choice;
		cin.ignore();
		if (choice < 1 || choice > 3)
			cout << "Sorry, but " << choice << " is not one of the options listed. Please enter a number between 1 and 3." << endl;
		else {
			// not that it's really necessary, but just in case something goes wrong when it tries to return the choice, it'll dump out of the loop, and return a -1, which is outside the acceptable range, and start the menu over.
			done = true;
			return choice;
		}
	}
}

double triangle() {
	int base, height;
	double area;
	cout << "Enter the base length:" << endl;
	cin >> base;
	cin.ignore();
	cout << "Enter the height length:" << endl;
	cin >> height;
	cin.ignore();
	cout << endl;
	cout << "You entered:" << endl << endl;
	cout << "Base =   [" << base << "]" << endl;
	cout << "Height = [" << height << "]" << endl << endl;
	cout << "Is this correct? y/n" << endl;
	string correct;
	std::getline(cin, correct);
	if (correct[0] == 'Y' || correct[0] == 'y')
		area = base * height;
	else
		area = triangle();	// recursive functions are more fun than loops!
	return area;
}

double trapezoid() {
	int base1, base2, height;
	double area;
	cout << "Enter the length of the first base:" << endl;
	cin >> base1;
	cin.ignore();
	cout << "Enter the length of the second base:" << endl;
	cin >> base2;
	cin.ignore();
	cout << "Enter the height:" << endl;
	cin >> height;
	cin.ignore();
	string correct;
	cout << "You entered:" << endl << endl;
	cout << "Base 1 = [" << base1 << "]" << endl;
	cout << "Base 2 = [" << base2 << "]" << endl;
	cout << "Height = [" << height << "]" << endl << endl;
	cout << "Is this correct? y/n" << endl;
	std::getline(cin, correct);
	if (correct[0] == 'y' || correct[0] == 'Y') {
		// I like to be (overly) explicit when I'm doing multiple steps in math. It helps cut down on math errors.
		// My #1 rule in coding is make it easy for others to read to minimize how much commenting is necessary to explain what you're doing.
		area = base1 + base2;
		area = area / 2;
		area = area * height;
	}
	else
		area = trapezoid();	// recursive functions are more fun than loops!
	return area;
}

double elipse() {
	const double pi = 3.14159265358979;
	int axis1, axis2;
	double area;
	cout << "Enter the length of Axis 1: " << endl;
	cin >> axis1;
	cin.ignore();
	cout << "Enter the length of Axis 2: " << endl;
	cin >> axis2;
	cin.ignore();
	cout << "You entered: " << endl << endl;
	cout << "Axis 1 = [" << axis1 << "]" << endl;
	cout << "Axis 2 = [" << axis2 << "]" << endl << endl;
	cout << "Is this correct? y/n" << endl;
	string correct;
	std::getline(cin, correct);
	if (correct[0] == 'y' || correct[0] == 'Y') {
		area = axis1 * axis2;
		area = area * pi;
	}
	else
		area = elipse();	// recursive functions are more fun than loops!
	return area;
}
