#include "Game.h"

void cGame::AddParticle(int type, SDL_Point pos,int time)
{
	int i = 0;

	while (Particle[i] != NULL && i < 99)
	{
		i++;
	}
	
	if (i < 99)
	{
		Particle[i] = new cParticle(type, time,pos);
	}

}

void cGame::Reset()
{
	GameStart = SDL_GetTicks();
	EndGame = false;
	Time = 0;
	Points = 0;
}

cGame::cGame()
{


	isButtonDown = true;
	isHit = false;
	isSqueak = false;

	Hammer = new cHammer;

	for (int i = 0; i < 99; i++)
	{
		Particle[i] = NULL;
	}

	SDL_Point point;
	point.x = 176;
	point.y = 600;
	Hamster[0] = new cHamster(point);

	point.x = 494;
	point.y = 600;
	Hamster[1] = new cHamster(point);

	point.x = 808;
	point.y = 600;
	Hamster[2] = new cHamster(point);

	point.x = 321;
	point.y = 386;
	Hamster[3] = new cHamster(point);
	
	point.x = 646;
	point.y = 386;
	Hamster[4] = new cHamster(point);
	
	point.x = 967;
	point.y = 386;
	Hamster[5] = new cHamster(point);

	Reset();

}

cGame::~cGame()
{

}

///////////////////////apdejt 2
STATUS cGame::Run(cEvent * e)
{

		SDL_Point Pos;
		e->ShowMouse(SDL_DISABLE);

		SDL_Point pos;
		e->GetMousePosition(&pos.x, &pos.y); //zapamiêtanie pozycji kursora
		Hammer->SetPos(&pos);


		if (e->CheckMouseButtons(SDL_BUTTON_LEFT) == false)
		{
			isButtonDown = true;
		}

		if (e->CheckMouseButtons(SDL_BUTTON_LEFT) == true && isButtonDown == true)
		{

			Hammer->Hit();
			isHit = true;
			isButtonDown = false;


			Pos.x = pos.x;
			Pos.y = pos.y;

			AddParticle(0, Pos, 1000);
		}

		srand(SDL_GetTicks());
		for (int i = 0; i < 6; i++)
		{

			int r = (rand() % 100) + 0;
			if (r < 2)	Hamster[i]->Lean(750);
		}

		if (Hammer->GetProg() >= 0.9f)
			for (int i = 0; i < 6; i++)
			{
				if (Hamster[i]->GetCover() < 0.4f && Hamster[i]->HitIs() == false)
				{
					SDL_Point point = Hamster[i]->GetPos();

					if ((pos.y > point.y + 20 && pos.y < point.y + 130) && (pos.x > point.x && pos.x < point.x + 130))
					{
						isSqueak = true;
						Hamster[i]->Hit();

						if (EndGame == false)Points++;

						Pos.x = pos.x;
						Pos.y = pos.y;

						AddParticle(1, Pos, 250);
					}
				}
			}

		Hammer->Run();

		for (int i = 0; i < 6; i++)
		{
			Hamster[i]->Run();
		}

		for (int i = 0; i < 99; i++)
		{
			if (Particle[i] != NULL)
			{
				Particle[i]->Run();

				if (Particle[i]->ReturnAge() >= 1.0f)
				{
					delete Particle[i];
					Particle[i] = NULL;
				}
			}
		}

		if (EndGame == false)
		{
			int Actual = SDL_GetTicks();
			Time = 60000 - (Actual - GameStart);
			if (Time <= 0)
			{
				EndGame = true;
				EndStart = SDL_GetTicks();
			}
		}

		if (EndGame == true && (SDL_GetTicks() - EndStart) > 4000)
		{
			return MENU;
		}
	
		if (e->CheckKeyboard(SDL_SCANCODE_ESCAPE)) return MENU;

		return GAME;
}
///////////////////////

cHammer* cGame::ReturnHammer()
{
	return Hammer;
}

cHamster * cGame::ReturnHamster(int i)
{
	return Hamster[i];
}

cParticle * cGame::ReturnParticle(int i)
{
	return Particle[i];
}

int cGame::ReturnTime()
{
	return Time;
}

int cGame::ReturnPoints()
{
	return Points;
}

bool cGame::isGameOn()
{
	return EndGame;
}

bool cGame::Hit()
{
	return isHit;
}

void cGame::HitDone()
{
	isHit = false;
}

bool cGame::Squeak()
{
	return isSqueak;
}

void cGame::SqueakDone()
{
	isSqueak = false;
}

