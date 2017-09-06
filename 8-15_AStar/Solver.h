#pragma once

#include "Node.h"
#include "StateStruct.h"
#include <algorithm>
#include <set>

struct OrderByCost
{
	bool operator()(Node const *n1, Node const *n2)
	{
		return n1->pathCost < n2->pathCost;
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
	std::priority_queue<Node*, std::vector<Node*>, OrderByCost> openList;
	std::vector<Node*> closedList;

	std::set<Node*> openSet;

	// Contains the solution
	std::vector<Node*> cameFrom;
};

