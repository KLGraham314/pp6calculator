#include <iostream>
#include <climits>
#include <cmath>
#include "PP6LIB/cppMath.hpp"
#include "PP6LIB/cppMenu.hpp"



int main()
{
    std::cout << "Welcome to the PP6 calculator!" << std::endl;

    while(true){
	int top = 0; // Variable for users to decide on which menu for day of the course
	std::cout << "Please choose which functions you would like to choose from based on the day of the course they were implemented." << std::endl;
	std::cout << "Enter '1' for Day 1, '2' for Day 2, '3' for Day 3, '4' for Day 4, or '0' to quit PP6 calculator." << std::endl;
	std::cin >> top; //Take user choice of menu
	if(!std::cin){ //If input failed, move onto the next iteration
		std::cout << "Input failed" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	} else if(top==0) { //Quit the program
		std::cout << "Thank you for using PP6 calculator. Goodbye!" << std::endl;
		break;
	} else if(top!=1 && top!=2 && top!=3 && top!=4){ //If input not valid, print message and move onto next iteration
		std::cout << "Please enter '0', '1', '2' , '3' or '4' only." << std::endl;
	} else {
		 menu(top); //Takes user to menu of choice;
	}
    }
	
	return 0;
}


