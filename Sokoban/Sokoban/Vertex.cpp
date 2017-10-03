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
    start = false;
    goal = false;
    indegree=0;
    name = id;
    
}
void Vertex::setGoal(){
    goal = true;
}
void Vertex::setStart(){
    start = true;
}
bool Vertex::getGoalstate(){
    return goal;
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
