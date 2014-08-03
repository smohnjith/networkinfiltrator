#include <stdio.h>
#include <stdlib.h>
#include "select.h"

int rand_range(int lower, int upper)
{
	int limit = upper - lower;
	int divisor = RAND_MAX / (limit + 1);
	int retval;
	do
	{ 
		retval = rand() / divisor;
	}
	while (retval > limit);
	return (retval + lower);
}
