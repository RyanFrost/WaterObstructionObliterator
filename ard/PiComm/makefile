OBJS = main.o SerialComm.o SocketManagerClient.o
CC = g++-4.7
DEBUG = -g
CXXFLAGS = -Wall -Wextra -c -std=c++11 $(DEBUG)
LFLAGS = -lwiringPi
Main : $(OBJS)
	$(CC) $(OBJS) -o Main $(LFLAGS)

main.o : main.cpp
	$(CC) $(CXXFLAGS) main.cpp

SerialComm.o : SerialComm.h SerialComm.cpp
	$(CC) $(CXXFLAGS) SerialComm.cpp $(LFLAGS)

SocketManagerClient.o : SocketManagerClient.h SocketManagerClient.cpp
	$(CC) $(CXXFLAGS) SocketManagerClient.cpp

clean:
	\rm *.o *~ Main

