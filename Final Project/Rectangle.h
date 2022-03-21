#include <iostream>
#include <cmath>
using namespace std;

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle:public Shape2D {
public:
    static int nRectangle;
    static double area;
    static double perimeter;

    //constructors
    Rectangle() {
        width = 0;
        length = 0;
    }
    Rectangle(double w, double l) {
        width = w;
        length = l;
        ++nRectangle;
    }

   //Function initializations
    double getLength();
    double getwidth();
    void setSides(double w, double l);
    double calcArea();
    double calcPerimeter();
    void print(ofstream& outf)const;

protected:
    double width;
    double length;
};

 int Rectangle::nRectangle = 0;
 double Rectangle::area = 0;
 double Rectangle::perimeter = 0;

//function definitions
//get functions
double Rectangle::getLength() { return length; }
double Rectangle::getwidth() { return width; }

//Set function
void Rectangle::setSides(double w, double l) {
    width = w;
    length = l;
}

//Calculation fuctions
double Rectangle::calcArea() {
    double aTerm = length * width;
    area += aTerm;
    return aTerm;
}
double Rectangle::calcPerimeter() {
    double pTerm = (2 * length) + (2 * width);
    perimeter += pTerm;
    return pTerm;
}
//Output functions
void Rectangle::print(ofstream& outf)const{
    outf << "rectangle" << " " << width << " " << length <<  endl;
}
#endif