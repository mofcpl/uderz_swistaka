#pragma once

#include<SDL_timer.h>
#include"Event.h"
#include"Data.h"




class cIntro
{
private:

	float Start, Actual;

public:

	STATUS Run(cEvent* e);

	cIntro();
	~cIntro();

};