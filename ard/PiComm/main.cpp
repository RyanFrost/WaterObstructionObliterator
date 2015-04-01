#include "SerialComm.h"
#include "SocketManagerClient.h"

#include <iostream>
#include <string>
#include <vector>






int main()
{
	SerialComm serialObj("/dev/ttyACM0",9600);
	SocketManagerClient socketObj(27015,"100.65.9.28");
	
	std::vector<int> nums = {0,1,2,3,4};

	socketObj.loadIntArrayToBuf(nums);
	socketObj.sendBuf();


	std::vector<char> data = socketObj.recvData();

	if (data[0] =='1')
	{
		std::cout << "Handshake Successful." << std::endl;
	}
	int pinNum = 0;
	int pinLevel = 0;
	while( pinNum >= 0 && pinLevel >= 0)
	{
		std::cout << "Input pin number:";
		std::cin >> pinNum;
		std::cout << "Input pin level:";
		std::cin >> pinLevel;
		if (pinNum >= 0 && pinLevel >= 0)
		{
			int status;
			if ( pinNum == 2 || pinNum == 4 || pinNum == 7)
			{
				status = serialObj.setPinDigital(pinNum,pinLevel);
			}
			else
			{
				status = serialObj.setPinAnalog(pinNum,pinLevel);
			}
			if (status < 0)
			{
				std::cout << "Problem with setting pin, error number: " << status;
			}
		}
		else
		{
			std::cout << "Pin number or level less than zero." << std::endl;
			break;
		}

	}





	return 0;
}
