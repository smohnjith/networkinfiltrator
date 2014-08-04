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
#include <stdint.h>
#include <unistd.h>
#include "colour.h"
#include "select.h"
#include "acquire.h"

void acquire_data(void)
{
	short mask_length = ((LINES * WIDTH) / LINES) * 2;
	int longmask_length = (LINES * WIDTH * COLUMNS) / 10;
	char buf[mask_length * COLUMNS];
	uint8_t change = 0;
	int bufcount = 0;
	int mask[mask_length];
	int longmask[longmask_length];
	int i, j, k;
	for (i = 0; i < longmask_length; i++) longmask[i] = rand_range(0, ((LINES * (WIDTH * COLUMNS)) - 1));
	for (i = 0; i < mask_length; i++) mask[i] = rand_range(0, ((LINES * WIDTH) - 1));
	for (i = 0; i < LINES; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			int iter = (i * WIDTH) + j;
			int x;
			for (x = 0; x < mask_length; x++) if (mask[x] == iter) change = 1;
			if (change)
			{
				printf(BG_MAGENTA);
				for (k = 0; k < COLUMNS; k++)
				{
					char c = rand_range(33, 123);
					printf("%c", c);
					buf[bufcount] = c;	
					bufcount++;
				}
				printf(" ");
				printf(COLOUR_RESET);
				change = 0;
			}
			else
			{
				for (k = 0; k < COLUMNS; k++)
				{
					for (x = 0; x < longmask_length; x++) if (longmask[x] == (iter + k)) change = 1;
					if (change)
					{
						printf(COLOUR_RESET);
						change = 0;
					}
					else printf(COLOUR_GREEN);
					printf("%c", rand_range(33, 123));
				}
				printf(" %s", COLOUR_RESET);
			}
		}
		fflush(stdout);
		printf("\n");
		usleep(25000);
	}
	printf(COLOUR_RESET);
	sleep(1);
	printf("\nSuccess: RSA key found\n\n");
	sleep(1);

	for (i = 0; i < mask_length; i++)
	{
		if (i == (mask_length / 2)) printf("\n");
		printf(BG_MAGENTA);
		for (j = 0; j < COLUMNS; j++)
		{
			printf("%c", buf[(i * COLUMNS) + j]);
		}
		printf(COLOUR_RESET);
		printf(" ");
		fflush(stdout);
		usleep(100000);
	}
}

