#include <iostream>
#include <climits>
#include <cmath>
#include "PP6LIB/cppMath.hpp"
#include "PP6LIB/cppMenu.hpp"



int main()
{
    while(true){
	int top = 0; // Variable for users to decide on which menu for day of the course
	std::cout << "Welcome to the PP6 calculator!" << std::endl;
	std::cout << "Please choose which functions you would like to choose from based on the day of the course they were implemented." << std::endl;
	std::cout << "Enter '1' for Day 1 and '2' for Day 2, or '0' to quit PP6 calculator." << std::endl;
	std::cin >> top; //Take user choice of menu
	if(!std::cin){ //If input failed, move onto the next iteration
		std::cout << "Input failed" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	} else if(top==0) { //Quit the program
		std::cout << "Thank you for using PP6 calculator. Goodbye!" << std::endl;
		break;
	} else if(top!=1 && top!=2){ //If input not valid, print message and move onto next iteration
		std::cout << "Please enter '0', '1' or '2' only." << std::endl;
	} else {
		 menu(top); //Takes user to menu of choice;
	}
    }
	
	return 0;
}


