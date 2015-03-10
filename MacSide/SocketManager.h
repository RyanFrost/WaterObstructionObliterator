#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <vector>




class SocketManager
{
private:
	
	//Properties
	int sockfd;
	struct sockaddr_in remoteHost;
	int port;
	
	std::vector<char> buf;
	
	//Methods
	void initSocket(void);
	
	void cleanUpSocket(void);


public:
	SocketManager(int);
	~SocketManager();
	


	
	void loadIntArrayToBuf(std::vector<int>);
	void loadDubArrayToBuf(std::vector<double>);
	void loadIntToBuf(int);
	void loadDubToBuf(double);
	
	std::vector<char> recvData(void);
	void sendBuf();
	
	std::vector<char> getBuf(void) { return buf;}


	

};

