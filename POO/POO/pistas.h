#ifndef PISTAS_H
#define PISTAS_H


#include "pilotos.h"
#include <vector>

class Carros;
class Pilotos;

class Pistas
{
	int comprimentoPista;  //feito
	int maxCarros;
	int nCarrosNaPista;
	bool finish;
	int tempo;
	//int x;
	//int y;

	//double tempoCorrida;

	vector<Carros*> carrosPista; //vetor de carros

	vector<pair<string, int>> ordemChegada;
public:

	Pistas(int comprimentoPista, int maxCarros);
	~Pistas();
	
	int getMaxCarros() { return maxCarros; }; //maximo de carros que pode ter na pista

	void setNCarrosNaPista(int nCarros) { this->nCarrosNaPista = nCarros; };// numero de carros na pista
	int getNCarrosNaPista() { return nCarrosNaPista; };

	double getComprimentoPista() { return comprimentoPista; };

	string getAsString();


	void retirarCarroDaPista(Carros* carro, char idCarro);
	vector<Carros*> getCarros() const { return carrosPista; };
	
	void setCarro(Carros *carro) { carrosPista.push_back(carro); };
	void copyCarV(vector<Carros*> carrosPista) { this->carrosPista = carrosPista; };

	void setTempoCorrida(int i) { this->tempo = this->tempo + i; };// tempo que decorreu
	int getTempoCorrida() { return tempo; };

	//void setLugar(string* piloto) { piloto.push_back(make_pair(piloto, 0); };
	//vector<string*> getLugar() const { return ordemChegada; };


};

#endif
