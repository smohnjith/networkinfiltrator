#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include "progress.h"
#include "select.h"
#include "colour.h"

void progress_bar (int high, int low)
{
	short i;
	short spacecount = 100;
	short count = 50;
	uint8_t on = 0;
	printf(COLOUR_YELLOW);
	char * last;
	for (i = 0; i <= 100; i++)
	{
		char * frame = malloc(60);
		char * percentage = malloc(9);
		short j, length;
		short n = 50 - count;
		sprintf(percentage, "] : %d%%", 100 - spacecount);
		strcat(frame, "[ ");
		for (j = 0; j <= n; j++) 
		{
			if (j < n) strcat(frame, "=");
			else if (j == n) strcat(frame, ">");
		}
		for (j = 0; j < count; j++) strcat(frame, " ");
		strcat(frame, percentage);
		printf("%s", frame);
		fflush(stdout);
		length = strlen(frame);
		usleep(rand_range(high, low));
		if (on) on = 0;
		else
		{
			count--;
			on = 1;
		}
		spacecount--;
		clr(length);
		if (i == 100) last = frame;
		free(frame);
		free(percentage);
	}
	printf(COLOUR_RESET);
	printf("%s%s%s\n\n", COLOUR_GREEN, last, COLOUR_RESET);
}

