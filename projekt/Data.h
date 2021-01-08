
#pragma once
#include<string>
#include"Event.h"

enum eObjectType {STATIC,ACTOR};

struct color
{
	unsigned int red, green, blue;
};

struct sVec2D
{
	int X, Y;
};

enum STATUS { GAME, INTRO, MENU, QUIT };



struct Button
{
	sVec2D lefttop;
	sVec2D rightdown;
	bool backlight;
	std::string surface[2];

};

class cModule
{
public:

	virtual STATUS Run(cEvent* e) = 0;

};

enum eDirection{NORTH,SOUTH,WEST,EAST};
enum eStatus{GO,STOP};

class cObject
{
protected:

	int ActionFrameNumber;
	std::string NorthFrame[3];
	std::string SouthFrame[3];
	std::string EastFrame[3];
	std::string WestFrame[3];
	int ActionTime;

	bool Ground;
	bool Collide;
	int ID;
	std::string Name;
	eDirection Orientation;
	eStatus Stat;
	eObjectType Type;

	sVec2D Pos;
	
	sVec2D CollPos;
	sVec2D CollSize;

	sVec2D GraphPos;
	sVec2D GraphSize;
	
public:
	virtual void Play(cEvent* e) = 0;

	void SetGround(bool gr) { Ground = gr; }
	bool IsGround() { return Ground; }
	
	void SetCollision(bool col) { Collide = col; }
	bool IsCollide() { return Collide; }

	void SetPos(int x, int y) { Pos.X = x; Pos.Y = y; }
	sVec2D GetPos() { return Pos; }

	void SetCollPos(int x, int y) { CollPos.X = x; CollPos.Y = y; }
	sVec2D GetCollPos() 
	{ 
		sVec2D AbsCollPos;
		AbsCollPos.X = Pos.X + CollPos.X;
		AbsCollPos.Y = Pos.Y + CollPos.Y;
		return AbsCollPos;
	}

	void SetCollSize(int x, int y) { CollSize.X = x; CollSize.Y = y; }
	sVec2D GetCollSize() {return CollSize;}

	void SetGraphPos(int x, int y) { GraphPos.X = x; GraphPos.Y = y; }
	sVec2D GetGraphPos() 
	{ 
		sVec2D AbsCollPos;
		AbsCollPos.X = Pos.X + GraphPos.X;
		AbsCollPos.Y = Pos.Y + GraphPos.Y;
		return AbsCollPos; 
	}
	void SetGraphSize(int x, int y) { GraphSize.X = x; GraphSize.Y = y; }
	sVec2D GetGraphSize() { return GraphSize; }

	std::string GetFrame(eDirection dir, int number)
	{
		switch (dir)
		{
		case NORTH:
		{
			return NorthFrame[number];
			break;
		}
		case SOUTH:
		{
			return SouthFrame[number];
			break;
		}
		case EAST:
		{
			return EastFrame[number];
			break;
		}
		case WEST:
		{
			return WestFrame[number];
			break;
		}

		}

	}

	virtual int GetActionTime() = 0;

	int GetActionFrameNumber() { return ActionFrameNumber; }

	eDirection GetDir()
	{
		return Orientation;
	}

	void CopyAnimation(std::string* north, std::string* south, std::string* east, std::string* west, int number)
	{
		for (int i = 0; i < number; i++)
		{
			NorthFrame[i] = north[i];
		}
		for (int i = 0; i < number; i++)
		{
			SouthFrame[i] = south[i];
		}
		for (int i = 0; i < number; i++)
		{
			EastFrame[i] = east[i];
		}
		for (int i = 0; i < number; i++)
		{
			WestFrame[i] = west[i];
		}

		ActionFrameNumber = number;
		
	}

	void CopyAnimation(std::string* north, int number)
	{
		for (int i = 0; i < number; i++)
		{
			NorthFrame[i] = north[i];
		}
		ActionFrameNumber = number;
	}


	eObjectType GetType()
	{
		return Type;
	}



};