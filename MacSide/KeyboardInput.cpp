#include "KeyboardInput.h"
#include <unistd.h>

KeyboardInput::KeyboardInput()
{

	if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
	{
	}
	
	keyStates = SDL_GetKeyboardState( NULL ); 
	return;
}

KeyboardInput::~KeyboardInput()
{
	SDL_Quit();
}

void KeyboardInput::updateKeyPadStates(void)
{
	while( SDL_PollEvent( &e ) != 0 )
	{
		usleep(5000);
	}
	
	keyPad[0] = keyStates[ SDL_SCANCODE_W ];
	keyPad[1] = keyStates[ SDL_SCANCODE_S ];
	keyPad[2] = keyStates[ SDL_SCANCODE_A ];
	keyPad[3] = keyStates[ SDL_SCANCODE_D ];
	keyPad[4] = keyStates[ SDL_SCANCODE_SPACE ];

}
std::array<bool,5> KeyboardInput::getKeyPadStates(void)
{
	updateKeyPadStates();
	return keyPad;
}
