#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

class Coloana
{
protected:
	vector<string> nume_coloana;
	string* date_coloana;
	int nr_date_coloana;
	string Tip;
	string valoare_implicita;
	int dimensiune;

public:
	Coloana();
	Coloana(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita);
	Coloana(vector<string> nume_coloana, string Tip, string valoare_implicita, string* date_coloana, int nr_date_coloana, int dimensiune);
	Coloana(vector<string> nume_coloana);
	Coloana(const Coloana& c);
	~Coloana();

	Coloana& operator=(const Coloana& c);
	
	bool operator!();

	Coloana operator++();

	Coloana operator++(int i);

	Coloana operator+(int valoare);

	Coloana operator-(int valoare);

	operator int();

	bool operator<= (int valoare);

	bool operator==(int valoare);
	
	string& operator[](int index);
	
	int get_nr_coloane();

	string* get_date_coloana();

	void set_date_coloane(int nr_date_coloana, string* date_coloana);

	friend ostream& operator<<(ostream&, Coloana);
	friend istream& operator>>(istream&, Coloana&);
};

