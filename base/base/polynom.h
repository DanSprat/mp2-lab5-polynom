#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
	    double c=1; // Коэффициент монома
		long long int Exp=0; // Число соответсвующее степеням монома 
	};
	class Link
	{
	public:
		Link * pNext;
		Monom data;
		Link(Monom data, Link * pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
		~Link() {  }
	};
	int MaxSize=5; // Максимальная степень полинома
	Link *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	polynom();
	polynom(const polynom &a);
	~polynom();
	polynom DerivativeBy(char c);
	polynom IntegralBy(char c);
	const polynom operator+ (const polynom &a);
	polynom& operator+=(const polynom &a); 
	polynom& operator= (const polynom a);
	double Calculate();
	void setPolynom(string &a);
	friend ostream& operator<<(ostream &os,const polynom &h);
};
