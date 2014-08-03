#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "colour.h"
#include "select.h"
#include "disclaim.h"

void disclaimer(void)
{
	int i;
	printf("\n\n\n");
	printf(COLOUR_YELLOW);
	for (i = 0; i < strlen(DISCLAIMER); i++)
	{
		printf("%c", DISCLAIMER[i]);
		fflush(stdout);
		usleep(rand_range(5000, 10000));
	}
	printf(COLOUR_RESET);
	printf("\n\n\n");
}
