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
	string tmp;
	string PreAbr;
	processing(a, proces);
	for (stringstream is(proces); is >> word;)
	{
		Monom Next;
		bool WereAbr = 0;
		int k = 0;
		bool IsLastNumber=0;
		while (k < word.size())
		{
			int i = k;
			tmp.clear();
			while (!(word[i] > 96 && word[i] < 123 ))
			{
				if (word[i] == 94)
					i++;
				else 
				{
					tmp += word[i];
					i++;
					if (i >= word.size())
					{
						IsLastNumber = 1;
						break;
					}
				}
			}
			stringstream os;
			if (tmp == "-" || tmp == "+")
				tmp += "1";
			os << tmp;
			int a;
			os >> a;
			if (!WereAbr)
			{
				if (i != 0)
				{
					
					Next.c = a;
					
				}
			}
			else
			{
				if (i != 0) 
				{
					if (tmp.size() == 0)
						Next.Exp += pow(MaxSize, vars[PreAbr]);
					else
						Next.Exp += a * pow(MaxSize, vars[PreAbr]);
				}
				a = 0;
			}
			PreAbr = word[i];
			WereAbr = 1;
			if (i >= word.size()-1 && IsLastNumber==0)
			{
				Next.Exp += pow(MaxSize, vars[PreAbr]);
			}
			k = i;
			k++;
			
		}
		/*if (poly == nullptr)
		{
			poly = new Link(Next, poly);
			poly->pNext = poly;
		}
		else*/
		{
			Link *temp = poly->pNext;
			Link *PreTemp = poly;
			while (Next.Exp < temp->data.Exp)
			{	
					PreTemp = temp;
					temp = temp->pNext;	
		    }
			PreTemp->pNext = new Link(Next, temp);	
		}
		
	}
}

polynom::polynom()
{
	Monom a = { 0,-1 };
	poly = new Link(a);
	poly->pNext = poly;
}


polynom::~polynom()
{
}
