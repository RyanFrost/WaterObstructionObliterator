#include "SerialComm.h"

#include <wiringPi.h>
#include <wiringSerial.h>

#include <string>

#include <algorithm>



SerialComm::SerialComm(std::string serialPortStr, int baudRate)
{


	//Open serial port, return -1 if unable to open
	if ((fd = serialOpen (serialPortStr.c_str(), baudRate)) < 0)
	{
		return;
	}
	
	//Setup wiringPi, return -2 if unable to setup
	if (wiringPiSetup() < 0)
	{	
		return;
	}
/*
	digitalPins = {2,4,7,8,12,13};
	analogPins = {3,5,6,9,10,11};
*/
	return; //Return 1 if all good

}	


SerialComm::~SerialComm()
{
	serialClose(fd);
}

int SerialComm::setPinDigital(int pinNumber, int pinLevel)
{
	//Check if input pinNumber is actually a digital pin. If not, return -1
	if ( !std::binary_search(digitalPins,digitalPins+6, pinNumber))
	{
		return -1;
	}
	else if (pinLevel > 1 || pinLevel < 0) //Make sure pinLevel is 0 or 1
	{
		return -2;
	}
	else
	{
		std::string intStr = std::to_string(pinNumber);	
	
		intStr.append("d"); // Separating character so arduino can differentiate between pinNumber & pinLevel
		intStr.append(std::to_string(pinLevel));
		intStr.append("\n"); // End character for arduino
		sendStr(intStr);
		return 1;
	}
	
}



int SerialComm::setPinAnalog(int pinNumber, int pinLevel)
{
	//Check if input pinNumber is actually an analog pin. If not, return -1
	if ( !std::binary_search(analogPins,analogPins+6, pinNumber))
	{
		return -1;
	}
	else if (pinLevel > 255 || pinLevel < 0) //Make sure pinLevel is within 0-255 range
	{
		return -2;
	}
	else
	{
		std::string intStr = std::to_string(pinNumber);	
	
		intStr.append("a"); // Separating character so arduino can differentiate between pinNumber & pinLevel
		intStr.append(std::to_string(pinLevel));
		intStr.append("\n"); // End character for arduino
		sendStr(intStr);
		return 1;
	}
	
}



void SerialComm::sendStr(std::string strToSend)
{

	serialPuts(fd,strToSend.c_str());
}
