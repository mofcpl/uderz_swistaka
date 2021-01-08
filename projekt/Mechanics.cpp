#include"Mechanics.h"
#include<math.h>

void cMechanics::Control(cObject * object, cEvent * e)
{
	cActor* actor = dynamic_cast<cActor*>(object);

	do
	{
		if (e->CheckKeyboard(SDL_SCANCODE_W))
		{
			actor->Move(NORTH);
			break;
		}
		if (e->CheckKeyboard(SDL_SCANCODE_S))
		{
			actor->Move(SOUTH);
			break;
		}
	if (e->CheckKeyboard(SDL_SCANCODE_A))
		{
			actor->Move(WEST);
			break;
		}
		if (e->CheckKeyboard(SDL_SCANCODE_D))
		{
			actor->Move(EAST);
			break;
		}
	} while (false);
}


void cMechanics::Follow(cObject* objectA, cObject* objectB, cEvent* e)
{
	int Ax = objectA->GetPos().X;
	int Ay = objectA->GetPos().Y;
	int Bx = objectB->GetPos().X;
	int By = objectB->GetPos().Y;

	int Dx = Ax - Bx;
	int Dy = Ay - By;

	int Length = sqrt(pow(Dx, 2) + pow(Dy, 2));

	cActor* actor = dynamic_cast<cActor*>(objectA);

	

		if (abs(Dx) > abs(Dy))
		{

			if (Dx >= 0)
			{
				actor->Turn(WEST);
				if (Length > 100) actor->Move(WEST);
			}
			if (Dx < 0)
			{
				actor->Turn(EAST);
				if (Length > 100) actor->Move(EAST);
			}

		}
		if (abs(Dx) < abs(Dy))
		{
			if (Dy >= 0)
			{
				actor->Turn(NORTH);
				if (Length > 100) actor->Move(NORTH);
			}
			if (Dy < 0)
			{
				actor->Turn(SOUTH);
				if (Length > 100) actor->Move(SOUTH);
			}
		}



}

void cMechanics::Collisions(cObject * objectlist[], int amount)
{
	
	
	for (int i = 0; i < amount; i++)
	{
		if (objectlist[i]->GetType()!=STATIC)
		for (int j = i+1; j < amount; j++)
		{
			if (j == i)continue;

			if (objectlist[i]->IsCollide() == false || objectlist[j]->IsCollide() == false) continue;

			int AposX = objectlist[i]->GetCollPos().X;
			int AposY = objectlist[i]->GetCollPos().Y;

			int BposX = objectlist[j]->GetCollPos().X;
			int BposY = objectlist[j]->GetCollPos().Y;

			double AWidth = objectlist[i]->GetCollSize().X;
			double AHeight = objectlist[i]->GetCollSize().Y;

			double BWidth = objectlist[j]->GetCollSize().X;
			double BHeight = objectlist[j]->GetCollSize().Y;
			
			if ((AposX >= BposX && AposX <= BposX + BWidth || AposX + AWidth >= BposX && AposX + AWidth <= BposX + BWidth) &&
				(AposY >= BposY && AposY <= BposY + BHeight || AposY + AHeight >= BposY && AposY + AHeight <= BposY + BHeight))
			{
								
				int Ax = objectlist[i]->GetPos().X;
				int Ay = objectlist[i]->GetPos().Y;
				int Bx = objectlist[j]->GetPos().X;
				int By = objectlist[j]->GetPos().Y;

				double Dx = Ax - Bx;
				double Dy = Ay - By;

				double Length = sqrt(pow(Dx, 2) + pow(Dy, 2));

				cActor* wskA = dynamic_cast<cActor*>(objectlist[i]);
				
				if (objectlist[j]->GetType() == STATIC)
				{

					Dx = (Dx / Length)*6;
					Dy = (Dy / Length)*6;

					objectlist[i]->SetPos(Ax + Dx, Ay + Dy);
					continue;
				}
				
				Dx = (Dx / Length)*2.5;
				Dy = (Dy / Length)*2.5;

				objectlist[i]->SetPos(Ax + Dx, Ay + Dy);
				objectlist[j]->SetPos(Bx - Dx, By - Dy);



			}

		}
	}

}




void cMechanics::AddObject(cObject* objectlist[], cObject* object,eObjectType type, int amount)
{
	
	objectlist[amount] = object;
	
}

void cMechanics::PlayObjects(cObject * objectlist[], cEvent * e, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		objectlist[i]->Play(e);
	}
}
