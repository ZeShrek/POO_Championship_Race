#ifndef PILOTOS_H
#define PILOTOS_H


#include <string>
#include <iostream>

#include "carros.h"
#include "pistas.h"

using namespace std;



class Pilotos {
	string nome; //quando é feito, nunca muda e é UNICO, programa verifica automaticamente e adapta
	string tipoPiloto;
	int pos = 0; //0 sem correr // 1-N posição // -1 destruido
	bool aConduzir; //false nao esta a conduzir, true esta a conduzir
	bool vida = true; //true vivo false morto
	int delay;

	Carros* carro;

public:
	Pilotos(string nome, string tipoPiloto);
	~Pilotos();

	string GetNome() { return nome; }
	void SetNome(string nome) { this->nome = nome; }

	string GetTipoPiloto() { return tipoPiloto; }
	void SetTipoPiloto(string tipoPiloto) { this->tipoPiloto = tipoPiloto; }

	bool getAConduzir() { return aConduzir; };
	void setAConduzir(bool aConduzir) { this->aConduzir = aConduzir; }

	bool getVida() { return vida; };
	void setVida(bool estadoVida) { this->vida = estadoVida; }

	virtual string getAsString();

	void entraNoCarroPiloto(Carros* carro);
	void saiDoCarroPiloto(Carros* carro);
	void apagaCarroDoPiloto(); //tira

	virtual int getDelay() { return delay; };






	
};



#endif