#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include "autodromos.h"
#include "dgv.h"
#include <vector>


using namespace std;

class Autodromos;
class Pilotos;
class carros;


class Campeonato {
	vector<Autodromos*> autodromosCampeonato;
	vector<Carros*> carrosDisponiveis;
	vector<Pilotos*> pilotosDisponiveis;
	vector<pair<Pilotos*, int>> classificacao;
	vector<string> nomeAutodromo;
	int nAutodromos;
	int capacidadePista;
	bool corridaDecorrer; //0 nao / 1 sim
	int nCarrosDiponiveis;
	int proximaCorrida = 0;
	
public:

	Campeonato();
	~Campeonato();


	vector<Autodromos*> getAutodromosCampeonato() { return autodromosCampeonato; };
	void addAutodromoCampeonato(Autodromos* data) {autodromosCampeonato.push_back(data); this->nAutodromos++;};
	void setAutodromoCampeonato(vector<Autodromos*> autodromosCampeonato) { this->autodromosCampeonato = autodromosCampeonato; };


	void getAsStringCampeonatoaAutodromos();

	vector<Carros*> getCarrosCampeonato() { return carrosDisponiveis; };
	void setCarrosCameonato(Carros* data) { carrosDisponiveis.push_back(data); };
	
	vector<Pilotos*> getPilotosCampeonato() { return pilotosDisponiveis; };
	void setPilotosCampeonato(Pilotos* data) { pilotosDisponiveis.push_back(data); };

	vector<string> getNomeAutodromo() { return nomeAutodromo; };
	void setNomeAutodromo(string data) { nomeAutodromo.push_back(data); };

	bool getCorridaDecorrer() { return corridaDecorrer; };
	void setCorridaDecorrer(bool corridaEstado) { this->corridaDecorrer = corridaEstado; }

	int getNumeroAutodromos() { return nAutodromos; }
	void setNumeroAutodromos(int i) { this->nAutodromos = i; };

	int getCapacidadePista() { return capacidadePista; }
	void setCapacidadePista(int i) { this->capacidadePista = i; };

	int getProximaCorrida() { return proximaCorrida; }
	void setProximaCorrida() { this->proximaCorrida++; };

	void setCarrosGaragem(Campeonato* camp);

	void inicioCorrida(string nomeAutodromo, Campeonato* camp);
	bool atualizaCorrida(string nomeAutodromo, Campeonato* camp, int i, bool aDecorrer);

};


#endif