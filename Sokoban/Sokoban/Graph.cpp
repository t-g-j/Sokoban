//
//  Graph.cpp
//  Graphs
//
//  Created by Thor Gunnlaugsson on 29/11/2016.
//  Copyright © 2016 Mjølner. All rights reserved.
//

#include "Graph.hpp"
Graph::Graph()
{
}
//
//vector<vector<Vertex*>> Graph::addVertex(int x, int y){
//    Vertex * newVertex = new Vertex(1);
//    sokoMatrix[x][y]= newVertex;
//    return sokoMatrix;
//}
void Graph::addEdge(int src, int dest, int cost)
{
    Vertex * source = nodes[src];
    Vertex * destination = nodes[dest];
    Edge *newEdge = new Edge(source, destination, cost);
    nodes[src]->EdgeInList.push_back(newEdge);
    nodes[dest]->incrementIndegree();
    edgePointer.push_back(newEdge);

}
void Graph::isGoal(int goalNode1, int goalNode2){
    cout<<"bool: "<<nodes[goalNode1]->getGoalstate()<<endl;
}

void Graph::setAGoal(int goalNode){
    nodes[goalNode]->setGoal();
}


void Graph::findNewVertexOfIndegreeZero()
{
}
void Graph::topsort()
{
    cout<<"TOPOLOGICAL SORT"<<endl;
    queue<Vertex*>q;
    
    
    for (int i= 0   ; i<nodes.size() ;  i++)
    {
       // cout<<"im in"<<endl;
        if (nodes[i]->getIndegree()==0)
        {
        //    cout<<"check"<<endl;
            q.push(nodes[i]);
        }
    }
        while (!q.empty() )
        {
            
            tmp = q.front();
            cout<<"Topological order: "<<tmp->getIdentifier()<<endl;
          
            
            for (int j = 0 ; j<tmp->EdgeInList.size(); j++)
            {
                    tmp->EdgeInList[j]->destination->decrementIndegree();
                
                if (tmp->EdgeInList[j]->destination->getIndegree()==0 )
                {
                    q.push(tmp->EdgeInList[j]->destination);
                    
                }
            }
            q.pop();
        }
}



void Graph::printIndegree()
{
    for (int i =0; i<nrVertex; i++)
    {
        cout<<"Vertice: "<<i<<" has "<<nodes[i]->getIndegree()<<" indegrees"<<endl;
    }
}
void Graph::printGraph()
{
    for (int i = 0; i < nrVertex; i++)
    {
        cout << "Vertix: " << i << " has " << nodes[i]->EdgeInList.size() << " edges" << endl;
        if (nodes[i]->EdgeInList.size() != 0)
        {
            for (int k = 0; k < nodes[i]->EdgeInList.size(); k++)
            {
                cout << "Edge " << k << " starts at " << i << " and ends in " << nodes[i]->EdgeInList[k]->destination->getIdentifier() << endl;
            }
        }
    }
}

vector<Edge*> Graph::kruskal(    int numVertices)//vector<Edge*>edgePointer)
{
    DisjSets ds{ numVertices };
    
    
    pq = cheapest;            //sorted queue copied to pq
    
    while( mst.size( ) != numVertices - 1 )
    {
     
        Edge * e = pq.front();       // Edge e = (u, v)
        pq.pop();
        
        int uset = ds.find( e->source->getIdentifier() );       //parent
        
        int  vset = ds.find( e->destination->getIdentifier()  );    //child
        
        if( uset != vset )
        {
            // Accept the edge
            mst.push_back( e );
            ds.unionSets( uset, vset );
        } 
     }
    
    return mst;
}

queue<Edge*> Graph::cheapQueue(vector<Edge *> ks)
{
    for (int c = 0 ; c<1000; c++)
    {
        for (int i = 0; i<ks.size(); i++)
        {
            if (ks[i]->cost == c )
            {
                cheapest.push(ks[i]);
            }
        }
    }
    return cheapest;
}


vector<Edge*> Graph::getVertex()
{
    return edgePointer;
}
void Graph::printTree( vector<Edge*> ks)
{

    for(int i = 0; i<ks.size(); i++)
    {

        cout<<"edge " <<i <<" from " << ks[i]->source->getIdentifier() <<" to "<<ks[i]->destination->getIdentifier()<<" cost "<<ks[i]->cost  <<endl;
    }
}

/*******************************
 SOKOBAN MAP RELATED FUNCTIONS
 *******************************/
