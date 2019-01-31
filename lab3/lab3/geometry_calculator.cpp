#include "pch.h"
#include "geometry_calculator.h"

geometry_calculator::geometry_calculator() {}

geometry_calculator::~geometry_calculator() {}

double geometry_calculator::triangle_area_calc() {
	std::cout << "##### Area of A Triangle Shape #####" << std::endl << std::endl;
	int base, height;
	bool done = false;
	while (!done) {
		std::cout << "Enter the base length:" << std::endl;
		std::cin >> base;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << "Enter the height length:" << std::endl << std::endl;
		std::cin >> height;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << std::endl << "You entered: " << std::endl << std::endl
			<< "Base: " << base << std::endl
			<< "Height: " << height << std::endl << std::endl << std::endl
			<< "Is this correct? y/n" << std::endl;
		std::string user_confirm;
		std::getline(std::cin, user_confirm);
		if (user_confirm[0] == 'Y' || user_confirm[0] == 'y') {
			m_base1 = base;
			m_height = height;
			done = true;
		}
		else { std::cout << "Okay, try again." << std::endl << std::endl; }
	}
	double area = m_base1 * m_height;
	return (area / 2);
}

double geometry_calculator::trapezoid_area_calc() {
	std::cout << "##### Area of a Trapezoid Shape #####" << std::endl << std::endl;
	int base1, base2, height;
	bool done = false;
	while (!done) {
		std::cout << "Enter the first base length:" << std::endl;
		std::cin >> base1;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << "Enter the second base length:" << std::endl;
		std::cin >> base2;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << "Enter the height length:" << std::endl;
		std::cin >> height;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << std::endl << "You entered:" << std::endl << std::endl
			<< "Base 1: " << base1 << std::endl
			<< "Base 2: " << base2 << std::endl
			<< "Height: " << height << std::endl << std::endl
			<< "Is this correct? y/n" << std::endl;
		std::string user_confirm;
		std::getline(std::cin, user_confirm);
		if (user_confirm[0] == 'Y' || user_confirm[0] == 'y') {
			m_base1 = base1;
			m_base2 = base2;
			m_height = height;
			done = true;
		}
		else { std::cout << "Okay, try again." << std::endl << std::endl; }
	}
	double area = m_base1 + m_base2;
	area = area / 2;
	return (area * m_height);
}

double geometry_calculator::elipse_area_calc() {
	std::cout << "##### Area of an Elipse Shape #####" << std::endl << std::endl;
	const double pi = 3.14159265358979;
	double axis1, axis2;
	bool done = false;
	while (!done) {
		std::cout << "Enter the length of the first axis:" << std::endl;
		std::cin >> axis1;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << "Enter the length of the second axis:" << std::endl;
		std::cin >> axis2;
		std::cin.ignore();	// nasty hack to ignore extra carriage return.
		std::cout << std::endl << "You entered:" << std::endl << std::endl
			<< "Axis 1: " << axis1 << std::endl
			<< "Axis 2: " << axis2 << std::endl << std::endl
			<< "Is this correct? y/n" << std::endl;
		std::string user_confirm;
		std::getline(std::cin, user_confirm);
		if (user_confirm[0] == 'Y' || user_confirm[0] == 'y') {
			m_axis1 = axis1;
			m_axis2 = axis2;
			done = true;
		}
		else { std::cout << "Okay, try again." << std::endl << std::endl; }
	}
	return (pi * m_axis1 * m_axis2);
}