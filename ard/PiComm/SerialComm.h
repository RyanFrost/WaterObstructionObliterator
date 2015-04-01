
#include <string>




class SerialComm
{
public:
	//Properties
	


	//Methods
	SerialComm(std::string serialPortStr, int baudRate);
	~SerialComm(void);
	int setPinDigital(int pinNumber, int pinLevel); // Pin level 0 or 1
	int setPinAnalog(int pinNumber, int pinLevel); //Pin level b/w 0-255


private:
	//Properties
	int fd;
	const int digitalPins[5] = {2,4,7,8,12};
	const int analogPins[7]  = {3,5,6,9,10,11,13};

	//Methods
	void sendStr(std::string strToSend); //Used by setPin functions


};
