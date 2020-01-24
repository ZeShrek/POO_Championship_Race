#ifndef CARROS_H
#define CARROS_H

#include <string>

using namespace std;

class Pilotos;

class Carros {
	string idCarro; //auto
	string marca; // nao pode ser criado sem marca
	string modelo; // se nao for dito, "modelo base"
	double capacidadeMaxima; //definido inicialmente
	double capacidadeInicial; 
	double velocidadeMaxima; //valor inicialmente definido na criaçao, nunca inferior a 0

	
	Pilotos* piloto;
	string nomeP;
public:
	double velocidadeAtual;
	double quantidadeEnergia; // em mAh, pode ser carregado mas tem de estar parado
	bool parado; // 0 parado | 1 em andamento
	bool acelarador; //aumenta 1ms, apenas se pode primir uma vez por segundo
	bool travao; // diminui 1ms, apenas se pode primir uma vez por segundo
	bool sinalEmergencia;
	bool comPiloto; //0 sem || 1 com -> apenas efetua açoes com piloto, o piloto so pode sair com carro parado
	bool estadoCarro; // false bom || true danificado
	int pX, pY;
	int distanciaPercorrida;

	Carros(double capacidadeInicial, double capacidadeMaxima, string marca, string modelo);
	~Carros();

	string GetMarca() { return marca; }
	void SetMarca(string marca) { this->marca = marca; }

	string GetaModelo() { return modelo; }
	void SetaModelo(string modelo) { this->modelo = modelo; }

	double GetCapacidadeInicial() { return capacidadeInicial; }
	void SetCapacidadeInicial(double capacidadeInicial) { this->capacidadeInicial = capacidadeInicial; }

	double GetCapacidadeMaxima() { return capacidadeMaxima; }
	void SetCapacidadeMaxima(double capacidadeMaxima) { this->capacidadeMaxima = capacidadeMaxima; }

	string GetIdCarro() { return idCarro; }
	void SetId(string idCarro) { this->idCarro = idCarro; }

	bool getSinalEmergencia() { return sinalEmergencia; };
	void setSinalEmergencia(bool sinal) { this->sinalEmergencia = comPiloto; }


	bool getComPiloto() {return comPiloto;};
	void setComPiloto(bool comPiloto) { this->comPiloto = comPiloto; }

	bool getEstadoCarro() { return estadoCarro; };
	void setEstadoCarro(bool estado) { this->estadoCarro = estado; }

	string getNomePiloto() { return nomeP; }
	void setNomePiloto(string nomePiloto) { this->nomeP = nomePiloto; }

	void setEnergia(double quantidadeE);
	double getEnergiaAtual() { return quantidadeEnergia; }

	void setEnergiaTodos();

	int getPY() {return pY;}
	void setPY(int y) { pY = y;}
	int getPX() { return pX; }
	void setPX(int x) { pX = x;}

	int getDistanciaPercorrida() { return distanciaPercorrida; }
	void setDistanciaPercorrida(int dist) { this->distanciaPercorrida = getDistanciaPercorrida() + dist; }

	double getVelocidadeAtual() { return velocidadeAtual; }
	void SetVelocidadeAtual(double velocidadeAtual) { this->velocidadeAtual = velocidadeAtual; }
	
	double getVelocidadeMaxima() { return velocidadeMaxima; }

	void setGastaEnergia(double e);
	
	

	
};

	




#endif