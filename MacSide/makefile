OBJS = main.o KeyboardInput.o SocketManager.o
CC = clang++
DEBUG = -g
CXXFLAGS = -stdlib=libc++ -std=c++11 -c 
LFLAGS = -lSDL2
IFLAGS = -I/Library/Frameworks/SDL2.framework/Headers

main : $(OBJS)
	$(CC) -stdlib=libc++ $(OBJS) -o main $(LFLAGS)

main.o : main.cpp
	$(CC) $(CXXFLAGS) main.cpp $(IFLAGS)

KeyboardInput.o : KeyboardInput.h KeyboardInput.cpp
	$(CC) $(CXXFLAGS) KeyboardInput.cpp $(IFLAGS)

SocketManager.o : SocketManager.h SocketManager.cpp
	$(CC) $(CXXFLAGS) SocketManager.cpp

clean:
	\rm *.o *~ main
