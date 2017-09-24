//
//  Box.cpp
//  Sokoban
//
//  Created by Thor on 24/09/2017.
//  Copyright © 2017 Thor. All rights reserved.
//

#include "Box.hpp"
Box::Box(){
    
};
Box::Box(int position){
    pos = position;
}
bool Box::inGoal(){
    return false;
}
bool Box::pushAble(){
    return false;
}
bool Box::unPushAble(){
    return false;
}
bool Box::notAtGoal(){
    return false;
}
void Box::updatePos(int newPos){
    pos = newPos;
}

Box::~Box(){
    
};
