#pragma once
#include <iostream>
class frac
{
private:
	int NOD(int a, int b);
public:
	int numer;
	int denumer;
	frac& DIV();
	frac(const frac &a);
	frac(int n = 0, int d = 1);
	frac(int &a);
	bool operator == (const frac& a);
	bool operator != (const frac& a);
	bool operator > (const frac& a);
	bool operator < (const frac& a);
	bool operator <= (const frac& a);
	bool operator >= (const frac& a);
	frac& operator= (const frac &a);
	~frac();
	friend frac operator-(int a, const frac&b);
	friend frac operator-(const frac &a, int b);
	friend frac operator-(const frac &a, const frac &b);
	friend frac operator-=(const frac &a, int b);
	friend frac operator-=(const frac &a, const frac &b);

	friend frac operator+(int a, const frac&b);
	friend frac operator+(const frac &a, int b);
	friend frac operator+(const frac &a, const frac &b);
	friend frac operator+=(frac &a, int b);
	friend frac operator+=(frac &a, const frac &b);

	friend frac operator*(int a, const frac&b);
	friend frac operator*(const frac &a, int b);
	friend frac operator*(const frac &a, const frac &b);
	friend frac operator*=(frac &a, int b);
	friend frac operator*=(frac &a, const frac &b);

	friend frac operator/(int a, const frac&b);
	friend frac operator/(const frac &a, int b);
	friend frac operator/(const frac &a, const frac &b);
	friend frac operator/=(frac &a, int b);
	friend frac operator/=(frac &a, const frac &b);
	friend frac abs(frac &a);
	friend std::ostream &operator<<(std::ostream&, const frac &h);
	
};

