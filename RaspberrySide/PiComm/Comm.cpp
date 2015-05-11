#include <wiringPi.h>
#include <wiringSerial.h>

#include <iostream>
#include <string>



int main()
{


	int fd;
	if ((fd = serialOpen ("/dev/ttyACM0", 9600)) < 0)
	{
		std::cout << "Unable to open serial device." << std::endl;
		return 0;
	}

	if (wiringPiSetup() == -1)
	{
		std::cout << "Unable to start wiringPi." << std::endl;
		return 0;
	}
	
	
	std::string input = "";
	while(input != "q")
	{
		std::cin >> input;
		
		std::cout << "Input: " << input << std::endl;
		input.append("\n");
		serialPuts(fd,input.c_str());
		
		
	}





	return 0;
}
