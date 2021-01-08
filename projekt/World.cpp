#include "World.h"


void cWorld::Run(cEvent * e)
{
	WorldMechanics->Control(ObjectList[1], e);
	WorldMechanics->Follow(ObjectList[4], ObjectList[1], e);
	WorldMechanics->PlayObjects(ObjectList, e, NumberOfObjects);
	WorldMechanics->Collisions(ObjectList, NumberOfObjects);
}

cWorld::cWorld()
{
	
	WorldMechanics = new cMechanics;
	NumberOfObjects = 0;
	std::string animationW[3];
	std::string animationE[3];
	std::string animationS[3];
	std::string animationN[3];
	
	cObject* trawa = new cStatic;
	animationN[0] = "grass";
	trawa->SetPos(640, 360);
	trawa->SetGraphPos(-640, -360);
	trawa->SetGraphSize(1280, 720);
	trawa->SetGround(true);
	trawa->CopyAnimation(animationN, 1);
	trawa->SetCollision(false);
	WorldMechanics->AddObject(ObjectList, trawa, STATIC, NumberOfObjects);
	NumberOfObjects++;

	cObject* bohater = new cActor ;
	animationE[0] = "east";
	animationE[1] = "east1";
	animationE[2] = "east2";
	animationW[0] = "west";
	animationW[1] = "west1";
	animationW[2] = "west2";
	animationN[0] = "north";
	animationN[1] = "north1";
	animationN[2] = "north2";
	animationS[0] = "south";
	animationS[1] = "south1";
	animationS[2] = "south2";
	bohater->SetPos(300, 350);
	bohater->SetCollPos(-25, -11);
	bohater->SetCollSize(49, 19);
	bohater->SetGraphPos(-26, -74);
	bohater->SetGraphSize(52, 81);
	bohater->CopyAnimation(animationN, animationS, animationE, animationW, 3);
	bohater->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, bohater, ACTOR, NumberOfObjects);
	NumberOfObjects++;

	cObject* bohater1 = new cActor;
	bohater1->SetPos(400, 350);
	bohater1->SetCollPos(-25, -11);
	bohater1->SetCollSize(49, 19);
	bohater1->SetGraphPos(-26, -74);
	bohater1->SetGraphSize(52, 81);
	bohater1->CopyAnimation(animationN, animationS, animationE, animationW, 3);
	bohater1->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, bohater1, ACTOR, NumberOfObjects);
	NumberOfObjects++;
	
	cObject* bohater2 = new cActor;
	bohater2->SetPos(400, 360);
	bohater2->SetCollPos(-25, -11);
	bohater2->SetCollSize(49, 19);
	bohater2->SetGraphPos(-26, -74);
	bohater2->SetGraphSize(52, 81);
	bohater2->CopyAnimation(animationN, animationS, animationE, animationW, 3);
	bohater2->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, bohater2, ACTOR, NumberOfObjects);
	NumberOfObjects++;

	cObject* bohater3 = new cActor;
	bohater3->SetPos(410, 350);
	bohater3->SetCollPos(-25, -11);
	bohater3->SetCollSize(49, 19);
	bohater3->SetGraphPos(-26, -74);
	bohater3->SetGraphSize(52, 81);
	bohater3->CopyAnimation(animationN, animationS, animationE, animationW, 3);
	bohater3->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, bohater3, ACTOR, NumberOfObjects);
	NumberOfObjects++;

	cObject* drzewo1 = new cStatic;
	animationN[0] = "tree";
	drzewo1->CopyAnimation(animationN, 1);
	drzewo1->SetPos(300, 300);
	drzewo1->SetCollPos(-52, -5);
	drzewo1->SetCollSize(100, 38);
	drzewo1->SetGraphPos(-115, -198);
	drzewo1->SetGraphSize(240, 237);
	drzewo1->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, drzewo1, STATIC, NumberOfObjects);
	NumberOfObjects++;

	cObject* drzewo2 = new cStatic;
	animationN[0] = "tree";
	drzewo2->CopyAnimation(animationN, 1);
	drzewo2->SetPos(550, 350);
	drzewo2->SetCollPos(-52, -5);
	drzewo2->SetCollSize(100, 38);
	drzewo2->SetGraphPos(-115, -198);
	drzewo2->SetGraphSize(240, 237);
	drzewo2->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, drzewo2, STATIC, NumberOfObjects);
	NumberOfObjects++;

	cObject* drzewo3= new cStatic;
	animationN[0] = "tree";
	drzewo3->CopyAnimation(animationN, 1);
	drzewo3->SetPos(200, 400);
	drzewo3->SetCollPos(-52, -5);
	drzewo3->SetCollSize(100, 38);
	drzewo3->SetGraphPos(-115, -198);
	drzewo3->SetGraphSize(240, 237);
	drzewo3->SetCollision(true);
	WorldMechanics->AddObject(ObjectList, drzewo3, STATIC, NumberOfObjects);
	NumberOfObjects++;

	Camera = new cCamera;
	Camera->FollowObject(bohater);
	Camera->SetCameraRes(640, 360);
}

cWorld::~cWorld()
{
	for (int i = 0; i < 100; i++)
	{
		if (ObjectList[i] != NULL) delete ObjectList[i];
	}

	delete Camera;
	delete WorldMechanics;
}
