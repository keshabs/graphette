#ifndef BITS_VECTOR_HPP
#define BITS_VECTOR_HPP

#include <vector>
#include <iostream>

// This function takes a decimal number and a number of nodes
// to find the binary representation of the decimal number and
// store it in a vector. Length of vector depends on number of nodes.

// Ex:
// num_nodes = 4       --->    Length of vector must be 6
// decimal_number = 3  --->    011 in binary
// vector = [0, 1, 1]  --->    vector = [0, 0, 1, 1]

std::vector<bool> bits_vector(int decimal_number, int num_nodes);


#endif // BITS_VECTOR_HPP
