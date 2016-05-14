#include "graphette.hpp"

std::vector<bool> bits_vector(int decimal_number, int num_nodes)
{
	int num_possible_edges = (num_nodes*(num_nodes-1)) / 2;
	std::vector<bool> result(num_possible_edges);
	
	// Convert to binary number and put each bit in result vector.
	int i = result.size() - 1;
	while (decimal_number != 0)
	{
		result[i] = decimal_number % 2;
		--i;
		decimal_number /= 2;	
	}

	return result;
}


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


std::vector<Graph*> generate_all_graphs(int num_nodes)
{
	std::vector<std::vector<bool>> all_bits_vectors = generate_all_bits_vectors(num_nodes);
	int num_graphs = pow(2, (num_nodes*(num_nodes - 1)) / 2);
	std::vector<Graph*> result;

	for (int i = 0; i < num_graphs; i++)
	{
		// The way I have constructed these Graphs is to define a new 
		// constructor in the Graph class. This new constructor takes in 
		// a number of nodes, and initializes its adjMatrix and adjList vectors.
		// Otherwise, we will get Segmentation Fault if we don't intialize these
		// private members in Graph class.
		Graph* g = new Graph(num_nodes);
        	g->setAdjMatrix(all_bits_vectors[i]);
	        g->set_decimal_representation(i);
        	result.push_back(g);
	}	

	
	return result;
}


std::vector<Graph*> generate_canonical(const std::vector<Graph*>& graph_vectors)
{
	// replaced_Graph is used to determine whether to insert a new Graph into graph_canonical or not
	bool replaced_Graph = false;
	std::vector<Graph*> graph_canonical;
	std::vector<Graph*> copy_c;

	for (auto i : graph_vectors)
	{
		if (graph_canonical.empty())
		{
			graph_canonical.push_back(i);
		}

		else
		{
			for (auto j = copy_c.begin(); j != copy_c.end(); j++)
			{
				if (graphIsomorphic(**j, *i))
				{
					replaced_Graph = true;
					if ((*j)->get_decimal_representation() > i->get_decimal_representation())
					{
						graph_canonical.erase(j);
						graph_canonical.push_back(i);
					}
					break;
				}
			}

			if (!replaced_Graph)
					graph_canonical.push_back(i);
		}

		replaced_Graph = false;
		copy_c = graph_canonical;
	}	

	return graph_canonical;	
}


Graph* get_canonical(Graph* g, std::vector<Graph*> graph_canonical)
{
	for (auto i : graph_canonical)
	{
		if (graphIsomorphic(*i, *g))
		{
			return i;
		}
	}	

	return nullptr;
}


// using namespace std;
// static Graph *isoG1, *isoG2;

// bool GraphAreConnected(Graph *G, int i, int j)
// {
//     assert(0 <= i && i < (int)G->getNumNodes() && 0 <= j && j < (int)G->getNumNodes());

// 	int k, n, me, other;
// 	vector<ushort> neighbors;
// 	// Check through the shorter list
// 	if(G->getDegree(i) < G->getDegree(j))
// 	{
// 	    me = i; other = j;
// 	}
// 	else
// 	{
// 	    me = j; other = i;
// 	}
// 	n = G->getDegree(me);
// 	//Convert this to SANA graph class neighbors = G->returnAdjLists()[me];
// 	vector<vector<ushort>> adjList;
// 	G->getAdjLists(adjList);
// 	neighbors = adjList[me];
// 	for(k=0; k<n; k++)
// 	    if(neighbors[k] == other)
// 		return true;
// 	return false;

// }

// static bool _allPermutations
//     (int n, int i, int *preArray, bool (*fcn)(int, int *))
// {
//     int j;
//     if( n == i) /* output! */
// 	return fcn(n, preArray);

//     for(j=0; j < n; j++)    /* put in slot i all j's not already appearing */
//     {
// 	int k;
// 	for(k=0; k<i; k++)  /* see if this j's already been used */
// 	{
// 	    if(preArray[k] == j)
// 		break;
// 	}
// 	if(k == i)  /* this j hasn't appeared yet */
// 	{
// 	    int result;
// 	    preArray[i] = j;
// 	    if((result = _allPermutations(n, i+1, preArray, fcn)))
// 		return result;
// 	}
//     }
//     return false;
// }

// bool _permutationIdentical(int n, int perm[])
// {
//     int i, j;
//     for(i=0; i<n; i++)
// 	if(isoG1->getDegree(i) != isoG2->getDegree(perm[i]))
// 	    return false;

//     for(i=0; i<n; i++) for(j=i+1; j<n; j++)
// 	/* The !GraphAreConnected is just to turn a bitstring into a boolean */
// 	if(!GraphAreConnected(isoG1, i,j) !=
// 	    !GraphAreConnected(isoG2, perm[i], perm[j]))
// 	    return false;   /* non-isomorphic */
//     return true;   /* isomorphic! */
// }

// bool CombinAllPermutations(int n, bool (*fcn)(int, int *))
// {
//     int array[n];
//     return _allPermutations(n, 0, array, fcn);
// }


// bool graphIsomorphic(Graph& G1, Graph& G2)
// {
//     int i, n = G1.getNumNodes(), degreeCount1[n], degreeCount2[n];

//     if(G1.getNumNodes() != G2.getNumNodes())
//     	return false;

//     if(n < 2)
//     	return true;

//     for(i=0; i<n; i++)
// 	degreeCount1[i] = degreeCount2[i] = 0;

//     for(i=0; i<n; i++)
//     {
// 	   ++degreeCount1[G1.getDegree(i)];
// 	   ++degreeCount2[G2.getDegree(i)];
//     }

//     for(i=0; i<n; i++)
// 	   if(degreeCount1[i] != degreeCount2[i])
// 	       return false;
//     isoG1 = &G1; isoG2 = &G2;
//     return !!CombinAllPermutations(n,_permutationIdentical);

// }
