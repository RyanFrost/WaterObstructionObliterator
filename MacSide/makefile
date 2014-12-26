OBJS = main.o
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -Wextra -c $(DEBUG)
LFLAGS = -lSDL2 -lncurses
IFLAGS = -I/Library/Frameworks/SDL2.framework/Headers

main : $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

main.o : main.cpp
	$(CC) $(CXXFLAGS) main.cpp $(IFLAGS)

clean:
	\rm *.o *~ main
