#include "BinarySearchTree.h"

TreeNode* BinarySearchTree::getRoot()
{
	return this->root;
}

void BinarySearchTree::insert(TreeNode* node)
{
	// TODO: Insert the node to the binary search tree
	// root->left < root < root->right
	// cout << "insert: " << node->val << "\n";
	if(this->root == nullptr){
		root = node;
		return;
	}
	TreeNode* cur = root;
	while(1){
		if(cur->left == nullptr and node->val < cur->val){
			cur->left = node;
			break;
		}
		else if(cur->right == nullptr and node->val > cur->val){
			cur->right = node;
			break;
		}
		else if(node->val < cur->val){
			cur = cur->left;
		}
		else if(node->val > cur->val){
			cur = cur->right;
		}
	}
}

void BinarySearchTree::preorder(TreeNode* root)
{
	// TODO: Use the preorder method to traverse the binary search tree
	if(root == nullptr) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void BinarySearchTree::inorder(TreeNode* root)
{
	// TODO: Use the inorder method to traverse the binary search tree
	if(root == nullptr) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void BinarySearchTree::postorder(TreeNode* root)
{
	// TODO: Use the postorder method to traverse the binary search tree
	if(root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}