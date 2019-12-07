#include "pch.h"
#include "frac.h"
#include <iostream>
using namespace std;
frac & frac::DIV()
{
	int a = NOD(abs(numer), abs(denumer));
	numer /= a;
	denumer /= a;
	return *this;
}

frac::frac(const frac & a)
{
	numer = a.numer;
	denumer = a.denumer;
}

frac::frac(int n, int d)
{
	int p = NOD(n, d);
	numer = n/p;
	denumer = d/p;
}

frac::frac(int & a)
{
	numer = a;
	denumer = 1;
}

bool frac::operator==(const frac & a)
{
	frac b(*this);
	b = b-a;
	return (b.numer == 0);
}

bool frac::operator!=(const frac & a)
{
	return (!(*this ==a));
}
frac operator-=(frac & a, int b)
{
	a = a - b;
	a.DIV();
	return a;
}

bool frac::operator>(const frac & a)
{
	frac b(*this);
	b =b-a;
	return (b.numer > 0);
}

bool frac::operator<(const frac & a)
{
	frac b(*this);
	b = b - a;
	return (b.numer > 0);
}

bool frac::operator<=(const frac & a)
{
	frac b(*this);
	b = b - a;
	return (b.numer <= 0);
}

bool frac::operator>=(const frac & a)
{
	frac b(*this);
	b = b - a;
	return (b.numer >= 0);
}

frac & frac::operator=(const frac & a)
{
	numer = a.numer;
	denumer = a.denumer;
	return *this;
}

int frac::NOD(int a, int b)
{
	int c;
	if (a < b)
	{
		c = b;
		b=a;
		a = c;
	}
	if (b != 0)
		a = NOD(a % b, b);
	return a;
}



frac::~frac()
{
}

frac operator+(int a, const frac & b)
{
	frac temp(b);
	temp.numer += a * temp.denumer;
	temp.DIV();
	return temp;
}
frac operator+(const frac &a, int b)
{
	frac temp(a);
	temp.numer += b * temp.denumer;
	temp.DIV();
	return temp;
}

frac operator+(const frac & a, const frac & b)
{
	frac temp;
	temp.numer = a.numer * b.denumer + b.numer * a.denumer;
	temp.denumer = a.denumer*b.denumer * temp.NOD(a.denumer,b.denumer);
	temp.DIV();
	return temp;
}

frac operator+=(frac & a, int b)
{
	a = a + b;
	a.DIV();
	return a;
}

frac operator+=(frac & a, const frac & b)
{
	a = a + b;
	return a;
}

frac operator*(int a, const frac & b)
{
	frac temp(b);
	temp.numer *= a;
	temp.DIV();
	return temp;
}

frac operator*(const frac & a, int b)
{
	frac temp(a);
	temp.numer *= b;
	temp.DIV();
	return temp;
}

frac operator*(const frac & a, const frac & b)
{
	frac temp(a);
	temp.numer *= b.numer;
	temp.denumer *= b.denumer;
	temp.DIV();
	return temp;
}

frac operator*=(frac & a, int b)
{
	a.numer *= b;
	a.DIV();
	return a;
}

frac operator*=(frac & a, const frac & b)
{
	a.numer *= b.numer;
	a.denumer *= b.denumer;
	a.DIV();
	return a;
}



frac operator-(int a, const frac & b)
{
	frac temp(b);
	temp.numer -= a * temp.denumer;
	temp.DIV();
	return temp;
}
frac operator-(const frac &a, int b)
{
	frac temp(a);
	temp.numer -= b * temp.denumer;
	temp.DIV();
	return temp;
}

frac operator-(const frac & a, const frac & b)
{
	frac temp;
	temp.numer = a.numer * b.denumer - b.numer * a.denumer;
	temp.denumer = a.denumer*b.denumer * temp.NOD(a.denumer, b.denumer);
	temp.DIV();
	return temp;
}



frac operator-=(frac & a, const frac & b)
{
	a = a - b;
	return a;
}

frac operator/(int a, const frac & b)
{
	frac temp(b);
	temp.denumer *= a;
	temp.DIV();
	return temp;
}

frac operator/(const frac & a, int b)
{
	frac temp(a);
	temp.denumer *= b;
	temp.DIV();
	return temp;
}

frac operator/(const frac & a, const frac & b)
{
	frac temp(a);
	temp.numer *= b.denumer;
	temp.denumer *= b.numer;
	temp.DIV();
	return temp;
}

frac operator/=(frac & a, int b)
{
	a.denumer *= b;
	a.DIV();
	return a;
}
frac operator/=(frac & a, const frac & b)
{
	a.numer *= b.denumer;
	a.denumer *= b.numer;
	a.DIV();
	return a;
}

frac abs(frac & a)
{
	frac temp(a);
	temp.numer = abs(temp.numer);
	return a;
}

std::ostream & operator<<(std::ostream & os, const frac & h)

{
	cout << h.numer;
	if (h.denumer != 1)
		cout << "/" << h.denumer;
	return os;
}
