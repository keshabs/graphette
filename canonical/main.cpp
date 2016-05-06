#include <iostream>
#include <string>
#include <chrono>
#include "bits_vector.hpp"
#include "convert_to_decimal.hpp"
#include "generate_all_graphs.hpp"
#include "generate_all_bits_vectors.hpp"
#include "printUpperTriangle.hpp"
#include "Graph.hpp"

// This function prints a bit vector in this format:
// v = [1, 1, 0, 0, 0, 0]  ---> 110000
void print_bits_vector(std::vector<bool> bv)
{
	for (auto i : bv)
	{
		std::cout << i;
	}
}

// This function is similar to Graph's print_adjMatrix() member function. So ignore it.
//
//void print_adjMatrix(Graph& g, bool upper)
//{
//	std::vector<std::vector<bool>> copy_adjMatrix;
//	g.getAdjMatrix(copy_adjMatrix);
//	for (unsigned int i = 0; i < copy_adjMatrix.size(); i++)
//	{
//		for (unsigned int j = 0; j < copy_adjMatrix.size(); j++)
//		{
//			if (upper)
//			{
//				if (i < j) std::cout << copy_adjMatrix[i][j] << " ";
//				else       std::cout << "  ";
//			}
//			else
//				std::cout << copy_adjMatrix[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
//}


int main()
{
//      IGNORE THIS COMMENT SECTION PART. THIS IS JUST MY DRAFT WORKS.
//	int dim = 4;
//	std::vector<std::vector<bool>> v;
//	std::vector<std::vector<bool>> d(dim, std::vector<bool>(dim));
//
//	for (int i = 0; i < dim; i++)
//	{
//		v.push_back(std::vector<bool>());
//		for (int j = 0; j < dim; j++)
//		{
//			v[0].push_back(1);
//		}
//	}
	

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	
	std::vector<Graph> graph_vectors = generate_all_graphs(4);
	std::cout << "Number of graphs: " << graph_vectors.size() << "\n\n";

	for (unsigned int i = 0; i < graph_vectors.size(); i++)
	{
	      std::cout << "Graph #" << i + 1 << ":\n";

	      // print_adjMatrix is another Graph member function I have defined.
	      // It just prints a Graph's adjMatrix in a full matrix or just the upper right triangle.
	      // 0 --> matrix
	      // 1 --> upper right triangle only
	      graph_vectors[i].print_adjMatrix(1);
	      std::cout << "\n";
	}
		

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();            	
	std::cout << "Time: " << duration << " seconds" << std::endl;                                 
	
	return 0;
}




