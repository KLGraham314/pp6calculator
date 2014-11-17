// FourVector.cpp
#include "FourVector.hpp"
#include <cmath>

struct FourVector {
	double x;
	double y;
	double z;
	double t;
};

FourVector* createFourVector() {
	return new FourVector;
}

void destroyFourVector(FourVector *&f) {
	if(f) {
		delete f;
		f = 0;
	}
}

void setFourVectorX(FourVector *f, double x) {
	if(f) f->x = x;
}

void setFourVectorY(FourVector *f, double y) {
	if(f) f->y = y;
}

void setFourVectorZ(FourVector *f, double z) {
	if(f) f->z = z;
}

void setFourVectorT(FourVector *f, double t) {
	if(f) f->t = t;
}

double getFourVectorX(FourVector *f) {
	if(f) return f->x;
}

double getFourVectorY(FourVector *f) {
	if(f) return f->y;
}

double getFourVectorZ(FourVector *f) {
	if(f) return f->z;
}

double getFourVectorT(FourVector *f) {
	if(f) return f->t;
}

void boost_z(FourVector *&f, double v){ //Boost along z-axis
	double gammainv = sqrt(1-(v*v));
	double gamma = 1.0/gammainv; //Lorentz factor
	f->x = f->x; //boosted x
	f->y = f->y; //boosted y
	f->z = gamma*((f->z) - (v*(f->t))); //boosted z
	f->t = gamma*((f->t) - (v*(f->z))); //boosted t
}

double spacetimeint(FourVector *f){ //Spacetime interval
	return sqrt( std::abs( ((f->x)*(f->x)) + ((f->y)*(f->y)) + ((f->z)*(f->z)) - ((f->t)*(f->t)) ) );
}

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
	
