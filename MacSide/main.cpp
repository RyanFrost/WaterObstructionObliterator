
#include "KeyboardInput.h"
#include "SocketManager.h"
#include <array>
#include <vector>
#include <iostream>



int main()
{

	KeyboardInput keyboard;
	SocketManager piComm(27015);

	std::vector<char> data = piComm.recvData();
	piComm.loadIntToBuf(1);
	piComm.sendBuf();
	for ( std::vector<char>::iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	std::array<bool,5> keyStates;
	while(false)
	{
		keyStates = keyboard.getKeyPadStates();
		if (keyStates[4] == true)
		{
			break;
		}
	}

	return 0;
}
