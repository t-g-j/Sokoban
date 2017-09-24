//
//  Edge.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 05/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge()
{
}

Edge::Edge(Vertex *sourceV, Vertex * destinationV, int price)
{
    source = sourceV;
    destination = destinationV;
    cost = price;
}


Edge::~Edge()
{
}
