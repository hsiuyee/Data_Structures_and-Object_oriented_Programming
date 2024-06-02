#include "DirectedGraph.h"

Node* DirectedGraph::findNode(int element)
{
	// Return the node with a specific element in the graph.
	// If the element is not in the graph, return nullptr.

	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->element == element)
			return this->nodes[i];
	}
	return nullptr;
}

int DirectedGraph::findNodeIndex(Node* nodeToFind)
{
	// Return the index of the node in the graph.
	// If the node is not in the graph, return -1.

	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i] == nodeToFind)
			return i;
	}
	return -1;
}

Edge* DirectedGraph::findEdge(int element1, int element2)
{
	// Return the edge connecting two specific elements in the graph.
	// If one of the elements or edge is not in the graph, return nullptr.
	//
	// NOTE: The direction of the target edge is from the node of element1 to the node of element2.

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->node1->element == element1 &&
			edges[i]->node2->element == element2)
			return edges[i];
	}
	return nullptr;
}

int DirectedGraph::findEdgeIndex(Edge* edgeToFind)
{
	// Return the index of the edge in the graph.
	// If the edge is not in the graph, return -1.

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == edgeToFind)
			return i;
	}
	return -1;
}

void DirectedGraph::simpleDebugger()
{
	// Print out the current status of the graph.

	cout << "Node\tEdge" << "\n";
	for (Node* node : nodes) {
		cout << setw(4) << node->element << "\t";
		for (Edge* edge : node->edges) {
			cout << edge->node1->element << " -> " << edge->node2->element << " (" << edge->length << "), ";
		}
		cout << endl;
	}
}

// Marks: [1 point]
DirectedGraph::~DirectedGraph()
{
	// TODO: Delete all allocated memory
	nodes.clear();
	edges.clear();
}

// Marks: [7 points]
Node* DirectedGraph::addNode(int element)
{
	// TODO: Add a new node and return it.
	//       If the element already exists, return the node.
	// 
	// NOTE: Assume all the elements are unique.
	if (findNode(element) != nullptr) {
		return nullptr;
	}
	Node* nd = new Node(element);
	nodes.push_back(nd);
	/*cout << "Node\tEdge" << "\n";
	for (Node* node : nodes) {
		cout << setw(4) << node->element << "\t";
		cout << endl;
	}*/
	return nd;
}

// Marks: [7 points]
Edge* DirectedGraph::addEdge(Node* node1, Node* node2, int length)
{
	// TODO: Add a new edge directed from node1 to node2 if both nodes are present in the graph and return the edge.
	//       Otherwise, return nullptr.
	// 
	// NOTE: If one of the nodes is not in the graph, do not add it.
	//       Remember to link the node with edge, it will be helpful when doing the traverse.
	Edge* e = new Edge(node1, node2, length);
	if (findEdgeIndex(e)) {
		Edge* newedge = new Edge(node1, node2, length);
		this->edges.push_back(newedge);
		node1->edges.push_back(newedge);
		return newedge;
	}
	return nullptr;
}

// Marks: [5 points]
void DirectedGraph::removeNode(Node* node)
{
	// TODO: Remove the node from the graph.
	//       If the node is not in the graph, do nothing.
	// 
	// NOTE: When a node is removed, the connected edge also needs to be removed.
	// 
	// Hint: You can use 'std::vector::erase' to remove a single element.
	//       For example, to remove the second element you can use 'erase(begin() + 1)'
	if (findNodeIndex(node) == -1) {
		return;
	}
	nodes.erase(nodes.begin() + findNodeIndex(node));
	vector<Edge*> tmp;
	for (auto it : edges) {
		if (it->node1->element == node->element
			|| it->node2->element == node->element) continue;
		else {
			tmp.push_back(it);
		}
	}
	edges.clear();
	for (auto it : tmp) {
		edges.push_back(it);
	}
}

// Marks: [8 points]
void DirectedGraph::removeEdge(Edge* edge)
{
	// TODO: Remove the edge from the graph.
	//       If the edge is not in the graph, do nothing.
	// 
	// NOTE: Only the edge will be removed, the connected node will remain in the graph.
	// 
	// Hint: You can use 'std::vector::erase' to remove a single element.
	//       For example, to remove the second element you can use 'erase(begin() + 1)'
	int idx = findEdgeIndex(edge);
	if (idx == -1) return;
	edges.erase(edges.begin() + idx);
	Node* nd = edge->node1;
	for (int i = 0; i < nd->edges.size(); i++) {
		if (nd->edges[i] == edge) {
			nd->edges.erase(nd->edges.begin() + i);
			break;
		}
	}
}

