#include "pch.h"
#include "polynom.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
void polynom::processing(string & a,string &proces)
{
	char PreLetter=0;
	map <char,int> vars;
	int NumberOfVars;
	string search;
	for (int i = 0; i < a.size(); i++)
	{
		if (!(a[i] > 96 && a[i] < 123 || a[i] == 43 ||a[i]==45 || a[i] == 94 || a[i]>47 && a[i]<57 || a[i]==' ' ))
			throw 1;
		if (a[i] > 96 && a[i] < 123)
		{
			if (search.find(a[i]) == std::string::npos)
				search += a[i];
			else throw 1;
			if (PreLetter == 94)
				throw 1;
			proces += a[i];
		}
		if (a[i] > 47 && a[i] < 57)
		{
			string Number;
			while (a[i] > 47 && a[i] < 57)
			{
				Number += a[i];
				i++;
			}
			stringstream is;
			is << Number;
			int a;
			is >> a;
			if (a > MaxSize)
				throw 1;
			proces += Number;
			i--;
		}
		if (a[i] == ' ')
		{
			if (PreLetter == 43 || PreLetter == 45)
			{
				while (a[i] == ' ')
					i++;
				if (a[i] == 43 || a[i] == 45 || a[i] == 94)
					throw 1;
				i--;
		    }
			else
			{
				while (a[i] == ' ')
					i++;
				if (!(a[i] == 43 || a[i] == 45))
					throw 1;
			}
		}
		if (a[i] == 43 || a[i] == 45)
		{
			if (PreLetter == 43 || PreLetter == 45 || PreLetter ==94)
				throw 1;
			proces += ' ';
			proces += a[i];
			search.clear();
		}
		if (a[i] == 94)
		{
			if (!(PreLetter > 96 && PreLetter < 123))
				throw 1;
			proces += a[i];
		}
		PreLetter = a[i];
	}
}

void polynom::setPolynom(string & a)
{

	string proces;
	processing(a,proces);
	cout << proces;
}

polynom::polynom()
{
}


polynom::~polynom()
{
}
