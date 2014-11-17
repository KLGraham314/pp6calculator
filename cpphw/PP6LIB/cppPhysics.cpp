#include <iostream>
#include <cmath>
#include <cstdlib>
#include "cppPhysics.hpp"

void fenergy(double& mean, double& dev){
	double momenta[100]; //Array to hold 3-momenta
	double energies[100]; //Array to hold energies
	double sumenergy = 0; //Variable to hold sum of energies;
	for(int i=0; i<100; i++){
		double p = rand()%100; //Random number for 3-momentum
		momenta[i] = p;
		double m = rand()%100; //Random number for mass
		energies[i] = sqrt((p*p)+(m*m)); //Calculate energy from random p and m
		sumenergy += energies[i]; //Add energy to total
			}
		mean = sumenergy*0.01; // = sum/100
		double diff=0; // energy - mean energy summed
		for(int i=0;i<100;i++){
			diff+= ((energies[i] - mean)*(energies[i] - mean)); //Add to total
		}
		dev = sqrt((diff/99)); //Calculate standard deviation
}

void boost_z(double& x, double& y, double& z, double&t, double v){ //Boost along z-axis
	double gammainv = sqrt(1-(v*v));
	double gamma = 1.0/gammainv; //Lorentz factor
	x = x; //boosted x
	y= y; //boosted y
	z = gamma*(z - (v*t)); //boosted z
	t = gamma*(t - (v*z)); //boosted t
}

double spacetimeint(double x, double y, double z, double t){ //Spacetime interval
	return sqrt( abs(  (x*x) + (y*y) + (z*z) - (t*t) ) ); 
}

