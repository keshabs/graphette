#include "convert_to_decimal.hpp"

long convert_to_decimal(std::vector<bool> v, int len)
{
	long result = 0;
	unsigned int j = 0;

	for (int i = v.size() - 1; i >= 0 && j < v.size(); i--, j++)
	{
		if (v.at(i) == 1)
		{
			long n = pow(2, int(j));
			result += n;		
		}		
	}	
	
	return result;
}
