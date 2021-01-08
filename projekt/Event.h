#pragma once

#include<SDL.h>
#include<SDL_keyboard.h>
#include<SDL_mouse.h>

class cEvent
{
private:

	SDL_Event input;
	SDL_Point mousepos;
	SDL_Window* pWindow;

	int Width, Height;

public:

	cEvent();
	~cEvent();


	void Init(SDL_Window* window, int resX, int resY); 
	void UpdateEvents();
	bool CheckEvent(Uint32 eve);
	bool CheckKeyboard(SDL_Scancode code);
	void GetMousePosition(int* x, int* y);
	bool CheckMouseButtons(Uint32 button);
	void ShowMouse(int toogle); 
};

