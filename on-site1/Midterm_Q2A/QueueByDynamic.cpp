#include "QueueByDynamic.h"

QueueByDynamic::QueueByDynamic(int capacity)
{
	// TODO: Initialize the dynamic array
	queue = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		queue[i] = 0;
	}
	currentCapacity = capacity;
	currentSize = 0;
}

void QueueByDynamic::push(int element)
{
	// TODO: Add an element at the end of the queue.
	//       If the queue is full, double the capacity of the queue first, and then push the element.
	if (currentSize < currentCapacity) {
		queue[currentSize] = element;
		currentSize++;
	}
	else {
		this->doubleCapacity();
		queue[currentSize] = element;
		currentSize++;
	}
}

void QueueByDynamic::pop()
{
	// TODO: Remove an element at the head of the queue.
	//       If there is no element in the queue, do nothing.
	if (currentSize == 0) return;
	else {
		for (int i = 1; i < currentCapacity; i++) {
			queue[i - 1] = queue[i];
		}
		queue[currentSize] = 0;
		currentSize--;
	}
}

int QueueByDynamic::front()
{
	// TODO: Return the value at the head of the queue.
	//       If there is no element in the queue, return -1.
	if (currentSize == 0) return -1;
	else {
		return queue[0];
	}
}

int QueueByDynamic::back()
{
	// TODO: Return the value at the end of the queue.
	//       If there is no element in the queue, return -1.
	if (currentSize == 0) return -1;
	else {
		return queue[currentSize - 1];
	}
}

void QueueByDynamic::doubleCapacity()
{
	// TODO: Double the capacity of the queue.
	QueueByDynamic temp(currentCapacity * 2);
	for (int i = 0; i < currentCapacity; i++) {
		temp.queue[i] = queue[i];
	}
	this->queue = new int[currentCapacity * 2];
	for (int i = 0; i < currentCapacity * 2; i++) {
		queue[i] = 0;
	}
	currentCapacity = currentCapacity * 2;
	for (int i = 0; i < currentCapacity * 2; i++) {
		queue[i] = temp.queue[i];
	}
}

int QueueByDynamic::capacity()
{
	// Return the capacity of the queue.
	return this->currentCapacity;
}

int QueueByDynamic::size()
{
	// Return the current size of the queue.
	return this->currentSize;
}

bool QueueByDynamic::empty()
{
	// Return true if the queue is empty. Otherwise return false.
	return this->currentSize == 0;
}

bool QueueByDynamic::full()
{
	// Return true if the queue is full. Otherwise return false.
	return this->currentSize == this->currentCapacity;
}

void QueueByDynamic::print()
{
	// Print the value in the queue from front to back.
	for (int i = 0; i < currentSize; i++)
		cout << this->queue[i] << " ";
	cout << endl;
}
