#pragma once

#include"Data.h"
#include"Event.h"
#include"Hammer.h"
#include"Hamster.h"
#include"Particle.h"


class cGame
{
private:

	int Time;
	int GameStart;
	int EndStart;
	int Points;

	cHammer* Hammer;
	cHamster* Hamster[9];
	cParticle* Particle[99];

	bool isButtonDown;
	
	bool isHit;
	bool isSqueak;
	bool EndGame;

	void AddParticle(int type, SDL_Point pos, int time);

public:	

	cGame();
	~cGame();

	STATUS Run(cEvent* e);

	cHammer* ReturnHammer();
	cHamster* ReturnHamster(int i);
	cParticle* ReturnParticle(int i);
	int ReturnTime();
	int ReturnPoints();
	bool isGameOn();

	void Reset();

	bool Hit();
	void HitDone();
	bool Squeak();
	void SqueakDone();

};