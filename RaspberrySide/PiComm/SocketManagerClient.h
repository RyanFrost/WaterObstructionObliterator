#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <vector>
#include <string>



class SocketManagerClient
{
private:
	
	//Properties
	int sockfd;
	struct sockaddr_in remoteHost;
	int port;
	std::string ip;
	
	std::vector<char> buf;
	
	//Methods
	void initSocket(void);
	
	void cleanUpSocket(void);


public:
	SocketManagerClient(int,std::string);
	~SocketManagerClient();
	


	
	void loadIntArrayToBuf(std::vector<int>);
	void loadDubArrayToBuf(std::vector<double>);
	void loadIntToBuf(int);
	void loadDubToBuf(double);
	
	std::vector<char> recvData(void);
	void sendBuf();
	
	std::vector<char> getBuf(void) { return buf;}


	

};

