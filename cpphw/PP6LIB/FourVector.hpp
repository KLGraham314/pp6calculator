#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include <iostream>

// Forward declare struct
class FourVector {
 public:
	//Constructors
	FourVector(){ t=0; x = 0; y = 0; z = 0 ; interval = 0; }
	FourVector(const double t_, const double x_, const double y_, const double z_);
	FourVector(const FourVector& other);

	//Member functions
	void boost_z(const double v);
	void setX(const double x);
	void setY(const double y);
	void setZ(const double z);
	void setT(const double t);
	double getX() const;
	double getY() const;
	double getZ() const;
	double getT() const;
	double getInterval() const;

	//Member assignment operator functions
	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);
	FourVector& operator=(const FourVector& rhs);


 private:
	//Member variables
	double x;
	double y;
	double z;
	double t;
	double interval;
	
	//Private member functions
	double spacetimeint() const;


};

//Free functions for operators
FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
std::ostream& operator<<(std::ostream& stream, const FourVector& f);
std::istream& operator>>(std::istream& stream, FourVector& f);

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
