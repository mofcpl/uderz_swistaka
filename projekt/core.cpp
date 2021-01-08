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
	

	// 1.Sta�okrokowa p�tla czasu rzeczywistego. warunek sprawdza zmienn� "wyj�cie" je�li jest warto�ci true p�tla nie jest wykonywana
	while (!wyjscie)
	{

		//Ten warunek sprawdz czy zosta� naci�ni�ty krzy�yk na okienku je�li tak zieminnia zmienn� "wyjscie" na true
		if (Event->CheckEvent(SDL_QUIT))
		{
			wyjscie = true;
			continue; //ta instrukcja zaczyna od razu p�tla od nowa, czyli od sprawdzenia warunku. Chodzi o to �e w tym miejscu wiadomo �e p�tla powinna si� sko�czy� wi�c
		}				//nie ma sensu wykonywa� dalszych instrukcji z niej.


		//2.Tu jest pobranie stanu wej�� czyli myszki i klawiatury
		Event->UpdateEvents(); 
		sVec2D Mouse;
		Event->GetMousePosition(&Mouse.X, &Mouse.Y); 

		//3. Logika i mechanika.
		while (Timer->getLaps() >= 1)
		{
			//Ca�e obliczanie mechaniki i logiki w p�tli sprowadza si� do wywo�ania metody Run obiektu Application(App).
			if(!Application->Run(Event)) wyjscie=true;		
		}
		
		//4.Generowanie grafiki
		Graph->DrawApplication();
		Sound->PlaySound(Application);
		Sound->PlayMusic(Application);

		//SDL_Delay(5);
		
		//Oddanie czasu procesora. Co by proces mia� co� dla siebie.
		
	}

}