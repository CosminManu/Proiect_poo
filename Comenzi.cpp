#include "Comenzi.h"
#include <fstream>

using namespace std;

Comenzi::Comenzi(string comanda)
{
	this->comanda = comanda;
}
Comenzi::Comenzi(string comanda, int cod)
{
	this->comanda = comanda;
	this->cod = cod;
}

void Comenzi::DeterminareComanda()
{
	string nume;
	string delimiter = " ";
	size_t pos = 0;
	string token;
	while ((pos = comanda.find(delimiter)) != string::npos) {
		token = comanda.substr(0, pos);
		com.push_back(token);
		comanda.erase(0, pos + delimiter.length());
	}

	com.push_back(comanda);

	if (com.size() == 1)
	{
		nume = com.at(0);
	}
	else nume = com.at(2);	

	if (this->com.at(0) == "CREATE")
	{
		if (this->com.at(1) == "TABLE")
		{
			
			CreateTable();
			
		}
	}
	if (this->com.at(0) == "DISPLAY")
	{
		if (this->com.at(1) == "TABLE")
		{
			DisplayTable();
			
		}
	}

	if (this->com.at(0) == "DROP")
	{
		if (this->com.at(1) == "TABLE")
		{
			DropTable();

		}
	}
	if (this->com.at(0) == "EXIT" || this->com.at(0) == "exit" || this->com.at(0) == "Exit")
	{
		Exit();
	}
}

int Comenzi::Exit()
{
	int x = 1;
	return x;
}
string Comenzi::getCom()
{
	return com.at(0);
}

void Comenzi::DropTable()
{
	int ok = 0;
	string line;
	string line1;
	fstream fisier("tabel.txt");
	if (fisier.is_open())
	{
		while (getline(fisier, line))
		{
			line.replace(line.find(line), line.length(), "");
			fisier << line;

		}
		cout << "	Tabela " << com.at(2) << " a fost stearsa" << endl;

		fisier.close();
	}
}


void Comenzi::CreateTable()
{
	ofstream fisier;
	int i = 0, t = 0;

	for (string s : com)
	{
		if (s == ")")
		{
			i = 0;
		}
		if (i != 0)
		{
			t++;

			if (t % 8 == 1)
			{
				vector_col.push_back(s);
			}
		}
		if (s == "(") {
			i = 1;
		}
	}
	fisier.open("tabel.txt");
	fisier << com.at(2) << endl;
	for (int i = 0; i < vector_col.size(); i++)
	{
		fisier << vector_col[i] << endl;

	}
	fisier.close();
	cout << endl;
	cout << "Tabela " << com.at(2) << " a fost creata" << endl;
					
}

void Comenzi::insertCol(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita)
{
	/*for (int i = 0; i < nume_coloana.size(); i++)
	{
		int nr_coloane = col->get_nr_coloane();
		col[nr_coloane] = Coloana(nume_coloana, Tip, dimensiune, valoare_implicita);
	}*/
}

void Comenzi::DisplayTable()			// DISPLAY TABLE comenzi
{
	cout << endl;

	//for (int i = 0; i < vector_col.size(); i++)
	//{
	//	cout <<"  " <<vector_col[i] << "		";
	//}

	int ok = 0;
	string line;
	string line1;
	ifstream fisier("tabel.txt");
	if (fisier.is_open())
	{
		while (getline(fisier, line))
		{
			ok++;
			if (com.at(2) == line1)
			{
				cout << "	" << line << "		";
			}

			if (ok == 1 && com.at(2) == line)
			{
				cout << "	Tabela " << com.at(2) << endl;
				line1 = line;
			}
		}

		fisier.close();
	}
	else cout << "Nu s a putut deschide fisierul" << endl;
	cout << endl;
}



Tabela* Comenzi::getTab()
{
	return tab;
}

void Comenzi::Select()
{

}

void Comenzi::Update()
{

}

void Comenzi::Insert()
{

}

void Comenzi::Delete()
{

}
