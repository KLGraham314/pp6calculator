#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include "cppMenu.hpp"
#include "cppMath.hpp"
#include <cstdlib>
#include "cppPhysics.hpp"
#include "FileReader.hpp"
#include "FourVector.hpp"
#include "ThreeVector.hpp"
#include "Particle.hpp"



void menu(int top){ //Function for menu for Day 1 operations

     double a=0, b=0, c=0, cminus=0, d=0, e=0, inside=0, E1=0, E2=0, px1=0, px2=0, py1=0, py2=0, pz1=0, pz2=0; //Declare number variables
     char op; //Declare char variable for users to decide on calculator function

     if(top==1){ //Day 1 

	while(true){ //While true, the calculator will keep performing functions until user quits
		std::cout << "What kind of operation do you want to perform? (type 'm' for multiplication, 'd' for division, 'a' for addition or 's' for subtraction, 'x' to calculate the x-intercept of a line, 'e' to solve a quadratic equation, 't' to calculate the length of a 3-vector, 'f' to calculate the length of a 4-vector, 'p' to calculate the invariant mass of two particles, or 'q' to quit and go back to the top level menu, followed by the enter key)" << std::endl; //Ask the user to choose operation
		std::cin >> op; //Take in user selection

		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		if(op=='q'){ break;} //User quits - go back to top level menu
		else if(op=='a'||op=='s'||op=='m'||op=='d'){ //For arithmetic, print this message and take inputs
			std::cout << "Enter two numbers separated by the enter key" << std::endl; //Ask the user to enter numbers
			std::cin >> a >> b; //Take user input
			if(op=='m'){ //Multiply
			    c = multiply(a,b);
			} else if(op=='d'){ //Divide
			    if(b==0){ //If b=0 answer will be infinite - inform user and move onto next iteration
				std::cout << "Divide by zero error" << std::endl;
				continue;
			    } else{
				c=divide(a,b);
			    }
			} else if(op=='a'){ //Add
			    c=add(a,b);
			} else if(op=='s'){ //Subtract
			     c=subtract(a,b);
			}
		}
		else if(op=='x'){ //For intercept function, print these messages and take inputs
			std::cout << "Enter the value of 'a' in the equation y = ax + b" << std::endl;
			std::cin >> a;
			std::cout << "Enter the value of 'b' in the equation y = ax + b" << std::endl;
			std::cin >> b;
			c=intercept(a,b);
		}
		else if(op=='e'){ //For quadratic funtion, print these messages and take inputs
			std::cout << "Enter the value of 'a' in a*x^2 + b*x + c = 0" << std::endl;
			std::cin>>a;
			std::cout << "Enter the value of 'b' in a*x^2 + b*x + c = 0" << std::endl;
			std::cin>>b;
			std::cout << "Enter the value of 'c' in a*x^2 + b*x + c = 0" << std::endl;
			std::cin>>d;
			inside = (b*b)-(4*a*d); //Evaluate b^2 - 4*a*c
			if(inside>=0){ //If inside is positive the answer will be real
				quadratic(a,b,inside,c,cminus);
			}else{ //If inside is negative the answer will be imaginary
				c = (-1*b)/(2*a); //Real part
				cminus = sqrt(-1*inside)/(2*a); //Imaginary part
			}
		}
		else if(op=='t'||op=='f'){ //For 3- or 4-vectors, print these messages and take inputs
			std::cout << "Enter the value of the first element of the vector" << std::endl;
			std::cin>>a;
			std::cout << "Enter the value of the second element of the vector" << std::endl;
			std::cin>>b;
			std::cout << "Enter the value of the third element of the vector" << std::endl;
			std::cin>>d;
			if(op=='t') c = tlength(a,b,d);
			if(op=='f'){ //Only 4-vectors have 4th element
				std::cout << "Enter the value of the fourth element of the vector" << std::endl;
				std::cin >> e;
				c = flength(a,b,d,e);
			}
		}
		else if(op=='p'){ //For invariant mass calculation, print these messages and take inputs
			std::cout << "Enter the energy of the first particle" << std::endl;
			std::cin >> E1;
			std::cout << "Enter the energy of the second particle" << std::endl;
			std::cin >> E2;
			std::cout << "Enter the x-momentum of the first particle" << std::endl;
			std::cin>> px1;
			std::cout << "Enter the x-momentum of the second particle" << std::endl;
			std::cin>> px2;
			std::cout << "Enter the y-momentum of the first particle" << std::endl;
			std::cin>> py1;
			std::cout << "Enter the y-momentum of the second particle" << std::endl;
			std::cin>> py2;
			std::cout << "Enter the z-momentum of the first particle" << std::endl;
			std::cin>> pz1;
			std::cout << "Enter the z-momentum of the second particle" << std::endl;
			std::cin>> pz2;
			bool real = invmass(E1,E2,px1,px2,py1,py2,pz1,pz2,c);
			if(real==0){ //If E^2<p^2, invmass will return 0
				std::cout << "E^2 < p^2 for these particles, which is unphysical" << std::endl;
				continue;
			}	 	
		} else { //If user has entered incorrect input, inform them and move onto next iteration
			std::cout << "User input must be m, d, a, s, x, e, t, f, p or q only" << std::endl;
			continue;
		}

		
		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}
		
		std::cout << c; //Print (first) answer
		if(op=='e'){ //For quadratic equation solution, print second part of answer
			if(inside>=0) std::cout << " or " << cminus; //For real answers
			if(inside<0) std::cout << " +/- " << cminus << "i"; //For imaginary numbers
		}
		std::cout << std::endl;
	} //End while loop
     } //End Day 1

     if(top==2){ //Day 2

	while(true){ //Loop until user quits

		std::cout << "What kind of operation do you want to perform? Enter 'r' to generate 100 random energies and 3-momenta and report the mean energy and standard deviation, 'm' to read in a file you have supplied to calculate the invariant mass of all mu+ mu- pairs and report the 10 largest invariant masses and which events formed these, or 'q' to quit and go back to the top level menu." << std::endl;
		std::cin >> op; //Take user input

		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		if(op=='r'){ //Generate 100 random energies and 3-momenta and give the mean energy and standard deviation
			double mean = 0;
			double dev = 0;
			std::cout <<"Generating 100 random energies and 3-momenta." <<std::endl;
			fenergy(mean, dev); //Calculate mean and standard deviation of those 100 energies
			std::cout <<"Mean energy is " << mean << " GeV." << std::endl;
			std::cout<< "Standard deviation is " << dev << " GeV." <<std::endl;

		} else if(op=='m'){ //Read in user-supplied file, calculate the invariant mass of all mu+ mu- pairs and report the 10 largest invariant masses and which events formed these
			const double mass = 0.106; //Muon mass in GeV
			FileReader f("observedparticles.dat"); //Open the file to be read
			// Only process if the file is open/valid
			if (f.isValid()) {
			      // Loop until out of lines
			      int k = 0; //Array index
			      double *invm = new double[100000]; //Array to hold invariant masses
			      for(int i=0; i<100000; i++) invm[i]=0; //initialise
			      int *findex = new int[100000]; //Array to hold mu- events
			      int *gindex = new int[100000]; //Array to hold mu+ events
			      while (f.nextLine()) {										      
					std::string namef = f.getField<std::string>(2); //Name of particle
					if(namef=="mu+"){ 
						int eventf = f.getField<int>(1); //Event number for this mu+					
						Particle muplus = Particle(); //Create new particle with defaults
						//Set momentum, mass and PDG code
						muplus.setThreeMomentum(f.getField<double>(3), f.getField<double>(4),f.getField<double>(5));
						muplus.setMass(105.66);
						muplus.setPDGCode(13);
						FourVector pplus = muplus.getFourMomentum(); //Get the 4-momentum of this mu+
						FileReader g("observedparticles.dat"); //Open file a second time
						while (g.nextLine()){
							std::string nameg = g.getField<std::string>(2); //Name of second particle
							if(nameg=="mu-"){
								int eventg = g.getField<int>(1); //Event number for this mu-
								Particle muminus = Particle(); // Create a new particle with defaults
								//Set momentum, mass and PDGCode for this mu-
								muminus.setThreeMomentum(g.getField<double>(3), g.getField<double>(4), g.getField<double>(5));
								muminus.setMass(105.66);
								muminus.setPDGCode(13);
								FourVector pminus = muminus.getFourMomentum(); //Get 4-momentum for this mu-
								FourVector added = pplus + pminus; //Add 4-momenta components
								double invmass = added.getInterval(); //Calculate invariant mass 
								invm[k]= invmass; //Add the inv mass to the array
								findex[k]= eventf; //Line of the mu+
								gindex[k]= eventg; //Line of the mu-
								k++; //Move to nexy array index
							}
						}
					} 
			      }
			     bubblesort(invm, findex, gindex); //Sort by highest inv mass, and sort corresponding mu+, mu- indices into same order
			     std::cout << "Inv mass \t mu+ event \t mu- event" << std::endl; //Print
			     for(int i=0; i<10; i++){
					std::cout << invm[i] << '\t' << '\t' << findex[i] << '\t'<< '\t' << gindex[i] << std::endl;
			     }
			     delete[] invm;
			     delete[] findex;
			     delete[] gindex;
			} else { // File is not open/valid
			      std::cout << "Failed to open file. Check file is named 'observedparticles.dat', is in the same directory as this, and is of a valid format" << std::endl;
			      continue; 
			}

		} else if(op=='q'){ //Quit and go back to top level menu
			break;

		} else{ // Invalid input
			std::cout << "Input must be 'r' or 'q' only" << std::endl;
			continue;
		}

	} //End while loop
    }	//End Day 2

    if(top==3){ //Day 3 operations
	while(true){
		std::cout << "What kind of operation do you want to perform? Enter 'b' to boost a 4-vector along the x-axis, 'l' to calulate the length of a 4-vector or 'q' to quit to top level menu." << std::endl;
		std::cin >> op; //Take in user input for operation

		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		if(op=='b'){
			double t, x, y, z, v=2; //4-vector component variables; v=2 so is not valid initially
			std::cout << "Enter the components of the 4-vector and the boost velocity (in nat units)." << std::endl;
			std::cout << "Enter in the order t, x, y, z:" << std::endl;
			FourVector *f = new FourVector(); //Create null 4-vector
			std::cin >> *f; //Take in t,x,y,z from user and set in class
			while(v<0||v>1){ //Take in v from user until is valid
				std::cout << "v (must be between 0 and 1): ";
				std::cin >> v;
			}
			f->boost_z(v); //Calculate boosted coordinates
			std::cout << "The boosted components are: \n" << *f; //Print boosted 4-vector components

		} else if(op=='l'){ //Calculate length of 4-vector
			double t, x, y, z; //4-vector component variables
			std::cout << "Enter the components of the 4-vector." << std::endl;
			std::cout << "Enter in the order t, x, y, z:" << std::endl;
			FourVector *f = new FourVector(); //Create null 4-vector
			std::cin >> *f; //Take in t,x,y,z from user and set in class
			double ds = f->getInterval(); //Calculate spacetime interval;
			std::cout << "ds = " << ds << std::endl; //Print interval

		//	FourVectorCausalType typ = getFourVectorCausalType(f);
		//	if(typ==UNDEFINED_TYPE) std::cout << "Didn't work" << std::endl;
		//	if(typ==TIMELIKE_TYPE) std::cout << "Timelike" << std::endl;
		//	if(typ==SPACELIKE_TYPE) std::cout << "Spacelike" << std::endl;
		//	if(typ==NULL_TYPE) std::cout << "Null" << std::endl;

		} else if(op=='q'){//Go back to top level menu
			break;
		} else{ //Invalid input
			std::cout << "Input must be 'b','l' or 'q' only." << std::endl;
			continue;
		}
	}

    } //End Day 3

    if(top==4){ //Day 4 operations
	while(true) {
		std::cout << "What kind of operation do you want to perform? Enter 'r' to read in the pdg.dat file you have supplied, or 'q' to quit to the top level menu." << std::endl;
		std::cin >> op; //Take in user input for operation
		
		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		if(op=='r'){ //Read in pdg.dat file
			FileReader p("pdg.dat");
			if (p.isValid()) {
				std::vector<std::string> particleTypes; //Vector to hold particle types
				std::vector<int> pdgCodes; //Vector to hold PDG codes
				std::vector<double> charges; //Vector to hold particle charges
				std::vector<double> masses; //Vector to hold particle masses in MeV
				while (p.nextLine()) { //For each line, append data to vectors
					particleTypes.push_back(p.getField<std::string>(1));
					pdgCodes.push_back(p.getField<int>(2));
					charges.push_back(p.getField<double>(3));
					masses.push_back(p.getField<double>(4));
				}
				//Create iterators to use in for loop
				std::vector<std::string>::iterator iterParticleTypes = particleTypes.begin();
				std::vector<int>::iterator iterPdgCodes = pdgCodes.begin();
				std::vector<double>::iterator iterCharges = charges.begin();
				std::vector<double>::iterator iterMasses = masses.begin();
				std::vector<std::string>::iterator particleTypesEnd = particleTypes.end();
				std::cout << "Particle Type \t Code \t \t Charge \t Mass /MeV \n"; //Column headers
				for( ; iterParticleTypes!=particleTypesEnd; iterParticleTypes++){ //Print data to screen
					std::cout << *iterParticleTypes << "\t\t" << *iterPdgCodes << "\t\t" << *iterCharges << "\t\t" << *iterMasses << std::endl;
					iterPdgCodes++;
					iterCharges++;
					iterMasses++;
				}
			} else { //File not opened
				std::cout << "Failed to open file. Check pdg.dat has correct name and is in correct folder." << std::endl;
				continue;
			}

		} else if(op=='q'){ //Go back to top level menu
			break;

		} else { //Invalid input
			std::cout << "Input must be 'r' or 'q' only." << std::endl;
			continue;
		}
    	}
    } //End Day 4	

} //End menu()

