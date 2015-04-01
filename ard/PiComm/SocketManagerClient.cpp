#include "SocketManagerClient.h"


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>

#include <iostream>
#include <vector>
#include <string>
//#include <boost/lexical_cast.hpp>





SocketManagerClient::SocketManagerClient(int portNumber,std::string ip) : port(portNumber),ip(ip)
{
	initSocket();
}


SocketManagerClient::~SocketManagerClient()
{
	cleanUpSocket();
}


void SocketManagerClient::initSocket()
{
	std::cout << "Connecting to robot..." << std::flush;
	
	//Setup remote address struct
	remoteHost.sin_family = AF_INET;

	if(inet_pton(AF_INET,ip.c_str(),&(remoteHost.sin_addr)) < 1 )
	{
		perror("IP address incorrect.");
	}
	
	remoteHost.sin_port = htons(port);


	//Create socket
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("cannot create socket");
		return;
	}

	
}


std::vector<char> SocketManagerClient::recvData(void)
{
	//Declare sockaddr_in struct for client
	
	socklen_t remLen = sizeof(remoteHost);

	int recv_len;
	
	// Preallocate buffer
	buf.resize(1024);
	
	if ((recv_len = recvfrom(sockfd, &buf[0], buf.size(), 0, (struct sockaddr *) &remoteHost, &remLen)) < 0)
	{
		perror("Recv Failed");
	}
	
	// Truncate buffer to length of message
	buf.resize(recv_len);
	
	return buf;

}

void SocketManagerClient::sendBuf(void)
{
	
	int remLen = sizeof(remoteHost);


	if (sendto(sockfd, &buf[0], buf.size(), 0, (sockaddr *) &remoteHost, remLen) < 0)
	{
		perror("Send failed.");
	}
}

void SocketManagerClient::loadIntArrayToBuf(std::vector<int> vec)
{
	// clear buffer
	
	buf.clear();
	
	std::string valStr;

	// Create string containing comma-delimited list of the input numbers
	for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		// cast the int to a string, then append to the main string
		valStr.append(std::to_string(*iter));
		
		if (iter < vec.end() - 1) // Doesn't put a comma after the last number
		{
			valStr.append(",");
		}
	}
	
	// copy the string into the vector<char> buffer
	std::copy(valStr.begin(), valStr.end(), back_inserter(buf));
}

void SocketManagerClient::loadDubArrayToBuf(std::vector<double> vec)
{

	buf.clear();

	std::string valStr;

	// Create string containing comma-delimited list of the input numbers
	for (std::vector<double>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		// cast the int to a string, then append to the main string
		valStr.append(std::to_string(*iter));

		if (iter < vec.end() - 1) // Doesn't put a comma after the last number
		{
			valStr.append(",");
		}
	}

	// copy the string into the vector<char> buffer
	std::copy(valStr.begin(), valStr.end(), back_inserter(buf));



}

void SocketManagerClient::loadIntToBuf(int integer)
{
	
	buf.clear();
	std::string intStr = std::to_string(integer);
	std::copy(intStr.begin(), intStr.end(), back_inserter(buf));
}

void SocketManagerClient::loadDubToBuf(double dub)
{
	buf.clear();
	std::string dubStr = std::to_string(dub);
	std::copy(dubStr.begin(), dubStr.end(), back_inserter(buf));
}


void SocketManagerClient::cleanUpSocket(void)
{
	close(sockfd);
	//std::cout << "Socket Destroyed." << std::endl;
}
