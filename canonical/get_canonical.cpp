#include "get_canonical.hpp"

Graph* get_canonical(Graph* g, std::vector<Graph*> graph_canonical)
{
	for (auto i : graph_canonical)
	{
		if (graphIsomorphic(*i, *g))
		{
			return i;
		}
	}	

	return nullptr;
}