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
	short mask_length = (ACQUIRE_TIME * 8) / 10;
	int mask[mask_length];
	int i, j, k;
	for (i = 0; i < mask_length; i++) mask[i] = rand_range(0, (ACQUIRE_TIME * 8));
	for (i = 0; i < ACQUIRE_TIME; i++)
	{
		for (j = 0; j < 8; j++)
		{
			int x;
			uint8_t change = 0;
			for (x = 0; x < mask_length; x++) if (mask[x] == (j * i)) change = 1;
			if (change)
			{
				printf(BG_MAGENTA);
				for (k = 0; k < 8; k++) printf("%c", rand_range(33, 123));
				printf(" ");
				printf(COLOUR_RESET);
			}
			else
			{
				for (k = 0; k < 8; k++) printf("%c", rand_range(33, 123));
				printf(" ");
			}
		}
		printf("\n");
		usleep(10000);
	}
	printf(COLOUR_RESET);
}

