#pragma once
#ifndef __QUEUE_BY_DYNAMIC_H__
#define __QUEUE_BY_DYNAMIC_H__

#include <iostream>

using namespace std;

class QueueByDynamic
{
private:
    int currentCapacity;
    int currentSize;
    int* queue;

public:
    QueueByDynamic(int capacity);

    void push(int element);
    void pop();
    int front();
    int back();
    void doubleCapacity();

    int capacity();
    int size();
    bool empty();
    bool full();
    void print();
};

#endif // !__QUEUE_BY_DYNAMIC_H__
