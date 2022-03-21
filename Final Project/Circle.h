
#include <iostream>
#include <cmath>
using namespace std;

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle:public Shape2D {
public:
	static int ncircle;
	static double area;
	static double perimeter;

	//constructors
	Circle() {
		radius = 0;
	}
	Circle(double R) {
		radius = R;
		++ncircle;
	}

	//function initialization
	double getRadius();
	void setRadius(double R);
	double calcArea();
	double calcPerimeter();
	void print(ofstream& outf)const ;

	//deconstructor
	~Circle() {}
protected:
	double radius;
};

double Circle::area = 0;
double Circle::perimeter = 0;
int Circle::ncircle = 0;

//function definitions
//get and set functions for radius value
double Circle::getRadius() {
	return radius;
}
void Circle::setRadius(double R) {
	radius = R;
}

//calulation functions
double Circle::calcArea() {
	double Aterm = PI * pow(radius, 2);
	area += Aterm;
	return Aterm;
}
double Circle::calcPerimeter() {
	double Pterm = 2 * PI * radius;
	perimeter += Pterm;
	return Pterm;
}

//final output print function
void Circle::print(ofstream& outf)const {
	outf << "circle" << " " << radius << endl;
}

#endif