// Marks: [6 points]
int DirectedGraph::getIndegree(Node* node)
{
	// TODO: Return the indegree of the node in the graph.
	//       If the node is not in the graph, return -1.
	//       If the node is in the graph but not connected yet, return 0.
	// 
	// NOTE: The indegree of a node in a directed graph is the number of edges that are directed into that node.
	int rev = 0;
	if (findNodeIndex(node) == -1) return -1;
	for (auto it : edges) {
		if (it->node2->element == node->element) rev++;
	}
	return rev;
}

// Marks: [6 points]
int DirectedGraph::getOutdegree(Node* node)
{
	// TODO: Return the outdegree of the node in the graph.
	//       If the node is not in the graph, return -1.
	//       If the node is in the graph but not connected yet, return 0.
	// 
	// NOTE: The outdegree of a node in a directed graph is the number of edges that are directed out of that node.
	int rev = 0;
	if (findNodeIndex(node) == -1) return -1;
	for (auto it : edges) {
		if (it->node1->element == node->element) rev++;
	}
	return rev;
}

void DirectedGraph::dfsVisit(Node* root, vector<bool>& record) {
	cout << root->element << " ";
	record[root->element] = 1;
	for (auto it : root->edges) {
		if (!record[it->node2->element]) {
			record[it->node2->element] = 1;
			dfsVisit(it->node2, record);
		}
	}
}

// Marks: [4 points]
void DirectedGraph::dfs()
{
	// TODO: Use Depth-First Search to traverse the graph, 
	//       and print out the traversal order by following rules:
	// 
	//       1. The starting node of the DFS is the first unvisited node in the node vector of the graph.
	//       2. Using DFS, visit all nodes reachable from the starting node and print them out in the order of visitation.
	//       3. Repeat step 1 and 2 until all nodes in the graph have been visited.
	//
	// Hint: You can implement this function by using the 'std::stack' or create your own recursive function such as 'dfsVisit()'.
	//       However, this function will be called in main_Q2.cpp, so do not modify the original definition of the 'dfs()' function.
	if (this->nodes.size() == 0) return;
	vector<bool> record(this->nodes.size());
	int cnt = 1;
	for (int i = 0; i < nodes.size(); i++) {
		if (record[i] == false) {
			/*cout << "\n";*/
			cout << "Traversal " << cnt << " :";
			cout << "[";
			dfsVisit(nodes[i], record);
			cout << "]";
			cout << "\n";
			cnt++;
		}

	}
}

void DirectedGraph::bfsVisit(Node* root, vector<bool>& record) {
	queue<Node*> qu;
	qu.push(root);
	record[findNodeIndex(root)] = 1;
	while (qu.size()) {
		Node* x = qu.front();
		qu.pop();
		cout << x->element << " ";
		record[x->element] = 1;
		for (auto it : x->edges) {
			if (!record[it->node2->element]) {
				record[it->node2->element] = 1;
				dfsVisit(it->node2, record);
			}
		}
	}
}
// Marks: [4 points]
void DirectedGraph::bfs()
{
	// TODO: Use Breadth-First Search to traverse the graph, 
	//       and print out the traversal order by following rules:
	// 
	//       1. The starting node of the BFS is the first unvisited node in the node vector of the graph.
	//       2. Using BFS, visit all nodes reachable from the starting node and print them out in the order of visitation.
	//       3. Repeat step 1 and 2 until all nodes in the graph have been visited.
	//
	// Hint: You can implement this function by using the 'std::queue'.
	//       However, this function will be called in main_Q2.cpp, so do not modify the original definition of the 'bfs()' function.
	if (this->nodes.size() == 0) return;
	vector<bool> record(this->nodes.size());
	int cnt = 1;
	for (int i = 0; i < nodes.size(); i++) {
		if (record[i] == false) {
			/*cout << "\n";*/
			cout << "Traversal " << cnt << " :";
			cout << "[";
			bfsVisit(nodes[i], record);
			cout << "]";
			cout << "\n";
			cnt++;
		}

	}
}

int DirectedGraph::dfsetTotalLength(Node* root, vector<bool>& record) {
	int result = 0;
	for (auto it : root->edges) {
		if (!record[it->node2->element]) {
			record[it->node2->element] = 1;
			result += dfsetTotalLength(it->node2, record);
			result += it->length;
			/*cout << "length " << it->length << "\n";*/
		}
	}
	return result;
}

// Marks: [2 points]
int DirectedGraph::getMaxLength(Node* node)
{
	// TODO: Return the maximum length among all edges reachable from the given node.
	//       If the node is not in the graph, return -1.
	//       If there is no edge starting from the node, return -1.
	if (this->nodes.size() == 0) return 0;
	if (findNodeIndex(node) == -1) return -1;
	vector<bool> record(this->nodes.size());
	int temp = dfsetTotalLength(node, record);
	if(temp == -1) return -1;
}