#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
		int c=0; // Коэффициент монома
		int Exp=0; // Число соответсвующее степеням монома 
	};
	int MaxSize=10; // Максимальная степень полинома
	map <string, int> vars;
	Link  <Monom> *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

