/*This source code copyrighted by Lazy Foo' Productions (2004-2014)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include <ncurses.h>


bool init();
void close();

struct keyPadSet
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool action;
};



int main( int argc, char* args[] )
{
	if( !init() )
	{
		return 0;
	}


	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	
	keyPadSet keys;	
	const Uint8* keyStates = SDL_GetKeyboardState( NULL );

	//While application is running
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}

		//If 'q' is pressed, quit program
		if ( keyStates[ SDL_SCANCODE_Q] )
		{
			quit = true;	
		}

		//Set keys struct vals based on key status
		keys.up = keyStates[ SDL_SCANCODE_W ]; 
		keys.down = keyStates[ SDL_SCANCODE_S ];
		keys.left = keyStates[ SDL_SCANCODE_A ];
		keys.right = keyStates[ SDL_SCANCODE_D ];
		keys.action = keyStates [ SDL_SCANCODE_SPACE ];
		std::cout << '\r' << keys.up << keys.down << keys.left << keys.right << keys.action;

	}
	
	close();

	return 0;
}



bool init()
{

	bool success = true;

	if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "SDL could not initialize. SDL Error: " << SDL_GetError();
		success = false;
	}
	
	if ( initscr()  < 0 )
	{
		std::cout << "NCurses could not initialize.";
		success = false;
	}
	else
	{
		cbreak();
		noecho();
	}	

	return success;
}



void close()
{
	SDL_Quit();
	endwin();
}
