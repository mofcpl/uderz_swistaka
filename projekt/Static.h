#pragma once

#include"Data.h"

class cStatic : public cObject
{
private:


public:

	cStatic();

	void Play(cEvent* e) {};

	void Move(eDirection dir) {};

	int GetActionTime() { return 0; }

};