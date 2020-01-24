#include "crazydriver.h"
#include "pilotos.h"


Crazydriver::Crazydriver(string nome, string tipoPiloto) : Pilotos(nome, tipoPiloto) {
	this->delay = rand() % (5 - 1 + 1) + 1;
}