/*
 *Function for reading our map into private member for graph class
 */
void Graph::readMap(const string dest){
    string line;                    //string for reading each line
    ifstream sokoMap(dest);         //opening file from the destination
    int counter = 0;
    int ifcount =0;
    if(sokoMap.is_open() ){         //if the file is opened commence reading
        while (getline(sokoMap,line) ) {        // read one line at a time in the whole file
            map_content += line;                // append line into one big string
            if (counter == 0) {
                extractData(line);
                cout<<line<<endl;
            }
            if (counter >=1){                   // counter for skipping the first line
//                cout<<line<<endl;
            makingMatrix(line);              //Function call to see whats in the row
                ifcount ++;
            }
            map_content += "\n";                // append newline after each line
            counter ++;
            }
//        cout<<counter<<endl;
//        cout<<ifcount<<endl;
        }
    
    else{
        cout<<"could not open file. Check path to file"<<endl;  //Debug line
    }
    sokoMap.close();
}

/*******************************
 * Making each row for the matrix and pushback the row in the end.
 *******************************/
void Graph::makingMatrix(string line){
    string tmp;                             //Dummie string used for checkink upon
    for (int i = 0; i<line.size(); i++) {
        tmp = line[i];
        if (tmp == " ") {
            mapRow.push_back(0);
        }
        if (tmp == "X") {
            mapRow.push_back(1);
        }
        if (tmp == ".") {
            mapRow.push_back(2);
        }
        if (tmp == "J") {
            mapRow.push_back(8);
        }
        if (tmp == "G") {
            mapRow.push_back(9);
        }
        if (tmp == "M") {
            mapRow.push_back(5);
        }
    }
    mapMatrix.push_back(mapRow);        //Pushing back the row onto our matrix
    printfunc(mapRow);                  //Print function for the row
    mapRow.clear();                     // Clearing the row for next line

}
/*******************************
 * Extract data from the text file. amount of diamonds, coloums and rows.
 *******************************/
void Graph::extractData(string line){
    string tmpTier;
    string tmpEtter;
    int asciiCorrector = 48;
    for (int i = 0; i<line.size(); i+= 3) {
        tmpTier = line[i];
        tmpEtter= line[i+1];
        cout<<endl<<tmpTier<<" "<<tmpEtter<<" ";
        //cout<<tmpEtter<<" ";
        if (i==0) {
            //cout<<tmp<<endl;
            cols = (tmpTier[0]-asciiCorrector)*10 +(tmpEtter[0]-asciiCorrector);
        }
        if (i==3) {
            if (tmpTier == "0") {
                //cout<<"tmpEtter"<<tmpEtter<<endl;
                rows =tmpEtter[0]-asciiCorrector;
               // cout<<"cols"<<cols;
            }
            else{
            rows = (tmpTier[0]-asciiCorrector)*10 +(tmpEtter[0]-asciiCorrector);
            }
        }
        if (i==6) {
            if (tmpTier == "0") {
                //cout<<"tmpEtter"<<tmpEtter<<endl;
                nrDiamonds =tmpEtter[0]-asciiCorrector;
                // cout<<"cols"<<cols;
            }
            else{
                nrDiamonds = (tmpTier[0]-asciiCorrector)*10 +(tmpEtter[0]-asciiCorrector);
            }
        }
                
        }
    cout<<endl<<"rows:\t"<<rows<<endl<<"cols:\t"<<cols<<endl<<"Diamonds:\t"<<nrDiamonds<<endl;
    nrVertex = rows*cols;
}

/********************************
 * Prints whatever vector you give it
 *******************************/
void Graph::printfunc(vector<int> anyVec){
    for (int i = 0 ; i<anyVec.size(); i++) {
        cout<<anyVec[i]<<" ";
    }
    cout<<endl;
}
/*******************************
 * Print the Map in matrix format.
 *******************************/
