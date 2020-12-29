#pragma once

#include <fstream>
#include<vector>
#include <string>
#include <iostream>

using namespace std;

class Tabela
{
protected:
	string nume_tabel;
	vector<string> vector_coloane;
	int nr_coloane;
	int id_tabela;			// ang id 1 nr 1
									// dep id 2 nr 2
public:
	static int nr_tabela;

	Tabela();
	Tabela(string nume_tabel);
	Tabela(string nume_tabel, vector<string> vector_coloane);
	Tabela(string nume_tabel, vector<string> vector_coloane, int nr_coloane);
	Tabela(const Tabela& t);
	~Tabela();

	Tabela& operator=(const Tabela& t);
	
	string operator[](int index);

	Tabela operator+(int valoare);

	Tabela operator-(int valoare);

	Tabela operator++();

	Tabela operator++(int i);

	bool operator!();

	operator int();

	bool operator<=(int valoare);

	bool operator==(int valoare);

	friend ostream& operator<<(ostream&, Tabela);
	friend istream& operator>>(istream&, Tabela&);
	friend class Comenzi;
};
