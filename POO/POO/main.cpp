//2 modos
//modo 1: 
	//Define o que existe, carros,... com todas as caracteristicas, seja, configura��es
//modo 2:
	//Simula��o de campeonato
	//escolhe autodromos e ordena
	// manter pontua��o



#include <windows.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "main.h"
#include "pilotos.h"
#include "crazydriver.h"
#include "game.h"
#include "dgv.h"
#include "world.h"
#include "campeonato.h"
#include "comandos.h"
//#include "consola.h"

using namespace std;

int main()
{
	bool on = true;
	string opt;

	cout << true;




	cout << "-----------------" << endl;
	cout << "----POO 19/20----" << endl;
	cout << "-----------------" << endl;


	Dgv* d = new Dgv(); //direcao geral de via�ao
	Game *game = new Game(); // novo jogo(defini��es e affins)
	World* w = new World();//para ja autodromos

	while (on == true) {
		vector<string> autod;
		game->startConfig(d, w);

		system("pause");
		Campeonato* campeonato = new Campeonato;

		game->startChamp(d, w, campeonato);

		//aqui vai come�ar o campeonato

		cout << "Deseja sair? " << endl;
		cin >> opt;

		if (opt == "Sim" || opt == "sim") {
			cout << "Obrigado!" << endl;
			on = false;
		}


	}


	



	system("pause");
}

