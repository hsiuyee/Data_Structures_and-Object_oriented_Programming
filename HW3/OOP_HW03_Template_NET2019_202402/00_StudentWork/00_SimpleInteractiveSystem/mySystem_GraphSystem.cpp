//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
//
//
// Prof. Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2024/05/01
//
//
#include <iostream>
#include "mySystem_GraphSystem.h"
#include <time.h>
#include <cmath>

using namespace std;

int Param::GRAPH_MAX_NUM_NODES = 10000;
int Param::GRAPH_MAX_NUM_EDGES = 10000;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    //reset(); 
    mFlgAutoNodeDeletion = false;

    initMemoryPool();
    createDefaultGraph();
    //
    // Implement your own stuff
    //
}

void GRAPH_SYSTEM::initMemoryPool()
{
    mNodeArr_Pool = new GRAPH_NODE[Param::GRAPH_MAX_NUM_NODES];
    mEdgeArr_Pool = new GRAPH_EDGE[Param::GRAPH_MAX_NUM_EDGES];
    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mActiveNodeArr = new int[Param::GRAPH_MAX_NUM_NODES];
    mActiveEdgeArr = new int[Param::GRAPH_MAX_NUM_EDGES];
    mFreeNodeArr = new int[Param::GRAPH_MAX_NUM_NODES];
    mFreeEdgeArr = new int[Param::GRAPH_MAX_NUM_EDGES];
    //
    for (int i = 0; i < Param::GRAPH_MAX_NUM_NODES; ++i) {
        mNodeArr_Pool[i].id = i; // assign a unique id
    }
    for (int i = 0; i < Param::GRAPH_MAX_NUM_EDGES; ++i) {
        mEdgeArr_Pool[i].id = i; // assign a unique id
    }
    reset();
}

void GRAPH_SYSTEM::reset( )
{
    stopAutoNodeDeletion();

    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
    //
    // Implement your own stuff
    //
    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mCurNumOfFreeNodes = Param::GRAPH_MAX_NUM_NODES;
    mCurNumOfFreeEdges = Param::GRAPH_MAX_NUM_EDGES;
    for (int i = 0; i < mCurNumOfFreeNodes; ++i) {
        mFreeNodeArr[i] = i; // index is not used
    }
    for (int i = 0; i < mCurNumOfFreeEdges; ++i) {
        mFreeEdgeArr[i] = i; // index is not used
    }
}

void GRAPH_SYSTEM::createDefaultGraph( )
{
    reset( );
    //
    // Implement your own stuff
    //
    double r = 1.0;
    int id0, id1, id2;
    id0 = addNode(0.0, 0.0, 0.0, r);
    id1 = addNode(5.0, 0.0, 0.0, r);
    id2 = addNode(0.0, 0.0, 5.0, r);

    addEdge(id0, id1);
    addEdge(id2, id1);
}

void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;
    //
    // Implement your own stuff
    //
    float theta = 0.0;
    int temp;
    vector<int> nodes_index_in;
    vector<int> nodes_index_out;

    if (n == 0) return;
    for (int i = 0; i < n; i++) {
        theta += 2 * acos(-1) / n;
        temp = addNode(d * cos(theta), 0, d * sin(theta));
        nodes_index_in.push_back(temp);
        temp = addNode(r * cos(theta), 0, r * sin(theta));
        nodes_index_out.push_back(temp);
    }

    int circle_edge = n / 20 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int random = rand() % 2;
            // choose and vaild
            if (random == 1 && (abs(i - j) <= circle_edge || 
                ((n + i - j) <= circle_edge && abs(n - i - j) <= circle_edge) ||
                 (n + j - i)  <= circle_edge && abs(n - i - j) <= circle_edge)) {
                addEdge(nodes_index_in[i], nodes_index_out[j]);
            }
        }
    }
}

