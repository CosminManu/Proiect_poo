#include "Comenzi.h"

using namespace std;

Comenzi::Comenzi(string comanda)
{
	this->comanda = comanda;
}

bool Comenzi::DeterminareComanda()
{
	string delimiter = " ";
	size_t pos = 0;
	string token;
	while ((pos = comanda.find(delimiter)) != string::npos) {
		token = comanda.substr(0, pos);
		com.push_back(token);
		comanda.erase(0, pos + delimiter.length());
	}
	com.push_back(comanda);

	string nume = com.at(2);
	if (this->com.at(0) == "CREATE")
	{
		if (this->com.at(1) == "TABLE")
		{
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
			cout << endl;
			cout << "Tabela " << com.at(2) << " a fost creata" << endl;
			//CreateTable(com.at(2), vector_col);
			
		}
		if (vector_col.size() != 0)		// daca ai coloane
		{
			return 1;
		}
		else return 0;
	}
	if (this->com.at(0) == "DISPLAY")
	{
		if (this->com.at(1) == "TABLE")
		{
			if(this->com.at(2) == nume)
			DisplayTable();
		}
	}
	
}

Tabela* Comenzi::getTab()
{
	return tab;
}

void Comenzi::CreateTable(string x, vector<string> vector_col)
{
	/*tab->nr_tabela++;
	tab = new Tabela[tab->nr_tabela];
	for (int i = 0; i < tab->nr_tabela; i++) 
	{

		tab[i] = Tabela(x,vector_col,vector_col.size());
		tab->nr_tabela-=2;
	}
	tab[tab->nr_tabela - 1].id_tabela = tab->nr_tabela - 1;
	tab[tab->nr_tabela - 1].nr_coloane = vector_col.size();
	tab[tab->nr_tabela - 1].nume_tabel = x;
	tab[tab->nr_tabela - 1].vector_coloane = vector_col;

	tab[tab->nr_tabela - 1] = Tabela(x, vector_col, vector_col.size());*/		
														
}

void Comenzi::insertCol(vector<string> nume_coloana, string Tip, int dimensiune, string valoare_implicita)
{
	/*for (int i = 0; i < nume_coloana.size(); i++)
	{
		int nr_coloane = col->get_nr_coloane();
		col[nr_coloane] = Coloana(nume_coloana, Tip, dimensiune, valoare_implicita);
	}*/
}

void Comenzi::DropTable()
{
	if (tab->nr_tabela > 0)
	{
		delete[] tab;
		tab->nr_tabela--;
	}
}

void Comenzi::DisplayTable()
{
	cout << endl;
	cout << "	Tabela " << com.at(2) <<endl;
	for (int i = 0; i < vector_col.size(); i++)
	{
		cout <<"  " <<vector_col[i] << "		";
	}
	cout << endl;
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