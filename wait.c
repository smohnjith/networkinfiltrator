#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "wait.h"

void do_wait(char * msg, int n)
{
	int i, j;
	short length = (strlen(msg) + 7);
	char bar[4] = {'-', '\\', '|', '/'};
	printf("%s... (", msg);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%c)", bar[j]);
			fflush(stdout);
			usleep(250000);
			printf("\b\b");
		}
	}
	printf("\b");
}

