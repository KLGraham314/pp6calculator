#include <iostream>
#include <cmath>
#include <climits>
#include "cppMenu.hpp"
#include "cppMath.hpp"
#include <cstdlib>
#include "cppPhysics.hpp"
#include "FileReader.hpp"
#include "FourVector.hpp"


void swap(double& a, double& b){ //Swap doubles a and b
	double temp = a;
	a = b;
	b = temp;
}

void swapstring(std::string& a, std::string& b){ //Swap strings a and b
	std::string temp = a;
	a = b;
	b = temp;
}

void bubblesort(double array[10000], std::string farray[10000], std::string garray[10000]){
	int conditional = 1; //Assume disordered to start	
	while(conditional!=0){
	      for(int i=0; i<10000; i++){
		  if(array[i]<array[i+1]){
			 swap(array[i],array[i+1]);
			 swapstring(farray[i],farray[i+1]);
			 swapstring(garray[i],garray[i+1]);
		  }
	      }
		 conditional = 0; // If ordered, = 0;
		for(int i=0; i<10000; i++){
			if(array[i]<array[i+1]) conditional++; //Increment conditional if disordered
		}
	}
}



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
			      double invm[10000]; //Array to hold invariant masses
			      for(int i=0; i<10000; i++) invm[i]=0; //initialise
			      std::string findex[10000]; //Array to hold mu- events
			      std::string gindex[10000]; //Array to hold mu+ events
			      while (f.nextLine()) {
					std::string namef = f.getFieldAsString(2);
					double pxf = f.getFieldAsDouble(3);
					double pyf = f.getFieldAsDouble(4);
					double pzf = f.getFieldAsDouble(5);
					double Ef = sqrt((mass*mass)+(pxf*pxf)+(pyf*pyf)+(pzf*pzf));
					if(namef=="mu+"){
						FileReader g("observedparticles.dat");
						while (g.nextLine()){
							std::string nameg = g.getFieldAsString(2);
							if(nameg=="mu-"){
								double pxg = g.getFieldAsDouble(3);
								double pyg = g.getFieldAsDouble(4);
								double pzg = g.getFieldAsDouble(5);
								double Eg = sqrt((mass*mass)+(pxg*pxg)+(pyg*pyg)+(pzg*pzg));
								double invmass = sqrt((Ef+Eg)*(Ef+Eg)-(pxf+pxg)*(pxf+pxg)-(pyf+pyg)*(pyf+pyg)-(pzf+pzg)*(pzf+pzg));
								k++; //Move to nexy array index
								invm[k]= invmass; //Add the inv mass to the array
								findex[k]= namef; //Line of the mu+
								gindex[k]= nameg; //Line of the mu-

							}
						}
					} 
			      }
			     //bubblesort(invm, findex, gindex);
			     for(int i=0; i<10; i++){
					std::cout << invm[i] << std::endl;
			     }
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

} //End menu()

