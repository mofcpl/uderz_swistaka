
#include"Application.h"

cMenu * cApp::GetMenu()
{
	return Menu;
}

cIntro * cApp::GetIntro()
{
	return Intro;
}

cGame * cApp::GetGame()
{
	return Game;
}

cApp::cApp()
{
	
	APPSTATUS = MENU;

	Intro = new cIntro;
	Menu = new cMenu;
	Game = new cGame;
	Menu->GamePointer(Game);

}

cApp::~cApp()
{
	delete Game;
	delete Menu;
	delete Intro;
}

bool cApp::Run(cEvent* e)
{
	//apdejt 2
	switch (APPSTATUS)
	{

	case GAME: {APPSTATUS = Game->Run(e); return true; break; }
	case INTRO: {APPSTATUS = Intro->Run(e); return true; break; }
	case MENU: {APPSTATUS = Menu->Run(e); return true; break; }
	case QUIT: {return false; break; }
	}
	
}