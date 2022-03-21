#include <iostream>
#include <fstream>
using namespace std;

class Shape2D {
public:
	virtual double calcArea() = 0;
	virtual double calcPerimeter() = 0;
	virtual void print(ofstream&) const = 0;
	virtual ~Shape2D() = 0;
	friend ofstream& operator <<(ofstream&, const Shape2D&);
};

Shape2D::~Shape2D() {} // does nothing
ofstream& operator <<(ofstream& outf, const Shape2D& s2d) {
	s2d.print(outf); // call pure virtual function
	return outf;
}
