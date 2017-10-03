//
//  Graph.hpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 29/11/2016.
//  Copyright © 2016 Mjølner. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

#include "Vertex.hpp"

#include "Edge.hpp"
#include "DisjSets.hpp"
#include <iostream>

#include <vector>
#include <queue>


using namespace std;

class Graph
{
public:
    Graph();
    Graph(int N);
    void addEdge(int src, int dest, int cost);
    
    void addIndegree(int host);
    
    void findNewVertexOfIndegreeZero();
    void topsort();
    void printIndegree();
    void printGraph();
    
    void setAGoal(int goalNode);
    
    //Sokoban functions
    
    void InitializeEmpyt(const int x, const int y);
    void printMatrix(int x, int y);
    vector<vector<Vertex*>> addVertex(int x, int y);
    void sokoAddEdge(int src, int dest, int cost);
    //Debug
    void isGoal(int goalNode1, int goalNode2);
    

/****** KRUSKAL****/
    
    vector<Edge*> kruskal(int numVertices);//vector<Edge*> edgePointer);
    void printTree(vector<Edge*> ks);
    vector<Edge*> getVertex();
    queue<Edge*> cheapQueue(vector<Edge*>ks);
    ~Graph();
private:
    /*-------- Sokoban privates --------*/
    vector<Vertex*> sokoRow;
    vector<vector<Vertex*> > sokoMatrix;
    int nrDiamonds;
    
    /*----------------------------------*/
    vector<Vertex*> nodes;

    vector<Edge*>edgePointer;
    
    
    
    
    vector<Edge*> mst;// minimum spanning tree
    
    queue<Edge*>cheapest;
    queue<Edge*>pq;
    
    Vertex* tmp;
    
    
    
    int V;
};


#endif /* Graph_hpp */





