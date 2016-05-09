#ifndef GENERATE_ALL_GRAPHS_HPP
#define GENERATE_ALL_GRAPHS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "Graph.hpp"
#include "generate_all_bits_vectors.hpp"

// This functions is similar to generate_all_bits_vectors function.
// With a given number of nodes, we can generte all the possible 
// graph combinations with n nodes.

// I have defined a member function in SANA Graph class called setAdjMatrix().
// This member function uses a bit vector as input and put each bit inside
// that bit vector into the correct position of the Graph's adjMatrix, only
// in the upper right triangle of the matrix.

// Ex:
// v = [1, 1, 1, 0, 0, 1]
// Take v and put each bit in v to a Graph's adjMatrix.
// So the result will be
// 
// x 1 1 1
// x x 0 0
// x x x 1
// 
// x means we don't care about values in that position.

// So with 4 nodes, generate_all_graphs will generate 64 graphs.
std::vector<Graph*> generate_all_graphs(int node_number);


#endif // GENERATE_ALL_GRAPHS_HPP
