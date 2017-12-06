#include "Solver.h"

Solver::Solver(const string dest)
{
	string line;                    //string for reading each line
	ifstream sokoMap(dest);         //opening file from the destination
	if (sokoMap.is_open()) {         //if the file is opened commence reading
		while (getline(sokoMap, line)) {        // read one line at a time in the whole file
			map_content += line;                // append line into one big string
			map_content += "\n";                // append newline after each line
		}
	}
	else {
		cout << "could not open file. Check path to file" << endl;  //Debug line
	}
}

void Solver::makeMap()
{
	vector<string> data;
	std::stringstream ss(map_content);
	std::string to;

	if (&map_content != NULL)
		while (std::getline(ss, to, '\n'))
			data.push_back(to);
	data.erase(data.begin());
	size_t width = 0;
	for (auto &row : data)
		width = max(width, row.size());

	map<char, char> mapStatic = { { '.','.' },{ 'G','G' },{ 'M','.' },{ 'X','X' },{ 'J','.' } },
					mapVariable = { { '.','.' },{ 'G','.' },{ 'M','M' },{ 'X','.' },{ 'J','J' } };
	
	for (int r = 0; r < data.size(); r++) 
	{
		vector<char> staticTemp;
		vector<char> variableTemp;
		for (int c = 0; c < width; c++) 
		{
			char ch = c < data[r].size() ? data[r][c] : '.';
			staticTemp.push_back(mapStatic[ch]);
			variableTemp.push_back(mapVariable[ch]);
			if (ch == 'M') 
			{
				roboX = c;
				roboY = r;
			}
		}
		staticData.push_back(staticTemp);
		variableData.push_back(variableTemp);
	}
	cout << "first step" << endl;
}

string Solver::solve()
{
	unordered_map<string, string> closeList2;
	vector<Node> openList;
	openList.push_back(Node(variableData, " ", roboX, roboY));
	vector<vector<int>> direction = { {0,-1,UP},{1,0,RIGHT},{0,1,DOWN},{-1,0,LEFT} };
	cout << "Start while loop" << endl;
	int counter = 0;
	while (openList.size() > 0)
	{
		if(counter == 10000)
		{ 
			counter = 0;
			cout << closeList2.size() << endl;
		}
		Node current = openList[0];
		vector<vector<char>> tempState = current.State;
		string rount = current.rount;
		int x = current.posX;
		int y = current.posY;
		openList.erase(openList.begin());
		if (closeList2.find(stateToKey(tempState)) == closeList2.end())
		{
			for (int i = 0; i < 4; ++i)
			{
				tempState = current.State;
				int dx = direction[i][0];
				int dy = direction[i][1];
				if (tempState[y + dy][x + dx] == 'J')
				{
					if (push(x, y, dx, dy, tempState))
					{
							if (isSolved(tempState))
								return rount + to_string(direction[i][2]);
							openList.push_back(Node(tempState, rount + to_string(direction[i][2]), x + dx, y + dy));
					}
				}
				else if (move(x, y, dx, dy, tempState))
						openList.push_back(Node(tempState, rount + to_string(direction[i][2]), x + dx, y + dy));
			}
			closeList2.insert({ stateToKey(current.State),stateToKey(current.State) });
		}
		counter++;
	}

	return string();
}

Solver::~Solver()
{
}

string Solver::stateToKey(vector<vector<char>> state)
{
	string robotpos;
	string juvelpos;
	for (int r = 0; r < state.size(); r++)
	{
		for (int c = 0; c < state[r].size(); c++)
		{
			char ch = state[r][c];
			if (ch == 'M')
				robotpos = to_string(r) + to_string(c);
			else if (ch == 'J')
				juvelpos = juvelpos + to_string(r) + to_string(c);
		}
	}
	return robotpos+juvelpos;
}

bool Solver::push(int x, int y, int dx, int dy, vector<vector<char>> &tempState)
{
	if (staticData[y + 2 * dy][x + 2 * dx] == 'X' || tempState[y + 2 * dy][x + 2 * dx] != '.')
		return false;
	tempState[y][x] = '.';
	tempState[y + dy][x + dx] = 'M';
	tempState[y + 2 * dy][x + 2 * dx] = 'J';
	return true;
}

bool Solver::move(int x, int y, int dx, int dy, vector<vector<char>>& tempState)
{
	if (staticData[y + dy][x + dx] == 'X' || tempState[y + dy][x + dx] != '.')
		return false;
	tempState[y][x] = '.';
	tempState[y + dy][x + dx] = 'M';
	return true;
}

bool Solver::isSolved(vector<vector<char>> &tempState)
{
	for (size_t r = 0; r < tempState.size(); r++)
		for (size_t c = 0; c < tempState[r].size(); c++)
			if ((staticData[r][c] == 'G') != (tempState[r][c] == 'J'))
				return false;
	return true;
}
