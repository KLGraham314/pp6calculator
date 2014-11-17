#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

// Forward declare struct
struct FourVector;

enum FourVectorCausalType {
	SPACELIKE_TYPE,
	TIMELIKE_TYPE,
	NULL_TYPE,
	UNDEFINED_TYPE
};

//Creator function
FourVector* createFourVector();

//Destroyer function
void destroyFourVector(FourVector *&f);

//Setting member variables
void setFourVectorX(FourVector *f, double x);
void setFourVectorY(FourVector *f, double y);
void setFourVectorZ(FourVector *f, double z);
void setFourVectorT(FourVector *f, double t);

//Getting member variables
double getFourVectorX(FourVector *f);
double getFourVectorY(FourVector *f);
double getFourVectorZ(FourVector *f);
double getFourVectorT(FourVector *f);

//Member functions
void boost_z(FourVector *&f, double v);
double spacetimeint(FourVector *f);

//Return the causal type
FourVectorCausalType getFourVectorCausalType(FourVector *f);

#endif //FOURVECTOR_HPP
