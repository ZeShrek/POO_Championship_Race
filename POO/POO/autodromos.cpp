#include "autodromos.h"


Autodromos::Autodromos(string nomeAutodromo, int comprimentoPista, int maxCarros)
{
	this->nomeAutodromo = nomeAutodromo;
	this->pista = new Pistas(comprimentoPista, maxCarros);

	cout << "\nAutodromo Criado:\n\tNome: " << nomeAutodromo << "\n\tCapacidade: " << pista->getComprimentoPista() << "\n\tTamanho Pista: " << pista->getMaxCarros() << endl;
}

string Autodromos::getAsString() const {
	return "\n\t Nome: " + nomeAutodromo + " | " + pista->getAsString();
}


int Autodromos::getCapPista() const { return pista->getMaxCarros(); }

Pistas* Autodromos::getPista()
{
	return pista;
}

void Autodromos::setPista(Pistas* data)
{
	this->pista = data;
}

void Autodromos::preparaPista(Pistas* data) {
	
	int xLinha = 50;
	int yLinha = 8;
	int numeroPista = 1;

	vector<Carros*> carrosP = data->getCarros();
	
	Consola::gotoxy(40, 8);
	cout << "Pista " << numeroPista << " :";
	Consola::gotoxy(50, 6);
	cout << "|-Partida-|";
	int comp = data->getComprimentoPista();
	Consola::gotoxy(comp + 50, 15);
	cout << "|-Chegada-|";

	for (auto car = carrosP.begin(); car < carrosP.end(); car++) {
		(*car)->setPX(xLinha);
		//(*car)->setPY(yLinha);
		
		Consola::gotoxy((*car)->getPX(), yLinha);
		cout << ((*car)->GetIdCarro()) << endl;
		Consola::gotoxy(pista->getComprimentoPista() + 50, yLinha);
		cout << "||";

		Consola::gotoxy(40, 15 + numeroPista);
		cout << "Nome Piloto: " + (*car)->getNomePiloto() + " Id Carro: " + (*car)->GetIdCarro() + " Distancia Percorrida: " + to_string((*car)->getDistanciaPercorrida()) + " metros";

		yLinha++;
		numeroPista++;

	}
	data->copyCarV(carrosP);
	this->pista = data;
	//Consola::gotoxy(0, 5);
}


void Autodromos::moveCarrosCrazy(Pistas* data, int tempo, int delay, string idCarro) { //atualizaDados(pistaAux, tempo, camp)
	//int probAcao; //1 acelera 2 matem 3 trava
	int metros;

		vector<Carros*> carrosP = data->getCarros();

		for (auto car = carrosP.begin(); car < carrosP.end(); car++) {
			if ((*car)->GetIdCarro() == idCarro) {
			
				while (tempo > 0) {
					
					if (delay == 0) {
						 if ((*car)->getDistanciaPercorrida() < data->getComprimentoPista()) {

							//ver posiçao etc

							 //Consola::gotoxy((*car)->getPX(), 8);
							 //cout << " "; //tira os anterior

							(*car)->setPX((*car)->getPX() + int((*car)->getVelocidadeAtual()));
							//(*car)->setPY(yLinha);


							metros = int((*car)->getVelocidadeAtual());
							(*car)->setDistanciaPercorrida(metros);
							//system("pause");
						}
					}
					else if (delay != 0) {
						delay--;
						break;
					}

					tempo--;
				}

				

			}
			

		}

	

	data->copyCarV(carrosP);
	this->pista = data;

}

void Autodromos::moveCarrosRapido(Pistas* data, int tempo, string idCarro) {
	int metros;
	int rapidoEme = 0;
	vector<Carros*> carrosP = data->getCarros();

	for (auto car = carrosP.begin(); car < carrosP.end(); car++) {
		if ((*car)->GetIdCarro() == idCarro) {

			while (tempo > 0) {
				rapidoEme++;
				if (rapidoEme == 10) {
					int prob = rand() % (10 - 1 + 1) + 1;
					if (prob != 1) {

						if ((*car)->getDistanciaPercorrida() < data->getComprimentoPista() && (*car)->getEnergiaAtual() > ((*car)->GetCapacidadeMaxima() / 2)) {

							if ((*car)->getVelocidadeMaxima() < (*car)->getVelocidadeAtual()) {

								(*car)->SetVelocidadeAtual((*car)->getVelocidadeAtual() + 1);
								(*car)->setGastaEnergia(0.1);

								Consola::gotoxy((*car)->getPX(), 8);
								cout << " "; //tira os anterior

								(*car)->setPX((*car)->getPX() + int((*car)->getVelocidadeAtual()));
								//(*car)->setPY(yLinha);


								metros = int((*car)->getVelocidadeAtual());
								(*car)->setDistanciaPercorrida(metros);
								//system("pause");

							}
						}
						else if ((*car)->getEnergiaAtual() < ((*car)->GetCapacidadeMaxima() / 2)) {
							int timer = 1;
							if (timer == 3) {
								(*car)->SetVelocidadeAtual((*car)->getVelocidadeAtual() + 1);
								(*car)->setGastaEnergia(0.1);

								(*car)->setPX((*car)->getPX() + int((*car)->getVelocidadeAtual()));

								metros = int((*car)->getVelocidadeAtual());
								(*car)->setDistanciaPercorrida(metros);

								timer = 0;
							}
							else {
								timer++;
							}

						}

					}
					else {
						(*car)->setSinalEmergencia(true);
					
					}
				}

				
					
				tempo--;
			
			}


				

		}


	}



	data->copyCarV(carrosP);
	this->pista = data;
}

void Autodromos::mostraPista(Pistas* data, int tempo) {
	system("cls");
	//int probAcao; //1 acelera 2 matem 3 trava
	int xLinha = 50;
	int yLinha = 1;
	int numeroPista = 1;
	int metros;
	int drop = 8;

	//y é o tempo que vai passar, entao tem de ser y * velocidade atual


	vector<Carros*> carrosP = data->getCarros();
	Consola::gotoxy(40, 8);
	cout << "Pista " << numeroPista << " :";
	Consola::gotoxy(50, 6);
	cout << "|-Partida-|";
	Consola::gotoxy(pista->getComprimentoPista() + 50, 6);
	cout << "|-Chegada-|";

		
		for (auto car = carrosP.begin(); car < carrosP.end(); car++) {
			Consola::gotoxy((*car)->getPX(), drop);
			cout << ((*car)->GetIdCarro()) << endl;
			Consola::gotoxy(40, 15 + yLinha);
			cout << "Nome Piloto: " + (*car)->getNomePiloto() + " Id Carro: " + (*car)->GetIdCarro() + " Distancia Percorrida" + to_string((*car)->getDistanciaPercorrida()) + " metros";

			yLinha++;
			numeroPista++;
			drop++;


		}
			//ver tipo
	//system("pause");

			

		

	

	Consola::gotoxy(0, 5);
}