void Graph::printMapMatrix(){

    cout<<endl;
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            cout<<mapMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
 * Print private member containing the map
 */
void Graph::printMapContent(){
    cout<<map_content<<endl;
}
/*******************************
 * Mapping the Matrix into a graph structure.
 *******************************/
void Graph::makeGraph(){
    static int counter= 0;
    //int G = rows*cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j<cols; j++) {
        
                
            
            vertexID newVertexID ;
            newVertexID.row = i;
            newVertexID.col = j;
            newVertexID.creationNr = counter++;

        Vertex * newVertex = new Vertex(newVertexID);
        nodes.push_back(newVertex);
            }
        
//            vertexID * nv = new vertexID(newVertexID);
//            nodesID.push_back(nv);
        
    }
}
void Graph::sokoAddEdge(vertexID  src, vertexID dest, int cost){
    Vertex * source = nodes[src.creationNr];
    Vertex * destination = nodes[dest.creationNr];
    Edge *newEdge = new Edge(source, destination, cost);
    nodes[src.creationNr]->EdgeInList.push_back(newEdge);
    nodes[dest.creationNr]->incrementIndegree();
    edgePointer.push_back(newEdge);
}
/*******************************
 * Printing the edges in the sokoban graph
 *******************************/
void Graph::printSokoGraph(vector<Edge *> g){
    for (int i = 0; i<g.size(); i++) {
        cout<<"edge " <<i <<" from " << g[i]->source->getRow()<<"," <<g[i]->source->getCol()<<" to "<<g[i]->destination->getRow()<<","<<g[i]->destination->getCol()<<" cost "<<g[i]->cost  <<endl;
    }
}


void Graph::linkGraph(){
    static int index = 0;
    static int tmp = 0;
    static int tmp2 =0;
    //for debugging purposes - wrong for loops
    for (int i = 0; i <rows; i++) {
        for (int j =0; j <cols; j++) {
            
            //Go through MapMatrix and look at neighbours.
            /*
             * Looking a everything not a wall
             **/
//            if (mapMatrix[i][j] != 1 ){
            cout<<mapMatrix[i][j]<<" ";
            if (j>! cols) {
            
                if ( (mapMatrix[i][j+1] == 2 ) && (mapMatrix[i][j] !=1)) {
                    tmp2++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index+1]->returnID(), 1);
                    sokoAddEdge(nodes[index+1]->returnID(), nodes[index]->returnID(), 1);
                    
                }
                if ((mapMatrix[i][j+1] == 8 ) && (mapMatrix[i][j] !=1)) {
                    tmp2++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index+1]->returnID(), 1);
                    sokoAddEdge(nodes[index+1]->returnID(), nodes[index]->returnID(), 1);
                }
                if ((mapMatrix[i][j+1] == 9 ) && (mapMatrix[i][j] !=1)) {
                    tmp2++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index+1]->returnID(), 1);
                    sokoAddEdge(nodes[index+1]->returnID(), nodes[index]->returnID(), 1);
                }
                if ((mapMatrix[i][j+1] == 5 ) && (mapMatrix[i][j] !=1)) {
                    tmp2++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index+1]->returnID(), 1);
                    sokoAddEdge(nodes[index+1]->returnID(), nodes[index]->returnID(), 1);
                }
            }
            if (i >! -1){
                
                if ( (mapMatrix[i-1][j] == 2 )&& (mapMatrix[i][j] !=1) ) {
                    tmp++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index-cols]->returnID(), 1);
                    sokoAddEdge(nodes[index-cols]->returnID(), nodes[index]->returnID(), 1);
                }

                if ((mapMatrix[i-1][j] == 8 )&& (mapMatrix[i][j] !=1) ) {
                    tmp++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index-cols]->returnID(), 1);
                    sokoAddEdge(nodes[index-cols]->returnID(), nodes[index]->returnID(), 1);
                }
                if ((mapMatrix[i-1][j] == 9 )&& (mapMatrix[i][j] !=1)) {
                    tmp++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index-cols]->returnID(), 1);
                    sokoAddEdge(nodes[index-cols]->returnID(), nodes[index]->returnID(), 1);
                }
                if ((mapMatrix[i-1][j] == 5 )&& (mapMatrix[i][j] !=1)) {
                    tmp++;
                    sokoAddEdge(nodes[index]->returnID(), nodes[index-cols]->returnID(), 1);
                    sokoAddEdge(nodes[index-cols]->returnID(), nodes[index]->returnID(), 1);
                }
            }
//            }
            index++;
         
        }
        cout<<endl;
        //cout<<"above:"<<tmp<<endl;
        //cout<<"beside:"<<tmp2<<endl;
    }
    cout<<"nodes"<<nodes.size()<<endl;
    printSokoGraph(edgePointer);
}
void Graph::Dijkstra(Vertex start, Vertex goal){
    
    queue<Vertex*>q;
    
    while (!q.empty() ) {
        
    }
    
}

Graph::~Graph()
{
}
