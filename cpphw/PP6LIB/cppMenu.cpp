#include <iostream>
#include <cmath>
#include <climits>
#include "cppMenu.hpp"
#include "cppMath.hpp"
#include <cstdlib>

void menu(int top){ //Function for menu for Day 1 operations
     double a=0, b=0, c=0, cminus=0, d=0, e=0, inside=0, E1=0, E2=0, px1=0, px2=0, py1=0, py2=0, pz1=0, pz2=0; //Declare number variables
     char op; //Declare char variable for users to decide on calculator function
     if(top==1){
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
	}
     }
     if(top==2){
	while(true){
		std::cout << "What kind of operation do you want to perform? Enter 'r' to generate 100 random energies and 3-momenta and report the mean energy and standard deviation, or 'q' to quit and go back to the top level menu." << std::endl;
		std::cin >> op;

		if(!std::cin){ //If input failed, move onto the next iteration
			std::cout << "Input failed" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		if(op=='r'){
			std::cout <<"Generating 100 random energies and 3-momenta." <<std::endl;
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
			double mean = sumenergy*0.01; // = sum/100
			std::cout <<"Mean energy is " << mean << " GeV." << std::endl;
			double diff=0; // energy - mean energy summed
			for(int i=0;i<100;i++){
				diff+= ((energies[i] - mean)*(energies[i] - mean)); //Add to total
			}
			double dev = sqrt((diff/99)); //Calculate standard deviation
			std::cout<< "Standard deviation is " << dev << " Gev." <<std::endl;

		} else if(op=='q'){
			break;
		} else{
			std::cout << "Input must be 'r' or 'q' only" << std::endl;
			continue;
		}

	}
    }	
}

