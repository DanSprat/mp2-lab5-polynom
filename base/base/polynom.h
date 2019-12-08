#pragma once
#include "Tlist.h"
#include <map>
#include "frac.h"
class polynom
{
	class Monom
	{
	public:
		Monom(string &a,int max);
		Monom();
		Monom(const frac &a, long long int b);
		frac c = {1,1}; // Коэффициент монома
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
	int MaxSize=10; // Максимальная степень полинома
	int size ;
	Link *poly;
	string input;

	void processing(string &a,string &proces);
public:	
	polynom& MergeSort(Link *&PreStart, Link *&start, int pluspos);
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
