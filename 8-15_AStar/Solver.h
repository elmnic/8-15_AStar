#pragma once

#include "Node.h"
#include "StateStruct.h"
#include <algorithm>
#include <set>

struct CompareCost
{
	bool operator()(const Node & n1, const Node & n2)
	{
		return n1.cost < n2.cost;
	}
};

class Solver
{
public:

	Solver();
	~Solver();

	std::vector<Node*> solve(StateStruct::State start, StateStruct::State goal);

private:
	bool isGoal(StateStruct:: State state, StateStruct::State goal);

	// Queue not yet expanded child nodes
	std::priority_queue<Node*, std::vector<Node*>, CompareCost> openList;
	std::vector<Node*> closedList;

	std::set<Node*> openSet;

	// Contains the solution
	std::vector<Node*> cameFrom;
};

