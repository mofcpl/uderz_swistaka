#pragma once

#include"Data.h"

class cCamera
{
private:

	cObject* FollowObj;
	sVec2D Pos;
	sVec2D Res;

public:

	void FollowObject(cObject* obj);
	void SetCameraRes(int x, int y);
	sVec2D GetPos();
};