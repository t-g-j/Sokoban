//
//  main.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 29/11/2016.
//  Copyright © 2016 Mjølner. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include "DisjSets.hpp"
#include "Dijkstra.hpp"
using namespace std;


int main()
{

    
    Graph gh(5);
  
    gh.addEdge(0, 1, 10);
    gh.addEdge(0, 4, 2);
    gh.addEdge(1, 2, 9);
    gh.addEdge(1, 3, 4);
    gh.addEdge(1, 4, 8);
    gh.addEdge(2, 3, 6);
    gh.addEdge(3, 4, 7);

    
    cout<<"GRAPH REPRESENTATION"<<endl;
    gh.printGraph();
    
    cout<<endl<<"INDEGREES"<<endl;
    gh.printIndegree();
    cout<<endl<<"TOPOLOGICAL SORT"<<endl;
    gh.topsort();
/*    cout<<endl<<"DISJOINT CHP 8"<<endl;
    DisjSets ds(8);
    ds.unionSets(4, 5);
    ds.unionSets(4, 6);
 

    
    ds.print();
    cout <<ds.find(6)<<endl;
    cout <<ds.find(5)<<endl;
    cout <<ds.find(1)<<endl;

*/

    cout<<endl<<"KRUSKAL"<<endl;
    vector<Edge*> msp = gh.getVertex();
        gh.cheapQueue(msp);
    vector<Edge*> test = gh.kruskal(5);

    gh.printTree(test);
    
    
    return 0;
}
/*
 Graphs
 Write your own implementation of the graph data structure and implement topological sort and at least
 one of the following three algorithms: Dijkstra, Kruskal, Prim. Hand in date: December 6th

 */