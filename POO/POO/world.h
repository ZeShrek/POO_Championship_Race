#pragma once

#include <vector>
#include "autodromos.h"

using namespace std;

class World {

	vector<Autodromos*> autodromosV; //vetor de autodromos
	vector<Autodromos*> autodromosCampeonato;
	int nAutodromosCamp;
	int nAutodromos;

public:

	World();
	~World();

	void addAutodromo(Autodromos* data) { autodromosV.push_back(data); };
	void SetAutodromo(vector<Autodromos*> autodromosV) { this->autodromosV = autodromosV; };
	vector<Autodromos*> getAutodromo() const { return autodromosV; };

	void addAutodromoC(Autodromos* data) { autodromosCampeonato.push_back(data); };
	void SetAutodromoC(vector<Autodromos*> autodromosCampeonato) { this->autodromosV = autodromosCampeonato; };
	vector<Autodromos*> getAutodromoC() const { return autodromosCampeonato; };

	int getNAutodromosC() { return nAutodromosCamp; }
	void setNAutodromosC(int nAutodromosC) { this->nAutodromosCamp = nAutodromosC; }

	void showAutodromos(World* world);
	void apagaAutodromo(string nome, World* w);

};
