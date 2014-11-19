#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include "FourVector.hpp"
#include "ThreeVector.hpp"

class Particle {
  public:
	//Constructors
	Particle(){ mass_ = 0; momentum_= ThreeVector(); pdg_code_=0; }
	Particle(const double mass, const ThreeVector momentum, const int pdg_code);
	Particle(const double mass, const int pdg_code);
	Particle(const Particle& other);
	Particle(const double mass, const double px, const double py, const double pz, const int pdg_code);

	//Set and get functions
	void setMass(const double mass);
	void setPDGCode(const int pdg_code);
	void setThreeMomentum(ThreeVector& momentum);
	void setThreeMomentum(double px, double py, double pz);
	double getMass() const;
	int getPDGCode() const;
	ThreeVector getThreeMomentum() const;
	FourVector getFourMomentum() const;
	double getEnergy() const;
	double getMagMomentum() const;

	//Member assignment operator functions
	Particle& operator=(const Particle& rhs);

 private:
	double mass_;
	ThreeVector momentum_;
	int pdg_code_;

};


#endif //PARTICLE_HPP
