#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <vector>

using namespace std;

class Vector
{
private:
	vector<int> vec;

public:
	Vector() = default;

	void heapSort();
	void heapify(int n, int i);
	void append(int element);
	void clear();

	void print() const;
};

#endif // !__VECTOR_H__