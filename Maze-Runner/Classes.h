
#ifndef MAZERUNNER_CLASS_H
#define MAZERUNNER_CLASS_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

struct node
{
	int x, y;

	node()
	{
		x = 0; y = 0;
	}
	node(int posx, int posy)
	{
		x = posx;
		y = posy;
	}
};
struct vertix
{
	int num;
	int x, y;
	float cost;
	int parent;
};

class The_Maze {
	int row, coloumn;
	pair <int, int> startingPoint, endingPoint;
	char** Maze;
	bool** visitedPositions;
	queue<node> Node;
	pair<int, int>** parents;
	stack<pair<int, int>> s;
	int dfs_path_ctr = 0;
	int dfs_steps_ctr = 0;
	///// Generation of the maze 
	void creating_2D_arrays();
	void Generation(); 
	pair < int, int > GetRandomNeighbour(int, int); 
	bool isValid(int i, int j); 
	void ConnectTwoNodes(pair< int, int >, pair < int, int >); 
	void fillMaze();
	void CustomizeShapeOfMaze();
	/////
	void zeroVisitedArray();
	void clear();
	void printMethod(int, int, pair<int, int>[], string);
	/////
	double BestFact(pair<int, int>);
	int bestTrack(pair<int, int>, int, pair<int, int>[]);
	void getChildren(node, priority_queue<pair<double, pair<int, int>>>&);
	void getChild(node, int, int, priority_queue<pair<double, pair<int, int>>>&);
	////
	void BFS_Helper(pair<int, pair<int, int>> ** &Cells, node temp, node temp2);
	void BFS_Found(pair<int, pair<int, int>> ** &Cells, node temp, node temp2, int count);
	////
	bool dfs_help(int i, int j);
	////
	float calcWeight(vertix s);
	void addEdge(vector<pair<vertix, vector<pair<float, vertix>>>> & Nodes);
	void Dijkstra(vector<pair<vertix, vector<pair<float, vertix>>>> & Nodes);
	void showOut(vector<pair<vertix, vector<pair<float, vertix>>>> & Nodes);


public:
	The_Maze();
	~The_Maze();
	void GenerateMaze(); 
	void takeInput(string);
	void printMaze();
	void BestFirst();
	void BFS();
	void dfs();
	void DijkstraSearch();
};



#endif //MAZERUNNER_CLASS_H