#pragma once
#include <iostream>
#include <string>

class geometry_calculator {

public:
	geometry_calculator();
	~geometry_calculator();

	double triangle_area_calc();
	double trapezoid_area_calc();
	double elipse_area_calc();

private:
	double m_base1, m_base2;
	double m_axis1, m_axis2;
	double m_height;
};
