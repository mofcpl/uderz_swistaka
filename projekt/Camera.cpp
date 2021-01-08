#include"Camera.h"

void cCamera::FollowObject(cObject * obj)
{
	FollowObj = obj;
}

sVec2D cCamera::GetPos()
{
	sVec2D pos;
	pos.X = FollowObj->GetPos().X - (Res.X / 2) ;
	pos.Y = FollowObj->GetPos().Y - (Res.Y / 2) ;

	return pos;
}

void cCamera::SetCameraRes(int x, int y)
{
	Res.X = x;
	Res.Y = y;
}
