#include <iostream>

#include "PrimeFactorization.h"

using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD_Factorization();

		cout << endl;
	}

	return 0;
}