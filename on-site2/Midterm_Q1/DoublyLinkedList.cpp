#include "DoublyLinkedList.h"

// Marks: [1 point]
DoublyLinkedList::~DoublyLinkedList()
{
	// TODO: Delete all allocated memory
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

// Marks: [5 points]
void DoublyLinkedList::append(int element)
{
	// TODO: Append a node to the end of the doubly linked list, the value of the node is 'element'.
	if (!head) {
		head = new ListNode(element);
		return;
	}
	ListNode* temp = new ListNode(element);
	ListNode* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = temp;
	temp->prev = current;
	temp->next = nullptr;
	tail = temp;
}

ListNode* DoublyLinkedList::getHead() {
	return this->head;
}

// Marks: [5 points]
void DoublyLinkedList::append(const DoublyLinkedList& list)
{
	// TODO: Append another list to the end of the doubly linked list.
	//
	// NOTE: When appending one doubly linked list to another, ensure that 
	//       each element is copied individually instead of directly concatenating the lists. 
	//       This means that if an element originally from the second list is removed from the first list, 
	//       it will only affect the first list, leaving the original element in the second list intact.
	// 
	//DoublyLinkedList dk = list;
	//ListNode** tmp = dk->getHead();
}

// Marks: [5 points]
void DoublyLinkedList::prepend(int element)
{
	// TODO: Prepend a node to the front of the doubly linked list, the value of the node is 'element'.
	if (!tail) {
		head = new ListNode(element);
		return;
	}
	ListNode* temp = new ListNode(element);
	ListNode* current = tail;
	while (current->next != NULL) {
		current = current->next;
	}
	current->prev = temp;
	temp->next = current;
	temp->prev = nullptr;
	head = temp;
}

// Marks: [5 points]
void DoublyLinkedList::prepend(const DoublyLinkedList& list)
{
	// TODO: Prepend another list to the front of the doubly linked list.
	//
	// NOTE: When appending one doubly linked list to another, ensure that 
	//       each element is copied individually instead of directly concatenating the lists. 
	//       This means that if an element originally from the second list is removed from the first list, 
	//       it will only affect the first list, leaving the original element in the second list intact.
}

// Marks: [5 points]
int DoublyLinkedList::getElement(int index)
{
	// TODO: Return the value at index 'index' in the doubly linked list.
	//       The valid index range is [0, n), where n is the size of the doubly linked list.
	//       If the index is out of the range, return -1.
	if (!head) {
		return -1;
	}
	ListNode* current = head;
	int cnt = 0;
	int find = -1;
	while (current->next != NULL) {
		if (cnt == index) {
			find = current->element;
			break;
		}
		current = current->next;
		cnt++;
	}
	if (find) return find;
	else return -1;
}

// Marks: [5 points]
int DoublyLinkedList::indexOf(int element)
{
	// TODO: Return the index of 'element' in the doubly linked list.
	//       If the element exists more than once, return the index of the first one.
	//       If the element is not in the doubly linked list, return -1.
	if (!head) {
		return -1;
	}
	ListNode* current = head;
	int rev = 0;
	bool find = false;
	while (current->next != NULL) {
		if (current->element == element) {
			find = true;
			break;
		}
		current = current->next;
		rev++;
	}
	if (find) return rev;
	else return -1;
}

// Marks: [5 points]
void DoublyLinkedList::insert(int index, int element)
{
	// TODO: Insert a node to the doubly linked list at position 'index', the value of the node is 'element'.
	//       The valid index range is [0, n), where n is the size of the doubly linked list.
	//       If the index is out of the range, do nothing.
	if (!head) {
		if (index == 0)
			head = new ListNode(element);
		return;
	}
	if (index == 0) {
		append(element);
		return;
	}
	ListNode* current = head;
	int cnt = 0;
	while (current->next != NULL && cnt < index - 1) {
		current = current->next;
		cnt++;
	}
	if (cnt != index - 1) {
		return;
	}
}

// Marks: [5 points]
void DoublyLinkedList::remove(int element)
{
	// TODO: Remove all the nodes with the same 'element' in the doubly linked list.
	//       If the element is not in the doubly linked list, do nothing.
	//if (indexOf(element) == -1) return;
	//while (head != nullptr && head->element != element) {
	//	head = head->next;
	//	head->prev = nullptr;
	//	if (head == nullptr) return;
	//}
	//if (!head) {
	//	return;
	//}
	//int flag = 0;
	//ListNode* p = head->prev;
	//ListNode* cur = head;
	//int cnt = 0;
	//while (cur->next != NULL) {
	//	if (cur->element == element) {
	//		//cur = cur->next;
	//		/*p->next = nullptr;*/
	//		flag = 1;
	//	}
	//	else {
	//		if (flag) {
	//			//p->next = cur;
	//			//cur->prev = p;
	//			flag = 0;
	//			////cur = cur->next;
	//		}
	//		else {
	//			p = p->next;
	//			cur = cur->next;
	//		}
	//	}
	//}
	//if (flag) tail = p;
}

// Marks: [3 points]
void DoublyLinkedList::reverse()
{
	// TODO: Reverse the doubly linked list.
	//
	// NOTE: You must reverse the pointers of the nodes instead of 
	//       swapping the elements of the nodes or you will get 0 score.
	//if (!head || head->next == NULL) return;
	//ListNode* p = nullptr;
	//ListNode* curr = head;
	//ListNode* n = nullptr; //      curr->next
							  // prev curr  
							  //      prev curr next

	//while (curr) {
		//n = curr->next;
		//curr->next = p;
		//p = curr;
		//curr = n;
	//}
	//tail = head;
	//head = p;

	//p = nullptr;
	//curr = head;
	//n = nullptr; //      curr->next
							  // prev curr  
							  //      prev curr next

	//while (curr) {
		//n = curr->next;
		//curr->prev = p;
		//p = curr;
		//curr = n;
	///}
	//tail = p;
}

// Marks: [3 points]
void DoublyLinkedList::printForward()
{
	// TODO: Print all the elements in the doubly linked list from head to tail.
	if (head == NULL) {
		cout << "[]\n";
	}
	else if (head->next == NULL) {
		cout << "[" << head->element << "]";
	}
	else {
		cout << "[";
		ListNode* current = head;
		while (current->next->next != NULL) {
			cout << current->element << " ";
			current = current->next;
		}
		cout << current->element << " ";
		cout << current->next->element << "]\n";
	}
}

// Marks: [3 points]
void DoublyLinkedList::printBackward()
{
	// TODO: Print all the elements in the doubly linked list from tail to head.
	if (tail == NULL) {
		cout << "[]\n";
	}
	else if (tail == NULL) {
		cout << "[" << tail->element << "]";
	}
	else {
		cout << "[";
		ListNode* current = tail;
		while (current->prev->prev != NULL) {
			cout << current->element << " ";
			current = current->prev;
		}
		cout << current->element << " ";
		cout << current->prev->element << "]\n";
	}
}