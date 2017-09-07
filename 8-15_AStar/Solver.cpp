#include "Solver.h"



Solver::Solver()
{
}

Solver::~Solver()
{
	clear();
}


std::vector<Node*> Solver::solve(StateStruct::State start, StateStruct::State goal)
{

	//TODO: Fix priority queue sorting

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
			std::cout << "Found solution" << std::endl;
			return reconstructPath(current);
		}

		std::cout << "openList top: " << current->totalCost << std::endl;

		// Create child nodes
		current->expandChildren();

		openSet.erase(current);
		openList.pop();
		closedList.push_back(current);

		//std::cout << "Nr of children: " << current->getChildren().size() << std::endl;

		for each (Node* child in current->getChildren())
		{
			//std::cout << "Child node..." << std::endl;

			// If child already expanded
			for (int i = 0; i < closedList.size(); i++)
			{
				if (StateStruct::compare(closedList[i]->getState(), child->getState()))
				{
					std::cout << "Already expanded" << std::endl;
					continue;
				}
			}

			/*if (std::find(closedList.begin(), closedList.end(), child) != closedList.end()) 
			{
				continue;
			}*/
			bool isInClosed = false;
			for (int i = 0; i < closedList.size(); i++)
			{
				if (StateStruct::compare(closedList[i]->getState(), child->getState()))
					isInClosed = true;
			}
			if (isInClosed)
				continue;
			
			// If child not yet opened, add to openList
			bool foundInstance = false;
			std::set<unsigned long>::iterator it;
			for (auto it = openSet.begin(); it != openSet.end(); it++)
			{
				Node *temp = *it;
				if (StateStruct::compare(temp->getState(), child->getState()))
				{
					foundInstance = true;
				}
			}

			if (!foundInstance)
			{
				std::cout << "Added to openList" << std::endl;
				openSet.insert(child);
				openList.push(child);
			}


			// If childs path cost is lower, then that path is better
			if (current->pathCost >= child->pathCost)
				continue;

			cameFrom.push_back(child);
			child->pathCost;
			//child->heuristicCost = child->pathCost + child->heuristic();

		}
	}

	return cameFrom;
}

std::vector<Node*> Solver::reconstructPath(Node * finalChild)
{
	std::vector<Node*> pathBackwards;
	pathBackwards.push_back(finalChild);



	return std::vector<Node*>();
}

void Solver::clear()
{

	while (!openList.empty())
	{
		delete openList.top();
		openList.pop();
	}

	for (auto i = closedList.begin(); i != closedList.end(); )
	{
		delete *i;
		i = closedList.erase(i);
	}

	openSet.clear();
	cameFrom.clear();
}

bool Solver::isGoal(StateStruct::State state, StateStruct::State goal)
{

	return false;
}

