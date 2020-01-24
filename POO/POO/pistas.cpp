#include "pistas.h"

Pistas::Pistas(int comprimentoPista, int maxCarros)
{
	this->comprimentoPista = comprimentoPista;
	this->maxCarros = maxCarros;
	this->finish = false;
}

string Pistas::getAsString()
{
	return  "Comprimento : " + to_string(comprimentoPista) + " | Capacidade : " + to_string(maxCarros) + "\n";
}


void Pistas::retirarCarroDaPista(Carros* carro, char idCarro) {
	
	for (auto car = carrosPista.begin(); car < carrosPista.end(); car++) {
	
	}

}