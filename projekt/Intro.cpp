#include<iostream>
#include"Intro.h"
#include"Data.h"


cIntro::cIntro()
{
	Start = SDL_GetTicks(); 
}


cIntro::~cIntro()
{

}


STATUS cIntro::Run(cEvent * e) //UPDATE 3
{
	e->ShowMouse(SDL_DISABLE);
	
	Actual = SDL_GetTicks();
	if (Actual - Start >= 3000) return MENU;  
	else return INTRO;

}





