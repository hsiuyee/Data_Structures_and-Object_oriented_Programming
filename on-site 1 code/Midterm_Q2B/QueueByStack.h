#ifndef __QUEUE_BY_STACK_H__
#define __QUEUE_BY_STACK_H__

#include <iostream>
#include <stack>

using namespace std;

class QueueByStack
{
private:
    stack<int> sta;
public:
    QueueByStack() = default;

    void push(int element);
    void pop();
    int front();
    void print();
};

#endif // !__QUEUE_BY_STACK_H__