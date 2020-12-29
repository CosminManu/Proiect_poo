#include "User.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;



User::User() {}
User::User(const User& u)
{
	date = u.date;
}
User::~User() {}
User& User:: operator= (const User& u)
{
	date = u.date;
	return *this;
}


void User::adauga(string user, string pass) {
	for (int i = 0; i < date.size(); i++)
		if (date[i].first == user) {
			cout << "Exista deja un utilizator cu acelasi username.\n";
			return;
		}
	date.push_back(make_pair(user, pass));
}
bool User::verifica()
{
	string user;
	string pass;
	int nr_utilizatori;
	ifstream in("date.in.txt");
	in >> nr_utilizatori;
	for (int i = 0; i < date.size(); i++)
	{
		for (int j = 0; j < nr_utilizatori; j++)
		{
			in >> user;
			if (date[i].first == user)
			{
				in >> pass;
				if (date[i].second == pass)
				{
					cout << "V-ati logat!" << endl;
					return 1;
				}
				cout << "Parola incorecta." << endl;
				return 0;
			}
			else {
				string abc;
				in >> abc;
			}
		}

	}
	cout << "Utilizatorul nu exista!\n";
	return 0;

}
void User::delUser(string user)
{
	for (int i = 0; i < date.size(); i++)
		if (date[i].first == user)
		{
			date.erase(date.begin() + i);
			cout << "Utilizator sters." << endl;
			return;
		}
	cout << "Utilizatorul nu exista!" << endl;
}

bool User::operator!()
{
	return date.size() > 0;
}
User::operator int()
{
	return date.size();
}

ostream& operator<< (ostream& out, User& u) {
	out << u.date.size() << endl;
	for (int i = 0; i < u.date.size(); i++)
	{
		out << u.date[i].first << " " << u.date[i].second << endl;
	}
	return out;
}
istream& operator>> (istream& in, User& u)
{
	string s1, s2;
	in >> s1 >> s2;
	u.adauga(s1, s2);

	return in;
}