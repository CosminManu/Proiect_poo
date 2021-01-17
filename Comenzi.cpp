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
			if (this->com.at(3) == "VALUES")
			{
				Insert();
			}			
		}
	}

	if (this->com.at(0) == "SELECT")		
	{
		if (this->com.at(2) == "FROM" || this->com.at(4) == "FROM")
		{
			Select();
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


void Comenzi::Select()										
{
	fstream fisier;
	fstream fisier1;
	string line1;
	int ok = 0, nr = 0, t = 0, i = 0, exit = 0, n = 0;
	string line;
	fisier.open("tabel.txt");

	if (ok == 0)
	{
		for (string s : com)
		{
			if (s == "FROM")
			{
				i = 0;
			}
			if (i != 0)
			{
				t++;

				if (t % 2 == 1)
				{
					vector_sel.push_back(s);		
				}
			}
			if (s == "SELECT") {
				i = 1;
			}
		}
	}
	n = vector_sel.size();
	cout << endl;

	while (getline(fisier, line))
	{
		nr++;
		if ((nr % 3 == 2) || (nr % 3 == 0))
		{
			vector_col.push_back(line);
		}
	}


	for (i = 0; i < vector_sel.size(); i++)
	{
		for (int j = 0; j < vector_col.size(); j++) 
		{
			if (vector_sel[i] == vector_col[j])		
			{
				ok = 0;
				fisier1.open("insert.txt", ios::in);
				while (getline(fisier1, line))
				{
					nr = 0;
					if (ok == 0)
					{
						cout << endl;
					}

					if (line != "")
					{
						if ((ok > 0 && com.at(5) == line) || line == com.at(5))
						{
							ok++;
							getline(fisier1, line);
							nr++;
							cout << "    " << line << "        ";
							getline(fisier1, line);
						}
						nr++;
						if (ok % 2 == 1 && nr != 1)
						{
							ok++;
							cout << "    " << line << "        \n";
						}
						if (ok == 0)
						{
							ok = 2;
						}

					}
				}
				
			}
		}
	}
	
	if (ok == 1)
	{
		cout << "\nColoana inexistenta";
	}
	fisier.close();
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
				if (line == com.at(2) && ok == 0)		
				{										
					line1 = line;
					ok = 1;
					nr++;
				}
				else
					if (line1 == com.at(2))
					{
						nr++;
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

		ifstream fisierOut("drop.txt", ios::binary);
		ofstream fisierIn("tabel.txt", ios::binary);
		if (fisierOut.is_open() && fisierIn.is_open() && fisierIn.good() && fisierOut.good())
		{
			fisierIn << fisierOut.rdbuf();
			fisierIn.close();
			fisierOut.close();
		}
		
		fisier1.open("drop.txt", ios::out | ios::trunc);
		fisier1.close();

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

void Comenzi::Insert()
{
	int i = 0, t = 0, ok = 0, gasit = 0;
	string line;
	fstream fisier;
	fstream fisier1;
	
	fisier1.open("tabel.txt", ios::in);
	while (getline(fisier1, line))
	{
		if (com.at(2) == line)
		{
			gasit = 1;
			if (ok == 0)
			{
				for (string s : com)
				{
					if (s == ")")
					{
						i = 0;
					}
					if (s == com.at(2))
					{
						vector_coloane.push_back(s);
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
			if (gasit == 0)
			{
				break;
			}
		}

	}
	if (gasit == 0)
	{
		cout << "Nu s au putut insera coloane pt ca tabela nu a fost creata.\n";
	}
	fisier1.close();
}

void Comenzi::DisplayTable()           
{
	cout << endl;

	int ok = 1, nr = 0, exit = 0;
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
			cout << "\nTabela nu exista";
			exit = -1;
		}
		fisier.close();
	}
	if (exit == 0)
	{
		if (fisier1.is_open())      
		{
			int ok = 0;
			while (getline(fisier1, line))
			{
				nr = 0;
				if (ok == 0)
				{
					cout << endl;
				}

				if (line != "")
				{
					if ((ok > 0 && com.at(2) == line) || line == com.at(2))
					{
						ok++;
						getline(fisier1, line);
						nr++;
						cout << "    " << line << "        ";
						getline(fisier1, line);
					}
					nr++;
					if (ok % 2 == 1 && nr != 1)  
					{
						ok++;
						cout << "    " << line << "        \n";
					}
					if (ok == 0)
					{
						ok = 2;
					}

				}


			}
		}
		else cout << "\nNu s a putut deschide fisierul";
	}
	fisier1.open("insert.txt", ios::out | ios::trunc);
	fisier1.close();
	
	cout << endl;
}


