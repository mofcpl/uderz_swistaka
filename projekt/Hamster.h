#pragma once
#include<SDL.h>

class cHamster
{

private:

	SDL_Point Position;
	int Speed;
	float Cover;
	bool Leans;
	bool LeanUp;
	bool isHit;
	float LeanStart;
	float HitTime;

public:

	cHamster(SDL_Point position);

	void Lean(int speed);
	void Run();
	void Hit();

	float GetCover();
	SDL_Point GetPos();
	bool HitIs();



};