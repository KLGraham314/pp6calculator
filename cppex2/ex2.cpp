#include <iostream>
#include <climits>
int main()
{
	double a, b, c; //Declare number variables
	char op; //Declare char variable
	int i=0;
	while(i==0){
	std::cout << "Enter two numbers separated by the enter key" << std::endl; //Ask the user to enter numbers
	std::cin >> a >> b; //Take user input
	std::cout << "What kind of operation do you want to perform? (type 'm' for multiplication, 'd' for division, 'a' for addition or 's' for subtraction, or 'q' for quit, followed by the enter key" << std::endl; //Ask the user to choose operation
	std::cin >> op; //Take in user input

	if(!std::cin){
		std::cout << "Input failed" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		continue;
	} else if(op=='m'){
		c = a*b;
	} else if(op=='d'){
		if(b==0){
			std::cout << "Divide by zero error" << std::endl;
			continue;
		} else{
			c=a/b;
		}
	} else if(op=='a'){
		c=a+b;
	} else if(op=='s'){
		c=a-b;
	} else if(op=='q'){
		break;
	 } else {
		std::cout << "User input must be m, d, a or s only" << std::endl;
		continue;
	}
	std::cout << c << std::endl;
	}
	return 0;
}
