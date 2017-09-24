//
//  DisjSets.hpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 08/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

#ifndef DisjSets_hpp
#define DisjSets_hpp

#include <stdio.h>
#include <vector>
#include <iostream>



using namespace std;

class DisjSets
{
public:
    explicit DisjSets(int numElements);
    
    int find( int x) const;
    //int find( int x);
    
    void print();
    
    void unionSets(int root1, int root2);
    
private:
    vector<int>s;
    int numElemtns;
};
#endif /* DisjSets_hpp */
