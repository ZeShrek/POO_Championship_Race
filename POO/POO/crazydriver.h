#ifndef CRAZYDRIVER_H
#define CRAZYDRIVER_H

#include "pilotos.h"



using namespace std;

class Crazydriver : public Pilotos {
	int delay; //entre 1 e 5, valor aleatorio
	//int currentPos; // se != primeiro ou ultimo acelera

public:
	Crazydriver(string tipo, string nome);

	int getDelay() { return delay; };


};
#endif