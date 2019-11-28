#pragma once
#include "Tlist.h"
#include <map>
class polynom
{
	class Monom
	{
	public:
		int c=1; // ����������� ������
		int Exp=0; // ����� �������������� �������� ������ 
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
		~Link() { delete pNext; }
	};
	int MaxSize=10; // ������������ ������� ��������
	map <string, int> vars;
	Link *poly;
	string input;
	void processing(string &a,string &proces);
public:	
	void setPolynom(string &a);
	polynom();
	~polynom();
};

