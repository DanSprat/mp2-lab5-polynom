#include "pch.h"
#include "polynom.h"
#include <vector>

#include <string>
#include <iostream>
#include <sstream>
using namespace std;
void polynom::processing(string & a,string &proces)
{
	char PreLetter=0;
	map <string, int> ::iterator it;
	string search;
	string s;
	for (int i = 0; i < a.size(); i++)
	{
		if (!(a[i] > 96 && a[i] < 123 || a[i] == 43 ||a[i]==45 || a[i] == 94 || a[i]>47 && a[i]<57 || a[i]==' ' ))
			throw 1;
		if (a[i] > 96 && a[i] < 123)
		{
			s = a[i];
			if (search.find(s) == std::string::npos)
				search += s;
			else throw 1;
			it = vars.find(s);
			if (it == vars.end())
				vars.insert(make_pair(s, vars.size()));
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
	string word;
	string Number;
	processing(a, proces);
	for (stringstream is(proces); is >> word;)
	{
		bool IsPreWordAbr=0;
		string PreAbr=0;
		string PreWord=0;
		Monom Next;
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] > 96 && word[i] < 123)
			{
				if (IsPreWordAbr)
					Next.Exp +=pow(MaxSize,vars[PreWord]);
				else
				{
					stringstream os;
					os << PreWord;
					int a;
					os >> a;
					Next.Exp += (a*pow(MaxSize,vars[PreAbr]));
					
				}
				PreWord = word[i];
				PreAbr = word[i];
			}
		}
	}
	cout << proces;
}

polynom::polynom()
{
}


polynom::~polynom()
{
}
