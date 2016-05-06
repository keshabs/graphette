#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include "Graph.hpp"

using namespace std;

static Graph *isoG1, *isoG2;

bool GraphAreConnected(Graph *G, int i, int j)
{
    assert(0 <= i && i < G->getNumNodes() && 0 <= j && j < G->getNumNodes());
    if(G->sparse)
    {
	int k, n, *neighbors, me, other;
	// Check through the shorter list
	if(G->degree[i] < G->degree[j])
	{
	    me = i; other = j;
	}
	else
	{
	    me = j; other = i;
	}
	n = G->degree[me];
	neighbors = G->neighbor[me];
	for(k=0; k<n; k++)
	    if(neighbors[k] == other)
		return true;
	return false;
    }
    else
    {
	if(SetIn(G->A[i],j))
	{
	    if(!SetIn(G->A[j],i))
		Fatal("SetIn(%d,%d)=%ld, SetIn(%d,%d)=%ld\n", i,j,SetIn(G->A[i],j), j,i,SetIn(G->A[j],i));
	    return true;
	}
	else
	    return false;
    }
}

static bool _allPermutations
    (int n, int i, int *preArray, bool (*fcn)(int, int *))
{
    int j;
    if( n == i) /* output! */
	return fcn(n, preArray);

    for(j=0; j < n; j++)    /* put in slot i all j's not already appearing */
    {
	int k;
	for(k=0; k<i; k++)  /* see if this j's already been used */
	{
	    if(preArray[k] == j)
		break;
	}
	if(k == i)  /* this j hasn't appeared yet */
	{
	    int result;
	    preArray[i] = j;
	    if((result = _allPermutations(n, i+1, preArray, fcn)))
		return result;
	}
    }
    return false;
}

bool CombinAllPermutations(int n, bool (*fcn)(int, int *))
{
    int array[n];
    return _allPermutations(n, 0, array, fcn);
}

static bool _permutationIdentical(int n, int perm[n])
{
    int i, j;
    for(i=0; i<n; i++)
	if(isoG1->getDegree(i) != isoG2->getDegree(perm[i]))
	    return false;

    for(i=0; i<n; i++) for(j=i+1; j<n; j++)
	/* The !GraphAreConnected is just to turn a bitstring into a boolean */
	if(!GraphAreConnected(isoG1, i,j) !=
	    !GraphAreConnected(isoG2, perm[i], perm[j]))
	    return false;   /* non-isomorphic */
    return true;   /* isomorphic! */
}

bool graphIsomorphic(const Graph& G1, const Graph& G2){
	 int i, n = G1.getNumNodes(), degreeCount1[n], degreeCount2[n];

	 if(G1.getNumNodes() != G2.getNumNodes())
		return false;

    if(n < 2)
		return true;

	 for(i=0; i<n; i++)
	   degreeCount1[i] = degreeCount2[i] = 0;

    for(i=0; i<n; i++)
    {
	   ++degreeCount1[G1.getDegree(i)];
	   ++degreeCount2[G2.getDegree(i)];
    }

    for(i=0; i<n; i++)
	   if(degreeCount1[i] != degreeCount2[i])
	       return false;
    isoG1 = &G1; isoG2 = &G2;
    return !!CombinAllPermutations(n,_permutationIdentical);

}

int main(){
	


	Graph g1(4, vector<vector<ushort>>{{1,3},{0,3},{0,1}});

	cout <<"num of nodes: " <<  g1.getNumNodes() << endl;
	cout <<"num of edges: " <<g1.getNumEdges() << endl;
	cout <<"degree of node 1: " << g1.getDegree(1) << endl;
	cout <<"degree of node 2: " << g1.getDegree(2) << endl;
	cout <<"degree of node 3: " << g1.getDegree(3) << endl;


	return 0;
}

