#include <iostream>
#include <deque>
#include <istream>
#include <queue>
#include <map>
using namespace std;


template<typename T> void printQueue(T& pQueue) {
	while (!pQueue.empty()) {
		cout << pQueue.top() << " ";
		pQueue.pop();
	}
}
int main1() {
	priority_queue<int, deque<int>, less<int> > queue2;
	queue2.push(4);
	queue2.push(1);
	queue2.push(7);
	printQueue(queue2);
	return 0;
}

void main2() {
    map<string, int, CaseInsensitiveCompare> map1;
    map1.insert(make_pair("John Smith", 100));
    map1.insert(make_pair("Tom King", 101));
    map1["Jane Smith"] = 102;
    map1["Jeff Reed"] = 103;

    cout << "Enter a string to search for the key: " << endl;
    string str;
    getline(cin, str, '\n');

    auto p = map1.find(str);
    if (p == map1.end())
        cout << "String " << str << " not found in map1" << endl;
    else
        cout << p->first << " " << p->second << endl;
}

int main() {
    main2( );
}