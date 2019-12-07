#include "pch.h"
#include "polynom.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
void polynom::processing(string & a, string &proces)
{
	char PreLetter = 0;
	string search;
	string s;
	for (int i = 0; i < a.size(); ++i)
	{
		if (!(a[i] >= 120 && a[i] <= 122 || a[i] == 43 || a[i] == 45 || a[i] == 94 || a[i]>47 && a[i]<57 || a[i] == ' '))
			throw 1;
		if (a[i] <= 122 && a[i] >= 120)
		{
			s = a[i];
			if (search.find(s) == std::string::npos)
				search += s;
			else throw 1;
			if (PreLetter == 94)
				throw 1;
			proces += a[i];
		}
		else
		{
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
			else
			{
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
						i--;
					}
				}
				else
				{
					if (a[i] == 43 || a[i] == 45)
					{
						if (PreLetter == 43 || PreLetter == 45 || PreLetter == 94)
							throw 1;
						proces += ' ';
						proces += a[i];
						search.clear();
					}
					else
					{
						if (a[i] == 94)
						{
							if (!(PreLetter >= 120 && PreLetter <= 122))
								throw 1;
							proces += a[i];
						}
					}
				}
			}
		}
		PreLetter = a[i];
	}
}
polynom polynom::DerivativeBy(char c)
{
	polynom temp;
	Link *help = poly->pNext;
	Link *current = temp.poly;
	while (help!=poly)
	{
		long long int p = help->data.Exp;
		int i = 120;
		long long int t = p;
		while (c>=i)
		{
			t = t / pow(MaxSize, 122 - i);
			i++;
		}
		int Coeff = t;
		if (t != 0)
		{
			current->pNext = new Link({ help->data.c*(Coeff),p- static_cast<int>(pow(MaxSize,122-c))}, temp.poly);
		}
		help = help->pNext;
		current = current->pNext;
	}
	return temp;
}
polynom polynom::IntegralBy(char c)
{
	polynom temp;
	Link *help = poly->pNext;
	Link *current = temp.poly;
	while (help != poly)
	{
		long long int p = help->data.Exp;
		int i = 120;
		long long int t = p;
		while (c >= i)
		{
			t = t / pow(MaxSize, 122 - i);
			i++;
		}
		int Coeff = t;
		if (t != MaxSize-1)
		{
			current->pNext = new Link({ {help->data.c / (Coeff + 1)},p + static_cast<int>(pow(MaxSize,122 - c)) }, temp.poly);
		}
		help = help->pNext;
		current = current->pNext;
	}
	return temp;
}
const polynom polynom::operator+(const polynom & a)
{
	polynom temp;
	Link *Max = this->poly->pNext;
	Link *Min = a.poly->pNext;
	Link *help;
	Link *Next=temp.poly;
	Monom b;
	if (Min->data.Exp > Max->data.Exp)
	{
		help = Min;
		Min = Max;
		Max = help;
	}
	while (Max->data.Exp != -1)
	{
		if (Max->data.Exp == Min->data.Exp)
		{
			if (Max->data.c != -(1)*Min->data.c)
			{
				b.c = Max->data.c + Min->data.c;
				b.Exp = Max->data.Exp;
				Next->pNext = new Link(b, temp.poly);
			}
			Max = Max->pNext;
			Min = Min->pNext;
		}
		else
		{
			while (Max->data.Exp > Min->data.Exp)
			{
				b.Exp = Max->data.Exp;
				b.c = Max->data.c;
				Next->pNext = new Link(b, temp.poly);
				Next = Next->pNext;
				Max = Max->pNext;
			}
			help = Min;
			Min = Max;
			Max = help;
		}
	}
	return temp;
}

polynom & polynom::operator+=(const polynom & a)
{
	Link *tmpa = a.poly->pNext;
	Link *tmp = poly;
	if (tmpa == tmpa->pNext)
		return *this;
	while (tmpa != a.poly)
	{
		while (tmp->pNext->data.Exp > tmpa->data.Exp)
			tmp = tmp->pNext;
		if (tmp->data.Exp == tmpa->data.Exp)
			if (!(tmp->data.c == (-1)*tmp->data.c))
				tmp->pNext = new Link({ tmpa->data.c + tmp->data.c,tmpa->data.Exp }, tmp->pNext);
		tmp->pNext = new Link({ tmpa->data.c,tmpa->data.Exp }, tmp->pNext);
		tmpa = tmpa->pNext;
		tmp = tmp->pNext;
	}
	return *this;
}

polynom & polynom::operator=(const polynom  a)
{
	Link *tmp = poly->pNext;
	while (tmp != poly)
	{
		poly->pNext = tmp->pNext;
		delete tmp;
		tmp = poly->pNext;
	}
	tmp = a.poly->pNext;
	Link *tmpnew = poly;
	while (tmp != a.poly)
	{
		tmpnew->pNext = new Link({ tmp->data.c,tmp->data.Exp }, poly);
		tmpnew = tmpnew->pNext;
		tmp = tmp->pNext;
	}
	return *this;
}

