#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "BinarySearchTree.h"

using namespace std;

void readFile(const char* filename)
{
	ifstream input(filename);
	stringstream ss;

	string line;

	int numTestcase, value;

	for (input >> numTestcase, input.ignore(); numTestcase--;) {
		getline(input, line);
		getline(input, line);
		ss.str("");
		ss.clear();
		ss << line;

		BinarySearchTree tree;

		while (ss >> value) {
			TreeNode* node = new TreeNode(value);
			tree.insert(node);
		}
		// cout << "numTestcase: " << numTestcase << "\n";
		// cout << "line: " << line << "\n";
		TreeNode* root = tree.getRoot();

		cout << "preorder: ";
		tree.preorder(root);
		cout << endl;

		cout << "inorder: ";
		tree.inorder(root);
		cout << endl;

		cout << "postorder: ";
		tree.postorder(root);
		cout << endl;

		cout << endl;
	}
}

int main() {
	readFile("Sample_Input.txt");
	// readFile("Hidden_Input.txt");

	return 0;
}