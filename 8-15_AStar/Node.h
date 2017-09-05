#pragma once
#include <vector>
#include <queue>
#include <stdlib.h>
#include <iostream>

class Node
{
public:
	typedef std::vector<std::vector<int>> State;
	
	Node(State state);
	~Node();

	int heuristic(int currentCost);
	int cost;

private:
	State mState;


};