void GRAPH_SYSTEM::createNet_Circular( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    //
    // Implement your own stuff
    //
    float theta = 0.0;
    int temp;
    vector<vector<int> > nodes_index(num_layers+1);

    if (n == 0) return;
    for (int j = 0; j < num_layers+1; j++) {
        for (int i = 0; i < n; i++) {
            theta += 2 * acos(-1) / n;
            temp = addNode((r + d * j) * cos(theta), 0, (r + d * j) * sin(theta));
            nodes_index[j].push_back(temp);
        }
    }
    
    // same center
    for (int j = 0; j < num_layers; j++) {
        for (int i = 0; i < n; i++) {
            addEdge(nodes_index[j][i], nodes_index[j][(i + 1) % n]);
        }
    }

    // same degree
    for (int j = 0; j < num_layers; j++) {
        for (int i = 0; i < n; i++) {
            addEdge(nodes_index[j+1][i], nodes_index[j][i]);
        }
    }

}
void GRAPH_SYSTEM::createNet_Square( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 5.;
    float offset_z = 5.;
    //
    // Implement your own stuff
    //
    // swap(n, num_layers);
    n = 11;
    num_layers = 3;
    //cout << n << " " << num_layers << "\n";
    int temp;
    vector<vector<bool>> candidate_point(n, vector<bool>(n, true));

    int start = floor((n - num_layers) / 2.0);
    int end = start + num_layers;

    for (int i = start; i < end; i++) {
        for (int j = start; j < end; j++) {
            candidate_point[i][j] = false;
        }
    }

    vector<int> nodes_index;
    vector<int> ptX;
    vector<int> ptY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (candidate_point[i][j] == true) {
                int temp = addNode((double)(r + i * d - start * d), 0, (double)(r + j * d - start * d));
                nodes_index.push_back(temp);
                ptX.push_back(i);
                ptY.push_back(j);
            }
        }
    }
    for (int i = 0; i < ptX.size(); i++) {
        for (int j = i+1; j < ptY.size(); j++) {
            int distance = abs(ptX[i] - ptX[j]) + abs(ptY[i] - ptY[j]);
            if (distance == 1) {
                addEdge(nodes_index[i], nodes_index[j]);
            }
        }
    }
}

void GRAPH_SYSTEM::createNet_RadialCircular( int n ) {

    reset( );

    float offset_x = 15.0;
    float offset_z = 15.0;

    float r = 15; // radius
    //
    // Implement your own stuff
    //    
    float theta = 0.0;
    int temp;
    vector<int> nodes_index;
    int center_index = addNode(0, 0, 0);

    if (n == 0) return;
    for (int i = 0; i < n; i++) {
        theta += 2 * acos(-1) / n;
        temp = addNode(r * cos(theta), 0, r * sin(theta));
        nodes_index.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        addEdge(nodes_index[i], center_index);
    }
}

GRAPH_NODE* GRAPH_SYSTEM::getFreeNode() {
    if (mCurNumOfFreeNodes == 0) return 0;
    --mCurNumOfFreeNodes;
    int id = mFreeNodeArr[mCurNumOfFreeNodes];
    GRAPH_NODE* n = &mNodeArr_Pool[id];
    mActiveNodeArr[mCurNumOfActiveNodes] = id;
    n->dynamicID = mCurNumOfActiveNodes;
    ++mCurNumOfActiveNodes;
    return n;
}
// return node id
int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
{
    //
    // Implement your own stuff
    //  
    GRAPH_NODE* g;
    g = getFreeNode();
    if (g == 0) return -1; // invalid id.
    g->p = vector3(x, y, z);
    g->r = r;
    g->edgeID.clear();
    return g->id;
}

GRAPH_EDGE* GRAPH_SYSTEM::getFreeEdge() {
    if (mCurNumOfFreeEdges == 0) return 0;
    --mCurNumOfFreeEdges;
    int id = mFreeEdgeArr[mCurNumOfFreeEdges];
    GRAPH_EDGE* e = &mEdgeArr_Pool[id];
    mActiveEdgeArr[mCurNumOfActiveEdges] = id;
    e->dynamicID = mCurNumOfActiveEdges;
    ++mCurNumOfActiveEdges;
    return e;
}
// return edge id
int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )
{
    //
    // Implement your own stuff
    //  
    GRAPH_EDGE* e;
    e = getFreeEdge();
    if (e == 0) return -1;
    e->nodeID[0] = nodeID_0;
    e->nodeID[1] = nodeID_1;
    mNodeArr_Pool[nodeID_0].edgeID.push_back(e->id);
    mNodeArr_Pool[nodeID_1].edgeID.push_back(e->id);
    return e->id;
}

