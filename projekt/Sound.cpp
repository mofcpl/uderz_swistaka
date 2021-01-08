#include "Sound.h"

void cSound::PlaySound(cApp * app)
{
	
	if (app->GetMenu()->Click() == true)
	{
		Mix_PlayChannel(-1, Click, 0);
		app->GetMenu()->ClickDone();
	}

	if (app->GetGame()->Hit() == true)
	{
		Mix_PlayChannel(-1, Hit, 0);
		app->GetGame()->HitDone();
	}

	if (app->GetGame()->Squeak() == true)
	{
		Mix_PlayChannel(-1, Squeak, 0);
		app->GetGame()->SqueakDone();
	}

}

void cSound::Init()
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Theme = Mix_LoadMUS("Sound/theme.wav");
	Hit = Mix_LoadWAV("Sound/hit.wav");
	Click = Mix_LoadWAV("Sound/click.wav");
	Swish = Mix_LoadWAV("Sound/swish.wav");
	Squeak = Mix_LoadWAV("Sound/squeak.wav");
}

void cSound::PlayMusic(cApp * app)
{
	if (app->APPSTATUS == QUIT)
	{
		Mix_HaltMusic();
	}
	else
	{
		if (Mix_PlayingMusic() == 0)
		{

			//Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
			Mix_PlayMusic(Theme, -1);
		}
	}
}

cSound::cSound()
{
	Theme = NULL;
	Swish = NULL;
	Click = NULL;
	Hit = NULL;
}

cSound::~cSound()
{
	delete Theme;
	delete Swish;
	delete Click;
	delete Hit;

	Mix_FreeMusic(Theme);
	Mix_Quit();
}