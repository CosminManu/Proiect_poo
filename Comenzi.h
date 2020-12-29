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

	Comenzi(string comanda);
	bool DeterminareComanda();

	Tabela* getTab();

	void CreateTable(string x, vector<string> vector_col);

	void insertCol(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita);

	void DropTable();

	void DisplayTable();

	void Select();
	void Update();
	void Insert();
	void Delete();
	friend class Tabela;
};