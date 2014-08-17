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
#include <termios.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "select.h"

extern uint8_t ky[4];

uint8_t echo = 1;
struct termios old, new;

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

void echo_off()
{
	(void) tcgetattr(fileno (stdout), &old);
	new = old;
	new.c_lflag &= ~ECHO;
	(void) tcsetattr(fileno(stdout), TCSAFLUSH, &new);
}

void echo_on()
{
	(void) tcsetattr(fileno(stdout), TCSAFLUSH, &old);
}

int reject(char * in)
{
	int i;
	if (strlen(in) != 4) return 0;
	for (i = 0; i < 4; i++) if (in[i] != ky[i]) return 0;
	return 1;
}
