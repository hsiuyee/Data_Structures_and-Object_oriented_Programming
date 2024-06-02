#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Vector.h"

using namespace std;

void readFile(const char* filename)
{
	ifstream input(filename);
	stringstream ss;

	string line;

	Vector vec;
	int element;

	while (getline(input, line)) {
		vec.clear();

		ss.str("");
		ss.clear();
		ss << line;

		while (ss >> element) {
			vec.append(element);
		}

		vec.heapSort();
		vec.print();
	}
}

int main()
{
	readFile("Sample_Input.txt");
	// readFile("Hidden_Input.txt");

	return 0;
}