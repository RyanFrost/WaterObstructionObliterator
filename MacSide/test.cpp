#include <netdb.h>
#include <iostream>
#include <string>

int main()
{
	hostent * he = gethostbyname("192.168.2.2");
	std::string str(he->h_addr);
	std::cout << str << std::endl;

	return 0;
}
