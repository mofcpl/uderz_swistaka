#include<SDL.h>
#include<SDL_timer.h>
#include"Timer.h"

cTimer::cTimer()
{
	SDL_InitSubSystem(SDL_INIT_TIMER);
	LapTime = 0;
}

cTimer::~cTimer()
{
	SDL_QuitSubSystem(SDL_INIT_TIMER);
}

void cTimer::start()
{
	startTime = SDL_GetTicks();
}

void cTimer::SetLapTime(double time)
{
	LapTime = time;
}

double cTimer::getTime()
{
	if (LapTime == 0) return 0;
	return SDL_GetTicks() - startTime;
}

double cTimer::getLaps()
{
	if (LapTime == 0) return 0;
	double laps = getTime() / LapTime;
	if (laps >= 1) start();
	return laps;
}