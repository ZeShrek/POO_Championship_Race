#ifndef AUTODROMOS_H
#define AUTODROMOS_H


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

#include "pistas.h"
#include "Consola.h"



using namespace std;

class Pistas;
class Garagens;
class Campeonato;
class Carros;
class Autodromos
{
	string nomeAutodromo;

	Pistas* pista; //pista
	
	vector<Carros*> garagem;  //garagem dos carros

public:
	Autodromos(string nomeAutodromo, int comprimentoPista, int maxCarros);
	~Autodromos();

	string GetNomeAutodromo() { return nomeAutodromo; }
	void SetNomeAutodromo(string nomeAutodromo) { this->nomeAutodromo = nomeAutodromo; }

	void setCarroGaragem(vector<Carros*> carrosG) { this->garagem = carrosG; };
	vector<Carros*> getCarroGaragem() const { return garagem; };

	void preparaPista(Pistas* data);
	void moveCarrosCrazy(Pistas* data, int y, int delay, string idCarro);
	void moveCarrosRapido(Pistas* data, int y, string idCarro);
	void mostraPista(Pistas* data, int tempo);
	


	string getAsString() const;
	int getCapPista() const;
	Pistas* getPista();
	void setPista(Pistas* data);

};

#endif
