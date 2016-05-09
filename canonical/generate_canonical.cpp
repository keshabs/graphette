#include "generate_canonical.hpp"

std::vector<Graph*> generate_canonical(const std::vector<Graph*>& graph_vectors)
{
	// replaced_Graph is used to determine whether to insert a new Graph into graph_canonical or not
	bool replaced_Graph = false;
	std::vector<Graph*> graph_canonical;
	std::vector<Graph*> copy_c;

	for (auto i : graph_vectors)
	{
		if (graph_canonical.empty())
		{
			graph_canonical.push_back(i);
		}

		else
		{
			for (auto j = copy_c.begin(); j != copy_c.end(); j++)
			{
				if (graphIsomorphic(**j, *i))
				{
					replaced_Graph = true;
					if ((*j)->get_decimal_representation() > i->get_decimal_representation())
					{
						graph_canonical.erase(j);
						graph_canonical.push_back(i);
					}
					break;
				}
			}

			if (!replaced_Graph)
					graph_canonical.push_back(i);
		}

		replaced_Graph = false;
		copy_c = graph_canonical;
	}	

	return graph_canonical;	
}
