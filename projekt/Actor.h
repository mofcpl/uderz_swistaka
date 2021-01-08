#pragma once

#include"Data.h"

class cActor : public cObject
{
private:
	
	float LastTime;
	int MaxSpeed;
	int Speed;
	int Agility;
	int Experience;
	bool isMove;

	sVec2D MoveVec;

public:

	cActor();
	~cActor();

	void Play(cEvent* e);
	
	void Move(eDirection dir);
	void Turn(eDirection dir);

	int GetLastStep() { return Speed+Agility; }
	int GetActionTime() { return LastTime; }
};

