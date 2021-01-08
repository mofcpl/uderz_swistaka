#include "Actor.h"

cActor::cActor()
{
	ActionTime = 0;
	LastTime = 0;
	Orientation = SOUTH;
	Stat = STOP;
	Type = ACTOR;
	MaxSpeed =4 ;
	Speed = 0;
	Agility = 1;
	MoveVec.X = 0;
	MoveVec.Y = 0;
}

cActor::~cActor()
{
	
}

void cActor::Play(cEvent * e)
{

	Pos.X += MoveVec.X;
	Pos.Y += MoveVec.Y;

	if (Speed > 0) Speed -= Agility;


	if (Speed == 0)
	{
		LastTime = 0;
		Stat = STOP;
	}


	MoveVec.X *= 0.9;
	MoveVec.Y *= 0.9;

}

void cActor::Move(eDirection dir)
{


	if (Stat == STOP) LastTime = SDL_GetTicks();

	if(Speed < MaxSpeed) Speed += Agility+1;
	Stat = GO;
	
	Orientation = dir;

	switch (Orientation)
	{
		case NORTH:
		{
			MoveVec.Y = -Speed;
			break;
		}
		case SOUTH:
		{
			MoveVec.Y = Speed;
			break;
		}
		case EAST:
		{
			MoveVec.X = Speed;
			break;
		}
		case WEST:
		{
			MoveVec.X = -Speed;
			break;
		}

	}



}

void cActor::Turn(eDirection dir)
{
	Orientation = dir;
}


