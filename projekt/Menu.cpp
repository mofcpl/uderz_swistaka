#include"Menu.h"

cMenu::cMenu()
{
	isClick = false;
	ButtonExitPressed = false;
	ButtonGamePressed = false;
}

cMenu::~cMenu()
{

}

void cMenu::GamePointer(cGame * pointer)
{
	pGame = pointer;
}


STATUS cMenu::Run(cEvent * e) //UPDATE 3
{
	e->ShowMouse(SDL_ENABLE);
	int x, y;
	e->GetMousePosition(&x, &y);

	if ((y > 80 && y < 440) && (x > 120 && x < 600))
	{
		
		if (e->CheckMouseButtons(SDL_BUTTON_LEFT) == true)
		{
			isClick = true;
			ButtonGamePressed = true;
			ClickTime = SDL_GetTicks();
		}
	}

	if ((y > 500 && y < 780) && (x > 120 && x < 600))
	{
		
		if (e->CheckMouseButtons(SDL_BUTTON_LEFT) == true)
		{
			isClick = true;
			ButtonExitPressed = true;
			ClickTime = SDL_GetTicks();
		}
	}

	if (ButtonGamePressed == true && SDL_GetTicks() - ClickTime >= 300)
	{
		isClick = false;
		ButtonGamePressed = false;
		pGame->Reset();
		return GAME;
	}

	if (ButtonExitPressed == true && SDL_GetTicks() - ClickTime >= 300)
	{
		isClick = false;
		ButtonExitPressed = false;
		return QUIT;
	}

	return MENU;
}

bool cMenu::Click()
{
	return isClick;
}

void cMenu::ClickDone()
{
	isClick = false;
}

