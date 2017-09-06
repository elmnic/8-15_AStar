#pragma once

#include <vector>>

using namespace std;;

struct StateStruct
{
	typedef vector<vector<int>> State;
};
	bool operator==(const StateStruct::State &s0, const StateStruct::State &s1)
	{
		return s0 == s1;
	}

