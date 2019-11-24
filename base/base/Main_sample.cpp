// base.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "polynom.h"
#include <string>
using namespace std;
void foo( int a)
{
	a = 5;
}
using namespace std;
int main()
{
	string a;
	polynom h;
	getline(cin, a);
	h.setPolynom(a);
}

