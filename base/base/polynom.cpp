#include "pch.h"
#include "polynom.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
void polynom::MergeOp(vector<polynom>& a, int b, int c)
{
	if (c - b == 1)
		return;
	if (c - b == 2)
	{
		a[b].Merge(a[b+1]);
		return;
	}
	MergeOp(a, b, b + (c - b) / 2);
	MergeOp(a,b+(c - b) / 2,c);
	a[b].Merge(a[b + (c - b) / 2]);
	return;
}
void polynom::processing(string & a, string &proces)
{
	char PreLetter = 0;
	string search;
	string s;
	for (int i = 0; i < a.size(); ++i)
	{
		if (!(a[i] >= 120 && a[i] <= 122 || a[i] == 43 || a[i] == 45 || a[i] == 94 || a[i]>47 && a[i]<57 || a[i] == ' ' || a[i]>=88 && a[i]<=90 || a[i]=='.'))
			throw 1;
		if (a[i] <= 122 && a[i] >= 120 || (a[i] >= 88 && a[i] <= 90))
		{
			if (a[i] >= 88 && a[i] <= 90)
				a[i] += 32;
			s = a[i];
			if (search.find(s) == std::string::npos)
				search += s;
			else throw 1;
			if (PreLetter == 94 || PreLetter== '.')
				throw 1;
			proces += a[i];
		}
		else
		{
			if (a[i] > 47 && a[i] < 57 || a[i] == '.')
			{
				string Number;
				while (a[i] > 47 && a[i] < 57 || a[i] == '.')
				{
					Number += a[i];
					i++;
				}
				stringstream is;
				is << Number;
				int a;
				is >> a;
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
						if (PreLetter == 43 || PreLetter == 45 || PreLetter == 94 || PreLetter == '.')
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
							//proces += a[i];
						}
					}
				}
			}
		}
		PreLetter = a[i];
	}
	if (PreLetter == '-' || PreLetter == '+' || PreLetter == '.' || PreLetter == '^' )
		throw 1;
}
polynom& polynom::Merge(polynom & a)
{
	Link *tmpa = a.poly->pNext;
	Link *tmp = poly;
	if (tmpa == tmpa->pNext)
		return *this;
	while (tmpa != a.poly)
	{
		while (tmp->pNext->data.Exp > tmpa->data.Exp)
			tmp = tmp->pNext;
		if (tmp->pNext->data.Exp == tmpa->data.Exp)
		{
			if (!(tmp->pNext->data.c == (-1)*tmpa->data.c))
			{
				tmp->pNext->data.c += tmpa->data.c;
			}
			else
			{
				Link *fordel = tmp->pNext;
				tmp->pNext = tmp->pNext->pNext;
				delete fordel;
			}
		}
		else
		{
			tmp->pNext = new Link({ tmpa->data.c,tmpa->data.Exp }, tmp->pNext);
			tmp = tmp->pNext;
		}
		Link *fordel = tmpa;
		tmpa = tmpa->pNext;
	}
	a.poly->pNext = a.poly;
	return *this;
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
polynom polynom::operator-()const
{
	polynom temp;
	Link *tmp =poly->pNext;
	while (tmp != poly)
	{
		tmp->pNext = new Link({-tmp->data.c,-tmp->data.Exp},temp.poly);
	}
	return temp;
}
polynom & polynom::operator-=(const polynom & a)
{
	*this += -a;
	return *this;
}
polynom polynom::operator-(const polynom & a)
{
	polynom b(a);
	return (b -= a);
}
polynom & polynom::operator*=(const polynom & a)
{
	if (a.poly->pNext == a.poly || poly->pNext == poly)
	{
		while (poly->pNext != poly)
		{
			Link *del = poly->pNext;
			poly->pNext = del->pNext;
			delete del;
		}
		return *this;
	}
	polynom h;
	h.poly = poly;
	Monom c(0, -1);
	poly = new Link(c);
	poly->pNext = poly;
	vector <polynom> Smth;
	Link *tmpa = a.poly->pNext;
	Link *tmpThis = h.poly->pNext;
	while (tmpThis != h.poly)
	{
		polynom b;
		Link *tmpb = b.poly;
		while (tmpa != a.poly)
		{
			tmpb->pNext = new Link({ tmpa->data.c * tmpThis->data.c, tmpThis->data.Exp + tmpa->data.Exp }, b.poly);
			tmpa = tmpa->pNext;
			tmpb = tmpb->pNext;
		}
		Smth.push_back(b);
		tmpThis = tmpThis->pNext;
		tmpa = tmpa->pNext;
	}
	MergeOp(Smth, 0, Smth.size());
	poly = Smth[0].poly;
	Smth[0].poly = new Link(c);
	Smth[0].poly->pNext = Smth[0].poly;
	return *this;
}
polynom& polynom::operator*=(double d)
{
	Link *temp = poly->pNext;
	while (temp != poly)
	{
		temp->data.c *= d;
		temp = temp->pNext;
	}
	return *this;
}
polynom polynom::operator*(double d)
{
	polynom b(*this);
	b *= d;
	return b;
}
polynom polynom::operator*(const polynom & a)
{
	/*vector <polynom> Smth;
	Link *tmpa = a.poly->pNext;
	Link *tmpThis = poly->pNext;
	if (tmpa == a.poly || tmpThis == poly)
	{
		return polynom();
	}
	while (tmpThis != poly)
	{
		polynom b;
		Link *tmpb = b.poly;
		while (tmpa != a.poly)
		{
			tmpb->pNext = new Link({tmpa->data.c * tmpThis->data.c, tmpThis->data.Exp + tmpa->data.Exp},b.poly);
			tmpa = tmpa->pNext;
			tmpb = tmpb->pNext;
		}
		Smth.push_back(b);
		tmpThis = tmpThis->pNext;
		tmpa = tmpa->pNext;
	}
	MergeOp(Smth, 0, Smth.size());
	return (Smth[0]);*/
	polynom c(*this);
	c *= a;
	return c;
}
polynom polynom::operator+(const polynom & a)
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
		if (tmp->pNext->data.Exp == tmpa->data.Exp)
		{
			if (!(tmp->pNext->data.c == (-1)*tmpa->data.c))
			{
				tmp->pNext->data.c += tmpa->data.c;
				tmp = tmp->pNext;
			}
			else
			{
				Link *fordel = tmp->pNext;
				tmp->pNext = tmp->pNext->pNext;
				delete fordel;
			}
		}
		else
		{
			tmp->pNext = new Link({ tmpa->data.c,tmpa->data.Exp }, tmp->pNext);
			tmp = tmp->pNext;
		}
		tmpa = tmpa->pNext;
	}
	return *this;
}

