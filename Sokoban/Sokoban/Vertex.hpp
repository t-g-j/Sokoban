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
    void discover();
    void hide();
    bool status();
    
    
    
    bool getGoalstate();
    
    vector<Edge*> EdgeInList;
    
    int getRow();
    int getCol();
    int getCreate();
    void setCost(int price);
    int getCost();
    void setPath(int pathPointer);
    int getpath();
    
    vertexID returnID();

    ~Vertex();


private:
    //start and stop signals for A*
    bool start;
    bool goal;
    bool known;
    int vCost;
    int path;
    
    vertexID name;
    int indegree;
    
} ;



#endif /* Vertex_hpp */
