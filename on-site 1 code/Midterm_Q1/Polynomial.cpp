#include "Polynomial.h"
Polynomial::Polynomial()
{
	// TODO: Initialize your data structure.
	for (int i = 0; i < MAXN; i++) {
		vec[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial& poly)
{
	// TODO: Implement the copy constructor.
	for (int i = 0; i < MAXN; i++) {
		vec[i] = poly.vec[i];
	}
}

void Polynomial::addTerm(int coef, int exp)
{
	// TODO: Add the term coef*x^exp to the polynomial.
	vec[exp] += coef;
}

void Polynomial::setCoef(int exp, int coef)
{
	// TODO: Set the coefficient of the term with exponent exp to coef.
	vec[exp] = coef;
}

int Polynomial::getCoef(int exp) const
{
	// TODO: Return the coefficient of the term with the exponent exp.
	//       If the exponent does not exist, return 0.
	return vec[exp];
}

Polynomial Polynomial::operator+(const Polynomial& other)
{
	// TODO: Add another polynomial instance to this instance.
	Polynomial poly1;
	poly1.vec[0] = 0;
	for (int i = 0; i < MAXN; i++) {
		poly1.vec[i] = vec[i] + other.vec[i];
	}
	return poly1;
}

Polynomial Polynomial::operator-(const Polynomial& other)
{
	// TODO: Subtract this instance by another polynomial instance.
	Polynomial poly1;
	for (int i = 0; i < MAXN; i++) {
		poly1.vec[i] = vec[i] - other.vec[i];
	}
	return poly1;
}

Polynomial Polynomial::operator*(const Polynomial& other)
{
	// TODO: Multiply this instance by another polynomial instance.
	Polynomial poly1;
	for (int i = 0; i < MAXN / 2; i++) {
		for (int j = 0; j < MAXN / 2; j++) {
			poly1.vec[i + j] += vec[i] * other.vec[j];
		}
	}
	return poly1;
}

Polynomial Polynomial::operator=(const Polynomial& other)
{
	// TODO: Assign another polynomial instance to this instance.
	for (int i = 0; i < MAXN; i++) {
		vec[i] = other.vec[i];
	}
	return (*this);
}

Polynomial Polynomial::differential() const
{
	// TODO: Do the differential on this instance and return it.
	Polynomial poly1;
	poly1.vec[0] = 0;
	for (int i = 1; i < MAXN; i++) {
		poly1.vec[i - 1] = vec[i] * i;
	}
	return poly1;
}

int Polynomial::solve(int value)
{
	// TODO: Evaluate the polynomial with a certain value.
	int result = 0;
	int pow = 1;
	for (int i = 0; i < MAXN; i++) {
		result = result + vec[i] * pow;
		pow *= value;
	}
	return result;
}

void Polynomial::print()
{
	// TODO: Print the polynomial.
	int first = true, term = 0;
	for (int i = MAXN - 1; i>= 0; i--) {
		if (vec[i] != 0) term++;
		if (vec[i] == 0) continue;
		if (first == false){
			if (i == 0 || (vec[i] != 1 && vec[i] != -1)){
				if (vec[i] > 0) {
					cout << "+ " << vec[i];
				}
				else {
					cout << "- " << -vec[i];
				}
			}
			else {
				if (vec[i] > 0) {
					cout << "+ ";
				}
				else {
					cout << "- ";
				}
			}
			if (i >= 2)
				cout << "x^" << i << " ";
			else if (i == 1) {
				cout << "x" << " ";
			}
		}
		else {
			if (i == 0 || (vec[i] != 1 && vec[i] != -1)) {
				cout << vec[i];
				if (i >= 2)
					cout << "x^" << i << " ";
				else if (i == 1) {
					cout << "x" << " ";
				}
			}

			else {
				if (i >= 2)
					cout << "x^" << i << " ";
				else if (i == 1) {
					cout << "x" << " ";
				}
			}
			first = false;
		}
		cout << " ";
	}
	if (term == 0) cout << "0";
	cout << "\n";
}
