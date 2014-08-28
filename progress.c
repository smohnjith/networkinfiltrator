/*
 *  Network Infiltrator
 *  Copyright (C) 2014  John S. Miller
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
	short pcount = 100;
	short spacecount = 50;
	uint8_t on = 0;
	printf(COLOUR_YELLOW);
	char * last;
	for (i = 0; i <= 100; i++)
	{
		char * frame = malloc(60);
		char * percentage = malloc(9);
		short j, length;
		short n = 50 - spacecount;
		sprintf(percentage, "] : %d%%", 100 - pcount);
		strcat(frame, "[ ");
		for (j = 0; j <= n; j++) 
		{
			if (j < n) strcat(frame, "=");
			else if (j == n) strcat(frame, ">");
		}
		for (j = 0; j < spacecount; j++) strcat(frame, " ");
		strcat(frame, percentage);
		printf("%s", frame);
		fflush(stdout);
		length = strlen(frame);
		usleep(rand_range(high, low));
		spacecount -= on;
		on = !on;
		pcount--;
		printf("\r");
		if (i == 100) last = frame;
		free(frame);
		free(percentage);
	}
	printf(COLOUR_RESET);
	printf("\n%s%s%s\n\n", COLOUR_GREEN, last, COLOUR_RESET);
}

