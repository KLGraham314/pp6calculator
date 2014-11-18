#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

// Forward declare struct
class FourVector {
 public:
	//Constructors
	FourVector(){ t=0; x = 0; y = 0; z = 0 ; interval = 0; }
	FourVector(const double t_, const double x_, const double y_, const double z_);
	FourVector(const FourVector& other);

	//Member functions
	void boost_z(const double v);
	void setX(const double x_);
	void setY(const double y);
	void setZ(const double z);
	void setT(const double t);
	double getX() const;
	double getY() const;
	double getZ() const;
	double getT() const;
	double getInterval() const;


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
