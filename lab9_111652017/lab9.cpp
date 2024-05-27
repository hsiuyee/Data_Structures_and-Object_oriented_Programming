#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;

void readFile(const char* filename)
{
	// TODO: read the input date from file
	ifstream infile(filename);
	int T, a, b, c;
	infile >> T;
	while(T--){
		Graph graph = Graph();
		int N, M;
		infile >> N;
		while(N--){
			infile >> a;
			graph.addNode(a);
		}
		infile >> M;
		while(M--){
			infile >> a >> b >> c;
			Node* tempA = new Node(a);
			Node* tempB = new Node(b);
			graph.addEdge(tempA, tempB, c);
		}
		graph.dfs();
		int sum = graph.getTotalLength();
		cout <<  " [" << sum << "]\n";
		cout << "\n";
	}
	infile.close();
}

int main()
{
	readFile("Sample_Input.txt");
	// readFile("Hidden_Input.txt");

	return 0;
}