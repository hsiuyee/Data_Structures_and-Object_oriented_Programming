#ifndef __PrimeFactorization_H__
#define __PrimeFactorization_H__

#include <vector>

class PrimeFactorization
{
private:
	int num1, num2;
	std::vector<int> num1_factor, num2_factor;

public:
	PrimeFactorization(int num1, int num2) : num1(num1), num2(num2) {}

	void Get_Prime_Factorization();
	void Print_Prime_Factorization();
	void Print_GCD_Factorization();
};

#endif // __PrimeFactorization_H__
