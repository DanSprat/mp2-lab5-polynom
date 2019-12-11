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
	setlocale(LC_ALL, "Russian");
	string a,b;
	polynom h, g,j;
	cout << "Введите первый полином:";
	getline(cin, a);
	h.setPolynom(a);
	cout << "Введите второй полином:";
    getline(cin, b);
	g.setPolynom(b);
	cout << "Polynoms: " << endl;
	cout << h << endl;
	cout << g << endl;
	h == g;
	cout << "Сумма полиномов " << g-h << endl;
	cout << "Интеграл по x первого полинома " << h.IntegralBy('x')<<endl;
	cout << "Производная по x второго полинома " << g.DerivativeBy('x') << endl;
	cout << "Произведение полиномов " << h*g << endl;
	double d = h.Calculate();
	cout << "Результат: " << d<<endl;
}

