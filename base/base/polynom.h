#pragma once
#include "Tlist.h"
class polynom
{
	class Monom
	{
		int c; // Коэффициент монома
		int Exp; // Число соответсвующее степеням монома 
	};
	int MaxSize; // Максимальная степень полинома
	Tlist <Monom> poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

