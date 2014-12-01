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

void swap(double& a, double& b){ //Swap doubles a and b
	double temp = a;
	a = b;
	b = temp;
}

void swapint(int& a, int& b){ //Swap ints a and b
	int temp = a;
	a = b;
	b = temp;
}

void bubblesort(double array[100000], int farray[100000], int garray[100000]){
	int conditional = 1; //Assume disordered to start	
	while(conditional!=0){
	      for(int i=0; i<100000; i++){
		  if(array[i]<array[i+1]){
			 swap(array[i],array[i+1]);
			 swapint(farray[i],farray[i+1]);
			 swapint(garray[i],garray[i+1]);
		  }
	      }
		 conditional = 0; // If ordered, = 0;
		for(int i=0; i<100000; i++){
			if(array[i]<array[i+1]) conditional++; //Increment conditional if disordered
		}
	}
}

