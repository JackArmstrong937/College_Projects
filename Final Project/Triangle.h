#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle:public Shape2D {
public:
    static int nTriangle;
    static double area;
    static double perimeter;

    Triangle() {
        vside[0] = 0;
        vside[1] = 0;
        vside[2] = 0;
    }

    Triangle(const double& s0, const double& s1,
        const double& s2) {
        vside.resize(3);
        vside[0] = s0;
        vside[1] = s1;
        vside[2] = s2;
        ++nTriangle;
    }

    //function initializations
    double getSides();
    void setSides(double s0, double s1, double s2);
    double calcArea();
    double calcPerimeter();
    void print(ofstream& outf) const;

    //deconstructor
    ~Triangle() {}

protected:
    vector<double> vside;
};

int Triangle::nTriangle = 0;
double Triangle::area = 0;
double Triangle::perimeter = 0;

//function definitions

double  Triangle::getSides() { return vside[3]; }
void Triangle::setSides(double s0, double s1, double s2) {
    s0 = s0;
    s1 = s1;
    s2 = s2;
}

//calculations
double Triangle::calcArea() {
    double S = (vside[0] + vside[1] + vside[2]) / 2;
    double aTerm = sqrt(S * (S - vside[0]) * (S - vside[1]) * (S - vside[2]));
    area += aTerm;
    return aTerm;
}
double Triangle::calcPerimeter() {
    double pTerm = (vside[0] + vside[1] + vside[2]);
    perimeter += pTerm;
    return pTerm;
}

//Outputs
void Triangle::print(ofstream& outf) const {
    outf << "triangle" << " " << vside[0] << " " << vside[1] << " " << vside[2] << endl;
}
#endif