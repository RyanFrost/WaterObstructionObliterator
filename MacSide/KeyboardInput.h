
#include <SDL.h>
#include <array>


class KeyboardInput
{
	private:
		SDL_Event e;
		const Uint8* keyStates;
		std::array<bool,5> keyPad; // values: up, down, left, right, action.
		void updateKeyPadStates(void);

	public:
		KeyboardInput();
		~KeyboardInput();
		
		std::array<bool,5> getKeyPadStates(void);	

};
