#ifndef DGV_H
#define DGV_H

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "pilotos.h"
#include "carros.h"
#include "pilotorapido.h"
#include "crazydriver.h"


class Dgv {
	
	//vetor de pilotos
	vector<Pilotos*> pilotosV;
	int nPilotos;
	//vetor de carros
	vector<Carros*> carrosV;
	int nCarros;	

public:
	Dgv();

	//pilotos
	vector<Pilotos*> getPiloto() const { return pilotosV; };
	//quando criado
	void addPiloto(Pilotos* data) { pilotosV.push_back(data); };
	void setPiloto(vector<Pilotos*> pilotosV) { this->pilotosV = pilotosV; };
	//quando carregado ficheiro



	//carros
	void addCarro(Carros* data) { carrosV.push_back(data); };
	void setCarro(vector<Carros*> carrosV) { this->carrosV = carrosV; };
	vector<Carros*> getCarro() const { return carrosV; };



	void apagaPiloto(string nome, Dgv *d);
	void apagaCarro(string nome, Dgv* d);

	void showPilotos(Dgv* d);
	void showCarros(Dgv* d);
	void listaCarrosDetalhe(Dgv* d);

	void entraNoCarro(string id, string nome);
	void saiDoCarro(string id);
	void EmparelharRestantes();

	void carregaBateriaCarro(string idCarro, string quantidade);
	void carregaBateriaTodosCarros();

	void atualizaDano(string idCarro);


};


#endif