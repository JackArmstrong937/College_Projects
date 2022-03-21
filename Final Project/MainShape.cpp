/*
 * =====================================================================================
 *
 *       Filename:  MainShape.cpp
 *
 *    Description: reads shape text file, totals number of shapes, there corresponding areas and perimeters. then outputs stats
 *
 *        Version:  1.0
 *        Created:  08/3/2020  
 *       Revision:  none
 *       Compiler:  visual studios
 *
 *         Author: Jack Armstrong
 *   
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

const double& PI = 3.14159;
const int& nshapes = 2000; // no. lines in Shapes.txt file

#include "Shape2D.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main() {
	//variable declaration
	double Rad, s0, s1, s2;
	double w = 0;
	double l = 0;
	string shapestr;
	vector<Shape2D*> vptr_shape(nshapes, nullptr); // size 2000

	//Shape.txt file reading and writing
	ifstream infile;
	infile.open("Shapes.txt"); // open “Shapes.txt” (2001 lines) for reading

	ofstream outfile;
	outfile.open("ShapesOut.txt"); // open “ShapesOut.txt” for writing

	int icount = 0;
	while (1) {
		infile >>  shapestr;
		if (shapestr == "circle") {
			infile >> Rad; // radius – type double
			vptr_shape[icount] = new Circle(Rad); 
				vptr_shape[icount]->calcArea(); 
			vptr_shape[icount]->calcPerimeter(); 
			
		}
		else if (shapestr == "rectangle") {
			infile >> w;
			infile >> l;
			vptr_shape[icount] = new Rectangle(w, l); 
			vptr_shape[icount]->calcArea(); 
			vptr_shape[icount]->calcPerimeter(); 
			
		}
		else if (shapestr == "triangle") {
			infile >> s0; // radius – type double
			infile >> s1; // radius – type double
			infile >> s2; // radius – type double
			vptr_shape[icount] = new Triangle(s0,s1,s2);
			vptr_shape[icount]->calcArea();
			vptr_shape[icount]->calcPerimeter();
		}
		else if (shapestr == "EOF") {
			break; // termination condition
		}
		else {
			cout << "Error: UNRECOGNIZED SHAPE, line no."
				 << icount + 1 << endl;
			return 1; // return with code ‘1’
		} 

		outfile << *vptr_shape[icount]; // de-reference pointer to pass derived class object(by reference) to overloaded operator<<()
			++icount; // increment loop counter
	} 

	//output stats:

	//circle:
	cout << "No. Circles = " << Circle::ncircle
		<< ", Total Circle Area = " << Circle::area
		<< ", Total Circle Perimeter = " << Circle::perimeter << endl;

	//Rectangle:
	cout << "No. Rectangles = " << Rectangle::nRectangle
		<< ", Total Rectangle Area = " << Rectangle::area
		<< ", Total Rectangle Perimeter = " << Rectangle::perimeter << endl;

	//Triangle:
	cout << "No. Triangles = " << Triangle::nTriangle
		<< ", Total Triangle Area = " << Triangle::area
		<< ", Total Triangle Perimeter = " << Triangle::perimeter << endl;

	//closing file
	infile.close();
	outfile.close();

	return 0;
}
