
#include "KeyboardInput.h"
#include "SocketManager.h"
#include <array>
#include <vector>
#include <iostream>
#include <unistd.h>

int keyCombination(std::array<bool,5>);

int main()
{

	KeyboardInput keyboard;
	SocketManager piComm(27015);

	std::vector<char> data = piComm.recvData();
	piComm.loadIntToBuf(1);
	piComm.sendBuf();



	std::array<bool,5> keyStates;
	while(true)
	{
		keyStates = keyboard.getKeyPadStates();
		int combo = keyCombination(keyStates);
		piComm.loadIntToBuf(combo);
		piComm.sendBuf();	
		

		
		if (keyStates[4] == true)
		{
			break;
		}
	usleep(30000);
	}
	
	return 0;
}



int keyCombination(std::array<bool,5> keys)
{
	std::array<bool,5> forward	= {1,0,0,0,0};	// Forward
	std::array<bool,5> back		= {0,1,0,0,0}; 	// Back
	std::array<bool,5> left 	= {0,0,1,0,0}; 	// Left
	std::array<bool,5> right 	= {0,0,0,1,0}; 	// Right
	std::array<bool,5> fwdLft 	= {1,0,1,0,0}; 	// Forward-Left
	std::array<bool,5> fwdRt 	= {1,0,0,1,0}; 	// Forward-Right
	std::array<bool,5> bkLft	= {0,1,1,0,0};	// Back-Left
	std::array<bool,5> bkRt		= {0,1,0,1,0};	// Back-Right

	if(keys == forward) 	{ return 1; }
	if(keys == back)	{ return 2; }
	if(keys == left)	{ return 3; }
	if(keys == right)	{ return 4; }
	if(keys == fwdLft)	{ return 5; }
	if(keys == fwdRt)	{ return 6; }
	if(keys == bkLft)	{ return 7; }
	if(keys == bkRt)	{ return 8; }
	else
	{
		return 0;
	}
	
}
