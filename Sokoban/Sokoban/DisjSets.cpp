//
//  DisjSets.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 08/12/2016.
//  Copyright © 2016 Mjøjlner. All rights reserved.
//

#include "DisjSets.hpp"

DisjSets::DisjSets(int numElemtns)
{
    for (int i = 0 ; i<numElemtns; i++)
    {
        s.push_back(-1);
    }
}

void DisjSets::unionSets(int root1, int root2)
{
    s[root2]=root1;
}
int DisjSets::find(int x)const
{
//    cout<<"i'm in"<<endl;
    if (s[x]<0)
    {
        return x;
    }
     else
    {
        return find(s[x]);
    }

}
void DisjSets::print()
{
    for (int i = 0; i<8; i++)
        
        cout<<"s contains "<<s[i]<<endl;
    
}