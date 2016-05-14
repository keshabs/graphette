#include <iostream>
#include <chrono>
#include "graphette.hpp"

int main(int arg, char* argv[])
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	// Generate all graphs with n nodes.
	// Generate the canonical array, in this case it's a vector.
	std::vector<Graph*> graph_vectors = generate_all_graphs(atoi(argv[1]));
	std::vector<Graph*> graph_canonical = generate_canonical(graph_vectors);
	std::cout << "Number of graphs                 : " << graph_vectors.size() << "\n";
	std::cout << "Size of canonical                : " << graph_canonical.size() << "\n";

	// This will show the decimal representations of adjMatrix of each Graph
	std::cout << "Canonical Graph adjMatrix dec_rep: ";
	for (Graph* g : graph_canonical)
		std::cout << g->get_decimal_representation() << " ";
	std::cout << "\n\n";

	// This will give an assertion error because a Graph with 7 nodes
	// can only have up to 2097152 edges. Delete just 1 digit in 3000000
	// to make it work.
	std::vector<std::vector<bool>> v = decimal_to_matrix(3000000, 7);
	print_matrix(v);

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




