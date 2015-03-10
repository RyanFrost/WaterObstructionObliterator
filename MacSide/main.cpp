#include <array>
#include "KeyboardInput.h"
#include "SocketManager.h"



int main()
{

	KeyboardInput keyboard;
	SocketManager piComm(27015);


	std::array<bool,5> keyStates;
	while(true)
	{
		keyStates = keyboard.getKeyPadStates();
		if (keyStates[4] == true)
		{
			break;
		}
	}

	return 0;
}
