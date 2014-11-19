// FourVector.cpp
#include "FourVector.hpp"
#include "ThreeVector.hpp"
#include <iostream>
#include <cmath>




//Assignment constructor
FourVector::FourVector(const double t, const double x, const double y, const double z) : t_(t), x_(x), y_(y), z_(z)
{
	compute_interval();	
}
//Copy constructor
FourVector::FourVector(const FourVector& other) : t_(other.t_), x_(other.x_), y_(other.y_), z_(other.z_)
{
	compute_interval();
}

FourVector::FourVector(const double t, const ThreeVector s){
	t_ = t;
	x_ = s.ThreeVector::getX();
	y_ = s.ThreeVector::getY();
	z_ = s.ThreeVector::getZ();
	compute_interval();
}
	

//Get and set functions
void FourVector::setX(const double x){
	x_ = x;
}
void FourVector::setY(const double y){
	y_ = y;
}
void FourVector::setZ(const double z){
	z_ = z;
}
void FourVector::setT(const double t){
	t_ = t;
}

double FourVector::getX() const {
	return x_;
}
double FourVector::getY() const {
	return y_;
}
double FourVector::getZ() const {
	return z_;
}
double FourVector::getT() const {
	return t_;
}
double FourVector::getInterval() const {
	return interval_;
}


void FourVector::boost_z(const double v){ //Boost along z-axis
	double gammainv = sqrt(1-(v*v));
	double gamma = 1.0/gammainv; //Lorentz factor
	x_ = x_; //boosted x
	y_ = y_; //boosted y
	z_ = gamma*((z_) - (v*(t_))); //boosted z
	t_ = gamma*((t_) - (v*(z_))); //boosted t
}

void FourVector::compute_interval() { //Spacetime interval
	interval_ = sqrt( std::abs( ((t_)*(t_)) - ((x_)*(x_)) - ((y_)*(y_)) - ((z_)*(z_)) ) );
}


//Member assignment operator functions
FourVector& FourVector::operator+=(const FourVector& rhs){
	t_ += rhs.t_;
	x_ += rhs.x_;
	y_ += rhs.y_;
	z_ += rhs.z_;
	return *this;
}
FourVector& FourVector::operator-=(const FourVector& rhs){
	t_ -= rhs.t_;
	x_ -= rhs.x_;
	y_ -= rhs.y_;
	z_ -= rhs.z_;
	return *this;
}
FourVector& FourVector::operator=(const FourVector& rhs){
	if(&rhs != this){
		t_ = rhs.t_;
		x_ = rhs.x_;
		y_ = rhs.y_;
		z_ = rhs.z_;
	}
	return *this;
}

//Free operator functions
FourVector operator+(const FourVector& lhs, const FourVector& rhs){
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}
FourVector operator-(const FourVector& lhs, const FourVector& rhs){
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}
std::ostream& operator<<(std::ostream& stream, const FourVector& f){
	stream << "t: ";
	stream << f.getT() << "\n x: " << f.getX() << "\n y: ";
	stream << f.getY() << "\n z: " << f.getZ() << "\n";
	return stream;
}
std::istream& operator>>(std::istream& stream, FourVector& f){
	double t, x, y, z;
	stream >> t >> x >> y >> z;
	f.setT(t);
	f.setX(x);
	f.setY(y);
	f.setZ(z);
	f.compute_interval();
	return stream;
}

/*
FourVectorCausalType getFourVectorCausalType(FourVector *f) {
	if(!f) {
		return UNDEFINED_TYPE;
	}
	double dssquared = ((f->x)*(f->x)) + ((f->y)*(f->y)) + ((f->z)*(f->z)) - ((f->t)*(f->t));
	if(dssquared==0){
		return NULL_TYPE;
	} else if(dssquared<0.0){
		return TIMELIKE_TYPE;
	} else if(dssquared>0.0){
		return SPACELIKE_TYPE;
	}
}
*/	
