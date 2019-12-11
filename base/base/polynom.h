#pragma once
#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class polynom
{
	class Monom
	{
	public:
		Monom(string &a,int max);
		Monom();
		Monom(double a, long long int b);
		double c; // Коэффициент монома
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
	void MergeOp(vector<polynom> &a,int b,int c);
	void processing(string &a,string &proces);
	polynom& Merge(polynom &a);
public:	
	polynom();
	polynom(const polynom &a);
	~polynom();
	polynom DerivativeBy(char c);
	polynom IntegralBy(char c);
	polynom operator-() const;
	polynom& operator-=(const polynom &a);
	polynom operator-(const polynom &a);
	polynom& operator *=(const polynom &a);
	polynom& operator *= (double b);
	polynom operator* (double b);
	polynom operator* (const polynom &a);
	polynom operator+ (const polynom &a);
	polynom& operator+=(const polynom &a); 
	polynom& operator= (const polynom a);
	double Calculate();
	void setPolynom(string &a);
	friend ostream& operator<<(ostream &os,const polynom &h);
};
