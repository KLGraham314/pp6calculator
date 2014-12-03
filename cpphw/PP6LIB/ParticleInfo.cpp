//ParticleInfo.cpp
#include "ParticleInfo.hpp"
#include "Particle.hpp"
#include "FileReader.hpp"
#include <map>
#include <cmath>


//Constructor
ParticleInfo::ParticleInfo(std::string& database){
	FileReader p(database);
	if(p.isValid()){
		while(p.nextLine()) {
			particle_Ids_.insert(std::make_pair(p.getField<std::string>(1), p.getField<int>(2)));
			particle_Names_.insert(std::make_pair(p.getField<int>(2), p.getField<std::string>(1)));
			particle_Charges_.insert(std::make_pair(p.getField<int>(2), p.getField<int>(3)));
			particle_Masses_.insert(std::make_pair(p.getField<int>(2), p.getField<double>(4)));
		}
	}
}

//Get functions
int ParticleInfo::getPDGCode(std::string& name){
	PartIdCont::iterator p = particle_Ids_.find(name);
	if(p!=particle_Ids_.end()){
		return (*p).second;
	} else return 0;
}
std::string ParticleInfo::getName(int PDGCode){
	PartNameCont::iterator p = particle_Names_.find(PDGCode);
	if(p!=particle_Names_.end()){
		return (*p).second;
	}else return 0;
}
int ParticleInfo::getCharge(int PDGCode){
	PartChargeCont::iterator p = particle_Charges_.find(PDGCode);
	if(p!=particle_Charges_.end()){
		return (*p).second;
	} else return 0;
}
double ParticleInfo::getMassMeV(int PDGCode){
	PartMassCont::iterator p = particle_Masses_.find(PDGCode);
	if(p!=particle_Masses_.end()){
		return (*p).second;
	} else return 0;
}
double ParticleInfo::getMassGeV(int PDGCode){
	double m = getMassMeV(PDGCode); 
	return 1000*m;
}

//Copy constructor
ParticleInfo::ParticleInfo(const ParticleInfo& other){
	particle_Ids_ = other.particle_Ids_;
	particle_Names_ = other.particle_Names_;
	particle_Charges_ = other.particle_Charges_;
	particle_Masses_ = other.particle_Masses_;
}
	
//Assignment operator
ParticleInfo& ParticleInfo::operator=(const ParticleInfo& rhs){
	if(&rhs != this){
		particle_Ids_ = rhs.particle_Ids_;
		particle_Names_ = rhs.particle_Names_;
		particle_Charges_ = rhs.particle_Charges_;
		particle_Masses_ = rhs.particle_Masses_;
	}
	return *this;
}

