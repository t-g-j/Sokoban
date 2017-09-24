//
//  Vertex.hpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 05/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

/*
 * Add publics function and private member for setting start and goal node
 */

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include "Edge.hpp"
#include <vector>


using namespace std;

class Edge;

class Vertex
{
public:
    Vertex();
    Vertex(int id);
    int getIdentifier();
    
    
    
    void decrementIndegree();
    
    void incrementIndegree();
    int getIndegree();
    
    // Set the start and goal node.
    void setGoal();
    void setStart();
    
    bool getGoalstate();
    
    vector<Edge*> EdgeInList;
    
    

    ~Vertex();


private:
    //start and stop signals for A*
    bool start;
    bool goal;
    
    int name;
    int indegree;
    
} ;



#endif /* Vertex_hpp */
