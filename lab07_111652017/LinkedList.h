#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
private:
	ListNode* head;

public:
	LinkedList() : head(nullptr) {}
	~LinkedList();

	void push_back(int x);
	void push_front(int x);
	void insert(int index, int x);
	void remove(int index);
	void reverse();
	void swap(int index1, int index2);
	void print();
};

#endif // !__LINKED_LIST_H__