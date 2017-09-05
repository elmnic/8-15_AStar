#pragma once

#include "Node.h"

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

	void h(Node::State state);

	std::vector<Node::State> solve(Node::State start, Node::State goal);

private:
	std::priority_queue<Node*, std::vector<Node*>, CompareCost> openList;
};

