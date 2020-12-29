#include "Tabela.h"

using namespace std;

Tabela::Tabela() : id_tabela(nr_tabela++)
{
	nume_tabel = "";
	nr_coloane = 0;
}

Tabela::Tabela(string nume_tabel)
	: id_tabela(nr_tabela++)
{
	this->nume_tabel = nume_tabel;
}

Tabela::Tabela(string nume_tabel, vector<string> vector_coloane)
	: id_tabela(nr_tabela++)
{
	this->nume_tabel = nume_tabel;
	this->vector_coloane = vector_coloane;
}

Tabela::Tabela(string nume_tabel, vector<string> vector_coloane, int nr_coloane) : id_tabela(nr_tabela++)
{
	this->nume_tabel = nume_tabel;
	this->nr_coloane = nr_coloane;
	this->vector_coloane = vector_coloane;
}

Tabela::Tabela(const Tabela& t) : id_tabela(nr_tabela++)
{
	this->nume_tabel = t.nume_tabel;
	this->nr_coloane = t.nr_coloane;
	this->vector_coloane = t.vector_coloane;
}

Tabela::~Tabela()
{
}

Tabela &Tabela::operator=(const Tabela& t)
{
	if (this != &t)
	{
		this->nume_tabel = t.nume_tabel;
		this->nr_coloane = t.nr_coloane;
		this->vector_coloane = t.vector_coloane;
		return *this;
	}
}

string Tabela::operator[](int index)
{
	if (index > 0 && index <= nr_coloane)
	{
		return vector_coloane[index];
	}
	else
	{
		throw exception("Index invalid");
	}
}

Tabela Tabela::operator+(int valoare)
{
	if (valoare > 0)
	{
		Tabela copie = *this;
		copie.nr_coloane += valoare;
		return copie;
	}
	else
	{
		throw exception("Valoare negativa");
	}
}

Tabela Tabela::operator-(int valoare)
{
	if (valoare > 0 && valoare < nr_coloane)
	{
		Tabela copie = *this;
		copie.nr_coloane -= valoare;
		return copie;
	}
	else
	{
		throw exception("Valoare incorecta");
	}
}

Tabela Tabela::operator++()
{
	this->nr_coloane++;
	return *this;
}

Tabela Tabela::operator++(int i)
{
	Tabela copie = *this;
	this->nr_coloane++;
	return copie;
}

bool Tabela::operator!()
{
	return nr_coloane > 0;
}

Tabela::operator int()
{
	return nr_coloane;
}

bool Tabela::operator<=(int valoare)
{
	return valoare <= nr_coloane;
}

bool Tabela::operator==(int valoare)
{
	return valoare == nr_coloane;
}

ostream& operator<<(ostream& out, Tabela t)
{
	out << "Nume tabel: " << t.nume_tabel << endl;
	out << "Numar coloane: " << t.nr_coloane << endl;
	out << endl;

	for (int i = 0; i < t.vector_coloane.size(); i++)
	{
		out << t.vector_coloane[i] << "		";
	}
	out << "Id Tabela: " << t.id_tabela << endl;

	return out;
}
istream& operator>>(istream& in, Tabela& t)
{
	cout << "Nume Tabel: ";
	in >> ws;
	getline(in, t.nume_tabel);
	cout << "Numar Coloane: ";
	in >> t.nr_coloane;
	cout << endl;

	if (in.good() && t.nr_coloane > 0)
	{
		if (t.vector_coloane.size() > 0) {
			for (int i = 0; i < t.vector_coloane.size(); i++)
			{
				in >> t.vector_coloane[i];
			}
		}
	}
	else
	{
		t.nr_coloane = 0;
	}
	return in;
}

int Tabela::nr_tabela = 0;