#include "input.h"
#include <string>
#include <iostream>

input::input()
{
	inputStr = "";
}

input::~input()
{

}

void input::readInput(void)
{
	std::cout << "Reading input:  ";
	std::cin >> inputStr;
	std::cout << '\r' << inputStr << std::endl;

}
