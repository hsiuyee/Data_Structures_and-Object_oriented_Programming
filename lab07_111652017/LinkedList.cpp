#include "LinkedList.h"

LinkedList::~LinkedList()
{
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::push_back(int x)
{
	// TODO: Insert a node to the end of the linked list, the node's value is x.
	if (!head) {
		head = new ListNode(x);
		return;
	}
	ListNode* temp = new ListNode(x);
	ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
	current->next = temp;
}

void LinkedList::push_front(int x)
{
	// Insert a node to the front of the linked list, the node's value is x.

	if (!head) {
		head = new ListNode(x);
		return;
	}
	ListNode* temp = new ListNode(x);

	temp->next = head;
	head = temp;
}

void LinkedList::insert(int index, int x)
{
	// TODO: Insert a node to the linked list at position "index", the node's value is x. 
	// 		 The index of the first node in the linked list is 0.
	if (!head) {
		if(index == 0)
		head = new ListNode(x);
		return;
	}
	if(index == 0){
		push_front(x);
		return;
	}
	ListNode* current = head;
    int cnt = 0;
    while(current->next != NULL && cnt < index - 1){
        current = current->next;
        cnt++;
    }
	if(cnt != index - 1) {
        return;
    }
	ListNode* temp = new ListNode(x);
    temp->next = current->next;
    current->next = temp;
	// cur -> (cur->next)
	// cur -> temp -> (cur->next)
}

void LinkedList::remove(int index)
{
	// TODO: Remove the node with index "index" in the linked list.
	if (!head) {
		return;
	}
	if(index == 0){
		head = head->next;
		return;
	}
	ListNode *prev = head;
	int cnt = 0;
    while(prev->next != NULL && cnt < index - 1){
        prev = prev->next;
        cnt++;
    }
	if(cnt != index - 1 || prev->next == NULL) return;
	prev->next = prev->next->next;
	// prev -> (prev->next) -> (prev->next->next)
}

void LinkedList::reverse()
{
	// // TODO: Reverse the linked list.
	if(!head || head->next == NULL) return;
	ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr; //      curr->next
							  // prev curr  
							  //      prev curr next

    while (curr) {
        next = curr->next;  
        curr->next = prev; 
        prev = curr;        
        curr = next;        
    }
	head = prev;
}

void LinkedList::swap(int index1, int index2)
{
	if (index1 == index2) return;
	if(!head || head->next == NULL) return;
	// TODO: Swap two nodes in the linked list
	ListNode *cur1 = head;
    for(int i = 0; i < index1 && cur1 != NULL; i++){
        cur1 = cur1->next;
    }

    ListNode *cur2 = head;
    for(int i = 0; i < index2 && cur2 != NULL; i++){
        cur2 = cur2->next;
    }
	if(cur1 == NULL || cur2 == NULL) return;
	int temp_val = cur1->val;
    cur1->val = cur2->val;
    cur2->val = temp_val;
}

void LinkedList::print()
{
	// TODO: Print all the elements in the linked list in order.
	if(head == NULL){
		cout << "[]\n";
	}
	else if(head->next == NULL){
		cout << "[" << head->val << "]";
	}
	else{
		cout << "[";
		ListNode *current = head; 
		while(current->next->next != NULL){
			cout << current->val << " ";
			current = current->next;
		}
		cout << current->val << " ";
		cout << current->next->val << "]\n";
	}
}
