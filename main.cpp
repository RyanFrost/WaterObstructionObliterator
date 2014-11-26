#include "input.h"

#include <string>


input inputObj;


int main()
{

	std::string inputStr;
	while (inputStr != "q")
	{
		inputObj.readInput();
		inputStr = inputObj.getInput();
	}

	return 0;
}
