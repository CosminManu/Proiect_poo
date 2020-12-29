#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

//int ok = 0;

class User
{
	vector<pair<string, string>> date;
public:
	User();

	User(const User& u);

	~User();

	User& operator= (const User& u);

	void adauga(string user, string pass);

	bool verifica();

	void delUser(string user);

	friend ostream& operator<< (ostream& out, User& u);

	friend istream& operator>> (istream& in, User& u);

	bool operator!();

	operator int();
};