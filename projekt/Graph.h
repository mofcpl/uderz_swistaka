#ifndef GRAPH_H
#define GRAPH_H

#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include"Application.h"


class cGraph
{
private:

	SDL_Renderer* Renderer;
	SDL_Window* Window; 

	cApp* pApp;
	cIntro* pIntro;
	cMenu* pMenu;

	sVec2D Resolution;
	bool Fullscreen;
	bool Accelerated;

	SDL_Texture* Intro;
	SDL_Texture* Menu;
	SDL_Texture* MapDown;
	SDL_Texture* MapTop;
	SDL_Texture* MapBottom;
	SDL_Texture* Hammer;
	SDL_Texture* Hamster;
	SDL_Texture* HamsterHit;
	SDL_Texture* ButtonGame;
	SDL_Texture* ButtonQuit;
	SDL_Texture* ButtonGamePressed;
	SDL_Texture* ButtonQuitPressed;
	SDL_Texture* Smoke;
	SDL_Texture* Fire;
	SDL_Texture* ScoreBoard;

	TTF_Font* Font = NULL;

	void DrawIntro();
	void DrawMenu();
	void DrawGame();

	SDL_Texture* LoadGraph(std::string path);

public:

	cGraph();
	~cGraph();

	void InitGraph(cApp* app);

	void DrawApplication();
	
	SDL_Window* WinHandle();



};


#endif // GRAPH_H