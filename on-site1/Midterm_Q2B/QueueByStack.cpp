#include "QueueByStack.h"

void QueueByStack::push(int element)
{
	// TODO: Add an element at the end of the queue.
	sta.push(element);
}

void QueueByStack::pop()
{
	// TODO: Remove an element at the head of the queue.
	//       If there is no element in the queue, do nothing.
	if (sta.size() < 1) return;
	stack<int> temp;
	while (sta.size()) {
		int x = sta.top();
		sta.pop();
		temp.push(x);
	}
	temp.pop();
	while (temp.size()) {
		int x = temp.top();
		temp.pop();
		sta.push(x);

	}
}

int QueueByStack::front()
{
	// TODO: Return the value at the head of the queue.
	//       If there is no element in the queue, return -1.
	if (sta.size() == 0) return -1;
	stack<int> temp;
	while (sta.size()) {
		int x = sta.top();
		sta.pop();
		temp.push(x);
	}
	int y = temp.top();
	while (temp.size()) {
		int x = temp.top();
		temp.pop();
		sta.push(x);
	}
	return y;
}

void QueueByStack::print()
{
	// TODO: Print the value in the queue from front to back.
	if (sta.empty()) {
		cout << "\n";
		return;
	}
	stack<int> temp;
	while (sta.size()) {
		int x = sta.top();
		sta.pop();
		temp.push(x);
	}
	while (temp.size()) {
		int x = temp.top();
		temp.pop();
		cout << x << " ";
		sta.push(x);
	}
	cout << "\n";
}
