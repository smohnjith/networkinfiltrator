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
