OBJS = main.o input.o
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -Wextra -c $(DEBUG)

TWOO : $(OBJS)
	$(CC) $(OBJS) -o TWOO

main.o : main.cpp
	$(CC) $(CXXFLAGS) main.cpp

input.o : input.h input.cpp
	$(CC) $(CXXFLAGS) input.cpp

clean:
	\rm *.o *~ TWOO
