//
//  main.cpp
//  Sokoban
//
//  Created by Thor on 24/09/2017.
//  Copyright © 2017 Thor. All rights reserved.
//

#include <iostream>
#include "Box.hpp"

#include "Edge.hpp"
#include "Graph.hpp"
#include "Vertex.hpp"



int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //Creating a 3x3 playing board
//    Graph g(9);
//    /*
//    Board is setup as counting downwars
//     0 3 6
//     1 4 7
//     2 5 8
//     */
//    // 0
//    g.addEdge(0, 3, 1);
//    g.addEdge(0, 1, 1);
//    // 1
//    g.addEdge(1, 0, 1);
//    g.addEdge(1, 4, 1);
//    g.addEdge(1, 2, 1);
//    // 2
//    g.addEdge(2, 1, 1);
//    g.addEdge(2, 5, 1);
//    // 3
//    g.addEdge(3, 0, 1);
//    g.addEdge(3, 4, 1);
//    g.addEdge(3, 6, 1);
//    // 4
//    g.addEdge(4, 3, 1);
//    g.addEdge(4, 1, 1);
//    g.addEdge(4, 7, 1);
//    g.addEdge(4, 5, 1);
//    // 5
//    g.addEdge(5, 4, 1);
//    g.addEdge(5, 2, 1);
//    g.addEdge(5, 8, 1);
//    // 6
//    g.addEdge(6, 3, 1);
//    g.addEdge(6, 7, 1);
//    // 7
//    g.addEdge(7, 6, 1);
//    g.addEdge(7, 4, 1);
//    g.addEdge(7, 8, 1);
//    // 8
//    g.addEdge(8, 5, 1);
//    g.addEdge(8, 7, 1);
    
    std::cout<<"false is "<<false<<"\ttrue is "<<true<<std::endl;
//    cout<<"GRAPH REPRESENTATION"<<endl;
//    g.printGraph();
 
    
//    g.setAGoal(0);
//    g.isGoal(1, 2);
//
    
    Graph soko;
    //soko.InitializeEmpyt(5, 10);
    //soko.printMatrix(5,10);
  
    Graph map;
    map.readMap("/Volumes/Second_HDD/tgj/github/Sokoban/Sokoban/testMap.txt");
    map.printMapContent();
    map.printMapMatrix();
    cout<<endl;
    map.makeGraph();
    map.linkGraph();
    
    map.Dijkstra(map.returnVertex(18), map.returnVertex(25));
    return 0;
}


/*********
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
 *****/

/*
 
 cout<<endl<<"DISJOINT CHP 8"<<endl;
 DisjSets ds(8);
 ds.unionSets(4, 5);
 ds.unionSets(4, 6);
 ds.print();
 cout <<ds.find(6)<<endl;
 cout <<ds.find(5)<<endl;
 cout <<ds.find(1)<<endl;
 
 */

/*
cout<<endl<<"KRUSKAL"<<endl;
vector<Edge*> msp = gh.getVertex();
gh.cheapQueue(msp);
vector<Edge*> test = gh.kruskal(5);
gh.printTree(test);
return 0;
}
*/

/*
 Graphs
 Write your own implementation of the graph data structure and implement topological sort and at least
 one of the following three algorithms: Dijkstra, Kruskal, Prim. Hand in date: December 6th
 */

