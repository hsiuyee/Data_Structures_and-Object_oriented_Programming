#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>

using namespace std;

struct Edge;

struct Node
{
	int element;
	vector<Edge*> edges;

	Node(int element) : element(element) {}
};

struct Edge
{
	Node* node1;
	Node* node2;
	int length;

	Edge(Node* node1, Node* node2, int length) : node1(node1), node2(node2), length(length) {}
};

class Graph
{
private:
	vector<Node*> nodes;
	vector<Edge*> edges;

	int findNodeIndex(Node* nodeToFind);
	void dfsVisit(Node*, vector<bool>&);
	Node* findNode(int element);

public:
	Graph() = default;
	~Graph();

	Node* addNode(int element);
	Edge* addEdge(Node* node1, Node* node2, int length);


	void dfs();

	int getTotalLength();

	void print();
};

#endif __GRAPH_H__