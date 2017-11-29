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

#include <fstream>

#define my_INF  1000000

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
    
    
    /*******************************
     SOKOBAN MAP RELATED FUNCTIONS
     *******************************/
    void readMap(const string dest);
    void makingMatrix(string line);
    void makeGraph();
    void extractData(string line);
    void linkGraph();
    //void InitializeEmpyt(const int x, const int y);
    void printMatrix(int x, int y);
    vector<vector<Vertex*>> addVertex(int x, int y);
    void sokoAddEdge(vertexID src,vertexID dest, int cost);
    
    void Dijkstra(Vertex* start, Vertex* goal);
    Vertex* returnVertex(int nr);
    /*******************************
     DEBUG
     *******************************/
    void isGoal(int goalNode1, int goalNode2);
    void printMapContent();     //Printing the map read from .txt file
    void printfunc(vector<int> anyVec);
    void printMapMatrix();
    void printSokoGraph(vector<Edge*>g);
    

/****** KRUSKAL****/
    
    vector<Edge*> kruskal(int numVertices);//vector<Edge*> edgePointer);
    void printTree(vector<Edge*> ks);
    vector<Edge*> getVertex();
    queue<Edge*> cheapQueue(vector<Edge*>ks);
    ~Graph();
    
    
    
private:
    /*-------- Sokoban privates --------*/
    //vector<Vertex*> sokoRow;
    //vector<vector<Vertex*> > sokoMatrix;
   
    /*-------- MAP privates --------*/
    vector<vector<int> >mapMatrix;
    vector<int>mapRow;
    int nrDiamonds;
    int rows;
    int cols;
    int nrVertex;
    
    string test = {"this is my test 1234567890"};        //only for debugging purpose 5/10-2017
    
    
    string map_content;
    /*---------- Dijkstra's ------------*/
    vector<Vertex*>path;
    int pathLenght;
    
    /*----------------------------------*/
    vector<Vertex*> nodes;
//    vector<vertexID*> nodesID;

    vector<Edge*>edgePointer;
    vector<Edge*> mst;// minimum spanning tree
    
    queue<Edge*>cheapest;
    queue<Edge*>pq;
    
    Vertex* tmp;
    
};


#endif /* Graph_hpp */





