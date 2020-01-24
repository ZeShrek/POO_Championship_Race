#include "pilotos.h"



using namespace std;


Pilotos::Pilotos(string tipoPiloto, string nome) {
	this->nome = nome;
	this->tipoPiloto = tipoPiloto;
	this->aConduzir = false;

	cout << "\nPiloto Criado:\n" << "\tNome: " << this->nome << "\n\tTipo: " << this->tipoPiloto << endl;


}

Pilotos::~Pilotos() {

};


string Pilotos::getAsString() {
	return  "\n\t Nome: " + nome + " | Tipo: " + tipoPiloto;
}


void Pilotos::entraNoCarroPiloto(Carros* carro) {
		this->carro = carro;
		carro->setComPiloto(true);
		this->aConduzir = true;
	
}

void Pilotos::saiDoCarroPiloto(Carros* carro) {
	carro->setComPiloto(false);
	this->aConduzir = false;
	this->carro = NULL;

	

}

