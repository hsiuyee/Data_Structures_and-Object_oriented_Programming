#include "Graph.h"
#include <stack>

Graph::~Graph()
{
	// OPTIONAL: delete all allocated memory
	for(int i = 0; i < this->nodes.size(); i++){
		delete this->nodes[i];
	}
	for(int i = 0; i < this->edges.size(); i++){
		delete this->edges[i];
	}
	this->nodes.clear();
	this->edges.clear();
}

Node* Graph::findNode(int element)
{
	for (int i = 0; i < nodes.size(); i++) {
		if (this->nodes[i]->element == element)
			return this->nodes[i];
	}
	return nullptr;
}

int Graph::findNodeIndex(Node* nodeToFind)
{
	for (int i = 0; i < nodes.size(); i++) {
		if (this->nodes[i] == nodeToFind)
			return i;
	}
	return -1;
}

Node* Graph::addNode(int element)
{
	// TODO: Add a new node and return it.
	//       If the element already exists, return the node.
	// 
	// NOTE: Assume all the elements are unique.
	if(findNode(element) != nullptr){
		return nullptr;
	}
	Node* nd = new Node(element);
	this->nodes.push_back(nd);
	return nd;
}

Edge* Graph::addEdge(Node* node1, Node* node2, int length)
{
	// TODO: Add two nodes as a new edge if both nodes are in the graph.
	//       Otherwise, return nullptr.
	//
	// NOTE: The direction is from node1 to node2.
	//       Remember to link the node with edge, it will be helpful when doing the traverse.
	node1 = findNode(node1->element);
	node2 = findNode(node2->element);
	if((findNodeIndex(node1) != -1) and (findNodeIndex(node2) != -1)){
		Edge* newedge = new Edge(node1, node2, length);
		this->edges.push_back(newedge);
		node1->edges.push_back(newedge);
		return newedge;
	}
	return nullptr;
}

void Graph::dfs()
{
	// TODO: Use Depth-First Search to traverse the graph.
	//
	// NOTE: Start from the first added node.
	//       If there are other nodes that are not connected, ignore them.
	//
	// Hint: You can use 'vector<bool>' to record whether the node has visited.
	//       You can use 'stack<Node*>' to traverse the graph, or you can also create 
	//       your own function to recursive such as 'void Graph::dfsVisit(Node*, vector<bool>&)'.
	if(this->nodes.size() == 0) return;
	cout << "[";
	vector<bool> record(this->nodes.size());
	dfsVisit(this->nodes[0], record);
	cout << "]";
}


void Graph::dfsVisit(Node* root, vector<bool>& record){
	cout << root->element << " ";
	record[root->element] = 1;
	for(auto it : root->edges){
		if(!record[it->node2->element]){
			record[it->node2->element] = 1;
			dfsVisit(it->node2, record);
		}
	}
}


int dfsetTotalLength(Node* root, vector<bool>& record){
	int result = 0;
	for(auto it : root->edges){
		if(!record[it->node2->element]){
			record[it->node2->element] = 1;
			result += dfsetTotalLength(it->node2, record);
			result += it->length;
		}
	}
	return result;
}

int Graph::getTotalLength()
{
	// TODO: Return the total lengths of all edges in the graph.
	//
	// NOTE: Start from the first added node.
	//       If there are other nodes that are not connected, ignore them.
	if(this->nodes.size() == 0) return 0;
	vector<bool> record(this->nodes.size());
	return dfsetTotalLength(this->nodes[0], record);
}

void Graph::print(){
	cout << "nodes\n";
	for(int i = 0; i < this->nodes.size(); i++){
		cout << this->nodes[i]->element << " ";
	}
	cout << "\nedges\n";
	for(int i = 0; i < this->edges.size(); i++){
		cout << this->edges[i]->node1->element << " " << this->edges[i]->node2->element << " " << this->edges[i]->length << "\n";
	}
}