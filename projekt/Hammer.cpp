#include "Hammer.h"

cHammer::cHammer()
{
	HitSpeed = 100.0f;
	HitProgress = 0.0f;
	isHitting = false;
}

void cHammer::SetPos(SDL_Point * Point)
{
	Position = *Point;
}

SDL_Point cHammer::GetPos()
{
	return Position;
}

float cHammer::GetProg()
{
	return HitProgress;
}

void cHammer::Hit()
{
	if (isHitting == false)
	{
		isHitting = true;
		HitStart = SDL_GetTicks();
	}
}

void cHammer::Run()
{
	if (isHitting == true)
	{
		float Current = SDL_GetTicks();
		HitProgress = (Current - HitStart)/HitSpeed;
		if (HitProgress > 1.0f)
		{
			HitProgress = 0.0f;
			isHitting = false;
		}
	}
}
