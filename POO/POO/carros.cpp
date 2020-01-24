#include "carros.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

vector<char > id = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z'};

string idCar() {
	char iD;

	
	int x = (rand() % 26) + 0;

	
	iD = id[x];
	

	string idC(1, iD);

	return idC;
};

Carros::Carros(double capacidadeInicial, double capacidadeMaxima, string marca, string modelo) {
	this->idCarro = idCar();
	this->marca = marca;
	this->modelo = modelo;
	this->capacidadeInicial = capacidadeInicial;
	this->capacidadeMaxima = capacidadeMaxima;
	this->velocidadeMaxima = (rand() % 15) + 6;
	this->velocidadeAtual = 0;
	this->quantidadeEnergia = capacidadeInicial; // em mAh, pode ser carregado mas tem de estar parado
	this->parado = false; // 0 parado | 1 em andamento
	this->sinalEmergencia = false;
	this->comPiloto = false; //0 sem || 1 com -> apenas efetua açoes com piloto, o piloto so pode sair com carro parado
	this->estadoCarro = 1; // 1 bom || 0 danificado
	this->pX = 0;
	this->pY = 0;



	}

Carros::~Carros() {

};


void Carros::setEnergia(double quantidadeE) {
	if (quantidadeEnergia == capacidadeMaxima) {
		cout << "bateria ja cheia" << endl;
	}
	else {
		double aux = quantidadeEnergia + quantidadeE;
		if (aux > capacidadeMaxima) {
			this->quantidadeEnergia = capacidadeMaxima;
			cout << "Bateria cheia" << endl;
		}
		else {
			this->quantidadeEnergia += quantidadeE;
			cout << "bateria recarregou uma parte" << endl;
		}


	}

}

void Carros::setEnergiaTodos() {

		this-> quantidadeEnergia == capacidadeMaxima;

}


void Carros::setGastaEnergia(double e) {
	this->quantidadeEnergia == quantidadeEnergia - e;
}