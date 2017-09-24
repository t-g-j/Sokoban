//
//  Box.hpp
//  Sokoban
//
//  Created by Thor on 24/09/2017.
//  Copyright © 2017 Thor. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
class Box{
public:
    Box();
    Box(int position);
    
    bool inGoal();
    bool pushAble();
    bool unPushAble();
    bool notAtGoal();
    void updatePos(int newPos);
    
    ~Box();
private:
    int pos;
};

#endif /* Box_hpp */
