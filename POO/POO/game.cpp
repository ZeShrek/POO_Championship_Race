#include "game.h"
#include "campeonato.h"
#include "dgv.h"
#include <Windows.h>
#include "consola.h"



using namespace std;

Game::Game() {}

bool Game::is_file_exist(string nameFile) {
	ifstream in;
	in.open(nameFile);
	if (!in.is_open()) {
		in.close();
		return false;
	}
	in.close();
	return true;
}

vector<string> Game::split_string_into_vector(string str) {
	vector<string> result;
	istringstream ss(str);
	string token;

	while (getline(ss, token, ' ')) {
		result.push_back(token);
	}
	return result;
}

void Game::startChamp(Dgv* d, World* world, Campeonato* campeonato) {

	system("cls"); //mudar depois

	arg = split_string_into_vector(cmd);
	bool over = false;
	bool aDecorrer = false;
	string autodromoCorrida;
	int len;
	int nextRace = 1;

	//vetores campeonato
	vector<Autodromos*> aut = world->getAutodromoC();
	int nAu = 0;


		for (auto autodromo = aut.begin(); autodromo < aut.end(); autodromo++) {
				campeonato->addAutodromoCampeonato((*autodromo));
				nAu++;
			
		}
		campeonato->setNumeroAutodromos(nAu);


		for (auto autodromo = aut.begin(); autodromo < aut.end(); autodromo++) {
			string nome;
			nome = (*autodromo)->GetNomeAutodromo();
			campeonato->setNomeAutodromo((nome));
		}

		
	//campeonato->getAsStringCampeonatoaAutodromos();

	vector<Carros*> car = d->getCarro();
		int nCarros = 0;		
		for (auto carros = car.begin(); carros < car.end(); carros++) {
			if ((*carros)->getComPiloto() == 1 && (*carros)->getEstadoCarro() == true) { //s
				campeonato->setCarrosCameonato((*carros));
				nCarros++;
			}
		}

		vector<Pilotos*> pilot = d->getPiloto();
		int nPilotos = 0;


		for (auto p = pilot.begin(); p < pilot.end(); p++) {
			if (	(*p)->getAConduzir() == true) {
				campeonato->setPilotosCampeonato((*p));
				nPilotos++;
			}
		}


		campeonato->setNumeroAutodromos(world->getNAutodromosC());

		//carros para as garagens
		campeonato->setCarrosGaragem(campeonato);


		int proximaCorrida;

	while (over != true) {
		//variaveis locais pista
		int comprimentoPista;
		string nomeAutodromo;

		//---------
		cout << "Insira um comando: " << endl;
		getline(cin, cmd);
		if (cmd != "") {
			arg = split_string_into_vector(cmd);
			len = arg.size();
			if (arg[0] == "listacarros") {
				d->listaCarrosDetalhe(d);
			}	
			else if (arg[0] == "carregabat") {
				d->carregaBateriaCarro(arg[1], arg[2]);
				
			}
			else if (arg[0] == "carregatudo") {
				d->carregaBateriaTodosCarros();

			}
			else if (arg[0] == "corrida") {
				if (aDecorrer == false) {
			
					cout << "Autodromo: " << campeonato->getAutodromosCampeonato().at(campeonato->getProximaCorrida())->GetNomeAutodromo();

					
					aDecorrer = true;
					nomeAutodromo = campeonato->getAutodromosCampeonato().at(campeonato->getProximaCorrida())->GetNomeAutodromo();
					campeonato->inicioCorrida(nomeAutodromo, campeonato); //arg nome do autodromo
		
					//campeonato->setProximaCorrida();
				}
				else {
					cout << "existe uma corrida a decorrer" << endl;
				}
			}
			else if (arg[0] == "acidente") {
				if (aDecorrer == true) {
					d->atualizaDano(arg[1]);
					
					//tira da pista
					//poe na garagem
					//atualiza dano na garagem
					
					
					}
				//d->acidente(arg[1]);

			}
			else if (arg[0] == "stop") {
				

			}
			else if (arg[0] == "destroi") {

				d->apagaCarro(arg[1], d);
				
				
			}
			else if (arg[0] == "passatempo") { //arg[1] -> tempo que passa em segundos


				if (aDecorrer == true) {
					
						aDecorrer = campeonato->atualizaCorrida(campeonato->getAutodromosCampeonato().at(campeonato->getProximaCorrida())->GetNomeAutodromo(), campeonato, stoi(arg[1]), aDecorrer);
						
						cout << "A decorrer";
						cout << aDecorrer;


				}
				else if (aDecorrer == false) {
					campeonato->setProximaCorrida();
					cout << aDecorrer;
					cout << "acabou";
				}
			
			}
			else if (arg[0] == "log") {

			}
		}
		

	}
}
		

