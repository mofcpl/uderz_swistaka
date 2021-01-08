#pragma once
#include<SDL.h>
#include"Event.h"


class cHammer
{
private:

	float HitProgress; 
	SDL_Point Position; 
	float HitSpeed; 
	bool isHitting; 
	float HitStart; 

public:

	cHammer();

	void SetPos(SDL_Point* Point);
	SDL_Point GetPos();
	float GetProg();
	void Hit();
	void Run();

};