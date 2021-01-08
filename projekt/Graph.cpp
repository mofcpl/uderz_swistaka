#include<Windows.h>
#include<SDL_render.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>
#include"Graph.h"


cGraph::cGraph()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_StartTextInput();

	Window = NULL;
	Renderer = NULL;
}

cGraph::~cGraph()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_StopTextInput();
}

void cGraph::InitGraph(cApp* app)
{	

	pApp = app;
	pIntro = app->GetIntro();
	pMenu = app->GetMenu();

	Window = SDL_CreateWindow("Uderz Œwistaka", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 960, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	
	Intro = LoadGraph("Graph/intro.bmp");
	Menu = LoadGraph("Graph/menu.png");
	MapTop = LoadGraph("Graph/gora.png");
	MapDown = LoadGraph("Graph/dol.png");
	MapBottom = LoadGraph("Graph/tyl.png");
	Hammer = LoadGraph("Graph/hammer2.png");
	Hamster = LoadGraph("Graph/hamster2.png");
	HamsterHit = LoadGraph("Graph/hamsterHit.png");
	ButtonGame = LoadGraph("Graph/start1.png");
	ButtonGamePressed = LoadGraph("Graph/start2.png");
	ButtonQuit = LoadGraph("Graph/wyjscie1.png");
	ButtonQuitPressed = LoadGraph("Graph/wyjscie2.png");
	Smoke = LoadGraph("Graph/bam2.png");
	Fire = LoadGraph("Graph/bam.png");
	ScoreBoard = LoadGraph("Graph/wynik.png");

	Font = TTF_OpenFont("Font/couree.fon",1);
	std::cout << "TTF_Init failed " << TTF_GetError() << std::endl;

};


SDL_Texture* cGraph::LoadGraph(std::string path)
{

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	std::cout << IMG_GetError() << std::endl;

	SDL_Texture* tmp = SDL_CreateTextureFromSurface(Renderer, loadedSurface);

	std::string error = IMG_GetError();
	if (error != "") std::cout << error << std::endl;

	std::cout << "Surface Loaded - "<< path << std::endl;
	
	return tmp;
}


void cGraph::DrawIntro()
{	
	//SDL_RenderCopy(Renderer,Intro,NULL,NULL);
}

void cGraph::DrawMenu()
{
	SDL_RenderCopy(Renderer, Menu, NULL, NULL);
	
	if (pMenu->ButtonGamePressed == false)
		SDL_RenderCopy(Renderer, ButtonGame, NULL, NULL);
	else SDL_RenderCopy(Renderer, ButtonGamePressed, NULL, NULL);

	if (pMenu->ButtonExitPressed == false)
		SDL_RenderCopy(Renderer, ButtonQuit, NULL, NULL);
	else SDL_RenderCopy(Renderer, ButtonQuitPressed, NULL, NULL);

}

void cGraph::DrawGame()
{

	SDL_Point pos;
	SDL_Rect Rect;

	
	SDL_RenderCopy(Renderer, MapBottom , NULL, NULL);
	SDL_RenderCopy(Renderer, MapTop, NULL, NULL);

	
	for (int i = 0; i < 6; i++)
	{
		cHamster* pHamster;
		pHamster = pApp->GetGame()->ReturnHamster(i);

		pos = pHamster->GetPos();
		float cover = pHamster->GetCover();

		Rect.x = pos.x;
		Rect.y = pos.y + 150 * cover;
		Rect.h = 207;
		Rect.w = 159;
		
		if (pHamster->HitIs() == false)
		{

			SDL_RenderCopy(Renderer, Hamster, NULL, &Rect);
		}
		else
		{

			SDL_RenderCopy(Renderer, HamsterHit, NULL, &Rect);
		}



	}
	
	SDL_RenderCopy(Renderer, MapDown, NULL, NULL);

	cHammer* pHammer = pApp->GetGame()->ReturnHammer();
	pos = pHammer->GetPos();

	Rect.x = pos.x+245;
	Rect.y = pos.y-455;
	Rect.h = 363;
	Rect.w = 207;

	SDL_Point Point;
	Point.x = 22*3;
	Point.y = 120*3;

	float Angle = -50 + (-50 * pHammer->GetProg());

	SDL_RenderCopyEx(Renderer, Hammer, NULL, &Rect, Angle, &Point, SDL_FLIP_NONE);

	for (int i = 0; i < 99; i++)
	{
		ZeroMemory(&Rect, sizeof(Rect));
	
		cParticle* pParticle = pApp->GetGame()->ReturnParticle(i);
		
		if (pParticle!=NULL)
		{
			
			float Visibility = 255 - pParticle->ReturnAge()*255;

			if (Visibility < 10)
			{
				int a = 1;
			}

			switch (pParticle->ReturnType())
			{
				case 0: 
				{

					Rect.w = 114 + 114* pParticle->ReturnAge();
					Rect.h = 81 + 81* pParticle->ReturnAge();
					Rect.x = pParticle->ReturnPos().x - 20 - Rect.w/2;
					Rect.y = pParticle->ReturnPos().y - Rect.h/2;
					
					SDL_SetTextureAlphaMod(Smoke, Visibility);
					SDL_RenderCopy(Renderer, Smoke,NULL,&Rect);
					break;
				}
				case 1: 
				{
					Rect.w = 114 + 114 * pParticle->ReturnAge();
					Rect.h = 81 + 81 * pParticle->ReturnAge();
					Rect.x = pParticle->ReturnPos().x - 20 - Rect.w / 2;
					Rect.y = pParticle->ReturnPos().y - Rect.h / 2;

					SDL_SetTextureAlphaMod(Fire, Visibility);
					SDL_RenderCopy(Renderer, Fire, NULL, &Rect);
					break;
				}
			}
				
			
		}
	}

	SDL_Color textColor = { 0, 0, 0, 0xFF };

	std::string TimeLeft = "Pozosta³o: ";
	std::string Points = "Punkty: ";
	std::string tmp;

	tmp = std::to_string(pApp->GetGame()->ReturnTime()/1000);
	TimeLeft = TimeLeft + tmp+'s';

	tmp = std::to_string(pApp->GetGame()->ReturnPoints());
	Points = Points + tmp;

	SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, TimeLeft.c_str(), textColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(Renderer, TextSurface);
	SDL_Surface* TextSurface2 = TTF_RenderText_Solid(Font, Points.c_str(), textColor);
	SDL_Texture* TextTexture2 = SDL_CreateTextureFromSurface(Renderer, TextSurface2);
		
	Rect = { 50, 50, TextSurface->w*4, TextSurface->h*4 };
	SDL_RenderCopy(Renderer, TextTexture, NULL, &Rect);

	Rect = { 950, 50,TextSurface2->w*4, TextSurface2->h*4 };
	SDL_RenderCopy(Renderer, TextTexture2, NULL, &Rect);

	SDL_FreeSurface(TextSurface);
	SDL_FreeSurface(TextSurface2);
	SDL_DestroyTexture(TextTexture);
	SDL_DestroyTexture(TextTexture2);

	if (pApp->GetGame()->isGameOn() == true)
	{
		Rect = { 0,0,1280,960 };
		SDL_RenderCopy(Renderer, ScoreBoard, NULL, &Rect);
		
		std::string Points = std::to_string(pApp->GetGame()->ReturnPoints());

		SDL_Surface* TextSurface3 = TTF_RenderText_Solid(Font, Points.c_str(), textColor);
		SDL_Texture* TextTexture3 = SDL_CreateTextureFromSurface(Renderer, TextSurface3);
		Rect = { 595, 480, TextSurface3->w * 8, TextSurface3->h * 8};
		SDL_RenderCopy(Renderer, TextTexture3, NULL, &Rect);
		SDL_FreeSurface(TextSurface3);
		SDL_DestroyTexture(TextTexture3);
	}

}

void cGraph::DrawApplication()
{
	SDL_RenderClear(Renderer);

	switch (pApp->APPSTATUS)
	{

	case GAME: {DrawGame(); break; }
	case INTRO: {DrawIntro(); break;}
	case MENU: {DrawMenu(); break; }

	}

	SDL_RenderPresent(Renderer);
	
}

SDL_Window * cGraph::WinHandle()
{
	return Window;
}

