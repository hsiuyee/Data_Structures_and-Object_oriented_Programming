#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
	TreeNode* root;

public:
	BinarySearchTree() : root(nullptr) {}

	TreeNode* getRoot();

	void insert(TreeNode* node);
	void preorder(TreeNode* root);
	void inorder(TreeNode* root);
	void postorder(TreeNode* root);
};

#endif // !__BINARY_SEARCH_TREE_H__