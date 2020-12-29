#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

class Exceptii
{
private:
	int vector_exceptii;
	string* cod_exceptie;

public:
	Exceptii();

	Exceptii(int vector_exceptii, string* cod_exceptie);


	Exceptii(const Exceptii& e);

	~Exceptii();

	Exceptii operator=(const Exceptii& e);
	string& operator[](int index);

	Exceptii operator+(int valoare);

	Exceptii operator-(int valoare);

	Exceptii operator++();

	Exceptii operator++(int i);

	bool operator!();

	operator int();

	bool operator<=(int valoare);

	bool operator==(int valoare);

	friend istream& operator>>(istream&, Exceptii&);
	friend ostream& operator<<(ostream&, Exceptii);
};