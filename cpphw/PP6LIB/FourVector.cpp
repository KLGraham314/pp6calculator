// FourVector.cpp
#include "FourVector.hpp"
#include <cmath>

//Assignment constructor
FourVector::FourVector(const double t_, const double x_, const double y_, const double z_) : t(t_), x(x_), y(y_), z(z_)
{
	interval = spacetimeint();	
}
//Copy constructor
FourVector::FourVector(const FourVector& other) : t(other.t), x(other.x), y(other.y), z(other.z)
{
	interval = spacetimeint();
}

//Get and set functions
void FourVector::setX(const double x_){
	x = x_;
}
void FourVector::setY(const double y_){
	y = y_;
}
void FourVector::setZ(const double z_){
	z = z_;
}
void FourVector::setT(const double t_){
	t = t_;
}
double FourVector::getX() const {
	return x;
}
double FourVector::getY() const {
	return y;
}
double FourVector::getZ() const {
	return z;
}
double FourVector::getT() const {
	return t;
}
double FourVector::getInterval() const {
	return interval;
}


void FourVector::boost_z(const double v){ //Boost along z-axis
	double gammainv = sqrt(1-(v*v));
	double gamma = 1.0/gammainv; //Lorentz factor
	x = x; //boosted x
	y = y; //boosted y
	z = gamma*((z) - (v*(t))); //boosted z
	t = gamma*((t) - (v*(z))); //boosted t
}

double FourVector::spacetimeint() const { //Spacetime interval
	return sqrt( std::abs( ((t)*(t)) - ((x)*(x)) - ((y)*(y)) - ((z)*(z)) ) );
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
