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

Vertex::Vertex(vertexID id)
{
    start = false;
    goal = false;
    indegree=0;
    name = id;
    known = false;
    vCost = 0;
    path = 0;
}
void Vertex::setPath(int pathPointer){
    path=pathPointer;
}
int Vertex::getpath(){
    return path;
}
bool Vertex::status(){
    return known;
}
void Vertex::hide(){
    known = false;
}
void Vertex::discover(){
    known = true;
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
    // THIS DOES NOT WORK
    return name.creationNr;
}
int Vertex::getCreate(){
    return name.creationNr;
}
int Vertex::getCol(){
    return name.col;
}
int Vertex::getRow(){
    return name.row;
}
int Vertex::getCost(){
    return vCost;
}
void Vertex::setCost(int price){
    vCost = price;
}
vertexID Vertex::returnID(){
    return name;
}
Vertex::~Vertex()
{
}
