//
//  Vertex.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 05/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

#include "Vertex.hpp"


Vertex::Vertex()
{
}

Vertex::Vertex(int id)
{
    indegree=0;
    name = id;
}

int Vertex::getIndegree()
{
    return indegree;
}
void Vertex::decrementIndegree()
{
    indegree--;
}
void Vertex::incrementIndegree()
{
    indegree++;
}

int Vertex::getIdentifier()
{
    return name;
}
Vertex::~Vertex()
{
}
