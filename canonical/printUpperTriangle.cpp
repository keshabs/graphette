#include "printUpperTriangle.hpp"

void printUpperTriangle(std::vector< std::vector<bool> > v, int dim)
{
	// It will always be a square matrix
	// dim is the length matrix
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (i < j)
				std::cout << v[i][j] << " ";
			else
				std::cout << "  ";
		}		
		std::cout << "\n";
	}
}

