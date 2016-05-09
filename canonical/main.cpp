#include <iostream>
#include <chrono>
#include <set>
#include "bits_vector.hpp"
#include "generate_all_graphs.hpp"
#include "generate_all_bits_vectors.hpp"
#include "Graph.hpp"
#include "graphIsomorphic.hpp"

int main(int arg, char* argv[])
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	std::vector<Graph*> graph_vectors = generate_all_graphs(atoi(argv[1]));
	
	// replaced_Graph is used to determine whether to insert a Graph into graph_canonical
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

	std::cout << "Number of graphs: " << graph_vectors.size() << "\n";
	std::cout << "Size of canonical: " << graph_canonical.size() << std::endl;

	// This will show the decimal representations of adjMatrix of each Graph
	for (auto g : graph_canonical)
		std::cout << g->get_decimal_representation() << " ";
	std::cout << "\n";

	// Deallocate all Graphs
	for (unsigned int i = 0; i < graph_vectors.size(); i++)
	{
		delete graph_vectors[i];
	}

	// Output the time the program takes to run in seconds
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();            	
	std::cout << "Time: " << duration << " seconds" << std::endl;                                 
	
	return 0;
}




