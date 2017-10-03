//
//  Graph.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 29/11/2016.
//  Copyright © 2016 Mjølner. All rights reserved.
//

#include "Graph.hpp"
Graph::Graph()
{
}

Graph::Graph(int N)
{
    V = N;
    for (int i = 0; i < N; i++)
    {
        Vertex * newVertex = new Vertex(i);
        nodes.push_back(newVertex);
    }
}
/* not working */
void Graph::InitializeEmpyt(const int x, const int y){
    for (int i = 0; i<x; i++) {
        sokoRow.push_back(nullptr);
        for (int j = 0 ; j<y; j++) {
            sokoMatrix.push_back(sokoRow);
        }
    }
}
/* not working */
void Graph::printMatrix(int x, int y){
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cout<<sokoMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<Vertex*>> Graph::addVertex(int x, int y){
    Vertex * newVertex = new Vertex(1);
    sokoMatrix[x][y]= newVertex;
    return sokoMatrix;
}
void Graph::sokoAddEdge(int src, int dest, int cost){
    
}





void Graph::addEdge(int src, int dest, int cost)
{
    Vertex * source = nodes[src];
    Vertex * destination = nodes[dest];
    Edge *newEdge = new Edge(source, destination, cost);
    nodes[src]->EdgeInList.push_back(newEdge);
    nodes[dest]->incrementIndegree();
    edgePointer.push_back(newEdge);

}
void Graph::isGoal(int goalNode1, int goalNode2){
    cout<<"bool: "<<nodes[goalNode1]->getGoalstate()<<endl;
}

void Graph::setAGoal(int goalNode){
    nodes[goalNode]->setGoal();
}


void Graph::findNewVertexOfIndegreeZero()
{
}
void Graph::topsort()
{
    cout<<"TOPOLOGICAL SORT"<<endl;
    queue<Vertex*>q;
    
    
    for (int i= 0   ; i<nodes.size() ;  i++)
    {
       // cout<<"im in"<<endl;
        if (nodes[i]->getIndegree()==0)
        {
        //    cout<<"check"<<endl;
            q.push(nodes[i]);
        }
    }
        while (!q.empty() )
        {
            
            tmp = q.front();
            cout<<"Topological order: "<<tmp->getIdentifier()<<endl;
          
            
            for (int j = 0 ; j<tmp->EdgeInList.size(); j++)
            {
                    tmp->EdgeInList[j]->destination->decrementIndegree();
                
                if (tmp->EdgeInList[j]->destination->getIndegree()==0 )
                {
                    q.push(tmp->EdgeInList[j]->destination);
                    
                }
            }
            q.pop();
        }
}



void Graph::printIndegree()
{
    for (int i =0; i<V; i++)
    {
        cout<<"Vertice: "<<i<<" has "<<nodes[i]->getIndegree()<<" indegrees"<<endl;
    }
}
void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Vertix: " << i << " has " << nodes[i]->EdgeInList.size() << " edges" << endl;
        if (nodes[i]->EdgeInList.size() != 0)
        {
            for (int k = 0; k < nodes[i]->EdgeInList.size(); k++)
            {
                cout << "Edge " << k << " starts at " << i << " and ends in " << nodes[i]->EdgeInList[k]->destination->getIdentifier() << endl;
            }
        }
    }
}

vector<Edge*> Graph::kruskal(    int numVertices)//vector<Edge*>edgePointer)
{
    DisjSets ds{ numVertices };
    
    
    pq = cheapest;            //sorted queue copied to pq
    
    while( mst.size( ) != numVertices - 1 )
    {
     
        Edge * e = pq.front();       // Edge e = (u, v)
        pq.pop();
        
        int uset = ds.find( e->source->getIdentifier() );       //parent
        
        int  vset = ds.find( e->destination->getIdentifier()  );    //child
        
        if( uset != vset )
        {
            // Accept the edge
            mst.push_back( e );
            ds.unionSets( uset, vset );
        } 
     }
    
    return mst;
}

queue<Edge*> Graph::cheapQueue(vector<Edge *> ks)
{
    for (int c = 0 ; c<1000; c++)
    {
        for (int i = 0; i<ks.size(); i++)
        {
            if (ks[i]->cost == c )
            {
                cheapest.push(ks[i]);
            }
        }
    }
    return cheapest;
}


vector<Edge*> Graph::getVertex()
{
    return edgePointer;
}
void Graph::printTree( vector<Edge*> ks)
{

    for(int i = 0; i<ks.size(); i++)
    {

        cout<<"edge " <<i <<" from " << ks[i]->source->getIdentifier() <<" to "<<ks[i]->destination->getIdentifier()<<"cost "<<ks[i]->cost  <<endl;
    }

}

Graph::~Graph()
{
}
