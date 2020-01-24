#include "world.h"
#include "Consola.h"
#include "autodromos.h"

World::World() {};

World::~World() {};


void World::apagaAutodromo(string nome, World* w) {
	vector<Autodromos*> p = w->getAutodromo();
	for (int k = 0; k < (int)p.size(); k++) {
		if (p[k]->GetNomeAutodromo() == nome) {
			p.erase(p.begin() + k);
			w->SetAutodromo(p);
		}
	}
}



void World::showAutodromos(World* world) {

	vector<Autodromos*> autodromoLista = world->getAutodromo();


	Consola::setTextColor(Consola::AZUL_CLARO);
	cout << "||||||||||||||||--Autodromos--||||||||||||||||" << endl;
	Consola::setTextColor(Consola::BRANCO);

	for (int j = 0; j < (int)autodromoLista.size(); ++j) {
		cout << autodromoLista[j]->getAsString() << endl;
	}
}