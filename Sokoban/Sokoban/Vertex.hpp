//
//  Vertex.hpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 05/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

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
    
    vector<Edge*> EdgeInList;
    
    
    ~Vertex();


private:
    int name;
    int indegree;
    
} ;



#endif /* Vertex_hpp */
