#include "campeonato.h"
#include "Consola.h"
#include "autodromos.h"

Campeonato::Campeonato() {};

Campeonato::~Campeonato() {};

void Campeonato::getAsStringCampeonatoaAutodromos() {

	vector<Autodromos*> p = autodromosCampeonato;


	for (int j = 0; j < (int)p.size(); ++j) {
		cout << p[j]->getAsString() << endl;
	}

}

void Campeonato::setCarrosGaragem(Campeonato* camp) {
	for (auto autodromo = autodromosCampeonato.begin(); autodromo < autodromosCampeonato.end(); autodromo++) {
		(*autodromo)->setCarroGaragem(camp->carrosDisponiveis);
	}

}


void Campeonato::inicioCorrida(string nomeAutodromo, Campeonato* camp) {

	
	int n = 0;
	Pistas* pistaAux;
	
	vector<Autodromos*> auxA = camp->getAutodromosCampeonato();

	for (auto autodromo = auxA.begin(); autodromo < auxA.end(); autodromo++) {

		if ((*autodromo)->GetNomeAutodromo() == nomeAutodromo) {

			pistaAux = (*autodromo)->getPista();

		
			vector<Carros*> car = (*autodromo)->getCarroGaragem();

				for (auto carro = car.begin(); carro < car.end(); carro++) {

					if (n < pistaAux->getMaxCarros()) {
						(*carro)->SetVelocidadeAtual(1);
						(*carro)->setPY(n);
						pistaAux->setCarro((*carro));

						n++;
					}

				}
			

				(*autodromo)->setPista(pistaAux);
				pistaAux->setNCarrosNaPista(n);
				(*autodromo)->preparaPista((*autodromo)->getPista());
			

			
		}

	}
	camp->setAutodromoCampeonato(auxA);

}


bool Campeonato::atualizaCorrida(string nomeAutodromo, Campeonato* camp, int tempo, bool aDecorrer) {
	int ncar = 0;
	int n = 0;
	Pistas* pistaAux;
	string nomePiloto;

	vector<Autodromos*> auxA = camp->getAutodromosCampeonato();

	for (auto autodromo = auxA.begin(); autodromo < auxA.end(); autodromo++) {

		if ((*autodromo)->GetNomeAutodromo() == nomeAutodromo) {
			pistaAux = (*autodromo)->getPista();
			vector<Carros*> carrosP = pistaAux->getCarros();
			n = carrosP.size();
			//carro a carro da pista
			for (auto car = carrosP.begin(); car < carrosP.end(); car++) {
				if ((*car)->getDistanciaPercorrida() < pistaAux->getComprimentoPista()) { //verifica distancia percorrida
					ncar++;
					nomePiloto = (*car)->getNomePiloto();
					vector<Pilotos*> pil = camp->getPilotosCampeonato();
					for (auto p = pil.begin(); p < pil.end(); p++) {
						if (nomePiloto == (*p)->GetNome() && (*p)->GetTipoPiloto() == "crazy") {
							int atraso = (*p)->getDelay();
							string idCarro = (*car)->GetIdCarro();
							(*autodromo)->moveCarrosCrazy(pistaAux, tempo, atraso, idCarro);
							
						}
						if (nomePiloto == (*p)->GetNome() && (*p)->GetTipoPiloto() == "rapido") {
							int atraso = (*p)->getDelay();
							string idCarro = (*car)->GetIdCarro();
							(*autodromo)->moveCarrosRapido(pistaAux, tempo, idCarro);

						}
						
					}
					
					//-----------update dist percorrida
					pistaAux->setTempoCorrida(tempo);
					
				
				}
				else {
					aDecorrer = false;
				}
			
			
			}

			(*autodromo)->setPista(pistaAux);
			(*autodromo)->mostraPista(pistaAux, tempo);

		}

	}

	/*if (n = ncar) {
		aDecorrer = true;
		cout << "Ainda nao acabou";
	}
	else if (ncar > n) {
		aDecorrer = false;
		cout << "ja acabou";

	}*/

	return aDecorrer;

}


