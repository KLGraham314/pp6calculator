//ThreeVector.cpp
#include <cmath>
#include "ThreeVector.hpp"

//Constructors

ThreeVector::ThreeVector(const ThreeVector& other) : x_(other.x_), y_(other.y_), z_(other.z_) {
	compute_length();	
}

ThreeVector::ThreeVector(const double x, const double y, const double z) : x_(x), y_(y), z_(z) {
	compute_length();
}

//Set and get functions
void ThreeVector::setX(double x){
	x_ = x;
	compute_length();
}
void ThreeVector::setY(double y){
	y_ = y;
	compute_length();
}
void ThreeVector::setZ(double z){
	z_ = z;
	compute_length();
}

double ThreeVector::getX() const {
	return x_;
}
double ThreeVector::getY() const {
	return y_;
}
double ThreeVector::getZ() const {
	return z_;
}
double ThreeVector::length() const {
	return len_;
}

//Private member functions
void ThreeVector::compute_length(){
	len_ = sqrt( x_*x_ + y_*y_ + z_*z_ );
}
