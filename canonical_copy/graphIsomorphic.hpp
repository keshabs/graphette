#ifndef GRAPHISOMORPHIC_HPP
#define GRAPHISOMORPHIC_HPP


#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include "Graph.hpp"


bool GraphAreConnected(Graph *G, int i, int j);
bool _permutationIdentical(int n, int perm[]);
bool CombinAllPermutations(int n, bool (*fcn)(int, int *));
bool graphIsomorphic(Graph& G1, Graph& G2);



#endif // GRAPHISOMORHPIC_HPP
