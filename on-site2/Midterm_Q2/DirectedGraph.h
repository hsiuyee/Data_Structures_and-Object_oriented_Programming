#ifndef __DIRECTED_GRAPH_H__
#define __DIRECTED_GRAPH_H__

#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Edge;

struct Node
{
	int element;			// The unique element stored in the Node
	vector<Edge*> edges;	// The list of edges for this node (at most one edge between any two nodes)

	Node(int _element) : element(_element) {}
};

struct Edge
{
	Node* node1;			// The start node of the edge
	Node* node2;			// The end node of the edge
	int length;				// The length of the edge

	Edge(Node* _node1, Node* _node2, int _length) : node1(_node1), node2(_node2), length(_length) {}
};

class DirectedGraph
{
private:
	vector<Node*> nodes;	// The list of nodes in the graph
	vector<Edge*> edges;	// The list of edges in the graph

public:
	DirectedGraph() = default;
	~DirectedGraph();

	Node* findNode(int element);
	int findNodeIndex(Node* nodeToFind);
	Edge* findEdge(int element1, int element2);
	int findEdgeIndex(Edge* edgeToFind);

	void simpleDebugger();

	Node* addNode(int element);
	Edge* addEdge(Node* node1, Node* node2, int length);

	void removeNode(Node* node);
	void removeEdge(Edge* edge);

	int getIndegree(Node* node);
	int getOutdegree(Node* node);

	void dfs();
	void bfs();
	void dfsVisit(Node*, vector<bool>&);
	void bfsVisit(Node*, vector<bool>&);
	int dfsetTotalLength(Node*, vector<bool>&);
	int getMaxLength(Node* node);
};

#endif // !__DIRECTED_GRAPH_H__