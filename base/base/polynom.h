#pragma once
#include "Tlist.h"
class polynom
{
	class Monom
	{
		int c; // ����������� ������
		int Exp; // ����� �������������� �������� ������ 
	};
	int MaxSize; // ������������ ������� ��������
	Tlist <Monom> poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

