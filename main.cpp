#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
#include<vector>
#include<stdlib.h>
#include <conio.h>
#include "Coloana.h"
#include "Tabela.h"
#include "User.h"
#include "Exceptii.h"
#include "Comenzi.h"

using namespace std;


int main()
{

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

	cout << endl<< "Introduceti una din urmatoarele comenzi: \n"
		<< "CREATE TABLE comenzi ( nume , text , 30 , NULL , varsta , integer , 10 , NULL ) \n" 
		<< "CREATE TABLE abc ( litera , text , 30 , NULL , cifra , integer , 10 , NULL )\n"
		<<"DISPLAY TABLE comenzi \n" 
		<<"DISPLAY TABLE abc \n"
		<<"DROP TABLE comenzi \n"
		<<"DROP TABLE abc \n"
		<<"INSERT INTO comenzi VALUES ( Denisa , 20 ) \n"
		<<"INSERT INTO comenzi VALUES ( Cosmin , 20 ) \n"
		<<"INSERT INTO comenzi VALUES ( Stefan , 22 ) \n"
		<<"INSERT INTO abc VALUES ( M , 31 ) \n"
		<<"SELECT nume , varsta FROM comenzi \n"
		<<endl;

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
}
