#include"core.h"

cCore::cCore()
{
	Timer = new cTimer;
	Event = new cEvent;
	Graph = new cGraph;
	Sound = new cSound;
	Application = new cApp;
}

cCore::~cCore()
{
	delete Application;
	delete Graph;
	delete Event;
	delete Sound;
	delete Timer;	
}

void cCore::Start()
{
	Init();
	RealTimeLoop();
}

void cCore::Init()
{
	Graph->InitGraph(Application); 
	Event->Init(Graph->WinHandle(), 1280, 960);
	Timer->SetLapTime(LAP_TIME);
	Timer->start();
	Sound->Init();
}

void cCore::RealTimeLoop()
{

	bool wyjscie = false;
	

	// 1.Sta³okrokowa pêtla czasu rzeczywistego. warunek sprawdza zmienn¹ "wyjœcie" jeœli jest wartoœci true pêtla nie jest wykonywana
	while (!wyjscie)
	{

		//Ten warunek sprawdz czy zosta³ naciœniêty krzy¿yk na okienku jeœli tak zieminnia zmienn¹ "wyjscie" na true
		if (Event->CheckEvent(SDL_QUIT))
		{
			wyjscie = true;
			continue; //ta instrukcja zaczyna od razu pêtla od nowa, czyli od sprawdzenia warunku. Chodzi o to ¿e w tym miejscu wiadomo ¿e pêtla powinna siê skoñczyæ wiêc
		}				//nie ma sensu wykonywaæ dalszych instrukcji z niej.


		//2.Tu jest pobranie stanu wejœæ czyli myszki i klawiatury
		Event->UpdateEvents(); 
		sVec2D Mouse;
		Event->GetMousePosition(&Mouse.X, &Mouse.Y); 

		//3. Logika i mechanika.
		while (Timer->getLaps() >= 1)
		{
			//Ca³e obliczanie mechaniki i logiki w pêtli sprowadza siê do wywo³ania metody Run obiektu Application(App).
			if(!Application->Run(Event)) wyjscie=true;		
		}
		
		//4.Generowanie grafiki
		Graph->DrawApplication();
		Sound->PlaySound(Application);
		Sound->PlayMusic(Application);

		//SDL_Delay(5);
		
		//Oddanie czasu procesora. Co by proces mia³ coœ dla siebie.
		
	}

}