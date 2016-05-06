#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include "Graph.hpp"

using namespace std;

static Graph *isoG1, *isoG2;


bool GraphAreConnected(Graph *G, int i, int j)
{
    assert(0 <= i && i < (int)G->getNumNodes() && 0 <= j && j < (int)G->getNumNodes());

	int k, n, me, other;
	vector<ushort> neighbors;
	// Check through the shorter list
	if(G->getDegree(i) < G->getDegree(j))
	{
	    me = i; other = j;
	}
	else
	{
	    me = j; other = i;
	}
	n = G->getDegree(me);
	//Convert this to SANA graph class neighbors = G->returnAdjLists()[me];
	vector<vector<ushort>> adjList;
	G->getAdjLists(adjList);
	neighbors = adjList[me];
	for(k=0; k<n; k++)
	    if(neighbors[k] == other)
		return true;
	return false;

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
bool _permutationIdentical(int n, int perm[])
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

bool CombinAllPermutations(int n, bool (*fcn)(int, int *))
{
    int array[n];
    return _allPermutations(n, 0, array, fcn);
}



bool graphIsomorphic(Graph& G1, Graph& G2){
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
	


	Graph g1(5, vector<vector<ushort>>{{0,1},{1,4},{4,0}});

	Graph g2(5,vector<vector<ushort>>{{1,3},{3,2},{1,4}});

	Graph g3(5,vector<vector<ushort>>{{1,3},{3,4},{1,4}});



	cout<< "isomorphic? = " << (graphIsomorphic(g1,g2) ? "yes" : "no") << endl; // should be no
	cout<< "isomorphic? = " << (graphIsomorphic(g1,g3) ? "yes" : "no") << endl; // should be yes
	cout<< "isomorphic? = " << (graphIsomorphic(g2,g3) ? "yes" : "no") << endl; // should be no


	return 0;
}

