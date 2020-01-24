#ifndef GAME_H
#define GAME_H

#include "Consola.h"
#include "Pilotos.h"
#include "dgv.h"
#include "carros.h"
#include "campeonato.h"
#include "world.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;

class Carros;
class Pilotos;
class Dgv;
class World;

class Game {
	//vetor para guardar duplas carros/pilotos
	Dgv* d;
	Pilotos* piloto;
	Carros* carro;
	World* world;
	int aux;
	string cmd;
	string command;
	string nameFile;
	vector<string> arg;
	vector<string> commands;

public:
	Game();
	~Game();

	
	vector<string> split_string_into_vector(string str);
	void startConfig(Dgv* d, World *world);
	bool is_file_exist(string fileName);
	void startChamp(Dgv* d, World* world, Campeonato* campeonato);

};

#endif