polynom & polynom::operator=(const polynom  &a)
{
	if (this == &a)
		return *this;
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

bool polynom::operator==(polynom &a)
{
	Link *temp = poly->pNext;
	Link *temp2 = a.poly->pNext;
	while (temp!=poly)
	{
		if (temp->data.c != temp2->data.c || temp->data.Exp != temp2->data.Exp)
			return 0;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return (temp == poly && temp2 == a.poly);
}

bool polynom::operator!=( polynom & a)
{
	return (!(*this == a));
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
	Link *temp = poly;
	for (stringstream is(proces); is >> word;)
	{
		Monom Next(word, MaxSize);
			Link *temp = poly->pNext;
			Link *PreTemp = poly;
			if (Next.c != 0)
			{
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
						size--;
					}
				}
				else
				{
					PreTemp->pNext = new Link(Next, temp);
					size++;
				}
			}
	}
}

polynom::polynom()
{
	size = 0;
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

void polynom::setsize(int c)
{
	if (c > 1000 || c < 1)
		throw 1;
	MaxSize = c;
}

ostream & operator<<(ostream & os,const polynom &h)
{
	polynom z(h);
	z.poly = z.poly->pNext;
	if (z.poly == z.poly->pNext)
		os << z.poly->data.c;
	bool IsFirst=1;
	vector<int> Exps;
	while (z.poly->data.Exp>=0)
	{
		Exps.clear();
		if (z.poly->data.c >= 0)
		{
			if (!IsFirst)
				os << "+";
		}
		else
			os << "-";
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
		if (abs(z.poly->data.c) !=1 || z.poly->data.Exp ==0)
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
			i++;
		}
		z.poly = z.poly->pNext;
	}
	return os;
}

polynom::Monom::Monom(string & a,int max):Monom()
{
	a += ' ';
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
				if (tmp.size() > 1)
				{
					c = atof(tmp.c_str());
					if (c == 0)
					{
						bool IsPoint=0;
						for (size_t k = 0; k < tmp.size(); k++)
						{
							if (tmp[k] == '.')
								if (IsPoint == 1)
									throw 1;
								else IsPoint = 1;
						}
					}
				}
					else
					{
						if (tmp == "+" || tmp == "-")
						{
							tmp.push_back('1');
							c = atof(tmp.c_str());
						}
						else
							if (tmp.size() == 0)
								c = 1;
							else
							{
								c = atof(tmp.c_str());
								if (c == 0)
									if (tmp != "0")
										throw 1;
							}
					}
					tmp.clear();
				WereAbr = 1;
			}
			else
			{
				auto ot = tmp.find('.');
				if (ot != string::npos)
					throw 1;
				int c = atoi(tmp.c_str());
				if (c >= max)
					throw 1;
				if (tmp.size()==0)
				Exp += pow(max, 122 - PreAbr);
				else
				{
					Exp += c*pow(max, 122 - PreAbr);
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

polynom::Monom::Monom(double a, long long int b):c(a),Exp(b)
{
}
