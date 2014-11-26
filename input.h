#pragma once

#include <string>


class input
{
	public:
		input(void);
		~input();
		void readInput(void);
		
		std::string getInput(void) { return inputStr; }

	private:
		std::string inputStr;

};
