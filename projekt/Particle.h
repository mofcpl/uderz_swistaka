#pragma once


#include<SDL.h>

class cParticle
{
private:

	SDL_Point Position;
	float Age;
	float LifeTime;
	float BornTime;
	int Type;

public:

	cParticle(int type, float lifetime,SDL_Point pos);
	bool Run();

	float ReturnAge();
	int ReturnType();
	SDL_Point ReturnPos();
};