//
//  Edge.hpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 05/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include "Vertex.hpp"

class Vertex;

class Edge
{
public:
    Edge();
    Edge(Vertex * sourceV, Vertex * destinationV, int price);
    Vertex * source;
    Vertex * destination;
    int cost;

    ~Edge();
private:
    

};



#endif /* Edge_hpp */
