#pragma once

#include"Event.h"
#include"Data.h"
#include"Game.h"


class cMenu
{
private:

	bool isClick;
	cGame* pGame;

public:

	cMenu();
	~cMenu();

	void GamePointer(cGame* pointer);
	bool ButtonGamePressed, ButtonExitPressed;
	float ClickTime;

	STATUS Run(cEvent* e);

	bool Click();
	void ClickDone();
};