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

struct vertexID{
    int row;
    int col;
    int creationNr;
};

class Vertex
{
public:
    Vertex();
    Vertex(vertexID id);
    
    int getIdentifier();
    
    
    
    void decrementIndegree();
    
    void incrementIndegree();
    int getIndegree();
    
    // Set the start and goal node.
    void setGoal();
    void setStart();
    
    
    
    bool getGoalstate();
    
    vector<Edge*> EdgeInList;
    
    int getRow();
    int getCol();
    int getCreate();
    vertexID returnID();

    ~Vertex();


private:
    //start and stop signals for A*
    bool start;
    bool goal;
    
    vertexID name;
    int indegree;
    
} ;



#endif /* Vertex_hpp */
