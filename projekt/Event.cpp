#include"Event.h"

cEvent::cEvent()
{
	SDL_InitSubSystem(SDL_INIT_EVENTS);
}

cEvent::~cEvent()
{
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

void cEvent::Init(SDL_Window* window, int resX, int resY)
{
	pWindow = window;
	Width = resX;
	Height = resY;

}

void cEvent::UpdateEvents()
{
	SDL_PollEvent(&input);
	SDL_GetMouseState(&mousepos.x, &mousepos.y);
}

bool cEvent::CheckEvent(Uint32 eve)
{
	if (input.type == eve) return 1; else return 0; 
}

bool cEvent::CheckKeyboard(SDL_Scancode code)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[code]) return 1; else return 0;
}

void cEvent::GetMousePosition(int* x, int* y)
{
	*x = mousepos.x;
	*y = mousepos.y;

	int width, height;
	SDL_GetWindowSize(pWindow, &width, &height);
	float scaleX = ((float)width / Width);
	float scaleY = ((float)height / Height);
	*x /= scaleX;
	*y /= scaleY;
}

bool cEvent::CheckMouseButtons(Uint32 button)
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button)) return true; else return false;
}

void cEvent::ShowMouse(int toogle) //UPDATE 3
{
	SDL_ShowCursor(toogle);
}