void Game::startConfig(Dgv *d, World* world) {
	int len;
	bool end = false;

	while (end != true) {
		cout << "Insira um comando: " << endl;
		getline(cin, cmd);
		if (cmd != "") {
			arg = split_string_into_vector(cmd);
			len = sizeof(arg) / sizeof(arg[0]);
			if (arg[0] == "carregaP") {
				nameFile = arg[1];
				//piloto->set_namefile(nameFile);
				cout << nameFile << endl;
				cout << "Carrega Pilotos";
			}
			else if(arg[0] == "carregaC") {
				nameFile = arg[1];
				cout << "Carrega Carros" << endl;
				end = true;
			}
			else if (arg[0] == "carregaA") {
				nameFile = arg[1];
				cout << "Carrega Autodromos" << endl;
			}
			else if (arg[0] == "cria") {

				if (arg[1] == "c") {

					cout << "cria carro" << endl;

					d->addCarro(new Carros(stod(arg[2]), stod(arg[3]), arg[4], arg[5]));

				}
				else if (arg[1] == "p") {
					if (arg[2] == "crazy") {
						d->addPiloto(new Crazydriver(arg[2], arg[3] + " " + arg[4]));
					}else if (arg[2] == "rapido") {
						d->addPiloto(new Rapido(arg[2], arg[3] + " " + arg[4]));
					}

						
						cout << arg[2].length() << arg[3].length();
						cout << "Piloto " << arg[3] /*+ " " + arg[4]*/ << " criado com sucesso" << endl;
						
				}
				else if (arg[1] == "a") {
					cout << "cria autodromo" << endl;
					world->addAutodromo(new Autodromos(arg[2], stod(arg[3]), stoi(arg[4])));
				}
				else if (arg[1] != "c" || arg[1] != "p" || arg[1] != "a") {
					LPCWSTR a = L"Comando errado\ncria c <capacidade inicial> <capacidade maxima> <marca> <modelo> para carro\ncria p <tipo> <nome> para piloto\na para autodromo";

					MessageBoxW(NULL, a, NULL, MB_OK);
				}
			

			}
			else if(arg[0] == "entranocarro"){

			//no arg[1] identificador do carro e no arg[2] o identificador do piloto
				d->entraNoCarro(arg[1], arg[2]);

			}
			else if (arg[0] == "saidocarro") {
				cout << 1;
				d->saiDoCarro(arg[1]);
				cout << 2;

			}
			else if (arg[0] == "lista") {
				d->showCarros(d);
				d->showPilotos(d);
				world->showAutodromos(world);
				

			}
			else if (arg[0] == "apaga") {
				if (arg[1] == "p") {
					d->apagaPiloto(arg[2], d);
				} 
				else if (arg[1] == "c") {
					d->apagaCarro(arg[2], d);
				}
				else if (arg[1] == "a") {
					world->apagaAutodromo(arg[2], world);
				} 
			}
			else if (arg[0] == "exit") {
				break;
			}
			else if (arg[0] == "Campeonato" || arg[0] == "campeonato") {

				//emparelhar carros restastes com pilotos
				d->EmparelharRestantes();

				//vetores campeonato
				vector<Autodromos*> aut = world->getAutodromo();
				int nAu = 0;

				for (int i = 1; i < arg.size(); i++) {
					for (auto autodromo = aut.begin(); autodromo < aut.end(); autodromo++) {
						if ((*autodromo)->GetNomeAutodromo() == arg[i]) {
							world->addAutodromoC((*autodromo));
							nAu++;
						}

					}
				}
				world->setNAutodromosC(nAu);

				//campeonato->getAsStringCampeonatoaAutodromos();

				break;
			}

		}
	}
}



