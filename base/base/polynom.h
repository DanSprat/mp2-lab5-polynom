#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
		int c; // ����������� ������
		int Exp; // ����� �������������� �������� ������ 
	};
	int MaxSize=100; // ������������ ������� ��������
	map <string, int> vars;
	Link  <Monom> *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

