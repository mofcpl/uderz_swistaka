#pragma once

class cTimer
{
private:
	unsigned __int32 startTime;
	double LapTime;
public:
	

	cTimer();
	~cTimer();

	void start();
	void SetLapTime(double time);
	double getTime();
	double getLaps();

};
