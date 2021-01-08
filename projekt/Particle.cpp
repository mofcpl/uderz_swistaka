#include"Particle.h"

cParticle::cParticle(int type, float lifetime, SDL_Point pos)
{
	Position = pos;
	Age = 0.0f;
	LifeTime = lifetime;
	Type = type;
	BornTime = SDL_GetTicks();
}

bool cParticle::Run()
{
	float Current = SDL_GetTicks();
	Age = (Current - BornTime) / LifeTime;
	if (Age > 1.0f) return false; else return true;
}

float cParticle::ReturnAge()
{
	return Age;
}

int cParticle::ReturnType()
{
	return Type;
}

SDL_Point cParticle::ReturnPos()
{
	return Position;
}
