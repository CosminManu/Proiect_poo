#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include "Tabela.h"
#include "Coloana.h"

using namespace std;

class Comenzi
{
private:
	Tabela* tab;
	Coloana* col;
	string comanda;
	int cod;
	vector<string> com;
public:
	vector <string> vector_col;
	vector <string> vector_coloane;

	Comenzi(string comanda);
	Comenzi(string comanda, int cod);

	void DeterminareComanda();

	Tabela* getTab();

	void CreateTable();

	void insertCol(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita);

	void DropTable();

	void DisplayTable();

	void Select();
	void Update();
	void Insert();
	void Delete();
	int Exit();
	friend class Tabela;
	
	string getCom();
};
