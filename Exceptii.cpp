#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Exceptii.h"

using namespace std;

Exceptii::Exceptii()
{
	vector_exceptii = 0;
	cod_exceptie = nullptr;
}

Exceptii::Exceptii(int vector_exceptii, string* cod_exceptie)
{
	this->vector_exceptii = vector_exceptii;
	if (cod_exceptie != nullptr)
	{
		this->cod_exceptie = new string[vector_exceptii];
		for (int i = 0; i < vector_exceptii; i++)
		{
			this->cod_exceptie[i] = cod_exceptie[i];
		}
	}
}

Exceptii::Exceptii(const Exceptii& e)
{

	if (e.cod_exceptie != nullptr && e.vector_exceptii > 0)
	{
		this->vector_exceptii = e.vector_exceptii;
		this->cod_exceptie = new string[vector_exceptii];
		for (int i = 0; i < vector_exceptii; i++)
		{
			this->cod_exceptie[i] = e.cod_exceptie[i];
		}
	}
	else
	{
		this->vector_exceptii = 0;
		this->cod_exceptie = nullptr;
	}

}

Exceptii::~Exceptii()
{
	if (cod_exceptie != nullptr)
	{
		delete[] cod_exceptie;
	}
}

Exceptii Exceptii::operator=(const Exceptii& e)
{
	if (cod_exceptie != nullptr)
	{
		delete[] cod_exceptie;
	}

	if (e.cod_exceptie != nullptr && e.vector_exceptii > 0)
	{
		this->vector_exceptii = e.vector_exceptii;
		this->cod_exceptie = new string[vector_exceptii];
		for (int i = 0; i < vector_exceptii; i++)
		{
			this->cod_exceptie[i] = e.cod_exceptie[i];
		}
	}
	else
	{
		this->vector_exceptii = 0;
		this->cod_exceptie = nullptr;
	}

	return *this;
}

string& Exceptii::operator[](int index)
{
	if (index > 0 && index < vector_exceptii)
	{
		return cod_exceptie[index];
	}
}

Exceptii Exceptii::operator+(int valoare)
{
	if (valoare > 0)
	{
		Exceptii copie = *this;
		copie.vector_exceptii += valoare;
		return copie;
	}
	else
	{
		throw exception("Valorea negativa");
	}
}

Exceptii Exceptii::operator-(int valoare)
{
	if (valoare > 0 && valoare < vector_exceptii)
	{
		Exceptii copie = *this;
		copie.vector_exceptii -= valoare;
		return copie;
	}
	else
	{
		throw exception("Valoare incorecta");
	}
}

Exceptii Exceptii::operator++()
{
	this->vector_exceptii++;
	return *this;
}

Exceptii Exceptii::operator++(int i)
{
	Exceptii copie = *this;
	this->vector_exceptii++;
	return copie;
}

bool Exceptii::operator!()
{
	return vector_exceptii > 0;
}

Exceptii::operator int()
{
	return vector_exceptii;
}

bool Exceptii:: operator<=(int valoare)
{
	return valoare <= vector_exceptii;
}

bool Exceptii::operator==(int valoare)
{
	return valoare == vector_exceptii;
}


istream& operator>>(istream& in, Exceptii& e)
{
	cout << "Exceptie: ";
	in >> e.vector_exceptii;
	if (e.cod_exceptie != nullptr)
	{
		delete[] e.cod_exceptie;
	}
	if (in.good() && e.vector_exceptii > 0)
	{
		e.cod_exceptie = new string[e.vector_exceptii];
		for (int i = 0; i < e.vector_exceptii; i++)
		{
			cout << "Cod exceptie: ";
			in >> e.cod_exceptie[i];
		}
	}
	else
	{
		e.cod_exceptie = nullptr;
		e.vector_exceptii = 0;
	}

	return in;
}
ostream& operator<<(ostream& out, Exceptii e)
{
	out << "Exceptie: ";
	out << e.vector_exceptii;
	out << "Cod exceptie: " << endl;
	for (int i = 0; i < e.vector_exceptii; i++)
	{
		out << e.cod_exceptie[i] << " ";
	}
	out << endl;
	return out;
}