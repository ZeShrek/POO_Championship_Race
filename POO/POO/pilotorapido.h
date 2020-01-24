#ifndef PILOTORAPIDO_H
#define PILOTORAPIDO_H

#include "pilotos.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Rapido : public Pilotos {
public:
	Rapido(string, string);
	void ToString();
};


#endif