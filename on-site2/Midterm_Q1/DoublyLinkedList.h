#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <iostream>

using namespace std;

struct ListNode
{
	int element;			// The element stored in this node
	ListNode* prev;			// Pointer to the previous node
	ListNode* next;			// Pointer to the next node

	ListNode() : element(0), prev(nullptr), next(nullptr) {}
	ListNode(int _element) : element(_element), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
	ListNode* head;			// Pointer to the head node of the linked list
	ListNode* tail;			// Pointer to the tail node of the linked list

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	~DoublyLinkedList();

	void append(int element);
	void append(const DoublyLinkedList& list);
	void prepend(int element);
	void prepend(const DoublyLinkedList& list);

	int getElement(int index);
	int indexOf(int element);

	void insert(int index, int element);
	void remove(int element);

	void reverse();

	void printForward();
	void printBackward();
	ListNode* getHead();
};

#endif // !__DOUBLY_LINKED_LIST_H__