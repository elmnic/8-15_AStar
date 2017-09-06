#include "Solver.h"



Solver::Solver()
{
}


std::vector<Node*> Solver::solve(StateStruct::State start, StateStruct::State goal)
{

	// Push start node
	openList.push(new Node(start, NULL, 0));

	// A set is used to search for the occurence of a node in the openList
	openSet.insert(openList.top());

	closedList.clear();
	cameFrom.clear();

	// Add start node to cameFrom vector
	cameFrom.push_back(openList.top());

	while (!openList.empty()) 
	{
		Node *current = openList.top();
		if (current->getState() == goal) 
		{
			return cameFrom;
		}

		// Create child nodes
		current->expandChildren();

		openSet.erase(current);
		openList.pop();
		closedList.push_back(current);

		std::cout << "Nr of children: " << current->getChildren().size() << std::endl;

		for each (Node* child in current->getChildren())
		{
			// If child already expanded
			if (std::find(closedList.begin(), closedList.end(), child) != closedList.end()) {
				continue;
			}
			
			// If child not yet opened, add to openList
			if (openSet.find(child) != openSet.end())  
			{
				openSet.insert(child);
				openList.push(child);
			}

			// If childs path cost is lower, then that path is better
			if (current->pathCost >= child->pathCost)
				continue;

			cameFrom.push_back(child);
			child->pathCost++;
			child->heuristicCost = child->pathCost + child->heuristic();

		}
	}

	return cameFrom;
}

bool Solver::isGoal(StateStruct::State state, StateStruct::State goal)
{

	return false;
}

Solver::~Solver()
{
}
