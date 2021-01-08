#include"Hamster.h"


cHamster::cHamster(SDL_Point position)
{
	Cover = 1.0f;
	Leans = false;
	Position = position;
	isHit = false;
}

void cHamster::Lean(int speed)
{
	if (Leans == false)
	{
		Speed = speed;
		Leans = true;
		Cover = 1.0f;
		LeanUp = true;
		LeanStart = SDL_GetTicks();
	}
}

void cHamster::Run()
{
	if (isHit == false)
	{
		if (Leans == true)
		{

			float Current = SDL_GetTicks();

			if (LeanUp == true)
			{

				Cover = 1.0f - (Current - LeanStart) / Speed;
				if (Cover < 0.0f)
				{
					LeanUp = false;
					LeanStart = SDL_GetTicks();
				}
			}
			else
			{
				Cover = (Current - LeanStart) / Speed;
				if (Cover > 1.0f)
				{
					Leans = false;
					Cover = 1.0f;
				}
			}
		}
	}
	else
	{
		float Current = SDL_GetTicks();
		if (Current - HitTime > 500)
		{
			isHit = false;
			Leans = false;
			Cover = 1.0f;
		}
	}

}

void cHamster::Hit()
{
	isHit = true;
	HitTime = SDL_GetTicks();
}

float cHamster::GetCover()
{
	return Cover;
}

SDL_Point cHamster::GetPos()
{
	return Position;
}

bool cHamster::HitIs()
{
	return isHit;
}
