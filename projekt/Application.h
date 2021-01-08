#pragma once

#include"Intro.h"
#include"Menu.h"
#include"Game.h"

class cApp
{
private :

	sVec2D Cursor;

	cMenu* Menu;
	cIntro* Intro;
	cGame* Game;

public:

	cMenu* GetMenu();
	cIntro* GetIntro();
	cGame* GetGame();

	STATUS APPSTATUS;

	cApp();
	~cApp();

	bool Run(cEvent* e);
};



