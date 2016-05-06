#ifndef GENERATE_ALL_BITS_VECTORS_HPP
#define GENERATE_ALL_BITS_VECTORS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "bits_vector.hpp"

// This function generates all the possible combinations of bits vectors
// using number of nodes as input. Think of it like generating all 
//  possible combinations of graphs with n nodes.

// Ex:
// num_nodes = 4
// Because there are 4 nodes, there are at most 6 possible
// edges meaning the length of a bit vector will be 6.
// So think of it like this: _ _ _ _ _ _
// Since each _ can be either 0 or 1, there will be 2^6 = 64 number of graphs.

// And this function's job is to generate 64 bits vectors with all the 
// possible combinations of binary values store in them.
// v0 = [0, 0, 0, 0, 0, 0]
// v1 = [0, 0, 0, 0, 0, 1]
// v2 = [0, 0, 0, 0, 1, 0]
// .
// .
// .
// .
// .
// .
// v62 = [1, 1, 1 ,1 ,1, 1]
std::vector<std::vector<bool>> generate_all_bits_vectors(int num_nodes);



#endif // GENERATE_ALL_BITS_VECTORS_HPP
