#pragma once

#include"Data.h"
#include"Actor.h"
#include"Static.h"

/** \class cMechanics
*	\brief Klasa algorytmów
*	\details Ta klasa przechowuje algorytmy
*	\mechaniki œwiata.
*/
class cMechanics
{
private:

public:

	/** \brief Sterowanie
	* \details Funkcja steruje wskazanym
	* \obiektem.
	* \param object cObject* sterowany obiekt
	*/
	void Control(cObject* object, cEvent* e);
	void Control2(cObject* object, cEvent* e);
	void Follow(cObject* objectA, cObject* objectB, cEvent* e);
	void Collisions(cObject* objectlist[], int amount);
	void AddObject(cObject* objectlist[],cObject* object, eObjectType type,int amount);
	void PlayObjects(cObject* objectlist[], cEvent * e, int amount);

};
