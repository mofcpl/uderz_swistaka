#pragma once


#include"Actor.h"
#include"World.h"
#include"Static.h"
#include"Data.h"
#include"Mechanics.h"
#include"Camera.h"

class cWorld
{
private:
	
	cMechanics* WorldMechanics;
	cCamera* Camera;
	
	int NumberOfObjects;
	cObject* ObjectList[100];

public:


	void Run(cEvent* e);
	int ReturnObjectsAmount() { return NumberOfObjects; };
	cObject* ReturnObject(int i) { return ObjectList[i]; };
	cCamera* ReturnCamera() { return Camera; };

	cWorld();
	~cWorld();
	
};
