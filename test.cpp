#include <iostream>
#include <vector>
#include <set>
#include "Graph.hpp"

using namespace std;

bool GraphIsomorphic(const Graph &G1, const Graph &G2);

int main(){
	vector<vector<ushort>> edgeList;
	vector<ushort> e1; e1.push_back(1); e1.push_back(3);
	vector<ushort> e2; e2.push_back(0); e2.push_back(3);
	vector<ushort> e3; e3.push_back(0); e3.push_back(1);
	edgeList.push_back(e1), edgeList.push_back(e2), edgeList.push_back(e3);

	Graph g1(4, edgeList);
	// g1.loadGwFile("syeast0.gw");
	cout << g1.getNumNodes() << endl;
	cout << g1.getNumEdges() << endl;
	cout << g1.getDegree(1) << endl;
	cout << g1.getDegree(2) << endl;

	cout << endl;
	cout << "testing test" << endl;
	cout << "testing line 2" << endl;

	return 0;
}


//Convert this function to C++!
bool GraphIsomorphic(const Graph &G1, const Graph &G2){
	//delete 'return true' after finish converting this function
	return true;

	// int i, n = G1.getNumNodes(), degreeCount1[n], degreeCount2[n];
 //    set<int> degreeOnce;

 //    /*
 //    ** First some simple tests.
 //    */
 //    if(G1.getNumNodes() != G2.getNumNodes())
	// 	return false;
    
 //    if(n < 2)
	// 	return true;

 //    /*
 //    ** Ensure each degree occurs the same number of times in each.
 //    */
 //    for(i=0; i<n; i++)
	//    degreeCount1[i] = degreeCount2[i] = 0;
 //    for(i=0; i<n; i++)
 //    {
	//    ++degreeCount1[G1.getDegree(i)];
	//    ++degreeCount2[G2.getDegree(i)];
 //    }
 //    for(i=0; i<n; i++)
	//    if(degreeCount1[i] != degreeCount2[i])
	//        return false;

 //    /*
 //    ** Let degree d appear only once.  Then there is exactly one vertex
 //    ** v1 in G1 with degree d, and exactly one vertex v2 in G2 with degree d.
 //    ** G1 and G2 are isomorphic only if the neighborhood of v1 is isomorphic
 //    ** to the neighborhood of v2.
 //    */
 //    // degreeOnce = SetAlloc(n);
 //    for(i=0; i<n; i++)
	// 	if(degreeCount1[i] == 1)
	// 		degreeOnce.insert(i);

	// //CONVERT REST OF CODE TO C++
 //    for(i=0; i<n; i++)
 //    {
	// 	/* Find out if the degree of vertex i in G1 appears only once */
	// 	if(SetIn(degreeOnce, G1->degree[i]))
	// 	{
	// 	    int j, degree = G1->degree[i];
	// 	    GRAPH *neighG1i, *neighG2j;

	// 	     find the (unique) vertex in G2 that has the same degree 
	// 	    for(j=0; j < n; j++)
	//     		if(G2->degree[j] == degree)
	//     		    break;
	// 	    assert(j < n);

	// 	    assert(!G1->sparse && !G2->sparse);
	// 	    neighG1i = GraphInduced(NULL, G1, G1->A[i]);
	// 	    neighG2j = GraphInduced(NULL, G2, G2->A[j]);

	// 	    /*
	// 	    ** Note: this recursion works only as long as
	// 	    ** _permutationIdentical doesn't call GraphsIsomorphic.
	// 	    ** (if it does, isoG1 and isoG2 get messed up).
	// 	    */

	// 	    j = GraphsIsomorphic(neighG1i, neighG2j);
	// 	    GraphFree(neighG1i);
	// 	    GraphFree(neighG2j);
	// 	    if(!j)
	// 			return false;
	// 	    /* Otherwise they *might* be isomorphic, so keep going */
	// 	}
 //    }
 //    SetFree(degreeOnce);

 //    /*
 //    ** Oh well, fire up the exponential search.
 //    ** CombinAllPermutations will return 0 iff all permutations were
 //    ** tried; the function _permutationIdentical should return non-zero
 //    ** when it finds an identical permutation, and that non-zero value
 //    ** will be returned here, indicating an identical permutation was
 //    ** found, ie, that the graphs are isomorphic.
 //    */
 //    isoG1 = G1; isoG2 = G2;
 //    return !!CombinAllPermutations(n, _permutationIdentical);	
}