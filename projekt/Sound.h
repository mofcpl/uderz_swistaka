#pragma once

#include<SDL.h>
#include<SDL_mixer.h>
#include"Application.h"



class cSound
{
private:

	Mix_Music *Theme;

	Mix_Chunk *Swish;
	Mix_Chunk *Click;
	Mix_Chunk *Hit;
	Mix_Chunk *Squeak;

public:

	void Init();
	void PlayMusic(cApp* app);
	void PlaySound(cApp* app);

	cSound();
	~cSound();
};