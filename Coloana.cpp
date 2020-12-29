#include "Coloana.h"

using namespace std;

Coloana::Coloana()
{
	this->date_coloana = nullptr;
	this->nr_date_coloana = 0;
	this->dimensiune = 0;
	this->valoare_implicita = "N/A";
	this->Tip = "necunoscut";
}
Coloana::Coloana(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita)
	: Coloana()
{
	this->Tip = Tip;
	this->dimensiune = dimensiune;
	this->valoare_implicita = valoare_implicita;
	this->nume_coloana = nume_coloana;
}
Coloana::Coloana(vector<string> nume_coloana, string Tip, string valoare_implicita, string* date_coloana, int nr_date_coloana, int dimensiune)
	: Coloana()
{
	this->Tip = Tip;
	this->dimensiune = dimensiune;
	this->valoare_implicita = valoare_implicita;
	if (nr_date_coloana > 0 && date_coloana != nullptr)
	{
		this->nr_date_coloana = nr_date_coloana;
		this->date_coloana = new string[nr_date_coloana];
		for (int i = 0; i < nr_date_coloana; i++)
		{
			this->date_coloana[i] = date_coloana[i];
		}
	}
	this->nume_coloana = nume_coloana;
}

Coloana::Coloana(vector<string> nume_coloana)
	:Coloana()
{
	this->nume_coloana = nume_coloana;
}

Coloana::Coloana(const Coloana& c) : Coloana()
{
	this->Tip = c.Tip;
	this->valoare_implicita = c.valoare_implicita;
	this->dimensiune = c.dimensiune;
	if (c.nr_date_coloana > 0 && c.date_coloana != nullptr)
	{
		this->nr_date_coloana = c.nr_date_coloana;
		this->date_coloana = new string[c.nr_date_coloana];
		for (int i = 0; i < nr_date_coloana; i++)
		{
			this->date_coloana[i] = c.date_coloana[i];
		}
	}
	else
	{
		this->nr_date_coloana = 0;
		this->date_coloana = nullptr;
	}
	this->nume_coloana = c.nume_coloana;
}

Coloana::~Coloana()
{
	if (date_coloana != nullptr)
	{
		delete[] date_coloana;
	}
}

Coloana &Coloana::operator=(const Coloana& c)
{
	if (date_coloana != nullptr)
	{
		delete[] date_coloana;
	}

	this->Tip = c.Tip;
	this->valoare_implicita = c.valoare_implicita;
	this->dimensiune = c.dimensiune;
	if (c.nr_date_coloana > 0 && c.date_coloana != nullptr)
	{
		this->nr_date_coloana = c.nr_date_coloana;
		this->date_coloana = new string[c.nr_date_coloana];
		for (int i = 0; i < nr_date_coloana; i++)
		{
			this->date_coloana[i] = c.date_coloana[i];
		}
	}
	this->nume_coloana = c.nume_coloana;

	return *this;
}

bool Coloana::operator!()
{
	return nr_date_coloana > 0;
}

Coloana Coloana::operator++()
{
	this->nr_date_coloana++;
	return *this;
}

Coloana Coloana::operator++(int i)
{
	Coloana copie = *this;
	this->nr_date_coloana++;
	return copie;
}

Coloana Coloana::operator+(int valoare)
{
	if (valoare > 0)
	{
		Coloana copie = *this;
		copie.nr_date_coloana += valoare;
		return copie;
	}
	else throw exception("Valoare negativa");
}

Coloana Coloana::operator-(int valoare)
{
	if (valoare > 0 && valoare < nr_date_coloana)
	{
		Coloana copie = *this;
		copie.nr_date_coloana -= valoare;
		return copie;
	}
	else throw exception("Valoare incorecta");
}

Coloana::operator int()
{
	return nr_date_coloana;
}

bool Coloana::operator<= (int valoare)
{
	return valoare <= nr_date_coloana;
}

bool Coloana::operator==(int valoare)
{
	return valoare == nr_date_coloana;
}

string& Coloana::operator[](int index)
{
	if (index > 0 && index <= nr_date_coloana)
	{
		return date_coloana[index];
	}
}



int Coloana::get_nr_coloane()
{
	return nr_date_coloana;
}

string* Coloana::get_date_coloana()
{
	return date_coloana;
}

void Coloana::set_date_coloane(int nr_date_coloana, string* date_coloana)
{
	if (date_coloana != nullptr && nr_date_coloana > 0)
	{
		this->nr_date_coloana = nr_date_coloana;
		if (date_coloana != nullptr)
		{
			delete[] this->date_coloana;
		}
		for (int i = 0; i < nr_date_coloana; i++)
		{
			this->date_coloana[i] = date_coloana[i];
		}
	}
}



ostream& operator<<(ostream& out, Coloana c)
{

	out << "Nume coloana: ";
	out << c.nume_coloana;

	out << "Tipul datelor: ";
	out << c.Tip << endl;					// string
	out << "Dimensiune: ";
	out << c.dimensiune << endl;			// int
	out << "Valoare implicita: ";
	out << c.valoare_implicita << endl;		// string
	out << "Nr datelor din coloana: ";
	out << c.nr_date_coloana << endl;
	out << "Datele coloanei: ";
	if (c.date_coloana != nullptr)
	{
		for (int i = 0; i < c.nr_date_coloana; i++)
		{
			out << c.date_coloana[i] << " ";		//string*
		}
	}
	out << endl;


	return out;
}

istream& operator>>(istream& in, Coloana& c)
{
	string buf;
	cout << "Nume coloana: ";
	for (int i = 0; i < c.nume_coloana.size(); i++)
	{
		in >> c.nume_coloana[i];
	}

	cout << "Tipul datei: ";
	in >> c.Tip;
	cout << "Dimensiune: ";
	in >> c.dimensiune;
	cout << "Valoare implicita: ";
	in >> c.valoare_implicita;
	cout << "Nr datelor din coloana: ";
	in >> c.nr_date_coloana;

	cout << "Datele coloanei: ";
	if (c.date_coloana != nullptr)
	{
		delete[]c.date_coloana;		// string*
	}
	if (in.good() && c.nr_date_coloana > 0)
	{
		c.date_coloana = new string[c.nr_date_coloana];
		for (int i = 0; i < c.nr_date_coloana; i++)
		{
			cout << "Coloana[" << i + 1 << "]: ";
			in >> c.date_coloana[i];
		}
	}
	else
	{
		c.nr_date_coloana = 0;
		c.date_coloana = nullptr;
	}
	cout << endl;

	return in;
}