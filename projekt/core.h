#pragma once

#define LAP_TIME 30

#include<SDL.h>
#include"Timer.h"
#include"Event.h"
#include"Graph.h"
#include"Sound.h"
#include"Application.h"

class cCore
{
private:

	cTimer* Timer;	
	cEvent* Event; 
	cGraph* Graph; 
	cSound* Sound;
	cApp* Application;

	void Init();			
	void RealTimeLoop();	
	
public:

	cCore();
	~cCore();
	
	void Start();

};
