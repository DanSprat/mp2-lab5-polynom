#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
		int c=0; // ����������� ������
		int Exp=0; // ����� �������������� �������� ������ 
	};
	int MaxSize=10; // ������������ ������� ��������
	map <string, int> vars;
	Link  <Monom> *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

