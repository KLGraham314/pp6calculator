//Particle.cpp
#include "Particle.hpp"
#include "FourVector.hpp"
#include "ThreeVector.hpp"
#include <cmath>

//Constructors
Particle::Particle(const double mass, const ThreeVector momentum, const int pdg_code) : mass_(mass), momentum_(momentum), pdg_code_(pdg_code){}

Particle::Particle(const double mass, const int pdg_code){
	mass_ = mass;
	momentum_ = ThreeVector();
	pdg_code_ = pdg_code;
}

Particle::Particle(const Particle& other) {
	mass_ = other.mass_;
	momentum_ = other.momentum_;
	pdg_code_ = other.pdg_code_; 	
}

Particle::Particle(const double mass, const double px, const double py, const double pz, const int pdg_code){
	mass_ = mass;
	pdg_code_ = pdg_code;
	momentum_ = ThreeVector(px,py,pz);
}

//Set and get functions
void Particle::setMass(const double mass){
	mass_ = mass;
}
void Particle::setPDGCode(const int pdg_code){
	pdg_code_ = pdg_code;
}
void Particle::setThreeMomentum(ThreeVector& momentum){
	momentum_ = momentum;
}
void Particle::setThreeMomentum(double px, double py, double pz){
	momentum_ = ThreeVector(px,py,pz);
}
double Particle::getMass() const {
	return mass_;
}
int Particle::getPDGCode() const {
	return pdg_code_;
}
ThreeVector Particle::getThreeMomentum() const {
	return momentum_;
}
FourVector Particle::getFourMomentum() const {
	FourVector *f;
	double magp = momentum_.length();
	double energy = sqrt(magp*magp + mass_*mass_);
	f->setThreeVector(momentum_);
	f->setT(energy);
	return *f;
}

//Member assignment operator functions
Particle& Particle::operator=(const Particle& rhs){
	if(&rhs != this){
		mass_ = rhs.mass_;
		momentum_ = rhs.momentum_;
		pdg_code_ = rhs.pdg_code_;
	}
	return *this;
}
