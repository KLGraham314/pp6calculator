#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <iostream>
#include "ThreeVector.hpp"


class FourVector {
 public:
	//Constructors
	FourVector(){ t_=0; x_ = 0; y_ = 0; z_ = 0 ; interval_ = 0; }
	FourVector(const double t_, const double x_, const double y_, const double z_);
	FourVector(const FourVector& other);
	FourVector(const double t, const ThreeVector s);

	//Member functions
	void boost_z(const double v);
	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);
	void setT(const double t);
	void setThreeVector(const ThreeVector& s);
	double getX() const;
	double getY() const;
	double getZ() const;
	double getT() const;
	double getInterval() const;
	ThreeVector getThreeVector();

	//Member assignment operator functions
	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);
	FourVector& operator=(const FourVector& rhs);
	friend std::istream& operator>>(std::istream& stream, FourVector& f);


 private:
	//Member variables
	double x_;
	double y_;
	double z_;
	double t_;
	double interval_;
	ThreeVector s_;
	
	//Private member functions
	void compute_interval();


};

//Free functions for operators
FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
std::ostream& operator<<(std::ostream& stream, const FourVector& f);

/*
	enum FourVectorCausalType {
		SPACELIKE_TYPE,
		TIMELIKE_TYPE,
		NULL_TYPE,
		UNDEFINED_TYPE
	};
*/

	
	//Return the causal type
//FourVectorCausalType getFourVectorCausalType(FourVector *f);

#endif //FOURVECTOR_HPP
