#include "test.h"

int fcn(int i, int j)
{
	return i+j;
}

int common_a = 1;
const int const_b = 2;

//const int const_g = 2;
extern const int const_h = fcn(10, 20);
