#include "dgv.h"
#include "pilotos.h"
#include "Consola.h"
#include <fstream>


Dgv::Dgv() {}

void Dgv::apagaPiloto(string nome, Dgv* d) {
	vector<Pilotos*> p = d->getPiloto();
	for (int k = 0; k < (int)p.size(); k++) {
		if (p[k]->GetNome() == nome) {
			p.erase(p.begin() + k);
			d->setPiloto(p);
		}
	}
}


void Dgv::apagaCarro(string nome, Dgv* d) {
	vector<Carros*> p = d->getCarro();
	for (int k = 0; k < (int)p.size(); k++) {
		if (p[k]->GetIdCarro() == nome) {
			p.erase(p.begin() + k);
			d->setCarro(p);
		}
	}
}


void Dgv::showPilotos(Dgv* d) {
	
	vector<Pilotos*> p = d->getPiloto();


	Consola::setTextColor(Consola::AZUL_CLARO);
	cout << "||||||||||||||||--PILOTOS--||||||||||||||||" << endl;
	Consola::setTextColor(Consola::BRANCO);

	for (int j = 0; j < (int)p.size(); ++j) {
		cout << p[j]->getAsString() << endl;
	}
}

void Dgv::showCarros(Dgv* d) {

	vector<Carros*> c = d->getCarro();


	Consola::setTextColor(Consola::AZUL_CLARO);
	cout << "||||||||||||||||--CARROS--||||||||||||||||" << endl;
	Consola::setTextColor(Consola::BRANCO);

	for (int j = 0; j < (int)c.size(); ++j) {
		cout << "Id Carro: "  << c[j]->GetIdCarro() << " | Marca: " << c[j]->GetMarca() << " |  Modelo: " << c[j]->GetaModelo() << " |  Capacidade Inicial: " << c[j]->GetCapacidadeInicial() << " |  Capacidade Maxima: " << c[j]->GetCapacidadeMaxima() << endl;
	}
}


void Dgv::listaCarrosDetalhe(Dgv* d) {
	vector<Carros*> c = d->getCarro();
	for (int j = 0; j < (int)c.size(); ++j) {
		cout << "Id Carro: " << c[j]->GetIdCarro() << " | Marca: " << c[j]->GetMarca() << " |  Modelo: " << c[j]->GetaModelo() << " |  Capacidade Inicial: " << c[j]->GetCapacidadeInicial() << " |  Capacidade Maxima: " << c[j]->GetCapacidadeMaxima() << endl;
	}


}


void Dgv::entraNoCarro(string id, string nome)
{
	bool encontrouPiloto = false;
	bool encontrouCarro = false;


	for (auto piloto = pilotosV.begin(); piloto < pilotosV.end(); piloto++) {
		if ((*piloto)->GetNome() == nome) {
			encontrouPiloto = true;
			if ((*piloto)->getAConduzir() == false) {
				for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
					if ((*carro)->GetIdCarro() == id) {
						encontrouCarro = true;
						if ((*carro)->getComPiloto() == false) {
							(*piloto)->entraNoCarroPiloto(*carro);
							(*carro)->setNomePiloto(nome);
							cout << (*carro)->getNomePiloto() << endl;
							cout << (*carro)->getNomePiloto() << " entrou no carro " << (*carro)->GetIdCarro() << endl;

						}
						else {
							cout << "O carro " << id << " ja tem piloto" << endl;
							break;
						}
					}
				}
			}
			else {
				cout << "O piloto " << nome << " ja se encontra num carro" << endl;
				break;
			}
		}
	}

	if (encontrouPiloto == false) {
		cout << "O piloto " << nome << " nao existe!" << endl;
	}
	else if (encontrouPiloto == true && encontrouCarro == false) {
		cout << "O carro " << id << " nao existe!" << endl;
	}


}

void Dgv::saiDoCarro(string id) {

	bool encontrouCarro = false;


	string nome;

	for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
		if ((*carro)->GetIdCarro() == id) {
			encontrouCarro = true;
			if ((*carro)->getComPiloto() == 1) {
				for (auto piloto = pilotosV.begin(); piloto < pilotosV.end(); piloto++) {
					if ((*piloto)->GetNome() == (*carro)->getNomePiloto()) {
						(*piloto)->saiDoCarroPiloto(*carro);
						(*carro)->setNomePiloto("");
						cout << (*piloto)->GetNome() << " saiu do carro " << id << endl;
					}
				}
			}
			else if ((*carro)->getComPiloto() == 0) {
				cout << "Este carro não tem piloto" << endl;
			}


		}
	}
}

void Dgv::EmparelharRestantes() {


	for (auto piloto = pilotosV.begin(); piloto < pilotosV.end(); piloto++) {
		if ((*piloto)->getAConduzir() == false) {
			for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
				if ((*carro)->getComPiloto() == false && (*piloto)->getAConduzir() == false) {
					(*piloto)->entraNoCarroPiloto(*carro);
					(*carro)->setNomePiloto((*piloto)->GetNome());
					cout << (*carro)->getNomePiloto() << endl;
					cout << (*piloto)->GetNome() << " entrou no carro " << (*carro)->GetIdCarro() << endl;

				}
			}
		}
	}

}

void Dgv::carregaBateriaCarro(string idCarro, string quantidade) {

	for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
		if ((*carro)->GetIdCarro() == idCarro) {
			(*carro)->setEnergia(stod(quantidade));
			cout << (*carro)->getEnergiaAtual();
			//setEnergiaTodos()
		}
	}
}

void Dgv::carregaBateriaTodosCarros() {

	for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
			(*carro)->setEnergiaTodos();
			cout << (*carro)->getEnergiaAtual();
		}
	}


void Dgv::atualizaDano(string idCarro) {
	for (auto carro = carrosV.begin(); carro < carrosV.end(); carro++) {
		if (idCarro == (*carro)->GetIdCarro()) {
			(*carro)->setEstadoCarro(true);
			for (auto piloto = pilotosV.begin(); piloto < pilotosV.end(); piloto++) {
				if ((*piloto)->GetNome() == (*carro)->getNomePiloto()) {
					cout << "O piloto morreu na sequencia do acidente" << endl;
					(*piloto)->saiDoCarroPiloto(*carro);
					(*piloto)->setVida(false);
					(*carro)->setNomePiloto("");
				}
			}
		}
	}
}
