#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>

using namespace std;

const int MAXN = 500;

class Polynomial
{
protected:
	int vec[MAXN];
public:
	Polynomial();
	Polynomial(const Polynomial& poly);

	void addTerm(int coef, int exp);
	void setCoef(int exp, int coef);
	int getCoef(int exp) const;

	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(const Polynomial& other);
	Polynomial operator=(const Polynomial& other);

	Polynomial differential() const;

	int solve(int value);
	void print();
};

#endif // !__POLYNOMIAL_H__
#pragma once
