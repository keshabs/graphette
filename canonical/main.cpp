#include <iostream>
#include <string>
#include <chrono>
#include "bits_vector.hpp"
#include "generate_all_graphs.hpp"
#include "generate_all_bits_vectors.hpp"
#include "printUpperTriangle.hpp"
#include "Graph.hpp"
#include "graphIsomorphic.hpp"

int main(int arg, char* argv[])
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	std::vector<Graph> graph_vectors = generate_all_graphs(atoi(argv[1]));
	std::cout << "Number of graphs: " << graph_vectors.size() << "\n\n";

	for (unsigned int i = 0; i < graph_vectors.size(); i++)
	{	
		// TEST CASES FOR CHECKING ISOMORPHISM 
		//for (unsigned int j = 0; j < graph_vectors.size(); j++)
			//std::cout << "Graph #" << i << " and Graph #" << j << ": " << graphIsomorphic(graph_vectors[i], graph_vectors[j]) << std::endl;
	     
	     // print_adjMatrix is another Graph member function I have defined.
	     // It just prints a Graph's adjMatrix in a full matrix or just the upper right triangle.
	     // 0 --> full matrix
	     // 1 --> upper right triangle only

	        // PRINT THE MATRIX AND ITS DECIMAL REPRESENTATION
		std::cout << "Decimal Rep: " << graph_vectors[i].get_decimal_representation()  << "\n";
	        graph_vectors[i].print_adjMatrix(1);
	        std::cout << "\n";
	}
		

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();            	
	std::cout << "Time: " << duration << " seconds" << std::endl;                                 
	
	return 0;
}




