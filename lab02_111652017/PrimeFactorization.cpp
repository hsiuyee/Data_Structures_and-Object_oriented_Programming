#include "PrimeFactorization.h"
#include <iostream>

using namespace std;

void PrimeFactorization::Get_Prime_Factorization()
{
	// TODO: Prime factorization num1 and num2, push result to the num1_factor and num2_factor.
	num1_factor.clear();
	num2_factor.clear();

	for (int i = 2; i * i <= num1; i++) {
		while (num1 % i ==0) {
			num1_factor.push_back(i);
			num1 /= i;
		}
	}
	if (num1 != 1) {
		num1_factor.push_back(num1);
	}

	for (int i = 2; i * i <= num2; i++) {
		while (num2 % i ==0) {
			num2_factor.push_back(i);
			num2 /= i;
		}
	}
	if (num2 != 1) {
		num2_factor.push_back(num2);
	}
}

void PrimeFactorization::Print_Prime_Factorization()
{
	int ptr1 = 0, ptr2 = 0;

	cout << "num1_prime_factor: ";
	for (int i = 0; i < (int)num1_factor.size(); i++) {
		int cnt = 1;
		int now = i + 1;
		while (now < (int)num1_factor.size() and num1_factor[now] == num1_factor[i]) {
			cnt++;
			now++;
		}
		if (cnt == 1) {
			cout << num1_factor[i];
		}
		else {
			cout <<  num1_factor[i] << "^" << cnt;
		}
		if(now != (int)num1_factor.size()) {
			cout << " * ";
		}
		i = now - 1;
	}
	cout << endl;

	cout << "num2_prime_factor: ";
	for (int i = 0; i < (int)num2_factor.size(); i++) {
		int cnt = 1;
		int now = i + 1;
		while (now < (int)num2_factor.size() and num2_factor[now] == num2_factor[i]) {
			cnt++;
			now++;
		}
		if (cnt == 1) {
			cout << num2_factor[i];
		}
		else {
			cout <<  num2_factor[i] << "^" << cnt;
		}
		if (now != (int)num2_factor.size()) {
			cout << " * ";
		}
		i = now - 1;
	}
	cout << endl;
}

void PrimeFactorization::Print_GCD_Factorization()
{
	cout << "GCD_prime_factor: ";
	int cnt_total_prime = 0;
	int ptr1 = 0, ptr2 = 0;
	bool first = 1;
	// cout << "echo\n";
	// for (int i = 0; i < (int)num1_factor.size(); i++) cout << num1_factor[i] << " ";
	// cout << endl;
	// cout << "echo\n";
	// for (int i = 0; i < (int)num2_factor.size(); i++) cout << num2_factor[i] << " ";
	// cout << endl;
	while (ptr1 < (int)num1_factor.size() and ptr2 < (int)num2_factor.size()) {
		if (num1_factor[ptr1] < num2_factor[ptr2]) {
			ptr1++;
			// cout << "\n";
			// cout << "ptr1: " << ptr1 << endl;
			// cout << "ptr2: " << ptr2 << endl;
			// cout << "num1_factor[ptr1]: " << num1_factor[ptr1] << endl;
			// cout << "num2_factor[ptr2]: " << num2_factor[ptr2] << endl;
			// cout << "\n";
		}
		else if(num1_factor[ptr1] > num2_factor[ptr2]) {
			ptr2++;
			// cout << "\n";
			// cout << "ptr1: " << ptr1 << endl;
			// cout << "ptr2: " << ptr2 << endl;
			// cout << "num1_factor[ptr1]: " << num1_factor[ptr1] << endl;
			// cout << "num2_factor[ptr2]: " << num2_factor[ptr2] << endl;
			// cout << "\n";
		}
		else {
			cnt_total_prime++;
			int cnt = 0;
			int prime = num1_factor[ptr1];
			while (ptr1 < (int)num1_factor.size() and ptr2 < (int)num2_factor.size()
				   and num1_factor[ptr1] == num2_factor[ptr2] and num1_factor[ptr1] == prime) {
					ptr1++;
					ptr2++;
					cnt++;
					// cout << "\n";
					// cout << "ptr1: " << ptr1 << endl;
					// cout << "ptr2: " << ptr2 << endl;
					// cout << "num1_factor[ptr1]: " << num1_factor[ptr1] << endl;
					// cout << "num2_factor[ptr2]: " << num2_factor[ptr2] << endl;
					// cout << "\n";
			}
			if (first) {
				first = 0;
			}
			else {
				cout << " * ";
			}
			if (cnt != 1) cout << prime << "^" << cnt;
			else cout << prime;
		}
	}
	if (cnt_total_prime == 0) {
		cout << 1;
	}
	cout << endl;
}