#include "cppMath.hpp"
#include <iostream>
#include <cmath>


//function definitions
double multiply(double a, double b){ //Function to multiply the two inputs
	return a*b;
}
double divide(double a, double b){ //Function to divide the two inputs
	return a/b;
}
double add(double a, double b){ //Function to add the two inputs
	return a+b;
}
double subtract(double a, double b){ //Function to subtract the two inputs
	return a-b;
}
double intercept(double a, double b){ //Function to calculate the x-intercept of y = a*x + b
	return (-1)*b/a;
}
void quadratic(double a, double b, double d, double& c, double & cminus){ //Function to find the solutions to a quadratic equation
	c = (((-1)*b)+ sqrt((b*b)-(4*a*d)))/(2*a);
	cminus = (((-1)*b) - sqrt((b*b)-(4*a*d)))/(2*a);
}
double tlength(double a, double b, double d){ //Function to find the length of a 3-vector
	double sumsqr = (a*a) + (b*b) + (d*d);
	return sqrt(sumsqr);
}
double flength(double a, double b, double d, double e){ //Function to find the length of a 4-vector
	double sumsqr = (a*a) - (b*b) - (d*d) - (e*e);
	 return sqrt(std::abs(sumsqr));
}
bool invmass(double E1, double E2, double px1, double px2, double py1, double py2, double pz1, double pz2, double& c){ //Function to calculate invariant mass of two particles
	double sumsqr = ((E1+E2)*(E1+E2)) - ((px1+px2)*(px1+px2)) - ((py1+py2)*(py1+py2)) - ((pz1+pz2)*(pz1+pz2));
	c = sqrt(sumsqr);
	if(sumsqr>=0) return 1; // In this case 1 = "true" = "success"
	if(sumsqr<0) return 0; // In this case 0 = "false" = "failure"
}
