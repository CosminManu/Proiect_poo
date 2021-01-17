#include "Comenzi.h"
#include <fstream>
#include<iomanip>

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

	if (this->com.at(0) == "INSERT")
	{
		if (this->com.at(1) == "INTO")
		{
			Insert();
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
	int ok = 0, nr = 0;
	string line;
	string line1;
	fstream fisier("tabel.txt");
	fstream fisier1("drop.txt");

	if (fisier.is_open())
	{
		while (getline(fisier, line))
		{
			if (nr < 3)
			{
				if (line == com.at(2) && ok == 0)		// DROP     TABLE     comenzi
				{										// comat0   com,at(1) com.at(2)
					line1 = line;
					ok = 1;
					nr++;
					//fisier << line;
				}
				else
					if (line1 == com.at(2))
					{
						nr++;
						//line.replace(line.find(line), line.length(), "");
						//fisier << line;
					}
			}
			else {
				if (nr == 3)
				{
					fisier1.open("drop.txt", ios::out | ios::app);
					fisier1 << noskipws;
					fisier1 << line << endl;
					fisier1.close();
					nr++;
				}
				if (line != com.at(2))
				{
					fisier1.open("drop.txt", ios::out | ios::app);
					fisier1 << noskipws;
					fisier1 << line << endl;
					fisier1.close();
				}
			}
		}

		// !!!
		/*fisier.open("tabel.txt", ios::out | ios::app | ios::trunc);
		ifstream fisier1("drop.txt");
		fisier1.open("drop.txt");*/


		while (getline(fisier1, line))
		{
			fisier << line << endl;
		}
		fisier1.close();
		fisier.close();
	
		if (ok == 1)
		{
			cout << "    Tabela " << com.at(2) << " a fost stearsa" << endl;
		}
		else
		{
			cout << endl << "Tabela nu exista" << endl;
		}

		fisier.close();
	}
}

// DROP TABLE comenzi --> drop.txt : abc litera cifra  
//tabel.txt : comenzi nume varsta abc litera cifra
//trunc = > sterge tabel.txt
//muti drop > tabel.txt
//     tabel.txt > tabel.txt

void Comenzi::CreateTable()
{
	
	fstream fisier;
	int i = 0, t = 0, ok = 0;
	string line;
	fisier.open("tabel.txt");

	while (getline(fisier, line) && ok == 0)
	{
		if (com.at(2) == line)
		{
			cout << "Tabela cu acest nume exista deja." << endl;
			ok = 1;
		}
	}

	fisier.close();
	if (ok == 0)
	{
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
		fisier.open("tabel.txt", ios::app);
		fisier << com.at(2) << endl;
		for (int i = 0; i < vector_col.size(); i++)
		{
			fisier << vector_col[i] << endl;

		}
		fisier.close();
		cout << endl;
		cout << "Tabela " << com.at(2) << " a fost creata" << endl;
	}
		
}

void Comenzi::insertCol(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita)
{
	/*for (int i = 0; i < nume_coloana.size(); i++)
	{
		int nr_coloane = col->get_nr_coloane();
		col[nr_coloane] = Coloana(nume_coloana, Tip, dimensiune, valoare_implicita);
	}*/
}

void Comenzi::Insert()
{
	int i = 0, t = 0, ok = 0;
	string line;
	fstream fisier;

	if (ok == 0)
	{
		for (string s : com)
		{
			if (s == ")")
			{
				i = 0;
			}
			if (i != 0)
			{
				t++;

				if (t % 2 == 1)
				{
					vector_coloane.push_back(s);
				}
			}
			if (s == "(") {
				i = 1;
			}
		}
		fisier.open("insert.txt", ios::app);
		
		for (int i = 0; i < vector_coloane.size(); i++)
		{
			fisier << vector_coloane[i] << endl;

		}
		fisier.close();
		cout << endl;
		cout << "S-au inserat coloanele!" << endl;
	}
}

void Comenzi::DisplayTable()            // DISPLAY TABLE comenzi
{
	cout << endl;

	int ok = 1, nr = 0;
	string line;
	string line1;
	fstream fisier1("insert.txt");
	ifstream fisier("tabel.txt");
	if (fisier.is_open())
	{
		while (getline(fisier, line))
		{
			if (com.at(2) == line1 && nr < 2)
			{
				cout << "    " << line << "        ";
				nr++;
			}

			if (ok == 1 && com.at(2) == line)
			{
				cout << "    Tabela " << com.at(2) << endl;
				line1 = line;
				ok = 2;
			}
		}
		if (ok != 2)
		{
			cout << "Tabela nu exista";
		}

		fisier.close();
	}

	if (fisier1.is_open())
	{	
		int ok = 0;
		while (getline(fisier1, line))
		{
			if (ok == 0) {
				cout << endl;
			}
			if (line != "")
			{
				ok++;
				cout << "    " << line << "        ";
			}
			if (ok == 2)
			{
				cout << endl;
				ok = 0;
			}
			
		}
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

void Comenzi::Delete()
{

}
