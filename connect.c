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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "wait.h"
#include "colour.h"
#include "connect.h"

void do_connect(char * msg)
{
	char * s = malloc(15 + strlen(msg));
	sprintf(s, "Connecting to %s", msg);
	do_wait(s, 3);
	printf(COLOUR_GREEN);
	printf("\nSuccessfully connected to %s\n", msg);
	printf(COLOUR_RESET);
	free(s);
	usleep(750000);
}
