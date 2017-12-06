#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

using namespace std;

struct Node {
public:
	vector<vector<char>> State;
	string rount;
	int posX;
	int posY;
	Node(vector<vector<char>> state,string rounte,int x, int y) : State(state) ,rount(rounte), posX(x),posY(y)
	{}
};

class Solver
{
public:
	Solver(const string dest);
	void makeMap();
	string solve();
	~Solver();
private:
	string map_content;
	string stateToKey(vector<vector<char>> state);
	bool push(int x, int y, int dx, int dy, vector<vector<char>> &tempState);
	bool move(int x, int y, int dx, int dy, vector<vector<char>> &tempState);
	bool isSolved(vector<vector<char>> &tempState);
	vector<vector<char>> staticData;
	vector<vector<char>> variableData;
	int roboX;
	int roboY;
};