void GRAPH_SYSTEM::askForInput( )
{
    //
    // Implement your own stuff
    // 
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph" << endl;
    cout << "2: create a graph with 10x10 nodes. Connect the consecutive nodes horizontally" << endl;
    cout << "3: create a graph with 10x10 nodes. Connect the consecutive nodes vertically" << endl;
    cout << "4: create a graph with 10x10 nodes. Create 10 randomly generated edges" << endl;
    cout << "5: create a graph with 10x10 nodes. Create 10 randomly generated edges attached at a random node" << endl;
    cout << "Delete: delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;
}

GRAPH_NODE *GRAPH_SYSTEM::findNearestNode( double x, double z, double &cur_distance2 ) const
{
    GRAPH_NODE *n = 0;
    //
    // Implement your own stuff
    // 
    cur_distance2 = DBL_MAX;
    for (int i = 0; i < mCurNumOfActiveNodes; i++) {
        GRAPH_NODE* current = &mNodeArr_Pool[mActiveNodeArr[i]];
        double nowDis = pow(current->p.x-x, 2) + pow(current->p.z-z, 2);
        if (cur_distance2 > nowDis) {
            cur_distance2 = nowDis;
            n = current;
        }
    }
    return n;
}

//
// compute mSelectedNode
//
void GRAPH_SYSTEM::clickAt(double x, double z)
{
    //
    // Implement your own stuff
    // 
    handlePassiveMouseEvent(x, z);
    if (mSelectedNode != mPassiveSelectedNode) {
        if (mSelectedNode != 0 && mPassiveSelectedNode != 0) {
            //check whether mSelectedNode and mPassiveSelectedNode has been connected.
            bool check_edge = false;
            for (int i = 0; i < mNodeArr_Pool[mSelectedNode->id].edgeID.size(); i++) {
                for (int j = 0; j < mNodeArr_Pool[mPassiveSelectedNode->id].edgeID.size(); j++) {
                    if (mNodeArr_Pool[mSelectedNode->id].edgeID[i] == mNodeArr_Pool[mPassiveSelectedNode->id].edgeID[j]) {
                        check_edge = true;
                    }
                }
            }

            if (check_edge == false) {
                addEdge(mSelectedNode->id, mPassiveSelectedNode->id);
            }
            mSelectedNode = 0;
        }
        else {
            mSelectedNode = mPassiveSelectedNode;
        }

    }
    else mSelectedNode = 0;
}


void GRAPH_SYSTEM::deleteEdge(int edgeID) {
    
    // Step 1. we do similar work in deleteNode function
    GRAPH_EDGE* original = &mEdgeArr_Pool[edgeID];
    mFreeEdgeArr[mCurNumOfFreeEdges] = original->id;
    mCurNumOfFreeEdges++;
    mCurNumOfActiveEdges--;

    mActiveEdgeArr[original->dynamicID] = mActiveEdgeArr[mCurNumOfActiveEdges];
    int id = mActiveEdgeArr[mCurNumOfActiveEdges];//mActiveEdgeArr[mCurNumOfActiveEdges] is the ID of the last edge.
    GRAPH_EDGE* last = &mEdgeArr_Pool[id];
    last->dynamicID = original->dynamicID;//update the last edge's dynamic id 

    // Step 2. we delete edges
    // refer to: https://shengyu7697.github.io/std-find/
    for (int i = 0; i < mCurNumOfFreeNodes; i++) {
        int id = mFreeNodeArr[i];
        GRAPH_NODE* n = &mNodeArr_Pool[id];
        auto it = find(n->edgeID.begin(), n->edgeID.end(), edgeID);
        if (it != n->edgeID.end()) {
            n->edgeID.erase(it);
        }
    }
}