double polynom::Calculate()
{
	vector <double> Values;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите значени€ переменных: " << endl;
	for (char check = 120; check<123; check++)
	{
		cout << check << " - ";
		double c;
		cin >> c;
		Values.push_back(c);
	}
	double Summ=0;
	Link *temp = poly->pNext;
	while (temp!= poly)
	{
		int i = 0;
		double SumMon =1;
		int TExp = temp->data.Exp;
		int div = pow(MaxSize, 2);
		while (TExp > MaxSize-1)
		{
			SumMon *= pow(Values[i++],TExp/div);
			TExp = TExp % div;
			div /= MaxSize;
		}
		SumMon *= pow(Values[i++], TExp);
		Summ += SumMon;
		temp = temp->pNext;
	}	
	return Summ;
}

void polynom::setPolynom(string & a)
{
	string proces;
	string word;
	string tmp;
	char PreAbr;
	processing(a, proces);
	for (stringstream is(proces); is >> word;)
	{
		Monom Next(word, MaxSize);
		/*Monom Next;
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
					Next.c.numer = a;	
				}
			}
			else
			{
				if (i != 0) 
				{
					if (tmp.size() == 0)
						Next.Exp += pow(MaxSize,122 - PreAbr );
					else
						Next.Exp += a * pow(MaxSize, 122-PreAbr);
				}
				a = 0;
			}
			PreAbr = word[i];
			WereAbr = 1;
			if (i >= word.size()-1 && IsLastNumber==0)
			{
				Next.Exp += pow(MaxSize, 122-PreAbr);
			}
			k = i;
			k++;
			
		}*/
			Link *temp = poly->pNext;
			Link *PreTemp = poly;
			while (Next.Exp < temp->data.Exp)
			{	
					PreTemp = temp;
					temp = temp->pNext;	
		    }
			if (Next.Exp == temp->data.Exp)
			{
				temp->data.c += Next.c;
				if (temp->data.c == 0)
				{
					PreTemp->pNext = temp->pNext;
					delete temp;
				}
			}
			else
			PreTemp->pNext = new Link(Next, temp);	
	}
}

polynom::polynom()
{
	Monom a = { 0,-1 };
	poly = new Link(a);
	poly->pNext = poly;
}

polynom::polynom(const polynom & a)
{
	Monom b = {0,-1};
	poly = new Link(b);
	poly->pNext = poly;
	Link *tmp = a.poly->pNext;
	Link *help = poly->pNext;
	while (tmp != a.poly)
	{
		help->pNext = new Link({ tmp->data.c,tmp->data.Exp }, poly);
		help = help->pNext;
		tmp = tmp->pNext;
	}
}


polynom::~polynom()
{
	Link *tmp = poly->pNext;
	while (tmp!=poly)
	{
		poly->pNext = tmp->pNext;
		delete tmp;
		tmp = poly->pNext;
	}
	delete poly;
}

ostream & operator<<(ostream & os,const polynom &h)
{
	polynom z(h);
	z.poly = z.poly->pNext;
	bool IsFirst=1;
	vector<int> Exps;
	while (z.poly->data.Exp>0)
	{
		Exps.clear();
		if (z.poly->data.Exp > 0)
		{
			if (!IsFirst)
				cout << "+";
		}
		else
			cout << "-";
		IsFirst = 0;
		long long int temp = z.poly->data.Exp;
		int i = 2;
		while (i!=0)
		{
			Exps.push_back(temp / static_cast<int>(pow(h.MaxSize, i)));
			temp = temp % static_cast<int>(pow(h.MaxSize, i));
			i--;
		}
		Exps.push_back(temp);
		frac g(1);
		if (z.poly->data.c != g)
			cout << abs(z.poly->data.c);
		i = 0;
		while (i<3)
		{
			char c = 120 + i;
			if (Exps[i] != 0)
			{
				if (Exps[i] != 1)
					cout << c << Exps[i];
				else
				{
					cout << c;
				}
				
			}
			/*cout << c;
			if (Exps[i] != 1)
				cout << Exps[i++];
			else i++;*/
			i++;
		}
		z.poly = z.poly->pNext;
	}
	return os;
}

polynom::Monom::Monom(string & a,int max):Monom()
{
	a += ' ';
	bool WereSlash;
	char PreAbr=0;
	char PreLetter = 0;
	bool WereAbr = 0;
	bool IsPreAbr = 0;
	string tmp;
	for (auto it = a.begin(); it != a.end(); it++)
	{
		if (!(*it >=120 && *it <=122 || *it>=88 && *it<=90 || *it =='/'  ||*it ==' '))
		{
			tmp += *it;
			IsPreAbr = 0;
		}
		else
		{
			if (!WereAbr)
			{
				if (tmp.find('/') == string::npos)
				{
					if (tmp.size() != 0)
						c = atoi(tmp.c_str());
					else
						c = 1;
					tmp.clear();
				}
				else
				{
					auto ot = tmp.find('/');
					c = { atoi(tmp.substr(0,ot).c_str()),atoi(tmp.substr(ot+1,tmp.size()).c_str()) };
				}
				WereAbr = 1;
			}
			else
			{
				if (tmp.size()==0)
				Exp += pow(max, 122 - PreAbr);
				else
				{
					Exp += atoi(tmp.c_str())*pow(max, 122 - PreAbr);
					tmp.clear();
				}
			}
			PreAbr = *it;
		}
	}
}

polynom::Monom::Monom():c(0),Exp(0)
{
}

polynom::Monom::Monom(const frac &a, long long int b):c(a),Exp(b)
{
}
