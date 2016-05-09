#include "generate_all_bits_vectors.hpp"

std::vector<std::vector<bool>> generate_all_bits_vectors(int num_nodes)
{
	//int num_vectors = pow(2, num_nodes);
	int num_vectors = pow(2, (num_nodes*(num_nodes - 1)) / 2);
	//std::vector<std::vector<bool>> result(num_vectors, std::vector<bool>(num_vectors));
	std::vector<std::vector<bool>> result;
	
	for (int i = 0; i < num_vectors; i++)
	{
		// Use i to make bits vector
		//std::vector<bool> bv = bits_vector(i, num_nodes);
		//result[i] = bv;
		result.push_back(bits_vector(i, num_nodes));
	}	

	return result;
}



