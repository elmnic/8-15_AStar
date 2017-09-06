#include "Solver.h"



Solver::Solver()
{
}


std::vector<Node*> Solver::solve(StateStruct::State start, StateStruct::State goal)
{

	// Push start node
	openList.push(new Node(start, NULL, 0));
	openSet.insert(openList.top());

	closedList.clear();

	// Add start node to cameFrom vector
	cameFrom.push_back(openList.top());

	while (!openList.empty()) 
	{
		Node *current = openList.top();
		if (current->getState() == goal) 
		{
			return cameFrom;
		}

		openSet.erase






		openList.pop();
		closedList.push_back(current);

		current->expandChildren();
		for each (Node* child in current->getChildren())
		{
			// If child in closedList
			if (std::find(closedList.begin(), closedList.end(), child) != closedList.end()) {
				continue;
			}
			
			for each (Node* nodeInPQueue in )
			{

			}
		}

	}



	return std::vector<Node*>();
}

bool Solver::isGoal(StateStruct::State state, StateStruct::State goal)
{

	return false;
}

Solver::~Solver()
{
}
