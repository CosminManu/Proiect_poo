#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include<stdlib.h>
#include "Coloana.h"
#include "Tabela.h"
#include "User.h"
#include "Exceptii.h"
#include "Comenzi.h"

using namespace std;


int main()
{
	//const char* nume = { "Departament" };
	//string date_coloana[] = { "Conta", "IT", "Vanzari" };
	//Coloana f(nume, date_coloana, 3);
	//Coloana h(nume);
	/*Coloana i;
	cin >> i;
	cout << i;*/

	//Coloana c1[] = { f,h };

	//Tabela t1("Departamente", c1, 2);
	//Tabela t2;
	/*cin >> t2;
	cout << t2;*/

	int ok = 0;
	while (ok == 0)
	{
		cout << endl;
		cout << "Logare" << endl;
		cout << "Introduceti username si parola: ";
		ofstream out("date.out.txt");
		ifstream in("date.in.txt");
		User u1;
		cin >> u1;
		ok = u1.verifica();
		if (ok == 0)
		{
			cout << "Mai incearca o data" << endl;
		}
	}

	cout << "Introduceti una din urmatoarele comenzi:"<<endl<< 
		"CREATE TABLE comenzi ( nume , text , 30 , NULL , varsta , integer , 10 , NULL ) \n" <<
		"DISPLAY TABLE comenzi " << endl;

	int var_exit = 0;
	while (var_exit != 1)
	{
		string sir;
		cout << "\n Introduceti comanda: (sau EXIT pt a iesi)" << endl;
		cin >> ws;
		getline(cin, sir);
		Comenzi c(sir);
		c.DeterminareComanda();
		
		if (c.getCom() == "EXIT" || c.getCom() == "Exit" || c.getCom() == "exit")
		{
			var_exit = c.Exit();
		}
	}
	//cout << sir;
	//sir = "CREATE TABLE comenzi ( nume , text , 30 , NULL , varsta , integer , 10 , NULL )"; 
	
	/*string sir;
	getline(cin, sir);
	Comenzi c(sir);
	c.DeterminareComanda();*/
}
