#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "LinkedList.h"

using namespace std;

#define OP_PUSH_BACK 'b'
#define OP_PUSH_FRONT 'f'
#define OP_INSERT 'i'
#define OP_REMOVE 'd'
#define OP_REVERSE 'r'
#define OP_SWAP 's'

void readFile(const char* filename)
{
	ifstream input(filename);
	stringstream ss;

	string line;

	char op;
	int value, index1, index2;

	while (getline(input, line)) {
		LinkedList list;

		ss.str("");
		ss.clear();
		ss << line;

		while (ss >> op) {
			switch (op) {
			case OP_PUSH_BACK:
				ss >> value;
				list.push_back(value);
				break;
			case OP_PUSH_FRONT:
				ss >> value;
				list.push_front(value);
				break;
			case OP_INSERT:
				ss >> index1 >> value;
				list.insert(index1, value);
				break;
			case OP_REMOVE:
				ss >> index1;
				list.remove(index1);
				break;
			case OP_REVERSE:
				list.reverse();
				break;
			case OP_SWAP:
				ss >> index1 >> index2;
				list.swap(index1, index2);
				break;
			default:
				break;
			}
		}

		list.print();
	}
}

int main() {
	// readFile("Sample_Input.txt");
	readFile("Hidden_Input.txt");

	return 0;
}