void GRAPH_SYSTEM::deleteNode( int nodeID ) {
    //
    // Implement your own stuff
    // 

    GRAPH_NODE* original = &mNodeArr_Pool[nodeID];

    // delete nodes first
    // update nodes data
    // example
    // suppose we have 1, 2, ... , 7, 8 now
    // we need to delete 2
    
    // Step 1. we need to free index of "data 2",
    //         then updating # of mCurNumOfFreeNodes and mCurNumOfActiveNodes
    
    // Step 2. we can change dynamicID of "data 8" to dynamicID of "data 2"
    //         and free dynamicID

    
    // Step 1.
    mFreeNodeArr[mCurNumOfFreeNodes] = original->id;
    mCurNumOfFreeNodes++;
    mCurNumOfActiveNodes--;

    // Step 2.
    // change data
    mActiveNodeArr[original->dynamicID] = mActiveNodeArr[mCurNumOfActiveNodes];
    // cout << "original->dynamicID" << original->dynamicID << "\n";
    // cout << "mCurNumOfActiveNodes" << mCurNumOfActiveNodes << "\n";
 
    // free dynamic id
    int id = mActiveNodeArr[mCurNumOfActiveNodes];
    GRAPH_NODE* last = &mNodeArr_Pool[id];
    last->dynamicID = original->dynamicID;
    // cout << "id" << id << "\n";
    // cout << "last->dynamicID" << last->dynamicID << "\n";

    while (original->edgeID.size()) {
        deleteEdge(original->edgeID[0]);
    }

    mSelectedNode = 0;
    mPassiveSelectedNode = 0;

    // -----------
}

void GRAPH_SYSTEM::deleteSelectedNode(  ) {
    //
    // Implement your own stuff
    // 
    if (isSelectedNode()) {
        deleteNode(mSelectedNode->id);
    }
}

bool GRAPH_SYSTEM::isSelectedNode( ) const
{
    //
    if (mSelectedNode != 0) return true;
    //
    // Implement your own stuff
    // 
    
    return false;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint( double &r, vector3 &p ) const
{
    // r = mSelectedNode->r;
    // p = mSelectedNode->p;
    //
    // Implement your own stuff
    // 
    if (isSelectedNode()) {
        r = mSelectedNode->r;
        p = mSelectedNode->p;
    }
}



void GRAPH_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
    
    switch( key ) {
    case 127: // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode( );
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph( );
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(5, 4); // you can modify this
        mSelectedNode = 0;

        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;

        break;
    case '5':
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(24);
        mSelectedNode = 0;

        break;

    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'g':
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent( double x, double z )
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) return;
    if ( cur_d2 > n->r*n->r ) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

//
// get the number of nodes
//
int GRAPH_SYSTEM::getNumOfNodes( ) const
{
    //
    // Implement your own stuff
    // 
    return mCurNumOfActiveNodes;
}

void GRAPH_SYSTEM::getNodeInfo( int nodeIndex, double &r, vector3 &p ) const
{
    //
    // Implement your own stuff
    // 
    if (nodeIndex >= mCurNumOfActiveNodes) return;
    int id = mActiveNodeArr[nodeIndex];
    const GRAPH_NODE* g = &mNodeArr_Pool[id];
    r = g->r;
    p = g->p;
}

//
// return the number of edges
//
int GRAPH_SYSTEM::getNumOfEdges( ) const
{
    //
    // Implement your own stuff
    // 
    return mCurNumOfActiveEdges;
}

//
// an edge should have two nodes: index 0 and index 1
// return the position of node with nodeIndex
//
vector3 GRAPH_SYSTEM::getNodePositionOfEdge( int edgeIndex, int nodeIndex ) const
{
    vector3 p;
    if (edgeIndex >= mCurNumOfActiveEdges) return p;
    //
    // Implement your own stuff
    // 
    int e_id = mActiveEdgeArr[edgeIndex];

    const GRAPH_EDGE* e = &mEdgeArr_Pool[e_id];

    int n_id = e->nodeID[nodeIndex];

    const GRAPH_NODE* n = &mNodeArr_Pool[n_id];

    p = n->p;

    return p;
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
// 
//
void GRAPH_SYSTEM::update( )
{
    if (!mFlgAutoNodeDeletion) {
     
        return;
    }
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;

    Sleep(250);
    //
    //
    // Implement your own stuff
    // 
}