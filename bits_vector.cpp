#include "bits_vector.hpp"

std::vector<bool> bits_vector(int decimal_number, int num_nodes)
{
	int num_possible_edges = (num_nodes*(num_nodes-1)) / 2;
	std::vector<bool> result(num_possible_edges);
	
	// Convert to binary number and put each bit in result vector.
	int i = result.size() - 1;
	while (decimal_number != 0)
	{
		bool remainder = decimal_number % 2;
		result[i] = remainder;
		--i;
		decimal_number /= 2;	
	}


	return result;
}
