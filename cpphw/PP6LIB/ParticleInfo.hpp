#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP
#include "Particle.hpp"
#include <map>

typedef std::map<std::string, int> PartIdCont;
typedef std::map<int, std::string> PartNameCont;
typedef std::map<int, int> PartChargeCont;
typedef std::map<int, double> PartMassCont;

class ParticleInfo {
  public:
	//Constructors
	ParticleInfo(std::string& database);
	
	//Get functions
	int getPDGCode(std::string& name);
	int getCharge(int PDGCode);
	std::string getName(int PDGCode);
	double getMassMeV(int PDGCode);
	double getMassGev(int PDGCode);

  private:
	//Copy constructor
	ParticleInfo(const ParticleInfo& other);
	
	//Assignment operator
	ParticleInfo& operator=(const ParticleInfo& rhs);

	//Member variables
	PartIdCont particle_Ids_;
	PartNameCont particle_Names_;
	PartChargeCont particle_Charges_;
	PartMassCont particle_Masses_;

};

#endif //PARTICLEINFO_HPP
	
