#include "generate_all_graphs.hpp"

std::vector<Graph> generate_all_graphs(int num_nodes)
{
	std::vector<std::vector<bool>> all_bits_vectors = generate_all_bits_vectors(num_nodes);
	int num_graphs = pow(2, (num_nodes*(num_nodes - 1)) / 2);
	std::vector<Graph> result;

	for (int i = 0; i < num_graphs; i++)
	{
		// The way I have constructed these Graphs is to define a new 
		// constructor in the Graph class. This new constructor takes in 
		// a number of nodes, and initializes its adjMatrix and adjList vectors.
		// Otherwise, we will get Segmentation Fault if we don't intialize these
		// private members in Graph class.
		Graph g = Graph(num_nodes);
		g.setAdjMatrix(all_bits_vectors[i]);
		result.push_back(g);
	}	
	
	return result;
}
