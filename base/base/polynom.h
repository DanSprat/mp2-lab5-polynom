#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
		int c; // Коэффициент монома
		int Exp; // Число соответсвующее степеням монома 
	};
	int MaxSize=100; // Максимальная степень полинома
	map <string, int> vars;
	Link  <Monom> *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

